public class Non implements ExpressionsBooleenne {

    private ExpressionsBooleenne expressionsBooleenne;

    public Non(ExpressionsBooleenne value)
    {
        expressionsBooleenne = value;
    }

    public boolean evalue()
    {
        return !expressionsBooleenne.evalue();
    }

    public void affiche()
    {
        System.out.print( "NON(");
        expressionsBooleenne.affiche();
        System.out.print( ")" );
    }
}
