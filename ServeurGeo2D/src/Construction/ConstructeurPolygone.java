package Construction;

import java.awt.Graphics;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class ConstructeurPolygone extends ConstructeurCOR
{

	ConstructeurPolygone(ConstructeurCOR constructeurSuivant) {
		super(constructeurSuivant);
		
	}

	public boolean resoudre1(Node s, Graphics g)
	{
		if(s.getNodeName().equalsIgnoreCase("polygone"))
		{
			NodeList list = s.getChildNodes();
			float x1 = 0,y1 = 0,x2 = 0, y2 = 0;
			String couleur;
			for (int i = 0; i<list.getLength(); i++) 
		    {
		    	if(list.item(i).getNodeName().equalsIgnoreCase("segment"))
		    	{
		    		NodeList segment = list.item(i).getChildNodes();
		    		for(int a = 0;a<segment.getLength();a++)
		    		{
		    			x1 = 0;
		    			y1 = 0;
		    			x2 = 0;
		    			y2 = 0;
		    			NodeList point = segment.item(a).getChildNodes();
		    			for(int b = 0;b<point.getLength();b++)
		    			{
		    				if(point.item(b).getNodeName().equalsIgnoreCase("X"))
					    	{
			    				if(x1 == 0)
			    					x1 = Float.parseFloat(point.item(b).getTextContent());
			    				else
			    					x2 = Float.parseFloat(point.item(b).getTextContent());
					    	}
					    	else if(point.item(b).getNodeName().equalsIgnoreCase("Y"))
					    	{
					    		if(y1 == 0)
					    			y1 = Float.parseFloat(point.item(b).getTextContent());
					    		else
					    			y2 = Float.parseFloat(point.item(b).getTextContent());
					    	}
		    			}
		    			g.drawLine((int)x1, (int)y1, (int)x2, (int)y2);
		    		}
		    	}
		    	else if(list.item(i).getNodeName().equalsIgnoreCase("couleur"))
		    	{
		    		couleur = list.item(i).getTextContent();
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
