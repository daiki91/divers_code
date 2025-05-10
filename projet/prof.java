import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class prof extends acceuil {
    private String prenomProf;
    private String nomProf;
    private String nommatiere;
    private String niveauEnseigner;

    // constructeur de la classe
    public prof(String prenomProf, String nomProf, String nommatiere, String niveauEnseigner) {
        System.out.println("bonjour c'est moi le prof repondant au nom  " + prenomProf + "  " + nomProf
                + " qui enseigne la/le  " + nommatiere + "  en classe de  " + niveauEnseigner);
        createFileProf(prenomProf, nomProf, nommatiere, niveauEnseigner);
    }

    // create getter and setter
    public String getNiveauEnseigner() {
        return niveauEnseigner;
    }

    public void setNiveauEnseigner(String niveauEnseigner) {
        this.niveauEnseigner = niveauEnseigner;
    }

    // create getter and setter
    public String getNomProf() {
        return nomProf;
    }

    public void setNomProf(String nomProf) {
        this.nomProf = nomProf;
    }

    // create getter and setter
    public String getNommatiere() {
        return nommatiere;
    }

    public void setNommatiere(String nommatiere) {
        this.nommatiere = nommatiere;
    }

    // create getter and setter
    public String getPrenomProf() {
        return prenomProf;
    }

    public void setPrenomProf(String prenomProf) {
        this.prenomProf = prenomProf;
    }

    // creer fichier classe et ecrire dessus

    /**
     * @param prenom
     * @param nom
     * @param nommatiere
     * @param niveauEnseigner
     */
    private static void createFileProf(String prenom, String nom, String nommatiere, String niveauEnseigner) {
        File fichier = new File(
                "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\prof.txt");
                
        if (!fichier.exists()) {
            try {
                fichier.createNewFile();
            } catch (IOException e) {
                // TODO: handle exception
                e.printStackTrace();
            }
        } else {
            try {FileWriter ecriture = new FileWriter(fichier);
                
                BufferedWriter espaceEcriture = new BufferedWriter(ecriture);
                
                espaceEcriture.append("\n" + "prenom   :" + prenom + "  |||   nom :" + nom + "\n");
                
                espaceEcriture.newLine();
                espaceEcriture.append(".  Vous enseigner le/la  " + nommatiere + " au eleve due" + niveauEnseigner);
                espaceEcriture.flush();
                espaceEcriture.close();
            
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
