public class Constante extends Variable{
    final public static Constante VRAI = new Constante(true);
    final public static Constante FAUX = new Constante(false);

    private Constante(boolean value)
    {
        super(value);
    }
}
