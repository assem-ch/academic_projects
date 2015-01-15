package pack;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Dimension;
import java.awt.ComponentOrientation;
import java.awt.Color;
import java.awt.Toolkit;

import javax.swing.JSplitPane;
import javax.swing.JButton;
import java.awt.event.KeyEvent;

import javax.swing.JTextArea;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JFileChooser;
import javax.swing.JDialog;



import java.awt.Rectangle;




import java.awt.GridLayout;

import java.io.ByteArrayInputStream;

import java.io.File;
import java.io.FileWriter;



import java.io.FileReader;
import java.io.IOException;

import javax.swing.JScrollPane;
import javax.swing.JTextPane;





public class myinterface 
{

	myinterface() {
		   jFrame=getJFrame();
				jFrame.show();
		
	}
	
	private JFrame jFrame = null;  //  @jve:decl-index=0:visual-constraint="24,-15"
	private JSplitPane jSplitPane = null;
	private JButton KBtn_load = null;
	private JPanel KPan1 = null;
	private JPanel KPan2 = null;
	private JTextArea KTArea = null;
	private JButton KBtn_check1 = null;
	private JButton KBtn_check2 = null;
	private JButton KBtn_compile = null;
	private JSplitPane jSplitPane1 = null;

	private JMenuBar KMBar = null;
	private JMenu Kmenu1 = null;
	private JMenu KMenu2 = null;
	private JMenu KMenu3 = null;
	private JMenuItem KMIabout = null;
	private JFileChooser KFchooser = null;
	private JDialog KDialog = null;  //  @jve:decl-index=0:visual-constraint="1214,35"
	private JScrollPane KScrollPane2 = null;
	private JTextPane KTArea2 = null;
	/**
	 * This method initializes jFrame	
	 * 	
	 * @return javax.swing.JFrame	
	 */
	private JFrame getJFrame() {
		if (jFrame == null) {
			jFrame = new JFrame();
			jFrame.setSize(new Dimension(1131, 664));
			jFrame.setComponentOrientation(ComponentOrientation.LEFT_TO_RIGHT);
			jFrame.setForeground(Color.black);
			jFrame.setIconImage(Toolkit.getDefaultToolkit().getImage("F:/books/Linux2Windoz roadmap/Adding Fonts to Command Line (cmd.exe) - Network Administration & Consulting Services_files/reddit.png"));
			jFrame.setResizable(false);
			jFrame.setTitle("mYparser");
			jFrame.setContentPane(getJSplitPane());
			jFrame.setJMenuBar(getKMBar());
			jFrame.setVisible(true);
		}
		return jFrame;
	}
	/**
	 * This method initializes jSplitPane	
	 * 	
	 * @return javax.swing.JSplitPane	
	 */
	private JSplitPane getJSplitPane() {
		if (jSplitPane == null) {
			jSplitPane = new JSplitPane();
			jSplitPane.setDividerSize(5);
			jSplitPane.setDividerLocation(125);
			jSplitPane.setRightComponent(getKPan2());
			jSplitPane.setLeftComponent(getKPan1());
		}
		return jSplitPane;
	}
	/**
	 * This method initializes KBtn_load	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getKBtn_load() {
		if (KBtn_load == null) {
			KBtn_load = new JButton();
			KBtn_load.setMnemonic(KeyEvent.VK_UNDEFINED);
			KBtn_load.setText("      load file      ");
			KBtn_load.setPreferredSize(new Dimension(130, 30));
			KBtn_load.setBounds(new Rectangle(0, 168, 114, 26));
			KBtn_load.setSelected(true);
			KBtn_load.addMouseListener(new java.awt.event.MouseAdapter() {   
			
				/* (non-Javadoc)
				 * @see java.awt.event.MouseAdapter#mousePressed(java.awt.event.MouseEvent)
				 */
				public void mousePressed(java.awt.event.MouseEvent e) {
					
					KDialog=getKDialog();
					 int status =KFchooser.showOpenDialog(	KDialog);
				
					 if (status ==JFileChooser.APPROVE_OPTION) {
					      File sFile =KFchooser.getSelectedFile();
					     
					      try {
					      char[] tampon = new char[(int) sFile.length()];
					      FileReader lecteur = new FileReader(sFile);
					      lecteur.read(tampon);
					      lecteur.close();
					      KTArea.setText( new String(tampon));
					      } catch (IOException ioe) {
					      ioe.printStackTrace();
					      				      }
					      
					     
					
					 
					 }
					
	
				}
			});
			
			
		}
		return KBtn_load;
	}
	/**
	 * This method initializes KPan1	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getKPan1() {
		if (KPan1 == null) {
		
			KPan1 = new JPanel();
			KPan1.add(getKBtn_load(), null);
			KPan1.add(getKBtn_check1(), null);
			KPan1.add(getKBtn_check2(), null);
			KPan1.add(getKBtn_compile(), null);
		}
		return KPan1;
	}
	/**
	 * This method initializes KPan2	
	 * 	
	 * @return javax.swing.JPanel	
	 */
	private JPanel getKPan2() {
		if (KPan2 == null) {
		
			GridLayout gridLayout1 = new GridLayout();
			gridLayout1.setRows(1);
			KPan2 = new JPanel();
			KPan2.setLayout(gridLayout1);
			KPan2.add(getJSplitPane1(), null);
		}
		return KPan2;
	}
	/**
	 * This method initializes KTArea	
	 * 	
	 * @return javax.swing.JTextArea	
	 */
	private JTextArea getKTArea() {
		if (KTArea == null) {
			KTArea = new JTextArea();
			KTArea.setColumns(30);
			KTArea.setText("write program here");
			KTArea.setWrapStyleWord(true);
			KTArea.setEditable(true);
			KTArea.setLineWrap(true);
			KTArea.setVisible(true);
		}
		return KTArea;
	}
	/**
	 * This method initializes KBtn_check1	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getKBtn_check1() {
		if (KBtn_check1 == null) {
			KBtn_check1 = new JButton();
			KBtn_check1.setMnemonic(KeyEvent.VK_UNDEFINED);
			KBtn_check1.setText("compile it");
			KBtn_check1.setPreferredSize(new Dimension(130, 30));
			KBtn_check1.setBounds(new Rectangle(114, 168, 111, 26));
			KBtn_check1.setSelected(true);
			KBtn_check1.addMouseListener(new java.awt.event.MouseAdapter() {   
						public void mousePressed(java.awt.event.MouseEvent e) {    

						    // CharArrayReader mystream=new CharArrayReader( KTArea.getText().toCharArray());
							String mystream=KTArea.getText();
									
						     pascal myparser=new pascal(new ByteArrayInputStream(mystream.getBytes())/*mystream*/);
							
							
						String log="test";
						try {log=myparser.ParseIt();} catch(ParseException pe){
							
							
						};
						
				       KTArea2.setText(log);
				       
				}
			
			});
		}
		return KBtn_check1;
	}
	/**
	 * This method initializes KBtn_check2	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getKBtn_check2() {
		if (KBtn_check2 == null) {
			KBtn_check2 = new JButton();
			KBtn_check2.setMnemonic(KeyEvent.VK_UNDEFINED);
			KBtn_check2.setText("Save to File");
			KBtn_check2.setPreferredSize(new Dimension(130, 30));
			KBtn_check2.setBounds(new Rectangle(225, 168, 111, 26));
			KBtn_check2.setSelected(true);
			KBtn_check2.addMouseListener(new java.awt.event.MouseAdapter() {
				public void mousePressed(java.awt.event.MouseEvent e) {
					
					 KDialog=getKDialog();
					 int status =KFchooser.showSaveDialog(	KDialog);
				
					 if (status ==JFileChooser.APPROVE_OPTION) {
					      File sFile =KFchooser.getSelectedFile();
					     
					      try {
					      FileWriter reducteur = new FileWriter(sFile);
					      reducteur.write(KTArea.getText());
					      reducteur.close();
					      
					      } catch (IOException ioe) {
					      ioe.printStackTrace();
					      				      };
					
									
					 };
					
					
					
					
					
					
					
					
					
					
				}
			});
		}
		return KBtn_check2;
	}
	/**
	 * This method initializes KBtn_compile	
	 * 	
	 * @return javax.swing.JButton	
	 */
	private JButton getKBtn_compile() {
		if (KBtn_compile == null) {
			KBtn_compile = new JButton();
			KBtn_compile.setMnemonic(KeyEvent.VK_UNDEFINED);
			KBtn_compile.setText("Save report as HTML");
			KBtn_compile.setPreferredSize(new Dimension(130, 30));
			KBtn_compile.setBounds(new Rectangle(336, 168, 121, 26));
			KBtn_compile.setSelected(true);
			KBtn_compile.addMouseListener(new java.awt.event.MouseAdapter() {
				public void mouseClicked(java.awt.event.MouseEvent e) {
					
					 KDialog=getKDialog();
					 int status =KFchooser.showSaveDialog(	KDialog);
				
					 if (status ==JFileChooser.APPROVE_OPTION) {
					      File sFile =KFchooser.getSelectedFile();
					     
					      try {
					     
					      FileWriter reducteur = new FileWriter(sFile);
					      reducteur.write(KTArea2.getText());
					      reducteur.close();
					      
					      } catch (IOException ioe) {
					      ioe.printStackTrace();
					      				      };
					
									
					 };
					
					
					
					
					
					
					
				}
			});
		}
		return KBtn_compile;
	}
	/**
	 * This method initializes jSplitPane1	
	 * 	
	 * @return javax.swing.JSplitPane	
	 */
	private JSplitPane getJSplitPane1() {
		if (jSplitPane1 == null) {
			jSplitPane1 = new JSplitPane();
			jSplitPane1.setDividerLocation(350);
			jSplitPane1.setDividerSize(5);
			jSplitPane1.setEnabled(false);
			jSplitPane1.setRightComponent(getKScrollPane2());
			jSplitPane1.setLeftComponent(getKTArea());
		}
		return jSplitPane1;
	}
	/**
	 * This method initializes KTArea2	
	 * 	
	 * @return javax.swing.JTextArea	
	 */
	
	/**
	 * This method initializes KMBar	
	 * 	
	 * @return javax.swing.JMenuBar	
	 */
	private JMenuBar getKMBar() {
		if (KMBar == null) {
			GridLayout gridLayout = new GridLayout();
			gridLayout.setRows(1);
			KMBar = new JMenuBar();
			KMBar.setPreferredSize(new Dimension(0, 30));
			KMBar.add(getKmenu1());
			KMBar.add(getKMenu2());
			KMBar.add(getKMenu3());
		}
		return KMBar;
	}
	/**
	 * This method initializes Kmenu1	
	 * 	
	 * @return javax.swing.JMenu	
	 */
	private JMenu getKmenu1() {
		if (Kmenu1 == null) {
			Kmenu1 = new JMenu();
			Kmenu1.setText("File");
		}
		return Kmenu1;
	}
	/**
	 * This method initializes KMenu2	
	 * 	
	 * @return javax.swing.JMenu	
	 */
	private JMenu getKMenu2() {
		if (KMenu2 == null) {
			KMenu2 = new JMenu();
			KMenu2.setText("Edit");
		}
		return KMenu2;
	}
	/**
	 * This method initializes KMenu3	
	 * 	
	 * @return javax.swing.JMenu	
	 */
	private JMenu getKMenu3() {
		if (KMenu3 == null) {
			KMenu3 = new JMenu();
			KMenu3.setText("Help");
			KMenu3.add(getKMIabout());
		}
		return KMenu3;
	}
	/**
	 * This method initializes KMIabout	
	 * 	
	 * @return javax.swing.JMenuItem	
	 */
	private JMenuItem getKMIabout() {
		if (KMIabout == null) {
			KMIabout = new JMenuItem();
		}
		return KMIabout;
	}
	/**
	 * This method initializes KFchooser	
	 * 	
	 * @return javax.swing.JFileChooser	
	 */
	private JFileChooser getKFchooser() {
		if (KFchooser == null) {
			KFchooser = new JFileChooser();
		
				KFchooser.setDialogTitle("choose a File PasCal");
				
			KFchooser.addPropertyChangeListener(new java.beans.PropertyChangeListener() {
				public void propertyChange(java.beans.PropertyChangeEvent e) {
					if ((e.getPropertyName().equals("enabled"))) {	}
				}
			});
			KFchooser.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent e) {
					 
				}
			});
		}
		return KFchooser;
	}
	/**
	 * This method initializes KDialog	
	 * 	
	 * @return javax.swing.JDialog	
	 */
	private JDialog getKDialog() {
		if (KDialog == null) {
			KDialog = new JDialog(getJFrame());
			KDialog.setSize(new Dimension(498, 445));
			KDialog.setContentPane(getKFchooser());
		}
		return KDialog;
	}
	/**
	 * This method initializes KScrollPane2	
	 * 	
	 * @return javax.swing.JScrollPane	
	 */
	private JScrollPane getKScrollPane2() {
		if (KScrollPane2 == null) {
			KScrollPane2 = new JScrollPane();
			KScrollPane2.setViewportView(getKTArea2());
		}
		return KScrollPane2;
	}
	/**
	 * This method initializes KTArea2	
	 * 	
	 * @return javax.swing.JTextPane	
	 */
	private JTextPane getKTArea2() {
		if (KTArea2 == null) {
			KTArea2 = new JTextPane();
			KTArea2.setText("result");
			KTArea2.setEditable(false);
			KTArea2.setName("KTAREA2");
			KTArea2.setBackground(new Color(250, 232, 232));
			KTArea2.setContentType("text/html");
		}
		return KTArea2;
	}

}

