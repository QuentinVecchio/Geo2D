package Serveur;

import java.io.IOException;

public class main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		ControllerServeur serveur = new ControllerServeur();
		serveur.initialisationView();
	}

}
