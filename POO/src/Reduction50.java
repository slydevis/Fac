public class Reduction50 extends TicketSimple{

    public Reduction50(TicketSimple ticketSimple)
    {
        super(ticketSimple.getDuree(),ticketSimple.prix()/2);
    }

    public static void main(String[] args) {
        Date.setMaintenant(new Date(1002131548));

        TicketSimple t = new Reduction50(new Ticket1jour());
        System.out.println("Prix de reduction 50 : " + t.prix());
        System.out.println("Reduction 50 est valide ? " + t.valide());
        Date.setMaintenant(Date.getMaintenant().plus(Duree.JOUR));
        System.out.println("Reduction 50 est valide après un jour en plus ? " + t.valide());

        System.out.println("------------------------");

        TicketSimple ticketSimple = new TicketSimple(Duree.HEURE, 50);
        System.out.println("Prix de ticket Simple : " + ticketSimple.prix());
        System.out.println("ticket Simple est valide ? " + ticketSimple.valide());
        Date.setMaintenant(Date.getMaintenant().plus(Duree.HEURE));
        System.out.println("ticket Simple est valide après une heure en plus ? " + ticketSimple.valide());

        System.out.println("------------------------");

        TicketSimple ticketSolo = new TicketSolo();
        System.out.println("Prix de ticket solo : " + ticketSolo.prix());
        System.out.println("ticket solo est valide ? " + ticketSolo.valide());
        Date.setMaintenant(Date.getMaintenant().plus(Duree.HEURE));
        System.out.println("ticket solo est valide après une heure en plus ? " + ticketSolo.valide());

        System.out.println("------------------------");

        TicketSimple ticket1Jour = new Ticket1jour();
        System.out.println("Prix de Ticket 1 jour : " + ticket1Jour.prix());
        System.out.println("Ticket 1 jour est valide ? " + ticket1Jour.valide());
        Date.setMaintenant(Date.getMaintenant().plus(Duree.JOUR));
        System.out.println("Ticket 1 jour est valide après un jour en plus ? " + ticket1Jour.valide());

        System.out.println("------------------------");

        TicketRechargeable ticketRechargeable = new TicketRechargeable(1);
        System.out.println("Nombre de voyage ticket rechargeable : " + ticketRechargeable.reste());
        System.out.println("Ticket rechargeable est valide ? " + ticketRechargeable.valide());
        System.out.println("Ticket rechargeable est valide ? " + ticketRechargeable.valide());
        System.out.println("Nombre de voyage ticket rechargeable : " + ticketRechargeable.reste());
        ticketRechargeable.recharge(1);
        System.out.println("Ticket rechargeable est valide après la recharge ? " + ticketRechargeable.valide());
        System.out.println("Nombre de voyage ticket rechargeable : " + ticketRechargeable.reste());

        System.out.println("------------------------");

        TicketMultiple ticketMultiple = new TicketMultiple(1);

        System.out.println("Nombre de voyage ticket multiple : " + ticketMultiple.reste());
        System.out.println("Ticket multiple est valide ? " + ticketMultiple.valide());
        System.out.println("Ticket multiple est valide ? " + ticketMultiple.valide());
        System.out.println("Nombre de voyage ticket multiple : " + ticketMultiple.reste());
        ticketRechargeable.recharge(50);
        System.out.println("Nombre de voyage ticket multiple après la recharge : " + ticketMultiple.reste());

        System.out.println("------------------------");

        TicketPerso ticketPerso = new TicketPerso();

        System.out.println("Ticket perso est valide ? " + ticketPerso.valide());

        ticketPerso.abonnement(Duree.MOIS, 30);

        System.out.println("Ticket perso est valide ? " + ticketPerso.valide());

        Date.setMaintenant(Date.getMaintenant().plus(Duree.MOIS));

        System.out.println("Ticket perso est valide après un mois ? " + ticketPerso.valide());

        ticketPerso.abonnement(Duree.MOIS, 30);

        System.out.println("Ticket perso est valide après renouvellement ? " + ticketPerso.valide());

        System.out.println("------------------------");
    }
}
