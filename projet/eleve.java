import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class eleve {
    private String numeroEtudiant;
    private String prenomEleve;
    private String nomEleve;
    private String dateNaissanceEleve;
    public String classeEleve;

    
    // create getter and setter
    public String getNumeroEtudiant() {
        return numeroEtudiant;
    }

    public void setNumeroEtudiant(String numeroEtudiant) {
        this.numeroEtudiant = numeroEtudiant;
    }

    // create getter and setter
    public String getPrenomEleve() {
        return prenomEleve;
    }

    public void setPrenomEleve(String prenomEleve) {
        this.prenomEleve = prenomEleve;
    }

    // create getter and setter
    public String getNomEleve() {
        return nomEleve;
    }

    public void setNomEleve(String nomEleve) {
        this.nomEleve = nomEleve;
    }

    // create getter and setter
    public String getClasseEleve() {
        return classeEleve;
    }

    public void setClasseEleve(String classeEleve) {
        this.classeEleve = classeEleve;
    }
    
    // create getter and setter
    public String getDateNaissanceEleve() {
        return dateNaissanceEleve;
    }
    
    public void setDateNaissanceEleve(String dateNaissanceEleve) {
        this.dateNaissanceEleve = dateNaissanceEleve;
    }
    //fonction main
    
    /*public static void main(String[] args) {
        System.out.println("bonjour");
        eleve eleve = new eleve("N03020219876","arphan","bodian","18/10/2002","licene3lgsi");
        
    }*/
    // creer la liste des eleves
    private static void createFileEleve(String prenom, String nom) {
        File fichier = new File(
                "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\eleve.txt");

        if (!fichier.exists()) {

            try {
                fichier.createNewFile();
            } catch (IOException e) {
                // TODO: handle exception
                e.printStackTrace();
            }
        } else {
            try {
                FileWriter ecriture = new FileWriter(fichier);
                BufferedWriter espaceEcriture = new BufferedWriter(ecriture);
                espaceEcriture.write("\n");
                espaceEcriture.write("\n"+"prenom   :" + prenom + "  |||   nom :" + nom+"\n");
                espaceEcriture.write("\n");
                espaceEcriture.close();
                ecriture.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    
    //constructeur de la classe
    public eleve(String numeroEtudiant ,String prenomEleve, String nomEleve, String dateNaissanceEleve, String classeEleve) {
        System.out.println("bonjour c'est moi l'eleve repondant au nom "+prenomEleve +"  "+ nomEleve/* "nee le  "+dateNaissanceEleve+" en classe de   "+classeEleve */);
        createFileEleve(prenomEleve ,nomEleve);;
    }

}
