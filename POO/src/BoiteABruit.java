public abstract class BoiteABruit {
    private static boolean isRetourne = false;
    abstract String bruit();

    void retourne()
    {
        if(BoiteABruit.isRetourne == true)
            System.out.print(bruit());


        BoiteABruit.isRetourne = !BoiteABruit.isRetourne;
    }
}
