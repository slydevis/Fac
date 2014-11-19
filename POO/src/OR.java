public class OR extends Composant {

    public OR()
    {
        entree = new Composant[2];
    }

    public void miseAJour()
    {
        if(entree[0] == null || entree[1] == null)
        {
            for(int i = 0; i < nbSorties; ++i)
                valeur = -1;
        }
        else if(entree[0].valeur == 1 || entree[1].valeur == 1)
        {
            for(int i = 0; i < nbSorties; ++i)
                valeur = 1;
        }
        else
        {
            for(int i = 0; i < nbSorties; ++i)
                valeur = 0;
        }

        for(int i = 0; i < nbSorties; ++i)
            sortie[i].getComposant().miseAJour();
    }

    public void add(Extremite extremite)
    {
        int num = extremite.getNum();
        extremite.getComposant().entree[num] = this;
        sortie[nbSorties] = extremite;
        nbSorties++;

        miseAJour();
    }
}
