package Construction;

import java.awt.Graphics;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class ConstructeurRectangle extends ConstructeurCOR
{

	ConstructeurRectangle(ConstructeurCOR constructeurSuivant) {
		super(constructeurSuivant);
		
	}

	public boolean resoudre1(Node s, Graphics g)
	{
		if(s.getNodeName().equalsIgnoreCase("rectangle"))
		{
			NodeList list = s.getChildNodes();
			float x1 = 0,y1 = 0,x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
			String couleur;
			for (int i = 0; i<list.getLength(); i++) 
		    {
		    	if(list.item(i).getNodeName().equalsIgnoreCase("point"))
		    	{
		    		NodeList point = list.item(i).getChildNodes();
		    		for(int a = 0;a<point.getLength();a++)
		    		{
		    			if(point.item(a).getNodeName().equalsIgnoreCase("X"))
				    	{
		    				if(x1 == 0)
		    					x1 = Float.parseFloat(point.item(a).getTextContent());
		    				else if( x2 == 0 && x1 != 0)
		    					x2 = Float.parseFloat(point.item(a).getTextContent());
		    				else if( x3 == 0 && x1 != 0 && x2 != 0)
		    					x3 = Float.parseFloat(point.item(a).getTextContent());
		    				else
		    					x4 = Float.parseFloat(point.item(a).getTextContent());
				    	}
				    	else if(point.item(a).getNodeName().equalsIgnoreCase("Y"))
				    	{
				    		if(y1 == 0)
				    			y1 = Float.parseFloat(point.item(a).getTextContent());
				    		else if( y2 == 0 && y1 != 0)
				    			y2 = Float.parseFloat(point.item(a).getTextContent());
				    		else if( y3 == 0 && y1 != 0 && y2 != 0)
				    			y3 = Float.parseFloat(point.item(a).getTextContent());
				    		else
				    			y4 = Float.parseFloat(point.item(a).getTextContent());
				    	}
		    		}
		    	}
		    	else if(list.item(i).getNodeName().equalsIgnoreCase("couleur"))
		    	{
		    		couleur = list.item(i).getTextContent();
		    	}
		    }
			//On dessine sur la fenetre
			g.drawLine((int)x1, (int)y1, (int)x2, (int)y2);
			g.drawLine((int)x1, (int)y1, (int)x3, (int)y3);
			g.drawLine((int)x4, (int)y4, (int)x2, (int)y2);
			g.drawLine((int)x3, (int)y3, (int)x4, (int)y4);
			return true;
		}
		else
		{
			return false;
		}
	}
}

