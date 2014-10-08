public class ListeEntier {
    ElementEntier tete;
    ElementEntier queu;

    private int size;

    ListeEntier()
    {
        size = 0;
        tete = null;
    }

    void ajoute(int value) {

        ElementEntier p = new ElementEntier(value, null);
        if(tete == null)
            tete = p;
        else
            queu.next = p;

        queu = p;

        size++;
    }

    void enleve()
    {
        if(this.longeur() == 0) return;

        tete = tete.next;

        size--;
    }


    int longeur() {
        return this.size;
    }

    int at(int pos)
    {
        if(this.longeur() == 0) return 0;

        int cpt = 0;
        for(ElementEntier i = tete; i != null; i = i.next)
        {
            if(cpt == pos)
                return i.value;

            cpt++;
        }
        return 0;
    }

    int minimum()
    {
        if(this.longeur() == 0) return 0;

        int buff = tete.value;

        for(ElementEntier i = tete; i != null; i = i.next)
        {
            if(buff > i.value)
                buff =  i.value;
        }

        return buff;
    }

    void copie(ListeEntier listeEntier)
    {
        if(listeEntier.listeVide()) return;

        int Ksize = this.longeur();
        for(int i = 0; i < Ksize; ++i)
            this.enleve();

        for(int i = 0; i < listeEntier.longeur(); ++i)
            this.ajoute(listeEntier.at(i));

        this.size = listeEntier.longeur();
    }

    boolean equale(ListeEntier listeEntier)
    {
        for(int i = 0; i < listeEntier.longeur(); ++i)
            if(this.at(i) != listeEntier.at(i)) return false;

        return true;
    }

    boolean listeVide()
    {
        if(this.longeur() == 0) return true;
        return false;
    }

    public static void main(String[] args) {

        ListeEntier listeEntier = new ListeEntier();

        for(int i = 5; i < 10; ++i)
            listeEntier.ajoute(i);

        for(int i = 0; i < listeEntier.longeur(); ++i)
            System.out.println(listeEntier.at(i));

        System.out.println("Taille = " + listeEntier.longeur());

        System.out.println(listeEntier.minimum());

        listeEntier.enleve();

        System.out.println("Taille = " + listeEntier.longeur());

        for(int i = 0; i < listeEntier.longeur(); ++i)
            System.out.println(listeEntier.at(i));

        ListeEntier copie = new ListeEntier();

        for(int i = 6; i < 10; ++i)
            copie.ajoute(i);

        if(listeEntier.equale(copie))
            System.out.println("listeEntier == copie");
        else
            System.out.println("listeEntier != copie");

        copie.enleve();

        if(listeEntier.equale(copie))
            System.out.println("listeEntier == copie");
        else
            System.out.println("listeEntier != copie");

        copie.copie(listeEntier);

        if(listeEntier.equale(copie))
            System.out.println("listeEntier == copie");
        else
            System.out.println("listeEntier != copie");
    }
}
