package Connexion;

import java.util.ArrayList;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class ViewConnexion extends JPanel
{	
	private static final long serialVersionUID = 1L;
	ArrayList<Connexion> connexions = new ArrayList<Connexion>();
	private String title[] = {"Nom","Adresse IP"};
	private JTable tableau;
	private Object[][] data = new Object[1000][2];
	
	public ViewConnexion()
	{
		this.add(new JScrollPane(tableau));	
	}
	
	public void refresh()
	{
		System.out.println("refresh");
		for(int i=0;i<this.connexions.size();i++)
		{
			Connexion c = (Connexion) connexions.get(i);
			if(c != null)
			{
				data[i][0] = c.getNom();
				data[i][1] = c.getAdresseIp();
			}
		}
		this.removeAll();
		this.tableau = new JTable(data, this.title);
		this.add(new JScrollPane(tableau));
	}
	
	public void addConnexion(Connexion c)
	{
		connexions.add(c);
		this.refresh();
	}
}
