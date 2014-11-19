import java.util.ArrayList;

public abstract class Composant {
    protected int valeur;
    protected int nbSorties;
    protected Extremite[] sortie = new Extremite[10];
    protected Composant[] entree;

    public Composant() {
        valeur = -1;
        nbSorties = 0;
    }

    abstract void miseAJour();

    abstract void add(Extremite extremite);

    void raccorde(Extremite extremite)
    {
        add(extremite);
    }

    public static void main(String[] args) {
        AND et = new AND();
        OR ou = new OR();
        UN un = new UN();
        ZERO zero = new ZERO();
        NOT non = new NOT();
        LED led1 = new LED("LED 1");
        LED led2 = new LED("LED 2");

        et.raccorde(new Extremite(ou, 0));
        et.raccorde(new Extremite(non));
        non.raccorde(new Extremite(led1));
        un.raccorde(new Extremite(et, 0));
        // provoque l'affichage que la led 1 est eteinte:
        un.raccorde(new Extremite(et, 1));
        zero.raccorde(new Extremite(ou, 1));
        // provoque l'affichage que la led 2 est allumee:
        ou.raccorde(new Extremite(led2));

    }
}
