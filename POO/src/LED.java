public class LED extends Composant {
    private String ledName;
    public LED(String name)
    {
        this.ledName = name;
        entree = new Composant[1];
    }

    public void miseAJour()
    {
        if(entree[0].valeur == -1)
        {
            return;
        }
        else if(entree[0].valeur == 1)
        {
            System.out.println(this.ledName + " est allumée");
        }
        else
        {
            System.out.println(this.ledName + " est éteinte");
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
