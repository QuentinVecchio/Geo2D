package Configuration;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;


public class ViewConfiguration extends JPanel
{

	private static final long serialVersionUID = 1L;
	private JButton btnSave = new JButton("Sauvegarder");
	private JPanel verticalPanel = new JPanel();
	private JPanel ipPanel = new JPanel();
	private JPanel portPanel = new JPanel();
	private Configuration config;
	private JTextField portText = new JTextField("Port");
	
	public ViewConfiguration(Configuration config)
	{
		this.config = config;
		this.setLayout(new BorderLayout());
		this.add(new JLabel("Configuration"), BorderLayout.NORTH);
		this.add(this.btnSave, BorderLayout.SOUTH);
		this.ipPanel.add(new JLabel("Adresse IP :"));
		this.ipPanel.add(new JLabel(config.getAdresseIp()));
		this.portPanel.add(new JLabel("Port :"));
		this.portText.setText(this.config.getPort());
		this.portPanel.add(this.portText);
		this.verticalPanel.setLayout(new GridLayout(2,1));
		this.verticalPanel.add(this.ipPanel);
		this.verticalPanel.add(this.portPanel);
		this.add(this.verticalPanel, BorderLayout.CENTER);
		this.btnSave.addActionListener(new btnSaveAction());
	}
	
	class btnSaveAction implements ActionListener
	{
	    public void actionPerformed(ActionEvent arg0) {
	    	config.setPort(portText.getText());
	    }
	}
}
