package Construction;

import java.awt.Graphics;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class ConstructeurEllipse extends ConstructeurCOR
{

	ConstructeurEllipse(ConstructeurCOR constructeurSuivant) {
		super(constructeurSuivant);
		
	}

	public boolean resoudre1(Node s, Graphics g) 
	{
		if(s.getNodeName().equalsIgnoreCase("ellipse"))
		{
			NodeList list = s.getChildNodes();
			float x = 0,y = 0,rayon = 0, hauteur = 0;
			String couleur;
			for (int i = 0; i<list.getLength(); i++) 
		    {
		    	if(list.item(i).getNodeName().equalsIgnoreCase("rayon"))
		    	{
		    		rayon = Float.parseFloat(list.item(i).getTextContent());
		    	}
		    	else if(list.item(i).getNodeName().equalsIgnoreCase("hauteur"))
		    	{
		    		hauteur = Float.parseFloat(list.item(i).getTextContent());
		    	}
		    	else if(list.item(i).getNodeName().equalsIgnoreCase("point"))
		    	{
		    		NodeList point = list.item(i).getChildNodes();
		    		for(int a = 0;a<point.getLength();a++)
		    		{
		    			if(point.item(a).getNodeName().equalsIgnoreCase("X"))
				    	{
				    		x = Float.parseFloat(point.item(a).getTextContent());
				    	}
				    	else if(point.item(a).getNodeName().equalsIgnoreCase("Y"))
				    	{
				    		y = Float.parseFloat(point.item(a).getTextContent());
				    	}
		    		}
		    	}
		    	else if(list.item(i).getNodeName().equalsIgnoreCase("couleur"))
		    	{
		    		couleur = list.item(i).getTextContent();
		    	}
		    }
			//On dessine sur la fenetre
			g.drawOval((int)x, (int)y, (int)rayon*2, (int)hauteur*2);
			return true;
		}
		else
		{
			return false;
		}
	}
}
