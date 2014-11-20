package Construction;

import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class ConstructeurSegment extends ConstructeurCOR
{

	ConstructeurSegment(ConstructeurCOR constructeurSuivant) {
		super(constructeurSuivant);
		
	}

	public boolean resoudre1(Node s) 
	{
		if(s.getNodeName().equalsIgnoreCase("segment"))
		{
			NodeList list = s.getChildNodes();
			float x1 = 0,y1 = 0,x2 = 0, y2 = 0;
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
		    				else
		    					x2 = Float.parseFloat(point.item(a).getTextContent());
				    	}
				    	else if(point.item(a).getNodeName().equalsIgnoreCase("Y"))
				    	{
				    		if(y1 == 0)
				    			y1 = Float.parseFloat(point.item(a).getTextContent());
				    		else
				    			y2 = Float.parseFloat(point.item(a).getTextContent());
				    	}
		    		}
		    	}
		    	else if(list.item(i).getNodeName().equalsIgnoreCase("couleur"))
		    	{
		    		couleur = list.item(i).getTextContent();
		    	}
		    }
			//On dessine sur la fenetre
			
			return true;
		}
		else
		{
			return false;
		}
	}
}
