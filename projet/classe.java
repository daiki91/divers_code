import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class classe extends acceuil{
    private String nomClasse;
    private int nombrePlace;
    private String sonEcole;

    public classe(String nomClasse, int nombrePlace, String sonEcole) {
        System.out.println("la classe " + nomClasse + " est cree dans l'ecole : " + sonEcole);
        createFileClasse(nomClasse, sonEcole, nombrePlace);

    }

    public int getNombrePlace() {
        return nombrePlace;
    }

    public void setNombrePlace(int nombrePlace) {
        this.nombrePlace = nombrePlace;
    }

    public String getNomClasse() {
        return nomClasse;
    }

    public void setNomClasse(String nomClasse) {
        this.nomClasse = nomClasse;
    }

    public String getSonEcole() {
        return sonEcole;
    }

    public void setSonEcole(String sonEcole) {
        this.sonEcole = sonEcole;
    }

    // creer fichier classe et ecrire dessus
    private static void createFileClasse(String nomClasse, String sonEcole, int nombrePlace) {
        File fichier = new File(
                "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\classe.txt");

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
                espaceEcriture.write("nom de la classe " + nomClasse);
                espaceEcriture.write("  |||    nom de la classe " + nombrePlace);
                espaceEcriture.write("  |||    nom de l'ecole' " + sonEcole);
                espaceEcriture.close();
                ecriture.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
