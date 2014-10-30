package Configuration;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import Erreur.Erreur;


public class Configuration 
{
	private String adresseIP;
	private String port;
	private InetAddress LocaleAdresse ;
	private FileOutputStream fos;
	private FileInputStream fis;
	
	public Configuration()
	{
		try 
		{
			LocaleAdresse = InetAddress.getLocalHost();
			adresseIP = LocaleAdresse.getHostAddress();
		} 
		catch (UnknownHostException e) {
			new Erreur("Problème avec la socket locale.");
		}

		try
		{
			this.port = "";
			fis = new FileInputStream(new File("port.txt"));
			byte[] buf = new byte[8];
	        while ((fis.read(buf)) >= 0) 
	        {
	           for (byte bit : buf) 
	           {
	              this.port += (char) bit;
	           }
	        }
	        this.port = this.port.trim();
	        System.out.println(this.port);
	        if((Integer.parseInt(port)<=65535 &&  Integer.parseInt(port)>=1) == false)
	        	port = "2107";
		}
		catch(IOException e)
		{
			port = "2107";
		}

   
        
	}

	public String getAdresseIp()
	{
		return this.adresseIP;
	}
	
	public InetAddress getAdresse()
	{
		return this.LocaleAdresse;
	}
	
	public String getPort()
	{
		return this.port;
	}
	
	public void setPort(String port)
	{
		if(Integer.parseInt(port)<=65535 &&  Integer.parseInt(port)>=1)
		{
			try
			{
				fos = new FileOutputStream(new File("port.txt"));
				fos.write(this.port.getBytes());
			}
			catch(IOException e)
			{
				new Erreur("Erreur d'écriture avec le fichier de sauvegarde du port.");
			}		
		}
	}
}
