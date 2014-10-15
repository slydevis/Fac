public class TesteChaise {
    public static void main(String[] args) {

        Plaque plaque = new Plaque(50, 122);

        plaque.decoupeSensLargeur(72);

        Plaque dos = new Plaque(50, 50);

        Plaque p1 = new Plaque(60, 3);
        Plaque p2 = new Plaque(60, 3);
        Plaque p3 = new Plaque(60, 3);
        Plaque p4 = new Plaque(60, 3);

        Barreau b1 = new Barreau(p1);
        Barreau b2 = new Barreau(p2);
        Barreau b3 = new Barreau(p3);
        Barreau b4 = new Barreau(p4);

        ChaiseEnKit chaise = new ChaiseEnKit(plaque, b1, b2, b3, b4, dos);

        System.out.println(chaise.conforme());

        System.out.println(chaise.hauteur());

        System.out.println(chaise.largeur());
    }
}
