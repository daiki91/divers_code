import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class ecole {
    private String nomEcole;
    private String lieuEcole;
    private int nombreClasse;
    private int nombreProf;

    //constructeur de la classe
    public ecole(String nomEcole,String lieuEcole,int nombreClasse,int nombreProf){
        createFileEcole();
    }

    public int getNombreProf() {
        return nombreProf;
    }
    public void setNombreProf(int nombreProf) {
        this.nombreProf = nombreProf;
    }
    public int getNombreClasse() {
        return nombreClasse;
    }
    public void setNombreClasse(int nombreClasse) {
        this.nombreClasse = nombreClasse;
    }
    public String getNomEcole() {
        return nomEcole;
    }
    public void setNomEcole(String nomEcole) {
        this.nomEcole = nomEcole;
    }
    public String getLieuEcole() {
        return lieuEcole;
    }
    public void setLieuEcole(String lieuEcole) {
        this.lieuEcole = lieuEcole;
    }
     // methode creation liste ecole
    private static void createFileEcole() {
        File fichier = new File(
                "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\ecole.txt");

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
                espaceEcriture.write("aller etudier a l'ecole");
                espaceEcriture.close();
                ecriture.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
