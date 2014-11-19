public class ZERO extends Composant {

    public ZERO()
    {
        entree = new Composant[1];
    }

    public void miseAJour()
    {
        for(int i = 0; i < nbSorties; ++i)
        {
            valeur = 0;
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
