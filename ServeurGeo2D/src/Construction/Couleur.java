package Construction;

public class Couleur {
	private int r;
	private int g;
	private int b;
	
	Couleur(String s)
	{
		if(s.equalsIgnoreCase("BLUE"))
		{
			this.setR(0);
			this.setG(0);
			this.setB(255);
		}
		else if(s.equalsIgnoreCase("RED"))
		{
			this.setR(255);
			this.setG(0);
			this.setB(0);
		}
		else if(s.equalsIgnoreCase("GREEN"))
		{
			this.setR(0);
			this.setG(255);
			this.setB(0);
		}
		else if(s.equalsIgnoreCase("YELLOW"))
		{
			this.setR(255);
			this.setG(255);
			this.setB(0);
		}
		else if(s.equalsIgnoreCase("CYAN"))
		{
			this.setR(0);
			this.setG(255);
			this.setB(255);
		}
		else
		{
			this.setR(0);
			this.setG(0);
			this.setB(0);
		}
	}
	
	public int getR()
	{
		return r;
	}
	
	public int getG()
	{
		return g;
	}
	
	public int getB()
	{
		return b;
	}
	
	public void setR(int red)
	{
		if(red >= 0 && red <= 255)
			r = red;
	}
	
	public void setG(int green)
	{
		if(green >= 0 && green <= 255)
			g = green;
	}
	
	public void setB(int blue)
	{
		if(blue >= 0 && blue <= 255)
			b = blue;
	}
	
}
