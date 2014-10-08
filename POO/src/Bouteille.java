public class Bouteille {
    int quantite;
    boolean est_ouverte;

    public Bouteille(int quantite)
    {
        this.quantite = quantite;
        est_ouverte = false;
    }

    public void ouvrir()
    {
        est_ouverte = true;
    }

    public void fermer()
    {
        est_ouverte = false;
    }

    public void verser_dans(Verre v, int q)
    {
        if(est_ouverte == true)
            v.emplir(q);

        quantite -= q;
    }

    public static void main(String argv[])
    {
        Bouteille orange = new Bouteille(100);
        Bouteille vodka = new Bouteille(100);
        Verre verre = new Verre(20);
        vodka.ouvrir();
        orange.ouvrir();
        vodka.verser_dans(verre, 5);
        orange.verser_dans(verre, 10);
        System.out.println("Verre = " + verre.quantite);
        verre.boire(verre.quantite);
        System.out.println("Verre = " + verre.quantite);
    }
}
