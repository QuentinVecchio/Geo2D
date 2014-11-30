package Construction;

public abstract class ConstructeurCOR extends Constructeur
{
	private Constructeur suivant;
	
	ConstructeurCOR(ConstructeurCOR  constructeurSuivant)
	{
		suivant = constructeurSuivant;
	}

	boolean resoudre(String s) 
	{
		boolean b = this.resoudre1(s);
		if  (b ==  true) 
			return true;
		else if  (suivant != null)  	
			return this.suivant.resoudre(s);
		else    
			return false;
	}

	abstract public boolean resoudre1(String s);
}
