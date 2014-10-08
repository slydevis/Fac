public class Systeme {

    Repertoire CurrentFolder;

    public Systeme()
    {
        CurrentFolder  = new Repertoire();
        mkdir("home");
        mkdir("bin");
    }

    public Repertoire mkdir(String nom)
    {
        Repertoire rep = new Repertoire(nom, CurrentFolder);
        CurrentFolder.ajoute(rep);
        return rep;
    }

    public void cd(String rep)
    {
        if(!rep.equals(".."))
        {
            Fichier result = CurrentFolder.cherche(rep);
            if(result != null)
                CurrentFolder = (Repertoire) result;
        }
        else if(rep.equals("/"))
        {
            Fichier result = CurrentFolder.cherche(rep);

            while(result != null && result.getNom().equals("/"))
            {
                result = CurrentFolder.cherche(rep);
                CurrentFolder = (Repertoire) result;
            }

        }
        else
        {
            CurrentFolder = CurrentFolder.father;
        }
    }

    public void ls()
    {
        CurrentFolder.affiche();
    }

    public void ls(String file)
    {
        Fichier tmp = CurrentFolder.cherche(file);
        if( tmp instanceof Repertoire ){
            ((Repertoire) tmp).affiche();
        }
        else{
            tmp.getNom();
        }
    }

    public void creeCompte(String login)
    {
        Repertoire saveWorkDir = this.CurrentFolder;

        cd("/");
        cd("home");
        mkdir(login);
        cd(login);

        CurrentFolder.ajoute(new FichierOrdinaire(".bashrc"));

        CurrentFolder = saveWorkDir;
    }

    public void login(String login)
    {
        cd("/");
        cd("home");
        cd(login);
    }

    public static void main(String argv[])
    {
        Systeme s = new Systeme();

        s.creeCompte("moi");
        s.creeCompte("pasmoi");

        s.login("moi");

        s.ls();

        s.ls("..");

        s.cd("..");
        s.mkdir("rep");

        s.ls();

        s.ls("moi");
        s.ls("..");
    }

}
