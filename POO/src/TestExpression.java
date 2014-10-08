public class TestExpression
{
    public static void main(String argv[])
    {
        Variable v = new Variable(true);

        ExpressionsBooleenne e = new ExpressionsBinaire(new Non(v), new OperateurOu(), Constante.FAUX);
        e.affiche();
        System.out.println(e.evalue());
        v.setValeur(false);
        System.out.println(e.evalue());
    }
}
