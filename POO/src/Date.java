public class Date {
    private int value;
    private static Date now;

    public Date(int value)
    {
        this.value = value;
    }

    public Date plus(int duree)
    {
        this.value += duree;
        return this;
    }

    public int getValue()
    {
        return this.value;
    }

    public boolean avant(Date d)
    {
        return this.value > d.getValue();
    }

    public static Date getMaintenant()
    {
        return Date.now;
    }

    public static void setMaintenant(Date date)
    {
        Date.now = date;
    }
}
