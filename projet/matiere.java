import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class matiere {
    private String nomMatiere;
    

    //constructeur de la classe
    public matiere(){
        createFileMatiere();
    }

    public String getNomMatiere() {
        return nomMatiere;
    }

    public void setNomMatiere(String nomMatiere) {
        this.nomMatiere = nomMatiere;
    }
     //creer fichier classe et ecrire dessus
    private static void createFileMatiere()
     {
        File fichier = new File(
                "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\matiere.txt");

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
                espaceEcriture.write("apprendre la matiere");
                espaceEcriture.close();
                ecriture.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
