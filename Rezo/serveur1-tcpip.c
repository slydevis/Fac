#include "bor-util.h"
// Exercice 1 :

typedef enum { E_LIBRE, E_LIRE_REQUETE, E_ECRIRE_REPONSE } Etat;

typedef struct {
  Etat etat;
  int soc;
  struct sockaddr_in adr;
} Slot;

struct sockaddr_in adr_client;

void init_slot (Slot *o) {
  memset(&o->adr, 0, sizeof(o->adr));
  o->soc = -1;
  o->etat = E_LIBRE;
}

int slot_est_libre (Slot *o) {
  if(o->etat == E_LIBRE)
    return 1;

  return -1;
}

void liberer_slot (Slot *o) {
  if(slot_est_libre(o))
    return;

  o->etat = E_LIBRE;
  init_slot(o);
}

// Exercice 2

#define SLOTS_NB 2

typedef struct {
  Slot slots[SLOTS_NB];
  int soc_ec;
  struct sockaddr_in adr;
} Serveur;

void init_serveur(Serveur *ser) {
  ser->soc_ec = -1;
  for(int i = 0; i < SLOTS_NB; i++)
    init_slot(&ser->slots[i]);
}

int chercher_slot_libre(Serveur *ser) {
  for(int i = 0; i < SLOTS_NB; i++)
    if(slot_est_libre(&ser->slots[i]))
      return i;

  return -1;
}

// Exercice 3

int demarrer_serveur(Serveur *ser, int port) {
    init_serveur(ser);
    ser->soc_ec = bor_create_socket_in(SOCK_STREAM, port, &ser->adr);
    if(ser->soc_ec < 0)
      return -1;
    if(bor_listen(ser->soc_ec, 8)) {
      close(ser->soc_ec);
      ser->soc_ec = -1;
      return -1;
    }

    return 0;
}
void fermer_serveur(Serveur *ser) {
  close(ser->soc_ec);
  ser->soc_ec = -1;

  for(int i = 0; i < SLOTS_NB; i++)
    liberer_slot(&ser->slots[i]);
}

// Exercice 4

int accepter_connexion(Serveur *ser) {
  printf("Serveur : connexion en cours...\n");
  int soc_se = bor_accept_in(ser->soc_ec, &adr_client);

  if(soc_se < 0) return -1;

  int i = chercher_slot_libre(ser);

  if(i < 0) {
    close(soc_se);
    printf("Serveur : Connexion refusée avec %s : trop de clients\n"
                                      , bor_adrtoa_in(&adr_client));

    return 0;
  }

  printf("Serveur[%d] : connexion établie avec %s\n", i, bor_adrtoa_in(&adr_client));

  Slot *o = &ser->slots[i];
  o->soc = soc_se;
  o->adr = adr_client;
  o->etat = E_LIRE_REQUETE;

  return 1;
}

// Exercice 5 :

int proceder_lecture__requete(Slot *o) {
	printf("Lecture en cours :\n");
	o->etat = E_ECRIRE_REPONSE;
	
	char* buff;
	bor_read_str(o->soc, buff, 20000);
	
	printf("%s\n", buff);
	
	return 0;
}

int proceder_ecriture_reponse(Slot *o) {
	o->etat = E_LIRE_REQUETE;
	return 0;
}	

void traiter_slot_si_eligible(Slot*o, fd_set *set_read, fd_set *set_write) {

  int k = 1;

  if(slot_est_libre(o)) return;

  switch(o->etat) {
    case E_ECRIRE_REPONSE :
        if(FD_ISSET(o->soc, set_write))
          k = proceder_ecriture_reponse(o);
      break;
    case E_LIRE_REQUETE :
        if(FD_ISSET(o->soc, set_read))
          k = proceder_lecture__requete(o);
      break;
    default :
      printf("Serveur : état invalide....\n");
      break;
  }

  if(k <= 0) {
    printf("Serveur[%d] : libération du slot\n", o->soc);
    liberer_slot(o);
  }
}

// Exercice 6 :

void inser_fd(int fd, fd_set *set, int *maxfd) {
  FD_SET(fd, set);
  if(*maxfd < fd) *maxfd = fd;
}

void preparer_select (Serveur *ser, int *maxfd, fd_set *set_read, fd_set *set_write) {
  FD_ZERO(set_read);
  FD_ZERO(set_write);
  *maxfd = -1;

  for(int i = 0; i < SLOTS_NB; i++) {
    Slot *o = &ser->slots[i];
    if(slot_est_libre(o)) continue;
    switch(o->etat) {
      case E_LIRE_REQUETE :
        inser_fd(o->soc, set_read, maxfd);
        break;
      case E_ECRIRE_REPONSE :
        inser_fd(o->soc, set_write, maxfd);
        break;
      default : ;
    }
  }
}

int faire_scrutation(Serveur *ser) {	
	fd_set set_read;
	fd_set set_write;
	int max_fd;

	preparer_select(ser, &max_fd, &set_read, &set_read); 
	
	select(max_fd, &set_read, &set_write, NULL, NULL);
	
	accepter_connexion(ser);

	for(int i = 0; i < SLOTS_NB; i++)
	{
		traiter_slot_si_eligible(&ser->slots[i], &set_read, &set_write);
	}
	
	return 0;
}

Serveur ser;

void gestionBoucle(int sig)
{
	if(sig == SIGINT)
	{
		printf("\nServeur : arret\n");
		fermer_serveur(&ser);
		exit(0);
	}
}
int main(int argc, char* argv[]) {
	if(argc - 1 != 1) {
		printf("Erreur : Nombre d'argument invalide\n");
		return -1;
	}
	
	int numPort = atoi(argv[1]);
		
	struct sockaddr_in adr;
	adr.sin_family      = AF_INET;
	adr.sin_addr.s_addr = INADDR_ANY;
	
	ser.adr = adr;

	bor_signal(SIGINT, gestionBoucle, SA_RESTART);
	
	demarrer_serveur(&ser, numPort);

	while(1){
		faire_scrutation(&ser);
	}
	
	fermer_serveur(&ser);
}

// TP9 : Serveur TCP/IP

#define REQSIZE 4096
typedef struct {
    .....
    char rep[REQSIZE];
    int rep_pos, fin_entete;
} Slot;

void init_slot(Slot *o) {
    .....
    o->rep[0] = '\0';
    o->rep_pos = 0;
    o->fin_entete = 0;
}

int lire_suite_requete(Slot *o) {
    int k = bor_read_str(o->soc, o->rep + o->rep_pos, REQSIZE - o->rep_pos);
    if(k > 0) o->rep_pos += k;
    return k;
}

int ecrire_suite_reponse(Slot *o) {
    int k = bor_write_str(o->soc, o->rep + o->rep_pos);
    if(k < 0) o->rep_pos += k;
    return k;
}

int chercher_fin_entete(Slot *o, int debut) {
    for(int i = debut; o->rep[i]; ++i)
    {
        if((o->rep[i] == '\n' && o->rep[i + 1] == '\n') ||
           (o->rep[i] == '\r' && o->rep[i + 1] == '\n' && o->rep[i + 2] == '\r' && o->rep[i + 3] == '\n'))
            return i;
    }
    return -1;
}

typedef enum {
    M_NONE,
    M_GET,
    M_TRACE,
} Id_methode;

typedef enum {
    C_OK                = 200,
    C_BAD_REQUEST       = 400,
    C_NOT_FOUND         = 404,
    C_METHOD_UNKNOWN    = 501,
} Code_reponse;

typedef struct {
    char methode[REQSIZE], url[REQSIZE], version[REQSIZE], chemin[REQSIZE];
    Id_methode id_meth;
    Code_reponse code_rep;
} Infos_entete;


char* get_http_error_message(Code_reponse code) {
    switch (code) {
    case C_OK:
        printf("OK");
        break;
    case C_BAD_REQUEST:
        printf("Erreur 400 : Bad request");
        break;
    case C_NOT_FOUND:
        printf("Erreur 404 : Not found");
        break;
    case C_METHOD_UNKNOWN:
        printf("Erreur 501 : Method unknown");
        break;
    default:
        printf("Code message inconnue");
        break;
    }
}

Id_methode get_id_methode(char* methode) {
    if(!strcasecmp(methode, "GET")) return M_GET;
    if(!strcasecmp(methode, "TRACE")) return M_TRACE;
    return M_NONE;
}

void analyser_requete(Slot *o, Infos_entete *ie) {
    // provisoire
    (void) o;
    ie->code_rep = C_NOT_FOUND;
}

void preparer_reponse(Slot *o, Infos_entete *ie) {
    // provisoire
    (void) ie;
    sprintf(o->rep, "HTTP/1.1 404 Not.found\n"
            "server : serweb\n"
            "connection : close\n"
            "Content-Type : text/html\n\n"
            "<html><head>\n"
            "<title>Not found</title>\n"
            "</head><body>\n"
            "<h1>Not Found</h1>\n"
            "</body></html>\n");
}

int proceder_lecture__requete(Slot *o) {
    int prec_pos = o->rep_pos;
    int k = lire_suite_requete(o);
    if(k <= 0) return -1;
    int debut = prec_pos - 3;
    o->fin_entete = chercher_fin_entete(o, debut);

    if(o->fin_entete < 0)
    {
        printf("Serveur[%d] : requete incomplete\n", o->soc);
        return 1;
    }

    printf("Serveur[%d] : reçue requête complete\n\"%s\"\n", o->soc, o->rep);
    analyser_requete(o, &ie);
    preparer_reponse(o, &ie);
    o->etat = E_ECRIRE_REPONSE;
    return 1;
}

int proceder_ecriture_reponse(Slot *o)
{
    int k = ecrire_suite_reponse(o);
    if(k < 0) return -1;
    if(o->rep_pos < (int)strlen(o->rep)) {
        printf("Serveur[%d] écriture réponse incomplète\n", o->soc);

        return -1
    }
    // On envoie ensuite le fichier
    return 0; // pour le moment
}
