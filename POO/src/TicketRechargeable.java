public class TicketRechargeable {

    private int nbVoy;
    public TicketSolo ticketSolo;

    public TicketRechargeable(int nbVoy)
    {
        ticketSolo = new TicketSolo();
        this.nbVoy = nbVoy;
    }

    public int reste()
    {
        return this.nbVoy;
    }

    public void recharge(int n)
    {
        this.nbVoy += n;
        ticketSolo = new TicketSolo();
    }

    public boolean valide()
    {
        if(nbVoy == 0) return false;

        if(!ticketSolo.valide())
        {
            nbVoy--;

            if(nbVoy == 0) return false;

            ticketSolo = new TicketSolo();
        }

        return true;
    }
}
