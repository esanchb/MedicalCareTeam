/*      */ package GUI;
/*      */ 
/*      */ import GUI.Graph.MedicalGraph;
/*      */ import Medical.CommandEvent;
/*      */ import Medical.DataFromCommander;
/*      */ import Medical.MedicalCommander;
/*      */ import Medical.MedicalControl;
/*      */ import Medical.Results.BloodPressure;
/*      */ import Medical.Results.ElectroCardioGram;
/*      */ import Medical.Results.Glucometry;
/*      */ import Medical.Results.PulseOximetry;
/*      */ import Medical.Results.Spirometry;
/*      */ import Medical.Types.BPMErrorCode;
/*      */ import Medical.Types.Indication;
/*      */ import Medical.Types.Request;
/*      */ import java.awt.Color;
/*      */ import java.awt.Container;
/*      */ import java.awt.Dimension;
/*      */ import java.awt.Font;
/*      */ import java.awt.Toolkit;
/*      */ import java.awt.event.ActionEvent;
/*      */ import java.awt.event.ActionListener;
/*      */ import java.io.PrintStream;
/*      */ import javax.swing.BorderFactory;
/*      */ import javax.swing.ImageIcon;
/*      */ import javax.swing.JButton;
/*      */ import javax.swing.JFrame;
/*      */ import javax.swing.JLabel;
/*      */ import javax.swing.JLayeredPane;
/*      */ 
/*      */ public class DoctorInterface extends JFrame implements Medical.MedicalCommandListener
/*      */ {
/*      */   private MedicalGraph mg_spr;
/*      */   private MedicalGraph mg_ecg;
/*      */   private MedicalGraph mg_spo2;
/*      */   private Integer[] testDataY;
/*      */   private Integer[] testDataX;
/*      */   private MedicalCommander medical_commander;
/*      */   private MedicalControl medicalControl;
/*      */   private DataFromCommander data;
/*   41 */   private int button_active = 0;
/*      */   private javax.swing.Timer timer;
/*   43 */   private boolean b_spirometry_started = false;
/*   44 */   private boolean b_ecg_started = false;
/*   45 */   private boolean b_pox_started = false;
/*   46 */   private boolean b_bloodpressure_started = false;
/*   47 */   private int i_graph_width = 683;
/*   48 */   private int i_graph_height = 177;
/*      */   private JLabel jLabel1;
/*      */   private JLabel jLabel2;
/*      */   
/*      */   private Integer[] discrimitator(int[] buffer) {
/*   53 */     int ratio = 8;
/*   54 */     int modulus = buffer.length / ratio;
/*      */     Integer[] temp_array;
/*   56 */     Integer[] temp_array; if (modulus == 0) {
/*   57 */       temp_array = new Integer[buffer.length / ratio];
/*      */     } else {
/*   59 */       temp_array = new Integer[(buffer.length - modulus) / ratio];
/*      */     }
/*      */     
/*   62 */     int count = 0; for (int count1 = 0; count1 < temp_array.length; count1++) {
/*   63 */       int temp_start = buffer[count];
/*   64 */       int temp_actual = buffer[count];
/*   65 */       int temp_delta = 0;
/*   66 */       for (int count2 = count; count2 < count + ratio; count2++) {
/*   67 */         if (temp_delta < Math.abs(temp_start - buffer[count2])) {
/*   68 */           temp_actual = buffer[count2];
/*   69 */           temp_delta = Math.abs(temp_start - buffer[count2]);
/*      */         }
/*      */       }
/*      */       
/*   73 */       temp_array[count1] = Integer.valueOf(temp_actual);count += ratio;
/*      */     }
/*      */     
/*      */ 
/*   77 */     return temp_array;
/*      */   }
/*      */   
/*      */   public DoctorInterface(MedicalCommander medical_commander, MedicalControl medical_control)
/*      */   {
/*   82 */     initComponents();
/*   83 */     restoreComponents();
/*   84 */     this.medical_commander = medical_commander;
/*   85 */     this.medicalControl = medical_control;
/*      */     
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  107 */     this.mg_ecg = new MedicalGraph(2, 683, 177);
/*  108 */     this.mg_ecg.setBorder(BorderFactory.createLineBorder(Color.BLACK));
/*  109 */     this.mg_ecg.setBackground(Color.BLACK);
/*  110 */     this.jlayerGraphECG.add(this.mg_ecg);
/*      */     
/*      */ 
/*  113 */     this.mg_spo2 = new MedicalGraph(3, this.i_graph_width, this.i_graph_height);
/*  114 */     this.mg_spo2.setBorder(BorderFactory.createLineBorder(Color.BLACK));
/*  115 */     this.mg_spo2.setBackground(Color.BLACK);
/*  116 */     this.jlayerGraphSPO2.add(this.mg_spo2);
/*      */     
/*  118 */     this.mg_spr = new MedicalGraph(1, 353, 221);
/*  119 */     this.mg_spr.setBorder(BorderFactory.createLineBorder(Color.BLACK));
/*  120 */     this.mg_spr.setBackground(Color.BLACK);
/*  121 */     this.jlayerGraphSPI.add(this.mg_spr);
/*      */   }
/*      */   
/*      */ 
/*      */   private JLabel jLabel5;
/*      */   
/*      */   private JLabel jLabelBPMstatus;
/*      */   
/*      */   private JLabel jLabelECGstatus;
/*      */   
/*      */   private JLabel jLabelGLUstatus;
/*      */   
/*      */   private JLabel jLabelSPIstatus;
/*      */   
/*      */   private JLabel jLabelSPO2status;
/*      */   
/*      */   private JLayeredPane jLayeredPane1;
/*      */   
/*      */   private JButton jbuttonBloodPressure;
/*      */   
/*      */   private JButton jbuttonExit;
/*      */   private JButton jbuttonGlucometry;
/*      */   private JButton jbuttonHeartRateDiagnostic;
/*      */   private JButton jbuttonPulseOximetryDiagnostic;
/*      */   private JButton jbuttonSpirometry;
/*      */   private JLabel jlabelBPMResult1;
/*      */   private JLabel jlabelBPMResult2;
/*      */   private JLabel jlabelBPMResult3;
/*      */   private void initComponents()
/*      */   {
/*  151 */     this.jLayeredPane1 = new JLayeredPane();
/*  152 */     this.jLabelBPMstatus = new JLabel();
/*  153 */     this.jlabelBPMResult1 = new JLabel();
/*  154 */     this.jlabelBPMResult2 = new JLabel();
/*  155 */     this.jlabelBPMResult3 = new JLabel();
/*  156 */     this.jlabelBPMResult4 = new JLabel();
/*  157 */     this.jlabelBPMStatus2 = new JLabel();
/*  158 */     this.jlabelBPMResult6 = new JLabel();
/*  159 */     this.jlabelBPMResult7 = new JLabel();
/*  160 */     this.jlabelBPMResult8 = new JLabel();
/*  161 */     this.jbuttonBloodPressure = new JButton();
/*  162 */     this.jLabelGLUstatus = new JLabel();
/*  163 */     this.jlabelGLUResult1 = new JLabel();
/*  164 */     this.jbuttonGlucometry = new JButton();
/*  165 */     this.jbuttonExit = new JButton();
/*  166 */     this.jLabelSPIstatus = new JLabel();
/*  167 */     this.jlabelSPIResult1 = new JLabel();
/*  168 */     this.jlabelSPIResult2 = new JLabel();
/*  169 */     this.jlabelSPIResult3 = new JLabel();
/*  170 */     this.jlabelSPIResult4 = new JLabel();
/*  171 */     this.jlabelSPIResult5 = new JLabel();
/*  172 */     this.jlayerGraphSPI = new JLayeredPane();
/*  173 */     this.jbuttonSpirometry = new JButton();
/*  174 */     this.jLabelSPO2status = new JLabel();
/*  175 */     this.jlabelSPO2Result1 = new JLabel();
/*  176 */     this.jlabelSPO2Result2 = new JLabel();
/*  177 */     this.jlayerGraphSPO2 = new JLayeredPane();
/*  178 */     this.jbuttonPulseOximetryDiagnostic = new JButton();
/*  179 */     this.jLabelECGstatus = new JLabel();
/*  180 */     this.jlabelECGResult1 = new JLabel();
/*  181 */     this.jlayerGraphECG = new JLayeredPane();
/*  182 */     this.jbuttonHeartRateDiagnostic = new JButton();
/*  183 */     this.jLabel5 = new JLabel();
/*  184 */     this.jLabel1 = new JLabel();
/*  185 */     this.jLabel2 = new JLabel();
/*  186 */     this.jlabelBPMResult5 = new JLabel();
/*      */     
/*  188 */     setDefaultCloseOperation(3);
/*  189 */     setAlwaysOnTop(true);
/*  190 */     setBackground(new Color(255, 255, 255));
/*  191 */     setMaximizedBounds(new java.awt.Rectangle(0, 0, 1024, 768));
/*  192 */     setMinimumSize(new Dimension(1024, 768));
/*  193 */     setUndecorated(true);
/*  194 */     getContentPane().setLayout(new java.awt.GridLayout(1, 0));
/*      */     
/*  196 */     this.jLayeredPane1.setBackground(new Color(255, 255, 255));
/*  197 */     this.jLayeredPane1.setAlignmentX(0.0F);
/*  198 */     this.jLayeredPane1.setAlignmentY(0.0F);
/*      */     
/*  200 */     this.jLabelBPMstatus.setFont(new Font("Dialog", 1, 14));
/*  201 */     this.jLabelBPMstatus.setForeground(new Color(255, 0, 0));
/*  202 */     this.jLabelBPMstatus.setBounds(690, 430, 250, -1);
/*  203 */     this.jLayeredPane1.add(this.jLabelBPMstatus, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  205 */     this.jlabelBPMResult1.setFont(new Font("Dialog", 1, 18));
/*  206 */     this.jlabelBPMResult1.setForeground(new Color(255, 0, 0));
/*  207 */     this.jlabelBPMResult1.setBounds(670, 450, 280, -1);
/*  208 */     this.jLayeredPane1.add(this.jlabelBPMResult1, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  210 */     this.jlabelBPMResult2.setFont(new Font("Dialog", 1, 18));
/*  211 */     this.jlabelBPMResult2.setForeground(new Color(255, 0, 0));
/*  212 */     this.jlabelBPMResult2.setBounds(670, 480, 280, 30);
/*  213 */     this.jLayeredPane1.add(this.jlabelBPMResult2, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  215 */     this.jlabelBPMResult3.setFont(new Font("Dialog", 1, 18));
/*  216 */     this.jlabelBPMResult3.setForeground(new Color(255, 0, 0));
/*  217 */     this.jlabelBPMResult3.setBounds(670, 510, 280, -1);
/*  218 */     this.jLayeredPane1.add(this.jlabelBPMResult3, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  220 */     this.jlabelBPMResult4.setFont(new Font("Dialog", 1, 18));
/*  221 */     this.jlabelBPMResult4.setForeground(new Color(255, 0, 0));
/*  222 */     this.jlabelBPMResult4.setBounds(670, 540, 280, -1);
/*  223 */     this.jLayeredPane1.add(this.jlabelBPMResult4, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  225 */     this.jlabelBPMStatus2.setFont(new Font("Dialog", 1, 14));
/*  226 */     this.jlabelBPMStatus2.setForeground(new Color(255, 0, 0));
/*  227 */     this.jlabelBPMStatus2.setHorizontalAlignment(0);
/*  228 */     this.jlabelBPMStatus2.setBounds(670, 430, 280, 20);
/*  229 */     this.jLayeredPane1.add(this.jlabelBPMStatus2, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  231 */     this.jlabelBPMResult6.setFont(new Font("Dialog", 1, 18));
/*  232 */     this.jlabelBPMResult6.setForeground(new Color(255, 0, 0));
/*  233 */     this.jlabelBPMResult6.setBounds(670, 450, 290, 30);
/*  234 */     this.jLayeredPane1.add(this.jlabelBPMResult6, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  236 */     this.jlabelBPMResult7.setFont(new Font("Dialog", 1, 18));
/*  237 */     this.jlabelBPMResult7.setForeground(new Color(255, 0, 0));
/*  238 */     this.jlabelBPMResult7.setBounds(670, 510, 280, 30);
/*  239 */     this.jLayeredPane1.add(this.jlabelBPMResult7, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  241 */     this.jlabelBPMResult8.setFont(new Font("Dialog", 1, 18));
/*  242 */     this.jlabelBPMResult8.setForeground(new Color(255, 0, 0));
/*  243 */     this.jlabelBPMResult8.setBounds(670, 540, 280, 30);
/*  244 */     this.jLayeredPane1.add(this.jlabelBPMResult8, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  246 */     this.jbuttonBloodPressure.setBackground(new Color(0, 0, 0));
/*  247 */     this.jbuttonBloodPressure.setFont(new Font("Calibri", 1, 11));
/*  248 */     this.jbuttonBloodPressure.setForeground(new Color(255, 255, 255));
/*  249 */     this.jbuttonBloodPressure.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/bpm_dark.png")));
/*  250 */     this.jbuttonBloodPressure.setAlignmentY(0.0F);
/*  251 */     this.jbuttonBloodPressure.setBorder(null);
/*  252 */     this.jbuttonBloodPressure.setBorderPainted(false);
/*  253 */     this.jbuttonBloodPressure.setContentAreaFilled(false);
/*  254 */     this.jbuttonBloodPressure.setMaximumSize(new Dimension(512, 768));
/*  255 */     this.jbuttonBloodPressure.setMinimumSize(new Dimension(512, 768));
/*  256 */     this.jbuttonBloodPressure.setPreferredSize(new Dimension(512, 768));
/*  257 */     this.jbuttonBloodPressure.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  259 */         DoctorInterface.this.jbuttonBloodPressureActionPerformed(evt);
/*      */       }
/*  261 */     });
/*  262 */     this.jbuttonBloodPressure.setBounds(630, 430, 350, 140);
/*  263 */     this.jLayeredPane1.add(this.jbuttonBloodPressure, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  265 */     this.jLabelGLUstatus.setFont(new Font("Dialog", 1, 16));
/*  266 */     this.jLabelGLUstatus.setForeground(new Color(0, 104, 158));
/*  267 */     this.jLabelGLUstatus.setHorizontalAlignment(0);
/*  268 */     this.jLabelGLUstatus.setBounds(670, 590, 270, 40);
/*  269 */     this.jLayeredPane1.add(this.jLabelGLUstatus, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  271 */     this.jlabelGLUResult1.setFont(new Font("Dialog", 1, 18));
/*  272 */     this.jlabelGLUResult1.setForeground(new Color(0, 104, 158));
/*  273 */     this.jlabelGLUResult1.setBounds(670, 640, 270, 60);
/*  274 */     this.jLayeredPane1.add(this.jlabelGLUResult1, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  276 */     this.jbuttonGlucometry.setBackground(new Color(0, 0, 0));
/*  277 */     this.jbuttonGlucometry.setFont(new Font("Calibri", 1, 11));
/*  278 */     this.jbuttonGlucometry.setForeground(new Color(255, 255, 255));
/*  279 */     this.jbuttonGlucometry.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/glu_dark.png")));
/*  280 */     this.jbuttonGlucometry.setAlignmentY(0.0F);
/*  281 */     this.jbuttonGlucometry.setBorder(null);
/*  282 */     this.jbuttonGlucometry.setBorderPainted(false);
/*  283 */     this.jbuttonGlucometry.setContentAreaFilled(false);
/*  284 */     this.jbuttonGlucometry.setMaximumSize(new Dimension(512, 768));
/*  285 */     this.jbuttonGlucometry.setMinimumSize(new Dimension(512, 768));
/*  286 */     this.jbuttonGlucometry.setPreferredSize(new Dimension(512, 768));
/*  287 */     this.jbuttonGlucometry.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  289 */         DoctorInterface.this.jbuttonGlucometryActionPerformed(evt);
/*      */       }
/*  291 */     });
/*  292 */     this.jbuttonGlucometry.setBounds(630, 580, 350, 140);
/*  293 */     this.jLayeredPane1.add(this.jbuttonGlucometry, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  295 */     this.jbuttonExit.setBackground(new Color(0, 0, 0));
/*  296 */     this.jbuttonExit.setFont(new Font("Calibri", 1, 11));
/*  297 */     this.jbuttonExit.setForeground(new Color(255, 255, 255));
/*  298 */     this.jbuttonExit.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/exit.png")));
/*  299 */     this.jbuttonExit.setAlignmentY(0.0F);
/*  300 */     this.jbuttonExit.setBorder(null);
/*  301 */     this.jbuttonExit.setBorderPainted(false);
/*  302 */     this.jbuttonExit.setContentAreaFilled(false);
/*  303 */     this.jbuttonExit.setMaximumSize(new Dimension(512, 768));
/*  304 */     this.jbuttonExit.setMinimumSize(new Dimension(512, 768));
/*  305 */     this.jbuttonExit.setPreferredSize(new Dimension(512, 768));
/*  306 */     this.jbuttonExit.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  308 */         DoctorInterface.this.jbuttonExitActionPerformed(evt);
/*      */       }
/*  310 */     });
/*  311 */     this.jbuttonExit.setBounds(980, 0, 40, 40);
/*  312 */     this.jLayeredPane1.add(this.jbuttonExit, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  314 */     this.jLabelSPIstatus.setFont(new Font("Dialog", 1, 14));
/*  315 */     this.jLabelSPIstatus.setForeground(new Color(255, 0, 128));
/*  316 */     this.jLabelSPIstatus.setHorizontalAlignment(0);
/*  317 */     this.jLabelSPIstatus.setBounds(150, 430, 250, 30);
/*  318 */     this.jLayeredPane1.add(this.jLabelSPIstatus, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  320 */     this.jlabelSPIResult1.setFont(new Font("Dialog", 1, 16));
/*  321 */     this.jlabelSPIResult1.setForeground(new Color(255, 0, 128));
/*  322 */     this.jlabelSPIResult1.setBounds(470, 450, 130, 40);
/*  323 */     this.jLayeredPane1.add(this.jlabelSPIResult1, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  325 */     this.jlabelSPIResult2.setFont(new Font("Dialog", 1, 16));
/*  326 */     this.jlabelSPIResult2.setForeground(new Color(255, 0, 128));
/*  327 */     this.jlabelSPIResult2.setBounds(470, 500, 130, 40);
/*  328 */     this.jLayeredPane1.add(this.jlabelSPIResult2, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  330 */     this.jlabelSPIResult3.setFont(new Font("Dialog", 1, 16));
/*  331 */     this.jlabelSPIResult3.setForeground(new Color(255, 0, 128));
/*  332 */     this.jlabelSPIResult3.setBounds(470, 550, 130, 40);
/*  333 */     this.jLayeredPane1.add(this.jlabelSPIResult3, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  335 */     this.jlabelSPIResult4.setFont(new Font("Dialog", 1, 16));
/*  336 */     this.jlabelSPIResult4.setForeground(new Color(255, 0, 128));
/*  337 */     this.jlabelSPIResult4.setBounds(470, 600, 130, 40);
/*  338 */     this.jLayeredPane1.add(this.jlabelSPIResult4, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  340 */     this.jlabelSPIResult5.setFont(new Font("Dialog", 1, 16));
/*  341 */     this.jlabelSPIResult5.setForeground(new Color(255, 0, 128));
/*  342 */     this.jlabelSPIResult5.setBounds(470, 650, 130, 40);
/*  343 */     this.jLayeredPane1.add(this.jlabelSPIResult5, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  345 */     this.jlayerGraphSPI.setBorder(BorderFactory.createLineBorder(new Color(0, 0, 0)));
/*  346 */     this.jlayerGraphSPI.setBounds(80, 470, 360, 230);
/*  347 */     this.jLayeredPane1.add(this.jlayerGraphSPI, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  349 */     this.jbuttonSpirometry.setBackground(new Color(0, 0, 0));
/*  350 */     this.jbuttonSpirometry.setFont(new Font("Calibri", 1, 11));
/*  351 */     this.jbuttonSpirometry.setForeground(new Color(255, 255, 255));
/*  352 */     this.jbuttonSpirometry.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/spir_dark.png")));
/*  353 */     this.jbuttonSpirometry.setAlignmentY(0.0F);
/*  354 */     this.jbuttonSpirometry.setBorder(null);
/*  355 */     this.jbuttonSpirometry.setBorderPainted(false);
/*  356 */     this.jbuttonSpirometry.setContentAreaFilled(false);
/*  357 */     this.jbuttonSpirometry.setMaximumSize(new Dimension(512, 768));
/*  358 */     this.jbuttonSpirometry.setMinimumSize(new Dimension(512, 768));
/*  359 */     this.jbuttonSpirometry.setPreferredSize(new Dimension(512, 768));
/*  360 */     this.jbuttonSpirometry.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  362 */         DoctorInterface.this.jbuttonSpirometryActionPerformed(evt);
/*      */       }
/*  364 */     });
/*  365 */     this.jbuttonSpirometry.setBounds(10, 430, 600, 300);
/*  366 */     this.jLayeredPane1.add(this.jbuttonSpirometry, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  368 */     this.jLabelSPO2status.setFont(new Font("Dialog", 1, 14));
/*  369 */     this.jLabelSPO2status.setForeground(new Color(207, 173, 2));
/*  370 */     this.jLabelSPO2status.setHorizontalAlignment(0);
/*  371 */     this.jLabelSPO2status.setBounds(770, 230, 200, 40);
/*  372 */     this.jLayeredPane1.add(this.jLabelSPO2status, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  374 */     this.jlabelSPO2Result1.setFont(new Font("Dialog", 1, 28));
/*  375 */     this.jlabelSPO2Result1.setForeground(new Color(207, 173, 2));
/*  376 */     this.jlabelSPO2Result1.setBounds(770, 270, 200, 70);
/*  377 */     this.jLayeredPane1.add(this.jlabelSPO2Result1, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  379 */     this.jlabelSPO2Result2.setFont(new Font("Dialog", 1, 22));
/*  380 */     this.jlabelSPO2Result2.setForeground(new Color(207, 173, 2));
/*  381 */     this.jlabelSPO2Result2.setBounds(770, 340, 200, 70);
/*  382 */     this.jLayeredPane1.add(this.jlabelSPO2Result2, JLayeredPane.DEFAULT_LAYER);
/*  383 */     this.jlayerGraphSPO2.setBounds(60, 230, 690, 180);
/*  384 */     this.jLayeredPane1.add(this.jlayerGraphSPO2, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  386 */     this.jbuttonPulseOximetryDiagnostic.setBackground(new Color(0, 0, 0));
/*  387 */     this.jbuttonPulseOximetryDiagnostic.setFont(new Font("Calibri", 1, 11));
/*  388 */     this.jbuttonPulseOximetryDiagnostic.setForeground(new Color(255, 255, 255));
/*  389 */     this.jbuttonPulseOximetryDiagnostic.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/spo2_dark.png")));
/*  390 */     this.jbuttonPulseOximetryDiagnostic.setAlignmentY(0.0F);
/*  391 */     this.jbuttonPulseOximetryDiagnostic.setBorder(null);
/*  392 */     this.jbuttonPulseOximetryDiagnostic.setBorderPainted(false);
/*  393 */     this.jbuttonPulseOximetryDiagnostic.setContentAreaFilled(false);
/*  394 */     this.jbuttonPulseOximetryDiagnostic.setMaximumSize(new Dimension(512, 768));
/*  395 */     this.jbuttonPulseOximetryDiagnostic.setMinimumSize(new Dimension(512, 768));
/*  396 */     this.jbuttonPulseOximetryDiagnostic.setPreferredSize(new Dimension(512, 768));
/*  397 */     this.jbuttonPulseOximetryDiagnostic.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  399 */         DoctorInterface.this.jbuttonPulseOximetryDiagnosticActionPerformed(evt);
/*      */       }
/*  401 */     });
/*  402 */     this.jbuttonPulseOximetryDiagnostic.setBounds(10, 220, 970, 200);
/*  403 */     this.jLayeredPane1.add(this.jbuttonPulseOximetryDiagnostic, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  405 */     this.jLabelECGstatus.setBackground(new Color(102, 0, 102));
/*  406 */     this.jLabelECGstatus.setFont(new Font("Dialog", 1, 14));
/*  407 */     this.jLabelECGstatus.setForeground(new Color(0, 102, 0));
/*  408 */     this.jLabelECGstatus.setHorizontalAlignment(0);
/*  409 */     this.jLabelECGstatus.setVerticalAlignment(3);
/*  410 */     this.jLabelECGstatus.setBounds(760, 20, 210, 40);
/*  411 */     this.jLayeredPane1.add(this.jLabelECGstatus, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  413 */     this.jlabelECGResult1.setFont(new Font("Dialog", 1, 46));
/*  414 */     this.jlabelECGResult1.setForeground(new Color(0, 102, 0));
/*  415 */     this.jlabelECGResult1.setHorizontalAlignment(0);
/*  416 */     this.jlabelECGResult1.setVerticalAlignment(3);
/*  417 */     this.jlabelECGResult1.setBounds(760, 70, 210, 120);
/*  418 */     this.jLayeredPane1.add(this.jlabelECGResult1, JLayeredPane.DEFAULT_LAYER);
/*  419 */     this.jlayerGraphECG.setBounds(60, 20, 690, 180);
/*  420 */     this.jLayeredPane1.add(this.jlayerGraphECG, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  422 */     this.jbuttonHeartRateDiagnostic.setBackground(new Color(255, 255, 255));
/*  423 */     this.jbuttonHeartRateDiagnostic.setFont(new Font("Dialog", 0, 18));
/*  424 */     this.jbuttonHeartRateDiagnostic.setForeground(new Color(0, 102, 0));
/*  425 */     this.jbuttonHeartRateDiagnostic.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/ecg_dark.png")));
/*  426 */     this.jbuttonHeartRateDiagnostic.setAlignmentY(0.0F);
/*  427 */     this.jbuttonHeartRateDiagnostic.setBorder(null);
/*  428 */     this.jbuttonHeartRateDiagnostic.setBorderPainted(false);
/*  429 */     this.jbuttonHeartRateDiagnostic.setContentAreaFilled(false);
/*  430 */     this.jbuttonHeartRateDiagnostic.setMaximumSize(new Dimension(200, 970));
/*  431 */     this.jbuttonHeartRateDiagnostic.setMinimumSize(new Dimension(200, 970));
/*  432 */     this.jbuttonHeartRateDiagnostic.setPreferredSize(new Dimension(200, 970));
/*  433 */     this.jbuttonHeartRateDiagnostic.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  435 */         DoctorInterface.this.jbuttonHeartRateDiagnosticActionPerformed(evt);
/*      */       }
/*  437 */     });
/*  438 */     this.jbuttonHeartRateDiagnostic.setBounds(10, 10, 970, 200);
/*  439 */     this.jLayeredPane1.add(this.jbuttonHeartRateDiagnostic, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  441 */     this.jLabel5.setBackground(new Color(102, 0, 102));
/*  442 */     this.jLabel5.setFont(new Font("Dialog", 1, 14));
/*  443 */     this.jLabel5.setForeground(new Color(0, 102, 0));
/*  444 */     this.jLabel5.setHorizontalAlignment(0);
/*  445 */     this.jLabel5.setVerticalAlignment(3);
/*  446 */     this.jLabel5.setBorder(BorderFactory.createLineBorder(new Color(255, 255, 255), 3));
/*  447 */     this.jLabel5.setBounds(760, 70, 210, 40);
/*  448 */     this.jLayeredPane1.add(this.jLabel5, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  450 */     this.jLabel1.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/fslicon3.png")));
/*  451 */     this.jLabel1.setBounds(890, 720, 130, 50);
/*  452 */     this.jLayeredPane1.add(this.jLabel1, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  454 */     this.jLabel2.setBackground(new Color(102, 102, 102));
/*  455 */     this.jLabel2.setHorizontalAlignment(0);
/*  456 */     this.jLabel2.setBorder(BorderFactory.createEmptyBorder(1, 1, 1, 1));
/*  457 */     this.jLabel2.setOpaque(true);
/*  458 */     this.jLabel2.setBounds(0, 0, 1020, 770);
/*  459 */     this.jLayeredPane1.add(this.jLabel2, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  461 */     this.jlabelBPMResult5.setFont(new Font("Dialog", 1, 18));
/*  462 */     this.jlabelBPMResult5.setForeground(new Color(255, 0, 0));
/*  463 */     this.jlabelBPMResult5.setBounds(670, 480, 280, 30);
/*  464 */     this.jLayeredPane1.add(this.jlabelBPMResult5, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  466 */     getContentPane().add(this.jLayeredPane1);
/*      */     
/*  468 */     Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
/*  469 */     setBounds((screenSize.width - 1020) / 2, (screenSize.height - 775) / 2, 1020, 775);
/*      */   }
/*      */   
/*      */   private void resetButton() {
/*  473 */     this.button_active = 0;
/*      */     
/*      */ 
/*      */ 
/*  477 */     this.jbuttonBloodPressure.setIcon(new ImageIcon(getClass().getResource(this.bp_icon_path)));
/*      */     
/*      */ 
/*  480 */     this.jbuttonGlucometry.setIcon(new ImageIcon(getClass().getResource(this.glu_icon_path)));
/*  481 */     this.jbuttonSpirometry.setIcon(new ImageIcon(getClass().getResource(this.spr_icon_path)));
/*  482 */     this.jbuttonPulseOximetryDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.pox_icon_path)));
/*      */     
/*  484 */     this.jbuttonHeartRateDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.ecg_icon_path)));
/*      */   }
/*      */   
/*      */   private void activateButton(int button_pressed) {
/*  488 */     activateButton(button_pressed, true);
/*      */   }
/*      */   
/*      */   private void activateButton(int button_pressed, boolean button_lock) {
/*  492 */     clearResults();
/*      */     
/*      */ 
/*  495 */     switch (this.button_active)
/*      */     {
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */     case 4: 
/*  508 */       this.jbuttonBloodPressure.setIcon(new ImageIcon(getClass().getResource(this.bp_icon_path)));
/*  509 */       break;
/*      */     case 5: 
/*      */       break;
/*      */     
/*      */     case 6: 
/*      */       break;
/*      */     
/*      */     case 7: 
/*  517 */       this.jbuttonGlucometry.setIcon(new ImageIcon(getClass().getResource(this.glu_icon_path)));
/*  518 */       break;
/*      */     case 8: 
/*  520 */       this.jbuttonSpirometry.setIcon(new ImageIcon(getClass().getResource(this.spr_icon_path)));
/*  521 */       break;
/*      */     case 9: 
/*  523 */       this.jbuttonPulseOximetryDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.pox_icon_path)));
/*  524 */       break;
/*      */     case 10: 
/*      */       break;
/*      */     
/*      */     case 11: 
/*  529 */       this.jbuttonHeartRateDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.ecg_icon_path)));
/*      */     }
/*      */     
/*      */     
/*      */ 
/*  534 */     switch (button_pressed)
/*      */     {
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */     case 4: 
/*  546 */       this.jbuttonBloodPressure.setIcon(new ImageIcon(getClass().getResource(this.bp_blue_icon_path)));
/*  547 */       break;
/*      */     case 5: 
/*      */       break;
/*      */     
/*      */     case 6: 
/*      */       break;
/*      */     
/*      */     case 7: 
/*  555 */       this.jbuttonGlucometry.setIcon(new ImageIcon(getClass().getResource(this.glu_blue_icon_path)));
/*  556 */       break;
/*      */     case 8: 
/*  558 */       this.jbuttonSpirometry.setIcon(new ImageIcon(getClass().getResource(this.spr_blue_icon_path)));
/*  559 */       break;
/*      */     case 9: 
/*  561 */       this.jbuttonPulseOximetryDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.pox_blue_icon_path)));
/*  562 */       break;
/*      */     case 10: 
/*      */       break;
/*      */     
/*      */     case 11: 
/*  567 */       this.jbuttonHeartRateDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.ecg_blue_icon_path)));
/*      */     }
/*      */     
/*  570 */     this.button_active = button_pressed;
/*      */   }
/*      */   
/*      */   private void clearResults()
/*      */   {
/*  575 */     this.jlabelBPMStatus2.setText("");
/*  576 */     this.jLabelSPIstatus.setText("");
/*  577 */     this.jLabelECGstatus.setText("");
/*  578 */     this.jLabelSPO2status.setText("");
/*  579 */     this.jLabelGLUstatus.setText("");
/*      */   }
/*      */   
/*      */   private void jbuttonBloodPressureActionPerformed(ActionEvent evt) {
/*  583 */     if (!this.b_bloodpressure_started) {
/*  584 */       activateButton(4);
/*  585 */       this.medical_commander.startBloodPressure();
/*      */       
/*  587 */       this.jlabelBPMStatus2.setText(this.medical_commander.getRequestDescription());
/*  588 */       this.b_bloodpressure_started = true;
/*  589 */     } else if (this.b_bloodpressure_started == true) {
/*  590 */       resetButton();
/*  591 */       clearResults();
/*  592 */       this.medical_commander.stopBloodPressure();
/*      */       
/*  594 */       this.jlabelBPMStatus2.setText(this.medical_commander.getRequestDescription());
/*  595 */       this.b_bloodpressure_started = false;
/*      */     }
/*      */   }
/*      */   
/*      */   private void jbuttonGlucometryActionPerformed(ActionEvent evt) {
/*  600 */     activateButton(7);
/*  601 */     this.medical_commander.startGlucometry();
/*      */     
/*  603 */     this.jLabelGLUstatus.setText(this.medical_commander.getRequestDescription());
/*      */   }
/*      */   
/*      */   private void jbuttonExitActionPerformed(ActionEvent evt)
/*      */   {
/*  608 */     this.medicalControl.showLogin();
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*      */   private void jbuttonSpirometryActionPerformed(ActionEvent evt)
/*      */   {
/*  615 */     if (!this.b_spirometry_started) {
/*  616 */       activateButton(8);
/*  617 */       this.mg_spr.setVisible(true);
/*      */       
/*  619 */       this.mg_ecg.setVisible(false);
/*  620 */       this.mg_spo2.setVisible(false);
/*  621 */       this.mg_spr.pauseAnimation();
/*  622 */       this.mg_spr.clearData();
/*  623 */       this.mg_spr.setMinValue(-100);
/*  624 */       this.mg_spr.setMaxValue(100);
/*  625 */       this.mg_spr.setQueueSize(300);
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  631 */       this.medical_commander.startSpirometryDiagnostic();
/*      */       
/*  633 */       this.jLabelSPIstatus.setText(this.medical_commander.getRequestDescription());
/*  634 */       this.b_spirometry_started = true;
/*  635 */     } else if (this.b_spirometry_started == true) {
/*  636 */       resetButton();
/*      */       
/*      */ 
/*  639 */       this.medical_commander.stopSpirometryDiagnostic();
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*  644 */       this.jLabelSPIstatus.setText(this.medical_commander.getRequestDescription());
/*  645 */       this.b_spirometry_started = false;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  651 */       this.data.spirometry.printAll();
/*      */       
/*      */ 
/*      */ 
/*  655 */       this.mg_spr.insertData(this.data.spirometry.getBufferVol(), this.data.spirometry.getBufferFlow());
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  662 */       this.jlabelSPIResult1.setText("FIVC:" + this.data.spirometry.getFIVC() + " [l]");
/*      */       
/*      */ 
/*      */ 
/*  666 */       this.jlabelSPIResult2.setText("PIF:" + this.data.spirometry.getPIF() + " [l/s]");
/*      */       
/*  668 */       this.jlabelSPIResult3.setText("FEV1:" + this.data.spirometry.getFEV1() + " [l]");
/*      */       
/*  670 */       this.jlabelSPIResult4.setText("FVC:" + this.data.spirometry.getFVC() + " [l]");
/*      */       
/*  672 */       this.jlabelSPIResult5.setText("FET:" + this.data.spirometry.getFET() + " [s]");
/*      */       
/*      */ 
/*  675 */       this.data.spirometry.newexam();
/*      */     }
/*      */   }
/*      */   
/*      */   private void jbuttonPulseOximetryDiagnosticActionPerformed(ActionEvent evt) {
/*  680 */     if (!this.b_pox_started) {
/*  681 */       activateButton(9);
/*  682 */       this.mg_spr.setVisible(false);
/*      */       
/*  684 */       this.mg_ecg.setVisible(false);
/*  685 */       this.mg_spo2.setVisible(true);
/*  686 */       this.mg_spo2.pauseAnimation();
/*  687 */       this.mg_spo2.clearData();
/*  688 */       this.mg_spo2.setMinValue(0);
/*  689 */       this.mg_spo2.setMaxValue(3000);
/*  690 */       this.mg_spo2.setQueueSize(250);
/*  691 */       this.mg_spo2.revalidateGraph();
/*  692 */       this.mg_spo2.startAnimation();
/*      */       
/*  694 */       this.medical_commander.startPulseOximetryDiagnostic();
/*      */       
/*  696 */       this.jLabelSPO2status.setText(this.medical_commander.getRequestDescription());
/*  697 */       this.b_pox_started = true;
/*  698 */     } else if (this.b_pox_started == true) {
/*  699 */       resetButton();
/*  700 */       this.mg_spo2.pauseAnimation();
/*      */       
/*  702 */       this.medical_commander.stopPulseOximetryDiagnostic();
/*      */       
/*      */ 
/*  705 */       this.jLabelSPO2status.setText(this.medical_commander.getRequestDescription());
/*  706 */       this.b_pox_started = false;
/*      */     }
/*      */   }
/*      */   
/*      */   private void jbuttonHeartRateDiagnosticActionPerformed(ActionEvent evt) {
/*  711 */     if (!this.b_ecg_started) {
/*  712 */       activateButton(11);
/*  713 */       this.mg_spr.setVisible(false);
/*      */       
/*  715 */       this.mg_ecg.setVisible(true);
/*  716 */       this.mg_ecg.pauseAnimation();
/*  717 */       this.mg_ecg.clearData();
/*  718 */       this.mg_ecg.setMinValue(64536);
/*  719 */       this.mg_ecg.setMaxValue(35000);
/*  720 */       this.mg_ecg.setQueueSize(200);
/*  721 */       this.mg_ecg.revalidateGraph();
/*  722 */       this.mg_ecg.startAnimation();
/*      */       
/*  724 */       this.medical_commander.startECGDiagnostic();
/*      */       
/*  726 */       this.jLabelECGstatus.setText(this.medical_commander.getRequestDescription());
/*  727 */       this.b_ecg_started = true;
/*  728 */     } else if (this.b_ecg_started == true) {
/*  729 */       resetButton();
/*  730 */       this.mg_ecg.pauseAnimation();
/*      */       
/*  732 */       this.medical_commander.stopECGDiagnostic();
/*      */       
/*      */ 
/*  735 */       this.jLabelECGstatus.setText(this.medical_commander.getRequestDescription());
/*  736 */       this.b_ecg_started = false;
/*      */     }
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*      */   private JLabel jlabelBPMResult4;
/*      */   
/*      */ 
/*      */   private JLabel jlabelBPMResult5;
/*      */   
/*      */ 
/*      */   private JLabel jlabelBPMResult6;
/*      */   
/*      */ 
/*      */   private JLabel jlabelBPMResult7;
/*      */   
/*      */ 
/*      */   private JLabel jlabelBPMResult8;
/*      */   
/*      */ 
/*      */   private JLabel jlabelBPMStatus2;
/*      */   
/*      */ 
/*      */   private JLabel jlabelECGResult1;
/*      */   
/*      */ 
/*      */   private JLabel jlabelGLUResult1;
/*      */   
/*      */ 
/*      */   private JLabel jlabelSPIResult1;
/*      */   
/*      */ 
/*      */   private JLabel jlabelSPIResult2;
/*      */   
/*      */ 
/*      */   private JLabel jlabelSPIResult3;
/*      */   
/*      */ 
/*      */   private JLabel jlabelSPIResult4;
/*      */   
/*      */ 
/*      */   private JLabel jlabelSPIResult5;
/*      */   
/*      */   private JLabel jlabelSPO2Result1;
/*      */   
/*      */   private JLabel jlabelSPO2Result2;
/*      */   
/*      */   private JLayeredPane jlayerGraphECG;
/*      */   
/*      */   private JLayeredPane jlayerGraphSPI;
/*      */   
/*      */   private JLayeredPane jlayerGraphSPO2;
/*      */   
/*      */   public void medicalCommandDataAvailable(CommandEvent evt)
/*      */   {
/*  792 */     this.data = evt.getMedicalData();
/*      */     
/*      */ 
/*  795 */     Types.Request request = this.data.getRequest();
/*  796 */     Types.Indication indicator = this.data.getIndicator();
/*      */     
/*  798 */     if (request != Types.Request.NONE) {
/*  799 */       switch (request)
/*      */       {
/*      */       case TMP_READ_TEMPERATURE: 
/*      */         break;
/*      */       
/*      */ 
/*      */       case HGT_READ_HEIGHT: 
/*      */         break;
/*      */       
/*      */ 
/*      */       }
/*      */       
/*  811 */     } else if (indicator != Types.Indication.NONE) {
/*  812 */       switch (indicator)
/*      */       {
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */       case GLU_MEASUREMENT_COMPLETE_OK: 
/*  819 */         this.jLabelGLUstatus.setText(indicator.getDescription());
/*      */         
/*  821 */         this.jlabelGLUResult1.setText("Glucose Level " + this.data.glucometry.getGlucoseLevel() + " units ");
/*  822 */         break;
/*      */       
/*      */       case GLU_CALIBRATION_COMPLETE_OK: 
/*  825 */         this.jLabelGLUstatus.setText(indicator.getDescription());
/*      */         
/*  827 */         this.jlabelGLUResult1.setText("Glucometry calibration parameter " + this.data.glucometry.getGlucoseLevel() + " units ");
/*      */         
/*  829 */         break;
/*      */       
/*      */       case BPM_MEASUREMENT_COMPLETE_OK: 
/*  832 */         this.jlabelBPMStatus2.setText(indicator.getDescription());
/*      */         
/*  834 */         this.jlabelBPMResult6.setText("Sistolic pressure:" + this.data.blood_pressure.getSistolic());
/*      */         
/*  836 */         this.jlabelBPMResult2.setText("Diastolic pressure:" + this.data.blood_pressure.getDiastolic());
/*      */         
/*  838 */         this.jlabelBPMResult7.setText("Heart Rate:" + this.data.blood_pressure.getHeartRate());
/*      */         
/*  840 */         this.jlabelBPMResult8.setText("Mean pressure:" + this.data.blood_pressure.getMeanPressure());
/*  841 */         this.b_bloodpressure_started = false;
/*  842 */         break;
/*      */       
/*      */       case BPM_LEAK_TEST_COMPLETE: 
/*  845 */         this.jlabelBPMStatus2.setText(indicator.getDescription());
/*      */         
/*  847 */         this.jlabelBPMResult6.setText("Blood pressure Leak test " + this.data.blood_pressure.getLeakTestResult());
/*  848 */         this.b_bloodpressure_started = false;
/*  849 */         break;
/*      */       case BPM_MEASUREMENT_ERROR: 
/*  851 */         resetButton();
/*  852 */         this.b_bloodpressure_started = false;
/*      */         
/*      */ 
/*  855 */         this.jlabelBPMStatus2.setText(indicator.getDescription());
/*      */         
/*  857 */         this.jlabelBPMResult6.setText("Description " + this.data.blood_pressure.getErrorCode().getDescription());
/*  858 */         break;
/*      */       
/*      */       case ECG_HEART_RATE_MEASUREMENT_COMPLETE_OK: 
/*  861 */         this.jLabelECGstatus.setText(indicator.getDescription());
/*      */         
/*  863 */         this.jlabelECGResult1.setText(this.data.ecg.getHeartRate() + " bpm");
/*  864 */         break;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */       case ECG_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/*  872 */         this.jLabelECGstatus.setText(indicator.getDescription());
/*      */         
/*  874 */         this.jlabelECGResult1.setText(this.data.ecg.getHeartRate() + " bpm");
/*  875 */         System.out.println("Results: Heart Rate " + this.data.ecg.getHeartRate() + " bpm");
/*      */         
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  882 */         this.mg_ecg.insertData(discrimitator(this.data.ecg.getBuffer()));
/*      */         
/*  884 */         break;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */       case SPR_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/*  892 */         this.jLabelSPIstatus.setText(indicator.getDescription());
/*      */         
/*      */ 
/*  895 */         this.jlabelSPIResult1.setText("FIVC:" + this.data.spirometry.getFIVC() + " [l]");
/*      */         
/*  897 */         this.jlabelSPIResult2.setText("PIF:" + this.data.spirometry.getPIF() + " [l/s]");
/*      */         
/*  899 */         this.jlabelSPIResult3.setText("FEV:" + this.data.spirometry.getFEV1() + " [l]");
/*      */         
/*  901 */         this.jlabelSPIResult4.setText("FVC:" + this.data.spirometry.getFVC() + " [l]");
/*      */         
/*  903 */         this.jlabelSPIResult5.setText("FET:" + this.data.spirometry.getFET() + " [s]");
/*      */         
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  919 */         break;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */       case POX_MEASUREMENT_COMPLETE_OK: 
/*  926 */         this.jLabelSPO2status.setText(indicator.getDescription());
/*      */         
/*  928 */         this.jlabelSPO2Result1.setText("Sp02: " + this.data.pulse_oximetry.getOxigenSaturation() + "%");
/*      */         
/*  930 */         this.jlabelSPO2Result2.setText("Heart rate: " + this.data.pulse_oximetry.getHeartRate() + " bpm");
/*  931 */         System.out.println("Results: Patient sp02 " + this.data.pulse_oximetry.getOxigenSaturation() + "%, Heart rate: " + this.data.pulse_oximetry.getHeartRate() + " bpm");
/*      */         
/*  933 */         break;
/*      */       
/*      */ 
/*      */       case POX_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/*  937 */         this.jLabelSPO2status.setText(indicator.getDescription());
/*      */         
/*  939 */         this.jlabelSPO2Result1.setText("Sp02 " + this.data.pulse_oximetry.getOxigenSaturation() + "%");
/*      */         
/*  941 */         this.jlabelSPO2Result2.setText("Heart rate: " + this.data.pulse_oximetry.getHeartRate() + " bpm");
/*  942 */         System.out.println("Results: Patient sp02 " + this.data.pulse_oximetry.getOxigenSaturation() + "%, Heart rate: " + this.data.pulse_oximetry.getHeartRate() + " bpm");
/*      */         
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  949 */         this.mg_spo2.insertData(discrimitator(this.data.pulse_oximetry.getBuffer()));
/*      */         
/*  951 */         break;
/*      */       
/*      */       case BPM_SEND_PRESSURE_VALUE_TO_PC: 
/*  954 */         this.jlabelBPMStatus2.setText(indicator.getDescription());
/*      */         
/*  956 */         this.jlabelBPMResult6.setText("Pressure " + this.data.blood_pressure.getPressure());
/*      */       }
/*      */       
/*      */     }
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*      */   private Integer[] Int2Integer(int[] array)
/*      */   {
/*  966 */     int num = array.length;
/*  967 */     Integer[] boxed = new Integer[num];
/*      */     
/*  969 */     for (int ct = 0; ct < num; ct++) {
/*  970 */       boxed[ct] = Integer.valueOf(array[ct]);
/*      */     }
/*      */     
/*  973 */     return boxed;
/*      */   }
/*      */   
/*      */   private Integer[] SprInt2Integer(int[] array)
/*      */   {
/*  978 */     int num = array.length;
/*  979 */     Integer[] boxed = new Integer[num];
/*      */     
/*  981 */     for (int ct = 0; ct < num; ct++) {
/*  982 */       boxed[ct] = Integer.valueOf((array[ct] - 2000) * 10 + 1000);
/*      */     }
/*      */     
/*  985 */     return boxed;
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*  990 */   protected String bp_icon_path = "/GUI/Images/bpm_dark.png";
/*  991 */   protected String glu_icon_path = "/GUI/Images/glu_dark.png";
/*  992 */   protected String spr_icon_path = "/GUI/Images/spir_dark.png";
/*  993 */   protected String pox_icon_path = "/GUI/Images/spo2_dark.png";
/*  994 */   protected String ecg_icon_path = "/GUI/Images/ecg_dark.png";
/*      */   
/*      */ 
/*      */ 
/*  998 */   protected String bp_blue_icon_path = "/GUI/Images/bpm_clear.png";
/*  999 */   protected String glu_blue_icon_path = "/GUI/Images/glu_clear.png";
/* 1000 */   protected String spr_blue_icon_path = "/GUI/Images/spir_clear.png";
/* 1001 */   protected String pox_blue_icon_path = "/GUI/Images/spo2_clear.png";
/* 1002 */   protected String ecg_blue_icon_path = "/GUI/Images/ecg_clear.png";
/*      */   
/*      */ 
/*      */ 
/*      */   protected void restoreComponents()
/*      */   {
/* 1008 */     this.jbuttonBloodPressure.setIcon(new ImageIcon(getClass().getResource(this.bp_icon_path)));
/* 1009 */     this.jbuttonGlucometry.setIcon(new ImageIcon(getClass().getResource(this.glu_icon_path)));
/* 1010 */     this.jbuttonSpirometry.setIcon(new ImageIcon(getClass().getResource(this.spr_icon_path)));
/* 1011 */     this.jbuttonPulseOximetryDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.pox_icon_path)));
/* 1012 */     this.jbuttonHeartRateDiagnostic.setIcon(new ImageIcon(getClass().getResource(this.ecg_icon_path)));
/*      */   }
/*      */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\DoctorInterface.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */