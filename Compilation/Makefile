CC = gcc

LIBS = -lm 
CCFLAGS = -Wall -ggdb

OBJ = analyseur_lexical.o analyseur_syntaxique.o syntabs.o affiche_arbre_abstrait.o util.o dico.o

all: compilateur.out

compilateur.out: test_yylex.c $(OBJ)
	$(CC) $(CCFLAGS) -o compilateur.out test_yylex.c $(OBJ)
analyseur_lexical.o: analyseur_lexical.c
	$(CC) $(CCFLAGS) -c analyseur_lexical.c
analyseur_syntaxique.o: analyseur_syntaxique.c
	$(CC) $(CCFLAGS) -c analyseur_syntaxique.c
syntabs.o: syntabs.c
	$(CC) $(CCFLAGS) -c syntabs.c
affiche_arbre_abstrait.o: affiche_arbre_abstrait.c
	$(CC) $(CCFLAGS) -c affiche_arbre_abstrait.c
dico.o: dico.c
	$(CC) $(CCFLAGS) -c dico.c

.PHONY : clean

clean:
	- rm -f $(OBJ)
	- rm -f test_yylex
