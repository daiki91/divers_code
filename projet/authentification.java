import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.io.FileWriter;
import javax.swing.*;

public class authentification {
    /**
     * @param args
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        /*
        creation des fichiers
             createFileEcole();
             createFileEleve();
            createFileProf();
            createFileMatiere();
            createFileClasse();
         
         */
       
       int a = 0;
       String nom, prenom, dateNaissance, code, mdp, phoneNumber;
       System.out.println("entrer votre nom :");
       nom = sc.nextLine();
       
       System.out.println("entrer votre prenom :");
       prenom = sc.nextLine();
       
       System.out.println("entrer votre date de naissance :");
       dateNaissance = sc.nextLine();
       
       // for (int a = 0; a <= 2; a++) {
           
           System.out.println("entrer votre numero de telephone :");
           phoneNumber = sc.nextLine();
           
           int compteur = Integer.parseInt(phoneNumber) / 10000000;

        switch (compteur) {
            case 70:
                System.out.println("l'operateur est expresso ");
                a = 5;
                break;
            case 75:
                System.out.println("l'operateur est primo ");
                a = 5;
                break;
                case 76:
                System.out.println("l'operateur est tigo/free ");
                a = 5;
                break;
                case 77:
                System.out.println("l'operateur est orange ");
                a = 5;
                break;
                case 78:
                System.out.println("l'operateur est orange ");
                a = 5;
                break;
                default:
                System.out.println("le format n'était pas approprié.");
                
            }
            // }
            
            // char code = inputLine.charAt(0);
            for (int i = 0; i <= 4; i++) {
                System.out.println("entrer votre mot de passe :");
            code = sc.nextLine();
            System.out.println("repeter le mot de passe :");
            mdp = sc.nextLine();
            // sc.close();
            if (code.equals(mdp)) {
                System.out.println("vous pouvez acceder au system");
                System.out.println(" Bienvenue Mr " + prenom + " " + nom);
                // Appel de la fonction pour afficher les informations
                affichagePersonne(prenom, nom, dateNaissance, phoneNumber, code);
                i = 5;
            } else {
                System.out.println("le mot de passe est incorrecte");
            }

        }
        sc.close();
       // createFileEleve(prenom ,nom);

    }

    // methode affichage formulaire
    private static void affichagePersonne(String prenom, String nom, String dateNaissance, String phoneNumber,
            String mdp) {

        System.out.println(" ____________________________________________________________________________");
        System.out.println(" ____________________________________________________________________________");
        System.out.println("|                                                                           |");
        System.out.println("      PROPRIETAIRE DE L'APPAREIL         :   " + prenom + " " + nom);
        System.out.println("|                                                                           |");
        System.out.println(" ____________________________________________________________________________");
        System.out.println(" ____________________________________________________________________________");
        System.out.println("|                                                                           |");
        System.out.println("      DATE DE NAISSANCE DU PROPRIETAIRE  :   " + dateNaissance);
        System.out.println("|                                                                           |");
        System.out.println(" ____________________________________________________________________________");
        System.out.println(" ____________________________________________________________________________");
        System.out.println("|                                                                           |");
        System.out.println("      LE NUMERO DE TELEPHONE             :   " + phoneNumber);
        System.out.println("|                                                                           |");
        System.out.println(" ____________________________________________________________________________");
        System.out.println(" ____________________________________________________________________________");
        System.out.println("|                                                                           |");
        System.out.println("      LE mdp est                         :   " + mdp);
        System.out.println("|                                                                           |");
        System.out.println(" ____________________________________________________________________________");
        System.out.println(" ____________________________________________________________________________");
    }
/*
 
// methode creation liste ecole
private static void createFileEcole() {
    File fichier = new File(
            "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\ecole.txt");

    if (!fichier.exists()) {

        try {
            fichier.createNewFile();
        } catch (IOException e) {
            
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
// creer la liste des eleves
private static void createFileEleve(String prenom, String nom) {
    File fichier = new File(
            "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\eleve.txt");

    if (!fichier.exists()) {

        try {
            fichier.createNewFile();
        } catch (IOException e) {
            
            e.printStackTrace();
        }
    } else {
        try {
            FileWriter ecriture = new FileWriter(fichier);
            BufferedWriter espaceEcriture = new BufferedWriter(ecriture);
            espaceEcriture.write("\n");
            espaceEcriture.write("\n"+"prenom   :" + prenom + "nom :" + nom+"\n");
            espaceEcriture.write("\n");
            espaceEcriture.close();
            ecriture.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
//creer fichier classe et ecrire dessus
private static void createFileProf()
 {
    File fichier = new File(
            "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\prof.txt");

    if (!fichier.exists()) {
        try {
            fichier.createNewFile();
        } catch (IOException e) {
            
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
//creer fichier classe et ecrire dessus
private static void createFileMatiere()
 {
    File fichier = new File(
            "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\matiere.txt");

    if (!fichier.exists()) {
        try {
            fichier.createNewFile();
        } catch (IOException e) {
            
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
//creer fichier classe et ecrire dessus
private static void createFileClasse()
{
    File fichier = new File(
            "C:\\Users\\arphan\\OneDrive\\Bureau\\etude\\l3_LGSI\\sem5\\POO\\diop\\projet\\classe.txt");

    if (!fichier.exists()) {
        try {
            fichier.createNewFile();
        } catch (IOException e) {
            
            e.printStackTrace();
        }
    } else {
        try {
            FileWriter ecriture = new FileWriter(fichier);
            BufferedWriter espaceEcriture = new BufferedWriter(ecriture);
            espaceEcriture.write("aller etudier en classe");
            espaceEcriture.close();
            ecriture.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
 */
}