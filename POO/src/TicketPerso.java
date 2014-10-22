public class TicketPerso extends TicketRechargeable {

    TicketSimple ticketSimple;

    TicketPerso()
    {
        super(0);
    }

    boolean abonnement(int duree, float prix)
    {
        if(ticketSimple == null && super.reste() == 0)
        {
            ticketSimple = new TicketSimple(duree, prix);
            super.recharge(9999);
            return true;
        }

        if(!ticketSimple.valide())
        {
            ticketSimple = new TicketSimple(duree, prix);
            return true;
        }

        return false;
    }

    public boolean valide()
    {
        return super.valide() && ticketSimple.valide();
    }
}
