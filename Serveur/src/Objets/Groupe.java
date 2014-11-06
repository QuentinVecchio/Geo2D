package Objets;

import java.util.ArrayList;

/**
 * @author Dylan
 *
 */
public class Groupe extends Figure{
	private ArrayList<Figure> groupe = new ArrayList();

	public Groupe(Point p1, couleur c, ArrayList<Figure> groupe) {
		super(p1, c);
		this.groupe = groupe;
	}
	
	public void translation(Point p){
		for(int i = 0; i < groupe.size(); i++){
			groupe.get(i).translation(p);
		}
	}
	
	@Override
	public String toString() {
		String res ="";
		res += "Groupe[ ";
		for(int i = 0; i < groupe.size(); i++){
			res += "\n Figure n� " + (i+1) + " = " + groupe.get(i).toString() + ", ";
		}
		res += "\n ]";
		return res;
	}

	
	
	
	
}
