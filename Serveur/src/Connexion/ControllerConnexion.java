package Connexion;

import java.io.IOException;

import javax.swing.JPanel;

public class ControllerConnexion
{
	private ViewConnexion view = new ViewConnexion();
	private ServerThread server;
	
	public ControllerConnexion(int port) throws IOException 
	{
		System.out.println("Demarrage serveur");
		this.server = new ServerThread(port,view);
		this.server.start();
	}
	
	public JPanel getView()
	{
		return this.view;
	}
}
