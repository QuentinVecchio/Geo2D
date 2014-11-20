package Configuration;

import java.net.InetAddress;
import javax.swing.JPanel;

public class ControllerConfiguration 
{
	private Configuration config = new Configuration();
	private ViewConfiguration view = new ViewConfiguration(config);
	
	public ControllerConfiguration()
	{
		
	}
	
	public JPanel getView()
	{
		return this.view;
	}
	
	public String getPort()
	{
		return this.config.getPort();
	}
	
	public InetAddress getAdresse()
	{
		return this.config.getAdresse();
	}
	
	
}
