public class ElementEntier {
    ElementEntier next;
    int value;

    ElementEntier(int value, ElementEntier entier)
    {
        this.value = value;
        next = entier;
    }
}
