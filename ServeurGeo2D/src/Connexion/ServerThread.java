package Connexion;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import Erreur.Erreur;

public class ServerThread extends Thread
{
	private int port;
	private ViewConnexion view;
	
	public ServerThread(int port, ViewConnexion view) 
	{
		this.port = port;
		this.view = view;
	}
	
	@SuppressWarnings("resource")
	public void run()
	{
		ServerSocket server = null;
		try 
		{
			server = new ServerSocket(port);
		} 
		catch (IOException e) {
			new Erreur("Problème avec la création de la socket serveur.");
		}
		ThreadGroup groupe = new ThreadGroup("socketsClients");
		//Lancement de la fonction infini
		System.out.println("Mise en ecoute...");
		while(true)
	    {
			System.out.println("En attente d'un client...");
		    Socket nouveauClientSocket;
		    Connexion nouveauClientThread = null;
		    try 
		    {
				nouveauClientSocket = server.accept();
				System.out.println("Connexion d'un client...");
			    try 
			    {
					nouveauClientThread = new Connexion(nouveauClientSocket, groupe);
				    nouveauClientThread.start();
				    view.addConnexion(nouveauClientThread);
				} 
			    catch (IOException e) 
			    {
			    	new Erreur("Problème de traitement d'un nouveau client (Problème processus).");
				} 
			} 
		    catch (IOException e) {
		    	new Erreur("Problème de traitement d'un nouveau client (Problème réseau).");
			}
	    }
	}
}
