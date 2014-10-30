package Serveur;

import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JTabbedPane;

import Configuration.ControllerConfiguration;
import Connexion.ControllerConnexion;

public class ControllerServeur {
	private ControllerConfiguration config = new ControllerConfiguration();
	private ControllerConnexion connexions;
	private JTabbedPane onglets = new JTabbedPane();

	public ControllerServeur()
	{
		
	}
	
	public void initialisationView() throws NumberFormatException, IOException
	{
		JFrame fenetre = new JFrame();
		fenetre.setTitle("ServeurGeo2D");
		fenetre.setLocationRelativeTo(null);
		fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		fenetre.setSize(400, 400);
		fenetre.add(this.onglets);
		this.connexions = new ControllerConnexion(Integer.parseInt(this.config.getPort()));
		this.onglets.add("Connexions",this.connexions.getView());
		this.onglets.add("Configuration",this.config.getView());
		fenetre.setVisible(true);
	}

}
