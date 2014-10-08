import java.util.ArrayList;
import java.util.List;

/**
 * Created by guillaume on 08/10/14.
 */
public class Repertoire implements Fichier {

    String nom;
    List<Fichier> tabFic;
    Repertoire father;

    public Repertoire(String nom, Repertoire father)
    {
        this.nom = nom;
        this.tabFic = new ArrayList<Fichier>();
        this.father = father;
    }

    public Repertoire()
    {
        this.nom = "/";
        this.tabFic = new ArrayList<Fichier>();
        this.father = this;
    }

    void ajoute(Fichier f)
    {
        if(this.tabFic.size() < 256)
            this.tabFic.add(f);
    }

    Fichier cherche(String nom)
    {
        if(nom.equals( ".." ) ){
            return this.father;
        }

        Fichier CurrentFile;
        for(int i = 0; i < tabFic.size(); ++i)
        {
            CurrentFile = tabFic.get(i);
            if(CurrentFile.getNom() == nom)
                return CurrentFile;
        }
        return null;
    }

    void affiche()
    {
            System.out.println("Dans le répertoir : " + this.getNom());
        for(int i = 0; i < tabFic.size(); ++i)
            System.out.println("- " + tabFic.get(i).getNom());
    }

    public String getNom()
    {
        return this.nom;
    }
}
