package Construction;

import java.awt.Graphics;

import org.w3c.dom.Node;

public abstract class ConstructeurCOR extends Constructeur
{
	private Constructeur suivant;
	
	ConstructeurCOR(ConstructeurCOR  constructeurSuivant)
	{
		suivant = constructeurSuivant;
	}

	boolean resoudre(Node s, Graphics g) 
	{
		boolean b = this.resoudre1(s,g);
		if  (b ==  true) 
			return true;
		else if  (suivant != null)  	
			return this.suivant.resoudre(s,g);
		else    
			return false;
	}
	abstract public boolean resoudre1(Node s, Graphics g);
}
