public class Variable implements ExpressionsBooleenne {

    private boolean value;

    public Variable(boolean value)
    {
        this.value = value;
    }

    public boolean evalue()
    {
        return value;
    }

    public void affiche()
    {
        if(value)
            System.out.print("VRAI");
        else
            System.out.print("FAUX");
    }

    public void setValeur(boolean value)
    {
        this.value = value;
    }
}
