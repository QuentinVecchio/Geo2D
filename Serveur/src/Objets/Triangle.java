/**
 * 
 */
package Objets;

/**
 * @author Dylan
 *
 */
public class Triangle extends Simple{
	private Point p2;
	private Point p3;
	
	public void translation(Point p){
		super.translation(p);
		getP2().setX(getP2().getX() + p.getX());
		getP2().setY(getP2().getY() + p.getY());
		getP3().setX(getP3().getX() + p.getX());
		getP3().setY(getP3().getY() + p.getY());
	}
	
	public Triangle(Point p1, couleur c, Point p2, Point p3) {
		super(p1, c);
		this.p2 = p2;
		this.p3 = p3;
	}
	
	public Point getP2() {
		return p2;
	}

	public void setP2(Point p2) {
		this.p2 = p2;
	}

	public Point getP3() {
		return p3;
	}

	public void setP3(Point p3) {
		this.p3 = p3;
	}

	@Override
	public String toString() {
		return "Triangle [p1= " + super.getP1() + ", p2=" + p2 + ", p3=" + p3 + ", couleur=" + super.getC() + "]";
	}
	
	
	
}
