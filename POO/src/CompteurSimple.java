public class CompteurSimple {

    int min, max, cpt;
    String name;

    public CompteurSimple(int min, int max, String name)
    {
        this.min = min;
        this.max = max;
        this.cpt = min;
        this.name = name;
    }

    public CompteurSimple(CompteurSimple compteurSimple)
    {
        this.min = compteurSimple.min;
        this.max = compteurSimple.max;
        this.cpt = compteurSimple.cpt;
        this.name = compteurSimple.name;
    }

    public void affiche()
    {
        System.out.println(name + " : " + cpt);
    }

    public boolean inc()
    {
        if(cpt != max) {
            cpt++;
            return false;
        }
        else {
            cpt = min;
            return true;
        }
    }

    public boolean equals(CompteurSimple compteurSimple)
    {
        if(this.min == compteurSimple.min &&
           this.max == compteurSimple.max &&
           this.cpt == compteurSimple.cpt &&
           this.name.equals(compteurSimple.name))
            return true;
        else
            return false;
    }

    public static void main(String argv[])
    {
        CompteurSimple trimestre = new CompteurSimple(1, 4, "Trimestre");
        trimestre.affiche();
        trimestre.inc(); trimestre.inc(); trimestre.inc();
        trimestre.affiche();
        trimestre.inc();
        trimestre.affiche();
    }
}
