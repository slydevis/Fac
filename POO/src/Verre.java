public class Verre {

    int contenance;
    int quantite;

    public Verre(int contenance)
    {
        this.contenance = contenance;
        this.quantite = 0;
    }

    public void emplir(int q)
    {
        if((quantite + q) <= contenance)
            quantite += q;
    }

    public void boire(int q)
    {
        if((quantite - q) >= 0)
            quantite -= q;
    }
}
