package Erreur;

import javax.swing.JOptionPane;

public class Erreur 
{
	public Erreur(String message)
	{
		JOptionPane.showMessageDialog(null, message, "Erreur", JOptionPane.ERROR_MESSAGE);
	}
}
