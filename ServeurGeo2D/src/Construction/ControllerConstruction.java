package Construction;

import java.io.StringReader;

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
			this.s = s.replace("\n", "").replace("\r", "").replace("\t", "").replace("\f", "");
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
	}
	
	public void appelConstructeurs()
	{
		constructionListeConstructeurs();
		//Création du doc xml
		Document document = convertStringToDocument(this.s);
		final Element racine = document.getDocumentElement();
		//Test pour savoir si le fichier est bon ou non
		if(racine.getNodeName().equalsIgnoreCase("dessins"))
		{
		    final NodeList racineNoeuds = racine.getChildNodes();
		    final int nbRacineNoeuds = racineNoeuds.getLength();
		    for (int i = 0; i<nbRacineNoeuds; i++) 
		    {
		    	if(racineNoeuds.item(i).getNodeType() == Node.ELEMENT_NODE) 
		    	{
		    	        final Node figure = racineNoeuds.item(i);
		    	        if(this.COR.resoudre(figure) == false)
		    	        	new Erreur("Erreur de construction, figure inconnu.");
		    	}
		    }
		}
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
