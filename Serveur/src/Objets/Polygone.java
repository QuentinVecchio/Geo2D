package Objets;

import java.util.ArrayList;

/**
 * @author Dylan
 *
 */
public class Polygone extends Segment {
	private ArrayList<Segment> segments = new ArrayList();
	
	public void translation(Point p){
		for(int i = 0; i < segments.size(); i++){
			segments.get(i).translation(p);
		}
	}
	
	public Polygone(Point p1, Point p2, couleur c, ArrayList<Segment> segments) {
		super(p1, p2, c);
		this.segments = segments;
	}

	public ArrayList<Segment> getSegments() {
		return segments;
	}

	public void setSegments(ArrayList<Segment> segments) {
		this.segments = segments;
	}	
	
	@Override
	public String toString() {
		String res ="";
		res += "Polygone[ ";
		for(int i = 0; i < segments.size(); i++){
			res += "\n Segment n� " + (i+1) + " = " + segments.get(i).toString() + ", ";
		}
		res += "\n ]";
		return res;
	}
	
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result
				+ ((segments == null) ? 0 : segments.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Polygone other = (Polygone) obj;
		if (segments == null) {
			if (other.segments != null)
				return false;
		} else if (!segments.equals(other.segments))
			return false;
		return true;
	}
	
	
}
