public class CompteurCompose {

    CompteurSimple compteurSimple;
    CompteurCompose compteurCompose;

    public CompteurCompose(CompteurSimple compteurSimple)
    {
        this.compteurSimple = compteurSimple;
        this.compteurCompose = null;
    }

    public CompteurCompose(CompteurSimple compteurSimple, CompteurCompose compteurCompose)
    {
        this.compteurSimple = compteurSimple;
        this.compteurCompose = compteurCompose;
    }

    public CompteurCompose(CompteurCompose compteurCompose)
    {
        if(compteurCompose.compteurCompose != null)
            this.compteurCompose = new CompteurCompose(compteurCompose.compteurCompose);
        this.compteurSimple = new CompteurSimple(compteurCompose.compteurSimple);
    }

    public boolean equals(CompteurCompose compteurCompose)
    {
        if(this.compteurSimple.equals(compteurCompose.compteurSimple))
            if(this.compteurCompose != null){
                this.compteurCompose.equals(compteurCompose);
                return true;
            }

        return false;

    }

    public boolean inc()
    {
        if(compteurSimple.inc())
        {
            if(compteurCompose != null)
                compteurCompose.inc();

            return true;
        }
        return false;
    }

    public void affiche()
    {
        if(compteurCompose != null)
            compteurCompose.affiche();

        compteurSimple.affiche();
    }

    public static void main(String argv[])
    {
        CompteurCompose c;
        c = new CompteurCompose(new CompteurSimple(0, 59, "Minute"),
                                    new CompteurCompose(new CompteurSimple(0, 23, "Heure"),
                                        new CompteurCompose(new CompteurSimple(1, 365, "Jour"))));

        c.affiche();

        for(int i = 1; i < 10000; i++)
            c.inc();

        c.affiche();

        CompteurSimple c2 = new CompteurSimple(0, 59, "Minute");
        CompteurSimple c3 = new CompteurSimple(c2);

        if(c2.equals(c3))
            System.out.println("C2 == C3");
        else
            System.out.println("C2 != C3");

        c2.inc();

        if(c2.equals(c3))
            System.out.println("C2 == C3");
        else
            System.out.println("C2 != C3");

        CompteurCompose cc = new CompteurCompose(new CompteurSimple(0, 59, "Minute"),
                                                    new CompteurCompose(new CompteurSimple(0, 23, "Heure")));

        CompteurCompose cc2 = new CompteurCompose(cc);

        if(cc.equals(cc2))
            System.out.println("CC == CC2");
        else
            System.out.println("CC != CC2");

        cc.inc();

        if(cc.equals(cc2))
            System.out.println("CC == CC2");
        else
            System.out.println("CC != CC2");
    }
}
