import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.chrono.JapaneseDate;
import java.awt.*;

public class acceuil {
    /**
     * @param args
     */
    public static void main(String[] args) {
        // creation d'une fenetre de lecture graphique
        JFrame fen = new JFrame("coordi");
        fen.setSize(500, 400);
        fen.setResizable(false);

        // System.out.println("bienvenue sur karang");
        JPanel pan = new JPanel();
        fen.setContentPane(pan);
        // ajout de label
        JLabel bienvenue = new JLabel("bienvenue sur karang");
        fen.getContentPane().add(bienvenue);
        // pour aller a la ligne
        fen.setLayout(new FlowLayout(FlowLayout.CENTER));

        JLabel label1 = new JLabel("      Qui etes-vous? ");
        fen.getContentPane().add(label1);

        // pour aller a la ligne
        fen.setLayout(new FlowLayout(FlowLayout.CENTER));

        JLabel nomlabel = new JLabel("\n" + "nom  =  ");
        fen.getContentPane().add(nomlabel);
        JTextField saisieNom = new JTextField(20);
        fen.getContentPane().add(saisieNom);
        // String vnom = saisieNom.getText();
        JLabel prenomlabel = new JLabel("\n" + "prenom  =  ");
        fen.getContentPane().add(prenomlabel);
        JTextField saisiePrenom = new JTextField(20);
        fen.getContentPane().add(saisiePrenom);
        // String vprenom = saisiePrenom.getText();
        // creation de bouton
        JLabel label2 = new JLabel(" Que representez-vous?  /n");
        fen.getContentPane().add(label2);
        JButton ecoleList = new JButton(" Ecole");
        fen.getContentPane().add(ecoleList);
        ecoleList.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // s'execute quand l'on clique sur le bouton eleve
                fen.dispose();
                JFrame fen_ecole = new JFrame("coordi_ecole");
                fen_ecole.setSize(500, 400);
                JPanel pan = new JPanel();
                fen_ecole.setVisible(true);
                fen_ecole.setContentPane(pan);
                JLabel label6 = new JLabel("le bouton eleve a ete clique");
                fen_ecole.getContentPane().add(label6);
                ImageIcon image = new ImageIcon("fon.jpg");
                fen_ecole.setIconImage(image.getImage());
                System.out.println(" le code bouton eleve a ete executer");
                fen_ecole.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                fen_ecole.setResizable(false);

            }
        });
       

        JButton eleveList = new JButton(" Eleve");
        fen.getContentPane().add(eleveList);
        eleveList.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // s'execute quand l'on clique sur le bouton eleve
                fen.dispose();
                String vprenomEleve = saisiePrenom.getText();
                String vnomEleve = saisieNom.getText();
                System.out.println("bonjour mr" + vprenomEleve + " " + vnomEleve);
                JFrame fen_eleve = new JFrame("coordi_eleve");
                fen_eleve.setSize(500, 400);
                JPanel pan = new JPanel();
                fen_eleve.setVisible(true);
                fen_eleve.setContentPane(pan);
                JLabel label6 = new JLabel("le bouton eleve a ete clique");
                fen_eleve.getContentPane().add(label6);
                // date de naissance
                JLabel dateNais = new JLabel("\n" + "date de naissance                                   =  ");
                fen_eleve.getContentPane().add(dateNais);
                JTextField saisieDate = new JTextField(20);
                fen_eleve.getContentPane().add(saisieDate);
                // essaie creation objet eleve = ok
                eleve eleve = new eleve("771364968", vprenomEleve, vnomEleve, "18/10/2002", "licence");

                JLabel label4 = new JLabel(
                        "bonjour c'est moi l'eleve repondant au nom " + vprenomEleve + "  "
                                + vnomEleve
                                + "  nee le  " + eleve.getDateNaissanceEleve() + " en classe de  \n "
                                + eleve.getClasseEleve());
                fen_eleve.getContentPane().add(label4);
                ImageIcon image = new ImageIcon("fon.jpg");
                fen_eleve.setIconImage(image.getImage());

                /// bouton retour
                JButton retour_accueil = new JButton(" retour  ");
                fen_eleve.getContentPane().add(retour_accueil);
                /*
                 * 
                 * public void actionPerformed(ActionEvent e)
                 * {
                 * // s'execute quand l'on clique sur le bouton eleve
                 * fen_eleve.dispose();
                 * }
                 */

                System.out.println(" le code bouton eleve a ete executer");
                fen_eleve.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                fen_eleve.setResizable(false);

            }
        });

        JButton profList = new JButton(" prof");
        fen.getContentPane().add(profList);
        profList.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // s'execute quand l'on clique sur le bouton prof
                fen.dispose();
                String vprenomProf = saisiePrenom.getText();
                String vnomProf = saisieNom.getText();
                JFrame fen_prof = new JFrame("coordi_prof");
                fen_prof.setSize(500, 400);
                JPanel pan = new JPanel();
                fen_prof.setVisible(true);
                fen_prof.setContentPane(pan);
                JLabel label7 = new JLabel("le bouton prof a ete clique");
                ImageIcon image = new ImageIcon("prof.jfif");
                label7.setIcon(image);
                label7.setText("mr  " + vprenomProf + " " + vnomProf + " " + " comment vivez vous");
                // couleur du texte
                label7.setForeground(new Color(0x00ff00));
                label7.setVerticalTextPosition(JLabel.CENTER);
                fen_prof.getContentPane().add(label7);
                fen_prof.getContentPane().setBackground(Color.darkGray);
                ImageIcon imagee = new ImageIcon("fon.jpg");
                fen_prof.setIconImage(imagee.getImage());

                // essaie creation objet prof = ok
                prof profA = new prof(vprenomProf, vnomProf, "system d'exploitation", "universitaire");
                System.out.println(" le code bouton prof a ete executer");
                fen_prof.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            }
        });
        JButton matiereList = new JButton("Matiere");
        fen.getContentPane().add(matiereList);
        matiereList.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // s'execute quand l'on clique sur le bouton prof
                fen.dispose();
                JFrame fen_matiere = new JFrame("coordi_matiere");
                fen_matiere.setSize(500, 400);
                JPanel pan = new JPanel();
                fen_matiere.setVisible(true);
                fen_matiere.setContentPane(pan);
                JLabel label7 = new JLabel("le bouton matiere a ete clique");
                fen_matiere.getContentPane().add(label7);
                ImageIcon image = new ImageIcon("fon.jpg");
                fen_matiere.setIconImage(image.getImage());

                System.out.println(" le code bouton matiere a ete executer");
                fen_matiere.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                fen_matiere.setResizable(false);

            }
        });

        JButton classeList = new JButton("classe");
        fen.getContentPane().add(classeList);
        classeList.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // s'execute quand l'on clique sur le bouton classe
                fen.dispose();
                JFrame fen_classe = new JFrame("coordi_classe");
                fen_classe.setSize(500, 400);
                JPanel pan = new JPanel();
                fen_classe.setVisible(true);
                fen_classe.setContentPane(pan);
                JLabel label7 = new JLabel("le bouton classe a ete clique");
                fen_classe.getContentPane().add(label7);
                // essaie creation objet classe = ok
                classe classeA = new classe("licaenceglsiB", 52, "ESP");

                JLabel labe5 = new JLabel(
                        "la classe " + classeA.getNomClasse() + " est cree dans l'ecole : " + classeA.getSonEcole());
                fen_classe.getContentPane().add(labe5);
                fen_classe.setResizable(false);
                System.out.println(" le code bouton classe a ete executer");
                fen_classe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            }
        });

        ImageIcon image = new ImageIcon("fon.jpg");
        fen.setIconImage(image.getImage());
        fen.getContentPane().setBackground(Color.lightGray);
        fen.setVisible(true);
        fen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

}
