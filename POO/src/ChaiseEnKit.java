/**
 * Created by guillaume on 15/10/14.
 */
public class ChaiseEnKit extends TabouretEnKit {

    Plaque dos;
    public ChaiseEnKit(Plaque p, Barreau b1, Barreau b2, Barreau b3, Barreau b4, Plaque dos)
    {
        super(p, b1, b2, b3, b4);
        this.dos = dos;
    }

    public boolean conforme()
    {
        return super.conforme() && (dos.largeur == p.largeur);
    }

    public int hauteur()
    {
        return super.hauteur() + dos.longeur;
    }

    public int largeur()
    {
        return super.largeur();
    }
}
