package Objets;

/**
 * @author Dylan
 *
 */
public class Figure {
	public enum couleur{black, blue, red, green, yellow, cyan;};
	private Point p1;
	private couleur c;
	
	public void translation(Point p){
		p1.setX(p1.getX() + p.getX());
		p1.setY(p1.getY() + p.getY());
	}
	
	public void homothetie(){}
	public void rotation(){}
	
	public Figure(Point p1, couleur c) {
		super();
		this.p1 = p1;
		this.c = c;
	}
	
	public Point getP1() {
		return p1;
	}

	public void setP1(Point p1) {
		this.p1 = p1;
	}
	public couleur getC() {
		return c;
	}
	public void setC(couleur c) {
		this.c = c;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Figure other = (Figure) obj;
		if (c != other.c)
			return false;
		if (p1 == null) {
			if (other.p1 != null)
				return false;
		} else if (!p1.equals(other.p1))
			return false;
		return true;
	}
	
	@Override
	public String toString() {
		return "Figure [p1=" + p1 + ", c=" + c + "]";
	}
	
}
