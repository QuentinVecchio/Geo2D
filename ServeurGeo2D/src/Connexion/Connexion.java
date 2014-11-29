package Connexion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

import Construction.ControllerConstruction;
import Erreur.Erreur;

public class Connexion extends Thread
{
	private Socket socket;
	private BufferedReader fluxEntrant;	
	private PrintStream fluxSortant;
	
	public Connexion(Socket socket, ThreadGroup groupe) throws IOException
	{
		super(groupe,"ReceveurEnvoyeur");
		this.socket = socket;
		try 
		{
			fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
		} 
		catch (IOException e) {
			new Erreur("Erreur paramètrage du flux entrant.");
		}
		try 
		{
			fluxSortant = new PrintStream(this.socket.getOutputStream());
		} 
		catch (IOException e) 
		{
			new Erreur("Erreur paramètrage du flux sortant.");
		}
	}
	
	public void run()
	{	
		String data = "";
		String ligne;
		System.out.println("Client : " + this.getNom() + "/" + this.getAdresseIp() );
		System.out.println("Lecture de la socket cliente...");
		try
		{
			//Lecture de la socket et reception du xml
				while ((ligne = fluxEntrant.readLine()) != null)
				{
					data += ligne;
				}
				System.out.println("Recu : " + data);
			//Création du dessin
				ControllerConstruction constructeur = new ControllerConstruction(data);
			//Renvoie de l'image
			//Fermeture de la socket
				try 
				{
					this.socket.close();		
				} 
				catch (IOException e) 
				{
					new Erreur("Problème avec la fermeture de la socket cliente.");
				}
		}
		catch(IOException erreur) 
		{
			new Erreur("Problème avec la lecture sur la socket cliente.");
		}
	    
	}
	
	public String getNom()
	{
		return socket.getInetAddress().getHostName();
	}
	
	public String getAdresseIp()
	{
		return socket.getInetAddress().getHostAddress();
	}
}
