public class ExpressionsBinaire implements ExpressionsBooleenne {

    ExpressionsBooleenne exp1;
    ExpressionsBooleenne exp2;
    OperateurBinaire expBin;

    public ExpressionsBinaire(ExpressionsBooleenne exp1, OperateurBinaire expBin, ExpressionsBooleenne exp2)
    {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.expBin = expBin;
    }

    public boolean evalue()
    {
        return expBin.applique(exp1.evalue(), exp2.evalue());
    }

    public void affiche()
    {
        System.out.print( "( " );
        exp1.affiche();
        System.out.print(expBin.getName());
        exp2.affiche();
        System.out.println( ") " );
    }

}
