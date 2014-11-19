public class UN extends Composant {

    public UN()
    {
        entree = new Composant[1];
    }

    public void miseAJour()
    {
        for(int i = 0; i < nbSorties; ++i)
        {
            valeur = 1;
            sortie[i].getComposant().miseAJour();
        }
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
