public class Barreau {
    Plaque p;

    Barreau(Plaque p)
    {
        this.p = p;
    }

    Plaque decoupeSensLargeur(int n)
    {
        return p.decoupeSensLargeur(n);
    }

    boolean conforme()
    {
        return p.largeur == 3;
    }
}
