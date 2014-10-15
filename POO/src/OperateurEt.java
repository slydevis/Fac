public class OperateurEt implements OperateurBinaire {

    public boolean applique(boolean e1, boolean e2)
    {
        return e1 && e2;
    }

    public String getName()
    {
        return " ET ";
    }
}
