package Construction;

import java.awt.Graphics;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import Erreur.Erreur;

public class ConstructeurGroupe extends ConstructeurCOR
{

	ConstructeurGroupe(ConstructeurCOR constructeurSuivant) {
		super(constructeurSuivant);
		
	}

	public boolean resoudre1(Node s, Graphics g) 
	{
		if(s.getNodeName().equalsIgnoreCase("groupe"))
		{
			ConstructeurCOR COR = new ConstructeurCercle(null);
			COR = new ConstructeurSegment(COR);
			COR = new ConstructeurTriangle(COR);
			COR = new ConstructeurPolygone(COR);
			COR = new ConstructeurGroupe(COR);
			NodeList racineNoeuds = s.getChildNodes();
		    int nbRacineNoeuds = racineNoeuds.getLength();
		    for (int i = 0; i<nbRacineNoeuds; i++) 
		    {
		    	if(racineNoeuds.item(i).getNodeType() == Node.ELEMENT_NODE) 
		    	{
		    	        final Node figure = racineNoeuds.item(i);
		    	        if(COR.resoudre(figure,g) == false)
		    	        	new Erreur("Erreur de construction, figure inconnu.");
		    	}
		    }
			return true;
		}
		else
		{
			return false;
		}
	}
}
