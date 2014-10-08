public class Compteur {
    public int cpt;
    public Compteur()
    {
        cpt = 0;
    }
    public void raz() {
        cpt = 0;
    }

    public void clic() {
        cpt++;
    }

    public int getCpt() {
        return this.cpt;
    }

    public static void main(String argv[])
    {
        Compteur compteur = new Compteur();
        compteur.clic();
        compteur.clic();
        System.out.println("Cpt = " + compteur.getCpt());
        compteur.raz();
    }
}
