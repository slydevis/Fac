public class BoiteAMeufSaintValentin extends BoiteAMeuh {
    private static int id = 0;
    private int nbRetourne;

    public BoiteAMeufSaintValentin()
    {
        super();
        nbRetourne = 0;
        BoiteAMeufSaintValentin.id++;
    }

    public int getNumero()
    {
        return BoiteAMeufSaintValentin.id;
    }

    public void retourne()
    {
        if(nbRetourne != 0 && nbRetourne%5 == 0)
        {
            if(nbRetourne%10 == 0)
            {
                System.out.print("Je t'ai ");
                nbRetourne = 0;
            }
            super.retourne();
        }

        nbRetourne++;

    }

    public static void main(String argv[])
    {
        BoiteAMeufSaintValentin boiteAMeufSaintValentin = new BoiteAMeufSaintValentin();

        for(int i = 0; i < 40; ++i)
        {
            boiteAMeufSaintValentin.retourne();
            if(i%10 == 0) System.out.println("");

        }
    }
}
