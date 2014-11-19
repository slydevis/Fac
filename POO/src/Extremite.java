public class Extremite {
    private Composant composant;
    private int num;

    public Extremite(Composant composant, int num)
    {
        this.composant = composant;
        this.num = num;
    }

    public Extremite(Composant composant)
    {
        this.composant = composant;
        this.num = 0;
    }

    public Composant getComposant()
    {
        return composant;
    }

    public int getNum()
    {
        return this.num;
    }
}
