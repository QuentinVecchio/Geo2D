package Objets;


/**
 * @author Dylan
 *
 */
public class Cercle extends Simple {
	private float rayon;

	public void translation(Point p){
		super.translation(p);
	}
	
	public Cercle(Point p1, couleur c, float r) {
		super(p1, c);
		this.rayon = r;
	}
	
	public float getRayon() {
		return rayon;
	}

	public void setRayon(float rayon) {
		this.rayon = rayon;
	}
	
	@Override
	public String toString() {
		return "Cercle [p1=" + super.getP1() + ", rayon=" + this.getRayon() + ", couleur =" + super.getC() + "] ";
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Cercle other = (Cercle) obj;
		if (Float.floatToIntBits(rayon) != Float.floatToIntBits(other.rayon))
			return false;
		return true;
	}

	
}
