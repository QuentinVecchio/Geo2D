/**
 * 
 */
package Objets;

/**
 * @author Dylan
 *
 */
public class Segment extends Simple{
	private Point p2;

	public void translation(Point p){
		super.translation(p);
		getP2().setX(getP2().getX() + p.getX());
		getP2().setY(getP2().getY() + p.getY());
	}
	
	public Segment(Point p1, Point p2, couleur c) {
		super(p1, c);
		this.p2 = p2;
	}

	public Point getP2() {
		return p2;
	}

	public void setP2(Point p2) {
		this.p2 = p2;
	}

	@Override
	public String toString() {
		return "Segment [p1=" + super.getP1() + ", p2=" + p2 + ", couleur =" + super.getC() + "] ";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Segment other = (Segment) obj;
		if (p2 == null) {
			if (other.p2 != null)
				return false;
		} else if (!p2.equals(other.p2))
			return false;
		return true;
	}
	
	
	
	
	
	

}
