/*     */ package Medical;
/*     */ 
/*     */ import java.awt.Container;
/*     */ import java.awt.GridLayout;
/*     */ import java.awt.event.ActionEvent;
/*     */ import java.awt.event.ActionListener;
/*     */ import java.awt.event.ItemEvent;
/*     */ import java.awt.event.ItemListener;
/*     */ import java.io.PrintStream;
/*     */ import java.util.Enumeration;
/*     */ import java.util.HashMap;
/*     */ import javax.comm.CommPortIdentifier;
/*     */ import javax.comm.SerialPort;
/*     */ import javax.swing.JButton;
/*     */ import javax.swing.JComboBox;
/*     */ import javax.swing.JDialog;
/*     */ import javax.swing.JFrame;
/*     */ import javax.swing.JLabel;
/*     */ import javax.swing.JPanel;
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ public class PortChooser
/*     */   extends JDialog
/*     */   implements ItemListener
/*     */ {
/*  33 */   protected HashMap map = new HashMap();
/*     */   
/*     */ 
/*     */ 
/*     */   protected String selectedPortName;
/*     */   
/*     */ 
/*     */ 
/*     */   protected CommPortIdentifier selectedPortIdentifier;
/*     */   
/*     */ 
/*     */ 
/*     */   protected JComboBox serialPortsChoice;
/*     */   
/*     */ 
/*     */ 
/*     */   protected SerialPort ttya;
/*     */   
/*     */ 
/*     */ 
/*     */   protected JLabel choice;
/*     */   
/*     */ 
/*     */ 
/*  57 */   protected final int PAD = 5;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void itemStateChanged(ItemEvent e)
/*     */   {
/*  65 */     this.selectedPortName = ((String)((JComboBox)e.getSource()).getSelectedItem());
/*     */     
/*     */ 
/*  68 */     this.selectedPortIdentifier = ((CommPortIdentifier)this.map.get(this.selectedPortName));
/*     */     
/*  70 */     this.choice.setText(this.selectedPortName);
/*     */   }
/*     */   
/*     */   public String getSelectedName()
/*     */   {
/*  75 */     return this.selectedPortName;
/*     */   }
/*     */   
/*     */   public CommPortIdentifier getSelectedIdentifier()
/*     */   {
/*  80 */     return this.selectedPortIdentifier;
/*     */   }
/*     */   
/*     */   public static void main(String[] ap)
/*     */   {
/*  85 */     PortChooser c = new PortChooser(null);
/*  86 */     c.setVisible(true);
/*  87 */     System.out.println("You chose " + c.getSelectedName() + " (known by " + c.getSelectedIdentifier() + ").");
/*     */     
/*  89 */     System.exit(0);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */   public PortChooser(JFrame parent)
/*     */   {
/*  96 */     super(parent, "Port Chooser", true);
/*     */     
/*  98 */     makeGUI();
/*  99 */     populate();
/* 100 */     finishGUI();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   protected void makeGUI()
/*     */   {
/* 108 */     Container cp = getContentPane();
/*     */     
/* 110 */     JPanel centerPanel = new JPanel();
/* 111 */     cp.add("Center", centerPanel);
/*     */     
/* 113 */     centerPanel.setLayout(new GridLayout(0, 2, 5, 5));
/*     */     
/* 115 */     centerPanel.add(new JLabel("Serial Ports", 4));
/* 116 */     this.serialPortsChoice = new JComboBox();
/* 117 */     centerPanel.add(this.serialPortsChoice);
/* 118 */     this.serialPortsChoice.setEnabled(false);
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 137 */     centerPanel.add(new JLabel("Your choice:", 4));
/* 138 */     centerPanel.add(this.choice = new JLabel());
/*     */     
/*     */     JButton okButton;
/* 141 */     cp.add("South", okButton = new JButton("OK"));
/* 142 */     okButton.addActionListener(new ActionListener() {
/*     */       public void actionPerformed(ActionEvent e) {
/* 144 */         PortChooser.this.dispose();
/*     */       }
/*     */     });
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected void populate()
/*     */   {
/* 158 */     Enumeration pList = CommPortIdentifier.getPortIdentifiers();
/*     */     
/*     */ 
/* 161 */     while (pList.hasMoreElements()) {
/* 162 */       CommPortIdentifier cpi = (CommPortIdentifier)pList.nextElement();
/*     */       
/* 164 */       this.map.put(cpi.getName(), cpi);
/* 165 */       if (cpi.getPortType() == 1) {
/* 166 */         this.serialPortsChoice.setEnabled(true);
/* 167 */         this.serialPortsChoice.addItem(cpi.getName());
/* 168 */       } else if (cpi.getPortType() != 2) {}
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 176 */     this.serialPortsChoice.setSelectedIndex(-1);
/*     */   }
/*     */   
/*     */   protected void finishGUI()
/*     */   {
/* 181 */     this.serialPortsChoice.addItemListener(this);
/*     */     
/*     */ 
/* 184 */     pack();
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\PortChooser.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */