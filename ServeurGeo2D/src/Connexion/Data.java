package Connexion;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.DocumentBuilder;

import java.io.File;
import java.io.IOException;
import org.w3c.dom.Element;
import org.w3c.dom.Document;
import org.xml.sax.SAXException;
import org.w3c.dom.NodeList;

public class Data 
{
	private String s;
	
	public Data(String s)
	{
		final DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		try 
		{
		    final DocumentBuilder builder = factory.newDocumentBuilder();
		    final Document document= builder.parse(new File("repertoire.xml"));
		    final Element racine = document.getDocumentElement();
		    if(racine.getNodeName().equalsIgnoreCase("groupe"))
		    {
		    	final NodeList racineNoeuds = racine.getChildNodes();
		    	final int nbRacineNoeuds = racineNoeuds.getLength();
				
		    	for (int i = 0; i<nbRacineNoeuds; i++) {
		    	    System.out.println(racineNoeuds.item(i).getNodeName());
		    	}
		    }
		}
		catch (final ParserConfigurationException e) {
		    e.printStackTrace();
		}
		catch (final SAXException e) {
		    e.printStackTrace();
		}
		catch (final IOException e) {
		    e.printStackTrace();
		}
	}
}
