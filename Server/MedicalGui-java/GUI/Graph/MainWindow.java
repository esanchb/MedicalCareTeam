/*     */ package GUI.Graph;
/*     */ 
/*     */ import java.awt.BorderLayout;
/*     */ import java.awt.Color;
/*     */ import java.awt.Container;
/*     */ import java.awt.event.ActionEvent;
/*     */ import java.awt.event.ActionListener;
/*     */ import java.io.PrintStream;
/*     */ import javax.swing.BorderFactory;
/*     */ import javax.swing.Box;
/*     */ import javax.swing.JButton;
/*     */ import javax.swing.JCheckBox;
/*     */ import javax.swing.JComponent;
/*     */ import javax.swing.JFrame;
/*     */ import javax.swing.JLabel;
/*     */ import javax.swing.JPanel;
/*     */ import javax.swing.JTextField;
/*     */ import javax.swing.SwingUtilities;
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
/*     */ 
/*     */ 
/*     */ 
/*     */ public class MainWindow
/*     */   extends JFrame
/*     */ {
/*     */   private static final long serialVersionUID = 1L;
/*     */   private MedicalGraph mg;
/*     */   private Integer[] testData;
/*     */   private JTextField inputData;
/*     */   private JButton button;
/*     */   private JCheckBox gridCheck;
/*     */   private JCheckBox animCheck;
/*     */   
/*     */   public MainWindow()
/*     */   {
/*  53 */     setTitle("MedicalGraph Test");
/*  54 */     setDefaultCloseOperation(3);
/*     */     
/*  56 */     setup();
/*     */     
/*  58 */     pack();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JPanel getMedicalGraph()
/*     */   {
/*  69 */     this.testData = new Integer[] { Integer.valueOf(0), Integer.valueOf(2), Integer.valueOf(11), Integer.valueOf(28), Integer.valueOf(53), Integer.valueOf(85), Integer.valueOf(124), Integer.valueOf(171), Integer.valueOf(225), Integer.valueOf(284), Integer.valueOf(350), Integer.valueOf(422), Integer.valueOf(499), Integer.valueOf(581), Integer.valueOf(667), Integer.valueOf(756), Integer.valueOf(849), Integer.valueOf(944), Integer.valueOf(1041), Integer.valueOf(1140), Integer.valueOf(1239), Integer.valueOf(1250), Integer.valueOf(1349), Integer.valueOf(1448), Integer.valueOf(1545), Integer.valueOf(1640), Integer.valueOf(1733), Integer.valueOf(1823), Integer.valueOf(1910), Integer.valueOf(1992), Integer.valueOf(2069), Integer.valueOf(2142), Integer.valueOf(2208), Integer.valueOf(2269), Integer.valueOf(2323), Integer.valueOf(2371), Integer.valueOf(2411), Integer.valueOf(2444), Integer.valueOf(2470), Integer.valueOf(2488), Integer.valueOf(2498), Integer.valueOf(2500), Integer.valueOf(2494), Integer.valueOf(2481), Integer.valueOf(2459), Integer.valueOf(2430), Integer.valueOf(2394), Integer.valueOf(2350), Integer.valueOf(2300), Integer.valueOf(2243), Integer.valueOf(2179), Integer.valueOf(2110), Integer.valueOf(2036), Integer.valueOf(1956), Integer.valueOf(1872), Integer.valueOf(1784), Integer.valueOf(1693), Integer.valueOf(1598), Integer.valueOf(1502), Integer.valueOf(1404), Integer.valueOf(1305), Integer.valueOf(1206), Integer.valueOf(1107), Integer.valueOf(1009), Integer.valueOf(912), Integer.valueOf(818), Integer.valueOf(726), Integer.valueOf(638), Integer.valueOf(553), Integer.valueOf(473), Integer.valueOf(398), Integer.valueOf(328), Integer.valueOf(264), Integer.valueOf(206), Integer.valueOf(155), Integer.valueOf(111), Integer.valueOf(73), Integer.valueOf(44), Integer.valueOf(21), Integer.valueOf(7), Integer.valueOf(0) };
/*  70 */     System.out.println(" TestData.lengthss: " + this.testData.length);
/*     */     
/*  72 */     this.mg = new MedicalGraph(2, 300, 200);
/*     */     
/*  74 */     this.mg.setBackgroundColor(Color.black);
/*  75 */     this.mg.setBorder(BorderFactory.createLineBorder(Color.black, 1));
/*  76 */     this.mg.setGridColor(Color.black);
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
/*  89 */     this.mg.setDelay(100);
/*     */     
/*  91 */     this.mg.insertData(this.testData);
/*  92 */     this.mg.setVisible(true);
/*  93 */     this.mg.pauseAnimation();
/*  94 */     this.mg.setMinValue(0);
/*  95 */     this.mg.setMaxValue(3000);
/*  96 */     this.mg.setQueueSize(5);
/*  97 */     this.mg.revalidateGraph();
/*  98 */     this.mg.startAnimation();
/*     */     
/*     */ 
/* 101 */     JPanel p = new JPanel();
/* 102 */     p.add(this.mg);
/*     */     
/* 104 */     return p;
/*     */   }
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
/*     */   private JPanel getTestUI()
/*     */   {
/* 136 */     this.inputData = new JTextField(10);
/* 137 */     this.button = new JButton("Input Data");
/* 138 */     this.button.addActionListener(new ActionListener()
/*     */     {
/*     */       public void actionPerformed(ActionEvent arg0)
/*     */       {
/* 142 */         String[] textValues = MainWindow.this.inputData.getText().trim().split(",");
/* 143 */         Integer[] values = new Integer[textValues.length];
/* 144 */         for (int i = 0; i < textValues.length; i++) {
/*     */           try {
/* 146 */             Integer v = Integer.valueOf(textValues[i]);
/* 147 */             values[i] = v;
/*     */           }
/*     */           catch (Exception e) {}
/*     */         }
/* 151 */         if (values.length == 1)
/*     */         {
/* 153 */           MainWindow.this.mg.insertData(values[0]);
/*     */         } else {
/* 155 */           MainWindow.this.mg.insertData(values);
/*     */         }
/* 157 */         MainWindow.this.inputData.setText("");
/*     */       }
/*     */       
/* 160 */     });
/* 161 */     this.gridCheck = new JCheckBox("Show Grid");
/* 162 */     this.gridCheck.setSelected(this.mg.isGridVisible());
/* 163 */     this.gridCheck.addActionListener(new ActionListener()
/*     */     {
/*     */       public void actionPerformed(ActionEvent arg0)
/*     */       {
/* 167 */         MainWindow.this.mg.setGridVisible(MainWindow.this.gridCheck.isSelected());
/*     */       }
/*     */       
/* 170 */     });
/* 171 */     this.animCheck = new JCheckBox("Pause Animation");
/* 172 */     this.animCheck.addActionListener(new ActionListener()
/*     */     {
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */       public void actionPerformed(ActionEvent arg0) {}
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 184 */     });
/* 185 */     Box b = Box.createVerticalBox();
/*     */     
/* 187 */     JPanel q = new JPanel();
/*     */     
/* 189 */     q.add(new JLabel("Input values: (use comma char for multiple values)"));
/* 190 */     q.add(this.inputData);
/* 191 */     q.add(this.button);
/*     */     
/* 193 */     JPanel r = new JPanel();
/* 194 */     r.add(this.gridCheck);
/* 195 */     r.add(this.animCheck);
/*     */     
/* 197 */     b.add(q);
/* 198 */     b.add(r);
/*     */     
/* 200 */     return addPanel(b);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void setup()
/*     */   {
/* 210 */     JPanel p = getMedicalGraph();
/* 211 */     JPanel ui = getTestUI();
/*     */     
/* 213 */     getContentPane().setLayout(new BorderLayout());
/* 214 */     getContentPane().add(p, "Center");
/* 215 */     getContentPane().add(ui, "South");
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JPanel addPanel(JComponent comp)
/*     */   {
/* 224 */     JPanel p = new JPanel();
/* 225 */     p.add(comp);
/*     */     
/* 227 */     return p;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public static void main(String[] args)
/*     */   {
/* 237 */     SwingUtilities.invokeLater(new Runnable()
/*     */     {
/*     */       public void run()
/*     */       {
/* 241 */         MainWindow mw = new MainWindow();
/* 242 */         mw.setVisible(true);
/*     */       }
/*     */     });
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Graph\MainWindow.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */