public class NOT extends Composant {

    public NOT()
    {
        entree = new Composant[1];
    }

    public void miseAJour()
    {
        if(entree[0] == null)
        {
            for(int i = 0; i < nbSorties; ++i)
                valeur = -1;
        }
        else if(entree[0].valeur == 1)
        {
            for(int i = 0; i < nbSorties; ++i)
                valeur = 0;
        }
        else
        {
            for(int i = 0; i < nbSorties; ++i)
                valeur = 1;
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
