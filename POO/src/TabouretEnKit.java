public class TabouretEnKit {

    Plaque p;
    Barreau b1;
    Barreau b2;
    Barreau b3;
    Barreau b4;

    public TabouretEnKit(Plaque p, Barreau b1, Barreau b2, Barreau b3, Barreau b4)
    {
        this.p = p;
        this.b1 = b1;
        this.b2 = b2;
        this.b3 = b3;
        this.b4 = b4;
    }

    int hauteur()
    {
        return b1.p.longeur;
    }

    int largeur()
    {
        return p.largeur;
    }

    boolean conforme()
    {
        return (p.largeur == p.longeur) && b1.conforme()
                                        && b2.conforme()
                                        && b3.conforme()
                                        && b4.conforme()
                                        && (b1.p.longeur == b2.p.longeur)
                                        && (b2.p.longeur == b3.p.longeur)
                                        && (b3.p.longeur == b4.p.longeur);
    }
}
