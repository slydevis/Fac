public class Polynome {

    Polynome polynome;
    Monome monome;

    Polynome(float coeff, int degre)
    {
        monome = new Monome(coeff, degre);
    }

    Polynome(float coeff, int degre, Polynome p)
    {
        monome = new Monome(coeff, degre);
        polynome = p;
    }

    void additionne(float coeff, int degree)
    {
        monome.additionne(coeff);
        for(Polynome buff = polynome; buff != null; buff = buff.polynome)
            buff.monome.additionne(coeff);
    }

    void additionne(Monome m)
    {
        monome.additionne(m);
        for(Polynome buff = polynome; buff != null; buff = buff.polynome)
            buff.monome.additionne(m);
    }

    void multiplie(float coeff, int degree)
    {
        monome.multiplie(coeff, degree);
        for(Polynome buff = polynome; buff != null; buff = buff.polynome)
            buff.monome.multiplie(coeff, degree);
    }

    void multiplie(Monome m)
    {
        monome.multiplie(m);
        for(Polynome buff = polynome; buff != null; buff = buff.polynome)
            buff.monome.multiplie(m);
    }

    void affiche()
    {
        this.monome.affiche();

        if(this.monome.coeff != 0)
            System.out.print(" + ");

        for(Polynome buff = polynome; buff != null; buff = buff.polynome) {
           buff.monome.affiche();
           if( buff.polynome != null && buff.monome.coeff != 0)
                System.out.print(" + ");
        }

        System.out.println("");
    }

    public static void main(String[] argv)
    {
        Polynome polynome1 = new Polynome(3.6f, 0, new Polynome(5.9f, 1, new Polynome(6.1f, 2)));

        polynome1.multiplie(2, 3);

        polynome1.affiche();
    }
}
