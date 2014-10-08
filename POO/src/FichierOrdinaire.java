public class FichierOrdinaire implements Fichier {

    String nom;

    public FichierOrdinaire(String nom)
    {
        this.nom = nom;
    }

    public String getNom()
    {
        return this.nom;
    }
}
