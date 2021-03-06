package Construction;

import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.io.StringReader;

import javax.swing.JFrame;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

import Erreur.Erreur;

public class ControllerConstruction 
{
	private String s;
	private ConstructeurCOR COR;
	/*
	 * Prend en paramètre le string contenant tout le xml
	 */
	public ControllerConstruction(String s)
	{	
		int index = 0;
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i) == '<')
			{
				index = i;
				break;
			}
		}
		this.s = s.substring((index));
		this.s = this.s.trim().replace("\n", "").replace("\r", "").replace("\t", "").replace("\f", "").replace("\0", "");
		System.out.println(this.s);
		this.appelConstructeurs();
	}
	
	public void constructionListeConstructeurs()
	{
		/*
		 * Création de tous les constructeurs
		 */
		COR = new ConstructeurCercle(null);
		COR = new ConstructeurSegment(COR);
		COR = new ConstructeurTriangle(COR);
		COR = new ConstructeurPolygone(COR);
		COR = new ConstructeurCarre(COR);
		COR = new ConstructeurRectangle(COR);
		COR = new ConstructeurEllipse(COR);
		COR = new ConstructeurGroupe(COR);
	}
	
	public void appelConstructeurs()
	{
		//Création de la fenetre
		JFrame fenetre; 
		fenetre = new JFrame("Dessin");    
		fenetre.setBounds(30, 60, 800, 1200);              
		fenetre.setVisible(true);
		fenetre.setIgnoreRepaint(true);
		fenetre.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); 
		int numBuffers = 1;
		fenetre.createBufferStrategy(numBuffers);  
		try 
		{
			Thread.sleep(150);
		} 
		catch (InterruptedException e) 
		{
			new Erreur("Erreur Thread dessiner.");
		}  
		BufferStrategy strategie = fenetre.getBufferStrategy();
		Graphics graphics = strategie.getDrawGraphics();        
		constructionListeConstructeurs();
		//Création du doc xml
		Document document = convertStringToDocument(this.s);
		final Element racine = document.getDocumentElement();
		//Test pour savoir si le fichier est bon ou non
		if(racine.getNodeName().equalsIgnoreCase("dessin"))
		{
		    final NodeList racineNoeuds = racine.getChildNodes();
		    final int nbRacineNoeuds = racineNoeuds.getLength();
		    //Récupération de la couleur 
		    final Node couleur = racineNoeuds.item(0);
		    if(couleur.getNodeName().equalsIgnoreCase("couleur"))
		    {
		    	Couleur c = new Couleur(couleur.getTextContent());
		    	graphics.setColor(new Color(c.getR(),c.getG(),c.getB()));
		    }
		    //Récuperation de toutes les figures
		    for (int i = 1; i<nbRacineNoeuds; i++) 
		    {
		    	if(racineNoeuds.item(i).getNodeType() == Node.ELEMENT_NODE) 
		    	{
		    	        final Node figure = racineNoeuds.item(i);
		    	        if(this.COR.resoudre(figure,graphics) == false)
		    	        	new Erreur("Erreur de construction, figure inconnu.");
		    	}
		    }
		}
		strategie.show();
	    graphics.dispose();
	}
	
	private Document convertStringToDocument(String xmlStr) 
	{
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();  
        DocumentBuilder builder;  
        try 
        {  
            builder = factory.newDocumentBuilder();  
            Document doc = builder.parse( new InputSource( new StringReader( xmlStr ) ) ); 
            return doc;
        } catch (Exception e) {  
            e.printStackTrace();  
        } 
        return null;
    }
}
