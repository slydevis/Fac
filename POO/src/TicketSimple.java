public class TicketSimple {
    private float prix;
    private int duree;
    private Date datelimite;

    public TicketSimple(int duree, float prix)
    {
        this.duree = duree;
        this.prix = prix;
        this.datelimite = null;
    }

    public float prix()
    {
        return this.prix;
    }

    public int getDuree()
    {
        return this.duree;
    }

    public Date getDatelimite()
    {
        return this.datelimite;
    }

    public boolean valide()
    {
        if(datelimite == null)
        {
            datelimite = Date.getMaintenant().plus(duree);
            return true;
        }

        return Date.getMaintenant().avant(datelimite);
    }
}
