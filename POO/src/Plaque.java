public class Plaque {
    int longeur;
    int largeur;

    Plaque(int longeur, int largeur)
    {
        if(longeur > largeur)
        {
            this.longeur = longeur;
            this.largeur = largeur;
        }
        else
        {
            this.longeur = largeur;
            this.largeur = longeur;
        }
    }

    Plaque decoupeSensLongeur(int n)
    {
        if(n >= this.largeur)
            return null;

        this.largeur -= n;
        return new Plaque(this.longeur, n);
    }

    Plaque decoupeSensLargeur(int n)
    {
        if(n >= this.longeur)
            return null;

        this.longeur -= n;

        if(this.largeur > this.longeur)
        {
            int buff = this.largeur;
            this.largeur = this.longeur;
            this.longeur = buff;
        }

        return new Plaque(n, this.largeur);
    }
}
