public class Monome {

    float coeff;
    int degre;

    Monome(float coeff, int degre)
    {
        this.coeff = coeff;
        this.degre = degre;
    }

    void additionne(float coeff)
    {
        this.coeff += coeff;
    }

    void additionne(Monome m)
    {
        if(m.degre == this.degre)
            this.additionne(m.coeff);
    }

    void multiplie(float coeff, int degre)
    {
        this.coeff *= coeff;
        this.degre += degre;
    }

    void multiplie(Monome m)
    {
        this.coeff *= m.coeff;
        this.degre += m.degre;
    }

    void affiche()
    {
        if(this.coeff != 0)
            System.out.print(this.coeff + "x^" + this.degre);
    }
}
