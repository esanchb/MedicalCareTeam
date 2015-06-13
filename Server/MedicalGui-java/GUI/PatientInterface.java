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
/*      */ import Medical.Types.Indication;
/*      */ import Medical.Types.Measurement;
/*      */ import Medical.Types.Request;
/*      */ import java.awt.Color;
/*      */ import java.awt.Container;
/*      */ import java.awt.Dimension;
/*      */ import java.awt.Font;
/*      */ import java.awt.Rectangle;
/*      */ import java.awt.Toolkit;
/*      */ import java.awt.event.ActionEvent;
/*      */ import java.awt.event.ActionListener;
/*      */ import java.io.PrintStream;
/*      */ import javax.swing.BorderFactory;
/*      */ import javax.swing.GroupLayout;
/*      */ import javax.swing.GroupLayout.Alignment;
/*      */ import javax.swing.GroupLayout.ParallelGroup;
/*      */ import javax.swing.GroupLayout.SequentialGroup;
/*      */ import javax.swing.ImageIcon;
/*      */ import javax.swing.JButton;
/*      */ import javax.swing.JLabel;
/*      */ import javax.swing.JLayeredPane;
/*      */ import javax.swing.JPanel;
/*      */ import javax.swing.LayoutStyle.ComponentPlacement;
/*      */ 
/*      */ public class PatientInterface extends javax.swing.JFrame implements Medical.MedicalCommandListener
/*      */ {
/*   39 */   protected String wellcome_instructions_image = "/GUI/Images/Instructions_Eng/instructions_welcome_english.jpg";
/*   40 */   protected String glu1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_glucometria_english_01.jpg";
/*   41 */   protected String glu2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_glucometria_english_02.jpg";
/*   42 */   protected String glu3_instructions_image = "/GUI/Images/Instructions_Eng/instructions_glucometria_english_03.jpg";
/*   43 */   protected String glu4_instructions_image = "/GUI/Images/Instructions_Eng/instructions_glucometria_english_04.jpg";
/*   44 */   protected String glu5_instructions_image = "/GUI/Images/Instructions_Eng/instructions_glucometria_english_05.jpg";
/*   45 */   protected String spr1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_espirometria_english_01.jpg";
/*   46 */   protected String spr2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_espirometria_english_02.jpg";
/*   47 */   protected String spr3_instructions_image = "/GUI/Images/Instructions_Eng/instructions_espirometria_english_03.jpg";
/*   48 */   protected String height1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_alturapeso_english_01.jpg";
/*   49 */   protected String height2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_alturapeso_english_02.jpg";
/*   50 */   protected String weight1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_alturapeso_english_01.jpg";
/*   51 */   protected String weight2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_alturapeso_english_02.jpg";
/*   52 */   protected String temp1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_temperatura_english_01.jpg";
/*   53 */   protected String temp2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_temperatura_english_02.jpg";
/*   54 */   protected String temp3_instructions_image = "/GUI/Images/Instructions_Eng/instructions_temperatura_english_03.jpg";
/*   55 */   protected String bp1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_BP_english_01.jpg";
/*   56 */   protected String bp2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_BP_english_02.jpg";
/*   57 */   protected String bp3_instructions_image = "/GUI/Images/Instructions_Eng/instructions_BP_english_03.jpg";
/*   58 */   protected String ecg1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_ecg_english_01.jpg";
/*   59 */   protected String ecg2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_ecg_english_02.jpg";
/*   60 */   protected String pox1_instructions_image = "/GUI/Images/Instructions_Eng/instructions_SpO2_english_01.jpg";
/*   61 */   protected String pox2_instructions_image = "/GUI/Images/Instructions_Eng/instructions_SpO2_english_02.jpg";
/*   62 */   protected String glu_button_image = "/GUI/Images/Welcome_Bottom_Glu.jpg";
/*   63 */   protected String pox_button_image = "/GUI/Images/Welcome_Bottom_SpO2.jpg";
/*   64 */   protected String ecg_button_image = "/GUI/Images/Welcome_Bottom_ECG.jpg";
/*   65 */   protected String bp_button_image = "/GUI/Images/Welcome_Bottom_BP.jpg";
/*   66 */   protected String temp_button_image = "/GUI/Images/Welcome_Bottom_Temp.jpg";
/*   67 */   protected String weight_button_image = "/GUI/Images/Welcome_Bottom_Weight.jpg";
/*   68 */   protected String height_button_image = "/GUI/Images/Welcome_Bottom_Height.jpg";
/*   69 */   protected String spr_button_image = "/GUI/Images/Welcome_Bottom_Spir.jpg";
/*   70 */   protected String welcome_button_image = "/GUI/Images/Welcome_Bottom.jpg";
/*      */   
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*   78 */   private int video_number = 0;
/*   79 */   private Types.Measurement currentMeasurement = Types.Measurement.NONE;
/*   80 */   private MediaClient player = null;
/*      */   
/*      */   private MedicalCommander medical_commander;
/*      */   
/*      */   private MedicalControl medicalControl;
/*      */   
/*      */   private DataFromCommander datap;
/*      */   
/*   88 */   private boolean b_ecg_started = false;
/*   89 */   private boolean b_spirometry_started = false;
/*      */   private MedicalGraph mgp;
/*      */   private MedicalGraph mgp_spr;
/*      */   private Integer[] testDataY;
/*      */   private Integer[] testDataX;
/*      */   private javax.swing.Timer timer;
/*   95 */   private int i_graph_width = 400;
/*   96 */   private int i_graph_height = 100;
/*      */   private JLayeredPane jLayerGraph2;
/*      */   private JPanel jPanel13;
/*      */   private JPanel jPanel2;
/*      */   private JButton jbuttonBloodPresure;
/*      */   private JButton jbuttonContinue;
/*      */   private JButton jbuttonExit;
/*      */   
/*  104 */   private Integer[] discrimitator(int[] buffer) { int ratio = 8;
/*  105 */     int modulus = buffer.length / ratio;
/*      */     Integer[] temp_array;
/*  107 */     Integer[] temp_array; if (modulus == 0) {
/*  108 */       temp_array = new Integer[buffer.length / ratio];
/*      */     } else {
/*  110 */       temp_array = new Integer[(buffer.length - modulus) / ratio];
/*      */     }
/*      */     
/*  113 */     int count = 0; for (int count1 = 0; count1 < temp_array.length; count1++) {
/*  114 */       int temp_start = buffer[count];
/*  115 */       int temp_actual = buffer[count];
/*  116 */       int temp_delta = 0;
/*  117 */       for (int count2 = count; count2 < count + ratio; count2++) {
/*  118 */         if (temp_delta < Math.abs(temp_start - buffer[count2])) {
/*  119 */           temp_actual = buffer[count2];
/*  120 */           temp_delta = Math.abs(temp_start - buffer[count2]);
/*      */         }
/*      */       }
/*      */       
/*  124 */       temp_array[count1] = Integer.valueOf(temp_actual);count += ratio;
/*      */     }
/*      */     
/*      */ 
/*  128 */     return temp_array;
/*      */   }
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
/*      */   public PatientInterface(MedicalCommander medical_commander, MedicalControl medical_control, MediaClient media_player)
/*      */   {
/*  144 */     initComponents();
/*  145 */     this.medical_commander = medical_commander;
/*  146 */     this.medicalControl = medical_control;
/*  147 */     this.player = media_player;
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
/*  161 */     this.mgp_spr = new MedicalGraph(1, this.i_graph_width, this.i_graph_height);
/*  162 */     this.mgp_spr.setBorder(BorderFactory.createLineBorder(Color.BLACK));
/*  163 */     this.mgp_spr.setBackground(Color.LIGHT_GRAY);
/*  164 */     this.jLayerGraph2.add(this.mgp_spr);
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */   private JButton jbuttonGlucometry;
/*      */   
/*      */ 
/*      */ 
/*      */ 
/*      */   private JButton jbuttonHeight;
/*      */   
/*      */ 
/*      */ 
/*      */   private JButton jbuttonOximetry;
/*      */   
/*      */ 
/*      */ 
/*      */   private JButton jbuttonPulseRate;
/*      */   
/*      */ 
/*      */ 
/*      */   private JButton jbuttonSpirometry;
/*      */   
/*      */ 
/*      */ 
/*      */   private JButton jbuttonTemperature;
/*      */   
/*      */ 
/*      */ 
/*      */   private void lockButtons()
/*      */   {
/*  198 */     this.jbuttonBloodPresure.setEnabled(false);
/*  199 */     this.jbuttonContinue.setEnabled(false);
/*  200 */     this.jbuttonExit.setEnabled(false);
/*  201 */     this.jbuttonGlucometry.setEnabled(false);
/*  202 */     this.jbuttonHeight.setEnabled(false);
/*  203 */     this.jbuttonOximetry.setEnabled(false);
/*      */     
/*  205 */     this.jbuttonPulseRate.setEnabled(false);
/*  206 */     this.jbuttonSpirometry.setEnabled(false);
/*  207 */     this.jbuttonTemperature.setEnabled(false);
/*  208 */     this.jbuttonWeight.setEnabled(false);
/*      */   }
/*      */   
/*      */   private void unLockButtons() {
/*  212 */     this.jbuttonBloodPresure.setEnabled(true);
/*  213 */     this.jbuttonContinue.setEnabled(true);
/*  214 */     this.jbuttonExit.setEnabled(true);
/*  215 */     this.jbuttonGlucometry.setEnabled(true);
/*  216 */     this.jbuttonHeight.setEnabled(true);
/*  217 */     this.jbuttonOximetry.setEnabled(true);
/*      */     
/*  219 */     this.jbuttonPulseRate.setEnabled(true);
/*  220 */     this.jbuttonSpirometry.setEnabled(true);
/*  221 */     this.jbuttonTemperature.setEnabled(true);
/*  222 */     this.jbuttonWeight.setEnabled(true);
/*      */   }
/*      */   
/*      */ 
/*      */   public void noneMeasurement()
/*      */   {
/*  228 */     this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.wellcome_instructions_image)));
/*  229 */     this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.welcome_button_image)));
/*  230 */     this.currentMeasurement = Types.Measurement.NONE;
/*  231 */     this.video_number = 1;
/*      */   }
/*      */   
/*      */   public boolean playVideo(Types.Measurement videoToPlay, int number)
/*      */   {
/*  236 */     if (this.currentMeasurement != videoToPlay) {
/*  237 */       this.currentMeasurement = videoToPlay;
/*  238 */       this.jlabelStatus.setText("");
/*  239 */       this.jlabelResult1.setText("");
/*  240 */       this.jlabelResult2.setText("");
/*  241 */       this.jlabelResult3.setText("");
/*  242 */       this.jlabelResult4.setText("");
/*  243 */       this.jlabelResult5.setText("");
/*      */     }
/*      */     
/*  246 */     this.video_number = number;
/*      */     
/*  248 */     switch (videoToPlay) {
/*      */     case HEIGHT: 
/*  250 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.height_button_image)));
/*      */       
/*  252 */       switch (number) {
/*      */       case 1: 
/*  254 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.height1_instructions_image)));
/*      */         
/*  256 */         return true;
/*      */       
/*      */       case 2: 
/*  259 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.height2_instructions_image)));
/*      */         
/*  261 */         return true;
/*      */       
/*      */       case 3: 
/*  264 */         this.medical_commander.startHeight();
/*  265 */         this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  266 */         lockButtons();
/*  267 */         return true;
/*      */       
/*      */       case 4: 
/*  270 */         noneMeasurement();
/*  271 */         return true;
/*      */       }
/*      */       
/*  274 */       return false;
/*      */     
/*      */ 
/*      */ 
/*      */     case WEIGHT: 
/*  279 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.weight_button_image)));
/*      */       
/*  281 */       switch (number) {
/*      */       case 1: 
/*  283 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.weight1_instructions_image)));
/*      */         
/*  285 */         return true;
/*      */       
/*      */       case 2: 
/*  288 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.weight2_instructions_image)));
/*      */         
/*  290 */         return true;
/*      */       
/*      */       case 3: 
/*  293 */         this.medical_commander.startWeight();
/*  294 */         this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  295 */         lockButtons();
/*  296 */         return true;
/*      */       
/*      */       case 4: 
/*  299 */         noneMeasurement();
/*  300 */         return true;
/*      */       }
/*      */       
/*  303 */       return false;
/*      */     
/*      */ 
/*      */     case TEMPERATURE: 
/*  307 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.temp_button_image)));
/*      */       
/*  309 */       switch (number) {
/*      */       case 1: 
/*  311 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.temp1_instructions_image)));
/*      */         
/*  313 */         return true;
/*      */       
/*      */       case 2: 
/*  316 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.temp2_instructions_image)));
/*      */         
/*  318 */         return true;
/*      */       
/*      */       case 3: 
/*  321 */         this.medical_commander.startTemperature();
/*  322 */         this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  323 */         lockButtons();
/*  324 */         return true;
/*      */       
/*      */       case 4: 
/*  327 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.temp3_instructions_image)));
/*      */         
/*  329 */         return true;
/*      */       
/*      */       case 5: 
/*  332 */         noneMeasurement();
/*  333 */         return true;
/*      */       }
/*      */       
/*  336 */       return false;
/*      */     
/*      */ 
/*      */     case BLOODPRESSURE: 
/*  340 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.bp_button_image)));
/*      */       
/*  342 */       switch (number) {
/*      */       case 1: 
/*  344 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.bp1_instructions_image)));
/*      */         
/*  346 */         return true;
/*      */       
/*      */       case 2: 
/*  349 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.bp2_instructions_image)));
/*      */         
/*  351 */         return true;
/*      */       
/*      */       case 3: 
/*  354 */         this.medical_commander.startBloodPressure();
/*  355 */         this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  356 */         lockButtons();
/*  357 */         return true;
/*      */       
/*      */       case 4: 
/*  360 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.bp3_instructions_image)));
/*      */         
/*  362 */         return true;
/*      */       
/*      */       case 5: 
/*  365 */         noneMeasurement();
/*  366 */         return true;
/*      */       }
/*      */       
/*  369 */       return false;
/*      */     
/*      */ 
/*      */ 
/*      */     case HEARTRATE: 
/*  374 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.ecg_button_image)));
/*      */       
/*  376 */       switch (number) {
/*      */       case 1: 
/*  378 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.ecg1_instructions_image)));
/*      */         
/*  380 */         return true;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */       case 2: 
/*  388 */         if (!this.b_ecg_started)
/*      */         {
/*  390 */           this.mgp_spr.setVisible(false);
/*  391 */           this.mgp.setVisible(true);
/*  392 */           this.mgp.pauseAnimation();
/*  393 */           this.mgp.clearData();
/*  394 */           this.mgp.setMinValue(64536);
/*  395 */           this.mgp.setMaxValue(35000);
/*  396 */           this.mgp.setQueueSize(200);
/*  397 */           this.mgp.revalidateGraph();
/*  398 */           this.mgp.startAnimation();
/*      */           
/*      */ 
/*      */ 
/*  402 */           this.medical_commander.startECGDiagnostic();
/*  403 */           this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  404 */           this.b_ecg_started = true;
/*      */         }
/*  406 */         lockButtons();
/*  407 */         return true;
/*      */       
/*      */ 
/*      */       case 3: 
/*  411 */         if (this.b_ecg_started == true)
/*      */         {
/*  413 */           this.mgp.pauseAnimation();
/*      */           
/*  415 */           this.medical_commander.stopECGDiagnostic();
/*      */           
/*  417 */           this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  418 */           this.b_ecg_started = false;
/*      */         }
/*  420 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.ecg2_instructions_image)));
/*      */         
/*  422 */         return true;
/*      */       
/*      */       case 4: 
/*  425 */         noneMeasurement();
/*  426 */         return true;
/*      */       }
/*      */       
/*  429 */       return false;
/*      */     
/*      */ 
/*      */ 
/*      */     case PULSEOXIMETRY: 
/*  434 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.pox_button_image)));
/*      */       
/*  436 */       switch (number) {
/*      */       case 1: 
/*  438 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.pox1_instructions_image)));
/*      */         
/*  440 */         return true;
/*      */       
/*      */       case 2: 
/*  443 */         this.medical_commander.startPulseOximetry();
/*  444 */         this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  445 */         lockButtons();
/*  446 */         return true;
/*      */       
/*      */       case 3: 
/*  449 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.pox2_instructions_image)));
/*      */         
/*  451 */         return true;
/*      */       
/*      */       case 4: 
/*  454 */         noneMeasurement();
/*  455 */         return true;
/*      */       }
/*      */       
/*  458 */       return false;
/*      */     
/*      */ 
/*      */ 
/*      */     case GLUCOMETRY: 
/*  463 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.glu_button_image)));
/*      */       
/*  465 */       switch (number) {
/*      */       case 1: 
/*  467 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.glu1_instructions_image)));
/*      */         
/*  469 */         return true;
/*      */       
/*      */       case 2: 
/*  472 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.glu2_instructions_image)));
/*      */         
/*  474 */         return true;
/*      */       
/*      */       case 3: 
/*  477 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.glu3_instructions_image)));
/*      */         
/*  479 */         return true;
/*      */       
/*      */       case 4: 
/*  482 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.glu4_instructions_image)));
/*      */         
/*  484 */         return true;
/*      */       
/*      */       case 5: 
/*  487 */         this.medical_commander.startGlucometry();
/*  488 */         this.jlabelStatus.setText("Measuring " + this.medical_commander.getRequestDescription());
/*  489 */         lockButtons();
/*  490 */         return true;
/*      */       
/*      */       case 6: 
/*  493 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.glu5_instructions_image)));
/*      */         
/*  495 */         return true;
/*      */       
/*      */       case 7: 
/*  498 */         noneMeasurement();
/*  499 */         return true;
/*      */       }
/*      */       
/*  502 */       return false;
/*      */     
/*      */ 
/*      */ 
/*      */     case SPIROMETRY: 
/*  507 */       this.jlabelExams.setIcon(new ImageIcon(getClass().getResource(this.spr_button_image)));
/*      */       
/*  509 */       switch (number) {
/*      */       case 1: 
/*  511 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.spr1_instructions_image)));
/*      */         
/*  513 */         return true;
/*      */       
/*      */       case 2: 
/*  516 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.spr2_instructions_image)));
/*      */         
/*  518 */         return true;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */       case 3: 
/*  527 */         this.mgp_spr.setVisible(true);
/*  528 */         this.mgp.setVisible(false);
/*  529 */         this.mgp_spr.pauseAnimation();
/*  530 */         this.mgp_spr.clearData();
/*  531 */         this.mgp_spr.setMinValue(-100);
/*  532 */         this.mgp_spr.setMaxValue(100);
/*  533 */         this.mgp_spr.setQueueSize(300);
/*  534 */         if (!this.b_spirometry_started)
/*      */         {
/*  536 */           this.medical_commander.startSpirometryDiagnostic();
/*  537 */           this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  538 */           this.b_spirometry_started = true;
/*      */         }
/*  540 */         lockButtons();
/*  541 */         return true;
/*      */       
/*      */ 
/*      */ 
/*      */       case 4: 
/*  546 */         if (this.b_spirometry_started == true)
/*      */         {
/*  548 */           this.medical_commander.stopSpirometryDiagnostic();
/*      */           
/*  550 */           this.jlabelStatus.setText(this.medical_commander.getRequestDescription());
/*  551 */           this.b_spirometry_started = false;
/*      */           
/*      */ 
/*  554 */           this.mgp_spr.insertData(this.datap.spirometry.getBufferFullVol(), this.datap.spirometry.getBufferFullFlow());
/*  555 */           this.datap.spirometry.newexam();
/*      */         }
/*      */         
/*  558 */         this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource(this.spr3_instructions_image)));
/*      */         
/*  560 */         return true;
/*      */       
/*      */       case 5: 
/*  563 */         noneMeasurement();
/*  564 */         return true;
/*      */       }
/*      */       
/*  567 */       return false;
/*      */     
/*      */ 
/*      */ 
/*      */ 
/*      */     case NONE: 
/*  573 */       noneMeasurement();
/*  574 */       return false;
/*      */     }
/*      */     
/*      */     
/*  578 */     return false;
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */   private void initComponents()
/*      */   {
/*  590 */     this.jPanel13 = new JPanel();
/*  591 */     this.jpanelInstructions = new JPanel();
/*  592 */     this.jlabelInstructions = new JLabel();
/*  593 */     this.jPanel2 = new JPanel();
/*  594 */     this.jpanelVideo = new JPanel();
/*  595 */     this.jlabelStatus = new JLabel();
/*  596 */     this.jlabelResult1 = new JLabel();
/*  597 */     this.jlabelResult2 = new JLabel();
/*  598 */     this.jlabelResult3 = new JLabel();
/*  599 */     this.jlabelResult4 = new JLabel();
/*  600 */     this.jlabelResult5 = new JLabel();
/*  601 */     this.jLayerGraph2 = new JLayeredPane();
/*  602 */     this.jbuttonContinue = new JButton();
/*  603 */     this.jbuttonExit = new JButton();
/*  604 */     this.jpanelExams = new JLayeredPane();
/*  605 */     this.jlabelExams = new JLabel();
/*  606 */     this.jbuttonSpirometry = new JButton();
/*  607 */     this.jbuttonGlucometry = new JButton();
/*  608 */     this.jbuttonOximetry = new JButton();
/*  609 */     this.jbuttonPulseRate = new JButton();
/*  610 */     this.jbuttonBloodPresure = new JButton();
/*  611 */     this.jbuttonTemperature = new JButton();
/*  612 */     this.jbuttonWeight = new JButton();
/*  613 */     this.jbuttonHeight = new JButton();
/*      */     
/*  615 */     setDefaultCloseOperation(3);
/*  616 */     setAlwaysOnTop(true);
/*  617 */     setBounds(new Rectangle(0, 0, 1024, 768));
/*  618 */     setMaximizedBounds(new Rectangle(0, 0, 1024, 768));
/*  619 */     setMinimumSize(new Dimension(1024, 768));
/*  620 */     setUndecorated(true);
/*  621 */     getContentPane().setLayout(null);
/*      */     
/*  623 */     this.jPanel13.setBackground(new Color(238, 238, 238));
/*  624 */     this.jPanel13.setBorder(BorderFactory.createEtchedBorder());
/*      */     
/*  626 */     this.jpanelInstructions.setBackground(new Color(238, 238, 238));
/*  627 */     this.jpanelInstructions.setBorder(BorderFactory.createTitledBorder(null, "Instructions", 0, 0, new Font("Calibri", 1, 24), new Color(63, 63, 63)));
/*      */     
/*  629 */     this.jlabelInstructions.setFont(new Font("Dialog", 0, 24));
/*  630 */     this.jlabelInstructions.setForeground(new Color(226, 54, 54));
/*  631 */     this.jlabelInstructions.setHorizontalAlignment(11);
/*  632 */     this.jlabelInstructions.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Instructions_Eng/instructions_welcome_english.jpg")));
/*  633 */     this.jlabelInstructions.setVerticalAlignment(1);
/*      */     
/*  635 */     GroupLayout jpanelInstructionsLayout = new GroupLayout(this.jpanelInstructions);
/*  636 */     this.jpanelInstructions.setLayout(jpanelInstructionsLayout);
/*  637 */     jpanelInstructionsLayout.setHorizontalGroup(jpanelInstructionsLayout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jpanelInstructionsLayout.createSequentialGroup().addContainerGap().addComponent(this.jlabelInstructions, -1, -1, 32767).addContainerGap()));
/*      */     
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  644 */     jpanelInstructionsLayout.setVerticalGroup(jpanelInstructionsLayout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jpanelInstructionsLayout.createSequentialGroup().addComponent(this.jlabelInstructions, -2, 450, -2).addContainerGap(48, 32767)));
/*      */     
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  651 */     this.jPanel2.setBackground(new Color(238, 238, 238));
/*  652 */     this.jPanel2.setBorder(BorderFactory.createTitledBorder(null, "Video", 0, 0, new Font("Calibri", 1, 24), new Color(63, 63, 63)));
/*      */     
/*  654 */     this.jpanelVideo.setBackground(new Color(0, 0, 0));
/*  655 */     this.jpanelVideo.setMaximumSize(new Dimension(576, 432));
/*  656 */     this.jpanelVideo.setMinimumSize(new Dimension(576, 432));
/*  657 */     this.jpanelVideo.setPreferredSize(new Dimension(576, 432));
/*      */     
/*  659 */     this.jlabelStatus.setBackground(new Color(0, 0, 0));
/*  660 */     this.jlabelStatus.setFont(new Font("Dialog", 0, 24));
/*  661 */     this.jlabelStatus.setForeground(new Color(184, 55, 59));
/*  662 */     this.jlabelStatus.setHorizontalAlignment(0);
/*  663 */     this.jlabelStatus.setVerticalAlignment(1);
/*  664 */     this.jlabelStatus.setFocusable(false);
/*  665 */     this.jlabelStatus.setHorizontalTextPosition(0);
/*  666 */     this.jlabelStatus.setRequestFocusEnabled(false);
/*      */     
/*  668 */     this.jlabelResult1.setBackground(new Color(0, 0, 0));
/*  669 */     this.jlabelResult1.setFont(new Font("Dialog", 0, 24));
/*  670 */     this.jlabelResult1.setForeground(new Color(184, 55, 59));
/*  671 */     this.jlabelResult1.setHorizontalAlignment(0);
/*  672 */     this.jlabelResult1.setFocusable(false);
/*  673 */     this.jlabelResult1.setHorizontalTextPosition(0);
/*  674 */     this.jlabelResult1.setRequestFocusEnabled(false);
/*      */     
/*  676 */     this.jlabelResult2.setBackground(new Color(0, 0, 0));
/*  677 */     this.jlabelResult2.setFont(new Font("Dialog", 0, 24));
/*  678 */     this.jlabelResult2.setForeground(new Color(184, 55, 59));
/*  679 */     this.jlabelResult2.setHorizontalAlignment(0);
/*  680 */     this.jlabelResult2.setFocusable(false);
/*  681 */     this.jlabelResult2.setHorizontalTextPosition(0);
/*  682 */     this.jlabelResult2.setRequestFocusEnabled(false);
/*      */     
/*  684 */     this.jlabelResult3.setBackground(new Color(0, 0, 0));
/*  685 */     this.jlabelResult3.setFont(new Font("Dialog", 0, 24));
/*  686 */     this.jlabelResult3.setForeground(new Color(184, 55, 59));
/*  687 */     this.jlabelResult3.setHorizontalAlignment(0);
/*  688 */     this.jlabelResult3.setFocusable(false);
/*  689 */     this.jlabelResult3.setHorizontalTextPosition(0);
/*  690 */     this.jlabelResult3.setRequestFocusEnabled(false);
/*      */     
/*  692 */     this.jlabelResult4.setBackground(new Color(0, 0, 0));
/*  693 */     this.jlabelResult4.setFont(new Font("Dialog", 0, 24));
/*  694 */     this.jlabelResult4.setForeground(new Color(184, 55, 59));
/*  695 */     this.jlabelResult4.setHorizontalAlignment(0);
/*  696 */     this.jlabelResult4.setFocusable(false);
/*  697 */     this.jlabelResult4.setHorizontalTextPosition(0);
/*  698 */     this.jlabelResult4.setRequestFocusEnabled(false);
/*      */     
/*  700 */     this.jlabelResult5.setBackground(new Color(0, 0, 0));
/*  701 */     this.jlabelResult5.setFont(new Font("Dialog", 0, 24));
/*  702 */     this.jlabelResult5.setForeground(new Color(184, 55, 59));
/*  703 */     this.jlabelResult5.setHorizontalAlignment(0);
/*  704 */     this.jlabelResult5.setFocusable(false);
/*  705 */     this.jlabelResult5.setHorizontalTextPosition(0);
/*  706 */     this.jlabelResult5.setRequestFocusEnabled(false);
/*      */     
/*  708 */     GroupLayout jpanelVideoLayout = new GroupLayout(this.jpanelVideo);
/*  709 */     this.jpanelVideo.setLayout(jpanelVideoLayout);
/*  710 */     jpanelVideoLayout.setHorizontalGroup(jpanelVideoLayout.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(this.jlabelStatus, -1, 576, 32767).addComponent(this.jlabelResult1, -1, 576, 32767).addComponent(this.jlabelResult2, -1, 576, 32767).addComponent(this.jlabelResult3, -1, 576, 32767).addComponent(this.jlabelResult4, -1, 576, 32767).addComponent(this.jlabelResult5, -1, 576, 32767));
/*      */     
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  719 */     jpanelVideoLayout.setVerticalGroup(jpanelVideoLayout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jpanelVideoLayout.createSequentialGroup().addComponent(this.jlabelStatus, -2, 57, -2).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addComponent(this.jlabelResult1, -2, 57, -2).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addComponent(this.jlabelResult2, -2, 57, -2).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addComponent(this.jlabelResult3, -2, 57, -2).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addComponent(this.jlabelResult4, -2, 57, -2).addGap(121, 121, 121).addComponent(this.jlabelResult5, -2, 57, -2).addContainerGap(-1, 32767)));
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
/*  736 */     GroupLayout jPanel2Layout = new GroupLayout(this.jPanel2);
/*  737 */     this.jPanel2.setLayout(jPanel2Layout);
/*  738 */     jPanel2Layout.setHorizontalGroup(jPanel2Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel2Layout.createSequentialGroup().addContainerGap().addComponent(this.jpanelVideo, -2, -1, -2).addContainerGap(-1, 32767)).addGroup(GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup().addContainerGap(73, 32767).addComponent(this.jLayerGraph2, -2, 463, -2).addGap(60, 60, 60)));
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
/*  749 */     jPanel2Layout.setVerticalGroup(jPanel2Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel2Layout.createSequentialGroup().addComponent(this.jpanelVideo, -2, 392, -2).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED, 9, 32767).addComponent(this.jLayerGraph2, -2, 97, -2)));
/*      */     
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*      */ 
/*  757 */     this.jbuttonContinue.setBackground(new Color(238, 238, 238));
/*  758 */     this.jbuttonContinue.setFont(new Font("Calibri", 1, 24));
/*  759 */     this.jbuttonContinue.setForeground(new Color(63, 63, 63));
/*  760 */     this.jbuttonContinue.setText("continue");
/*  761 */     this.jbuttonContinue.setBorder(BorderFactory.createBevelBorder(0));
/*  762 */     this.jbuttonContinue.setMaximumSize(new Dimension(144, 72));
/*  763 */     this.jbuttonContinue.setMinimumSize(new Dimension(144, 72));
/*  764 */     this.jbuttonContinue.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  766 */         PatientInterface.this.jbuttonContinueActionPerformed(evt);
/*      */       }
/*      */       
/*  769 */     });
/*  770 */     this.jbuttonExit.setBackground(new Color(238, 238, 238));
/*  771 */     this.jbuttonExit.setFont(new Font("Calibri", 1, 24));
/*  772 */     this.jbuttonExit.setForeground(new Color(63, 63, 63));
/*  773 */     this.jbuttonExit.setText("exit");
/*  774 */     this.jbuttonExit.setBorder(BorderFactory.createBevelBorder(0));
/*  775 */     this.jbuttonExit.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  777 */         PatientInterface.this.jbuttonExitActionPerformed(evt);
/*      */       }
/*      */       
/*  780 */     });
/*  781 */     GroupLayout jPanel13Layout = new GroupLayout(this.jPanel13);
/*  782 */     this.jPanel13.setLayout(jPanel13Layout);
/*  783 */     jPanel13Layout.setHorizontalGroup(jPanel13Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel13Layout.createSequentialGroup().addContainerGap().addGroup(jPanel13Layout.createParallelGroup(GroupLayout.Alignment.TRAILING).addComponent(this.jbuttonContinue, -2, 289, -2).addComponent(this.jpanelInstructions, -2, -1, -2)).addGroup(jPanel13Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel13Layout.createSequentialGroup().addGap(152, 152, 152).addComponent(this.jbuttonExit, -2, 271, -2)).addGroup(jPanel13Layout.createSequentialGroup().addPreferredGap(LayoutStyle.ComponentPlacement.UNRELATED).addComponent(this.jPanel2, -1, -1, 32767))).addContainerGap()));
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
/*  799 */     jPanel13Layout.setVerticalGroup(jPanel13Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel13Layout.createSequentialGroup().addContainerGap().addGroup(jPanel13Layout.createParallelGroup(GroupLayout.Alignment.LEADING, false).addComponent(this.jPanel2, -1, -1, 32767).addComponent(this.jpanelInstructions, -1, -1, 32767)).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED, -1, 32767).addGroup(jPanel13Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(this.jbuttonContinue, -2, 44, 32767).addComponent(this.jbuttonExit, -2, 44, -2)).addContainerGap()));
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
/*  813 */     getContentPane().add(this.jPanel13);
/*  814 */     this.jPanel13.setBounds(0, 0, 1024, 610);
/*      */     
/*  816 */     this.jpanelExams.setMaximumSize(new Dimension(1024, 200));
/*  817 */     this.jpanelExams.setMinimumSize(new Dimension(1024, 200));
/*      */     
/*  819 */     this.jlabelExams.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Bottom.jpg")));
/*  820 */     this.jlabelExams.setBounds(0, 40, 1040, 200);
/*  821 */     this.jpanelExams.add(this.jlabelExams, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  823 */     this.jbuttonSpirometry.setBorder(null);
/*  824 */     this.jbuttonSpirometry.setBorderPainted(false);
/*  825 */     this.jbuttonSpirometry.setContentAreaFilled(false);
/*  826 */     this.jbuttonSpirometry.setMaximumSize(new Dimension(72, 72));
/*  827 */     this.jbuttonSpirometry.setMinimumSize(new Dimension(72, 72));
/*  828 */     this.jbuttonSpirometry.setPreferredSize(new Dimension(72, 72));
/*  829 */     this.jbuttonSpirometry.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  831 */         PatientInterface.this.jbuttonSpirometryActionPerformed(evt);
/*      */       }
/*  833 */     });
/*  834 */     this.jbuttonSpirometry.setBounds(910, 20, 72, 72);
/*  835 */     this.jpanelExams.add(this.jbuttonSpirometry, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  837 */     this.jbuttonGlucometry.setBorder(null);
/*  838 */     this.jbuttonGlucometry.setBorderPainted(false);
/*  839 */     this.jbuttonGlucometry.setContentAreaFilled(false);
/*  840 */     this.jbuttonGlucometry.setMaximumSize(new Dimension(72, 72));
/*  841 */     this.jbuttonGlucometry.setMinimumSize(new Dimension(72, 72));
/*  842 */     this.jbuttonGlucometry.setPreferredSize(new Dimension(72, 72));
/*  843 */     this.jbuttonGlucometry.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  845 */         PatientInterface.this.jbuttonGlucometryActionPerformed(evt);
/*      */       }
/*  847 */     });
/*  848 */     this.jbuttonGlucometry.setBounds(780, 20, 72, 72);
/*  849 */     this.jpanelExams.add(this.jbuttonGlucometry, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  851 */     this.jbuttonOximetry.setBorder(null);
/*  852 */     this.jbuttonOximetry.setBorderPainted(false);
/*  853 */     this.jbuttonOximetry.setContentAreaFilled(false);
/*  854 */     this.jbuttonOximetry.setMaximumSize(new Dimension(72, 72));
/*  855 */     this.jbuttonOximetry.setMinimumSize(new Dimension(72, 72));
/*  856 */     this.jbuttonOximetry.setPreferredSize(new Dimension(72, 72));
/*  857 */     this.jbuttonOximetry.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  859 */         PatientInterface.this.jbuttonOximetryActionPerformed(evt);
/*      */       }
/*  861 */     });
/*  862 */     this.jbuttonOximetry.setBounds(660, 20, 72, 72);
/*  863 */     this.jpanelExams.add(this.jbuttonOximetry, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  865 */     this.jbuttonPulseRate.setBorder(null);
/*  866 */     this.jbuttonPulseRate.setBorderPainted(false);
/*  867 */     this.jbuttonPulseRate.setContentAreaFilled(false);
/*  868 */     this.jbuttonPulseRate.setMaximumSize(new Dimension(72, 72));
/*  869 */     this.jbuttonPulseRate.setMinimumSize(new Dimension(72, 72));
/*  870 */     this.jbuttonPulseRate.setPreferredSize(new Dimension(72, 72));
/*  871 */     this.jbuttonPulseRate.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  873 */         PatientInterface.this.jbuttonPulseRateActionPerformed(evt);
/*      */       }
/*  875 */     });
/*  876 */     this.jbuttonPulseRate.setBounds(540, 20, 72, 72);
/*  877 */     this.jpanelExams.add(this.jbuttonPulseRate, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  879 */     this.jbuttonBloodPresure.setBorder(null);
/*  880 */     this.jbuttonBloodPresure.setBorderPainted(false);
/*  881 */     this.jbuttonBloodPresure.setContentAreaFilled(false);
/*  882 */     this.jbuttonBloodPresure.setMaximumSize(new Dimension(72, 72));
/*  883 */     this.jbuttonBloodPresure.setMinimumSize(new Dimension(72, 72));
/*  884 */     this.jbuttonBloodPresure.setPreferredSize(new Dimension(72, 72));
/*  885 */     this.jbuttonBloodPresure.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  887 */         PatientInterface.this.jbuttonBloodPresureActionPerformed(evt);
/*      */       }
/*  889 */     });
/*  890 */     this.jbuttonBloodPresure.setBounds(410, 20, 72, 72);
/*  891 */     this.jpanelExams.add(this.jbuttonBloodPresure, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  893 */     this.jbuttonTemperature.setBorder(null);
/*  894 */     this.jbuttonTemperature.setBorderPainted(false);
/*  895 */     this.jbuttonTemperature.setContentAreaFilled(false);
/*  896 */     this.jbuttonTemperature.setMaximumSize(new Dimension(72, 72));
/*  897 */     this.jbuttonTemperature.setMinimumSize(new Dimension(72, 72));
/*  898 */     this.jbuttonTemperature.setPreferredSize(new Dimension(72, 72));
/*  899 */     this.jbuttonTemperature.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  901 */         PatientInterface.this.jbuttonTemperatureActionPerformed(evt);
/*      */       }
/*  903 */     });
/*  904 */     this.jbuttonTemperature.setBounds(290, 20, 72, 72);
/*  905 */     this.jpanelExams.add(this.jbuttonTemperature, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  907 */     this.jbuttonWeight.setBorder(null);
/*  908 */     this.jbuttonWeight.setBorderPainted(false);
/*  909 */     this.jbuttonWeight.setContentAreaFilled(false);
/*  910 */     this.jbuttonWeight.setMaximumSize(new Dimension(72, 72));
/*  911 */     this.jbuttonWeight.setMinimumSize(new Dimension(72, 72));
/*  912 */     this.jbuttonWeight.setPreferredSize(new Dimension(72, 72));
/*  913 */     this.jbuttonWeight.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  915 */         PatientInterface.this.jbuttonWeightActionPerformed(evt);
/*      */       }
/*  917 */     });
/*  918 */     this.jbuttonWeight.setBounds(170, 20, 72, 72);
/*  919 */     this.jpanelExams.add(this.jbuttonWeight, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  921 */     this.jbuttonHeight.setBorder(null);
/*  922 */     this.jbuttonHeight.setBorderPainted(false);
/*  923 */     this.jbuttonHeight.setContentAreaFilled(false);
/*  924 */     this.jbuttonHeight.setMaximumSize(new Dimension(72, 72));
/*  925 */     this.jbuttonHeight.setMinimumSize(new Dimension(72, 72));
/*  926 */     this.jbuttonHeight.setPreferredSize(new Dimension(72, 72));
/*  927 */     this.jbuttonHeight.addActionListener(new ActionListener() {
/*      */       public void actionPerformed(ActionEvent evt) {
/*  929 */         PatientInterface.this.jbuttonHeightActionPerformed(evt);
/*      */       }
/*  931 */     });
/*  932 */     this.jbuttonHeight.setBounds(40, 20, 72, 72);
/*  933 */     this.jpanelExams.add(this.jbuttonHeight, JLayeredPane.DEFAULT_LAYER);
/*      */     
/*  935 */     getContentPane().add(this.jpanelExams);
/*  936 */     this.jpanelExams.setBounds(0, 568, 1024, 200);
/*      */     
/*  938 */     Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
/*  939 */     setBounds((screenSize.width - 1024) / 2, (screenSize.height - 768) / 2, 1024, 768);
/*      */   }
/*      */   
/*      */   private void jbuttonGlucometryActionPerformed(ActionEvent evt)
/*      */   {
/*  944 */     playVideo(Types.Measurement.GLUCOMETRY, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonOximetryActionPerformed(ActionEvent evt)
/*      */   {
/*  949 */     playVideo(Types.Measurement.PULSEOXIMETRY, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonPulseRateActionPerformed(ActionEvent evt)
/*      */   {
/*  954 */     playVideo(Types.Measurement.HEARTRATE, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonBloodPresureActionPerformed(ActionEvent evt)
/*      */   {
/*  959 */     playVideo(Types.Measurement.BLOODPRESSURE, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonTemperatureActionPerformed(ActionEvent evt)
/*      */   {
/*  964 */     playVideo(Types.Measurement.TEMPERATURE, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonWeightActionPerformed(ActionEvent evt)
/*      */   {
/*  969 */     playVideo(Types.Measurement.WEIGHT, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonHeightActionPerformed(ActionEvent evt)
/*      */   {
/*  974 */     playVideo(Types.Measurement.HEIGHT, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonContinueActionPerformed(ActionEvent evt)
/*      */   {
/*  979 */     if (this.currentMeasurement != Types.Measurement.NONE) {
/*  980 */       this.video_number += 1;
/*  981 */       if (!playVideo(this.currentMeasurement, this.video_number)) {
/*  982 */         this.video_number -= 1;
/*      */       }
/*      */     }
/*  985 */     System.out.println("Info: Continue button pressed currentMeasurement " + this.currentMeasurement + " video_number " + this.video_number);
/*      */   }
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
/*      */   private void jbuttonSpirometryActionPerformed(ActionEvent evt)
/*      */   {
/* 1004 */     playVideo(Types.Measurement.SPIROMETRY, 1);
/*      */   }
/*      */   
/*      */   private void jbuttonExitActionPerformed(ActionEvent evt)
/*      */   {
/* 1009 */     if (!this.player.videoIsPlaying()) {
/* 1010 */       this.medicalControl.showLogin();
/*      */     }
/*      */   }
/*      */   
/*      */ 
/*      */ 
/*      */   private JButton jbuttonWeight;
/*      */   
/*      */ 
/*      */   private JLabel jlabelExams;
/*      */   
/*      */ 
/*      */   private JLabel jlabelInstructions;
/*      */   
/*      */ 
/*      */   private JLabel jlabelResult1;
/*      */   
/*      */ 
/*      */   private JLabel jlabelResult2;
/*      */   
/*      */ 
/*      */   private JLabel jlabelResult3;
/*      */   
/*      */ 
/*      */   private JLabel jlabelResult4;
/*      */   
/*      */ 
/*      */   private JLabel jlabelResult5;
/*      */   
/*      */ 
/*      */   private JLabel jlabelStatus;
/*      */   
/*      */ 
/*      */   private JLayeredPane jpanelExams;
/*      */   
/*      */ 
/*      */   private JPanel jpanelInstructions;
/*      */   
/*      */ 
/*      */   private JPanel jpanelVideo;
/*      */   
/*      */   public void medicalCommandDataAvailable(CommandEvent evt)
/*      */   {
/* 1053 */     this.datap = evt.getMedicalData();
/* 1054 */     Types.Request request = this.datap.getRequest();
/* 1055 */     Types.Indication indicator = this.datap.getIndicator();
/*      */     
/* 1057 */     if (request != Types.Request.NONE) {
/* 1058 */       switch (request) {
/*      */       case TMP_READ_TEMPERATURE: 
/* 1060 */         this.jlabelStatus.setText(request.getDescription());
/* 1061 */         this.jlabelResult1.setText(" Temperature " + this.datap.temperature.get() / 100.0F + " Celcius degrees ");
/* 1062 */         unLockButtons();
/* 1063 */         break;
/*      */       case HGT_READ_HEIGHT: 
/* 1065 */         this.jlabelStatus.setText(request.getDescription());
/* 1066 */         this.jlabelResult1.setText(" Height " + this.datap.height.get() + " cm ");
/* 1067 */         unLockButtons();
/* 1068 */         break;
/*      */       case WGT_READ_WEIGHT: 
/* 1070 */         this.jlabelStatus.setText(request.getDescription());
/* 1071 */         this.jlabelResult1.setText(" Weight " + this.datap.weight.get() + " kgr ");
/* 1072 */         unLockButtons();
/*      */       }
/*      */       
/* 1075 */     } else if (indicator != Types.Indication.NONE) {
/* 1076 */       switch (indicator)
/*      */       {
/*      */ 
/*      */ 
/*      */ 
/*      */       case GLU_MEASUREMENT_COMPLETE_OK: 
/* 1082 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1083 */         this.jlabelResult1.setText(" Glucose Level " + this.datap.glucometry.getGlucoseLevel() + " units ");
/* 1084 */         unLockButtons();
/* 1085 */         break;
/*      */       case GLU_CALIBRATION_COMPLETE_OK: 
/* 1087 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1088 */         this.jlabelResult1.setText(" Glucometry calibration parameter " + this.datap.glucometry.getGlucoseLevel() + " units ");
/*      */         
/* 1090 */         unLockButtons();
/* 1091 */         break;
/*      */       case BPM_MEASUREMENT_COMPLETE_OK: 
/* 1093 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1094 */         this.jlabelResult1.setText(" Sistolic pressure:" + this.datap.blood_pressure.getSistolic());
/* 1095 */         this.jlabelResult2.setText(" Diastolic pressure:" + this.datap.blood_pressure.getDiastolic());
/* 1096 */         this.jlabelResult3.setText(" Heart Rate:" + this.datap.blood_pressure.getHeartRate());
/* 1097 */         this.jlabelResult4.setText(" Mean pressure:" + this.datap.blood_pressure.getMeanPressure());
/* 1098 */         unLockButtons();
/* 1099 */         break;
/*      */       case BPM_LEAK_TEST_COMPLETE: 
/* 1101 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1102 */         this.jlabelResult1.setText("BMP Leak test " + this.datap.blood_pressure.getLeakTestResult());
/* 1103 */         unLockButtons();
/* 1104 */         break;
/*      */       case BPM_MEASUREMENT_ERROR: 
/* 1106 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1107 */         this.jlabelResult1.setText("Description " + this.datap.blood_pressure.getErrorCode().getDescription());
/* 1108 */         unLockButtons();
/* 1109 */         break;
/*      */       case ECG_HEART_RATE_MEASUREMENT_COMPLETE_OK: 
/* 1111 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1112 */         this.jlabelResult1.setText(" HeartRate " + this.datap.ecg.getHeartRate() + " bpm");
/* 1113 */         unLockButtons();
/* 1114 */         break;
/*      */       
/*      */ 
/*      */ 
/*      */ 
/*      */       case ECG_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/* 1120 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1121 */         this.jlabelResult1.setText(" HeartRate " + this.datap.ecg.getHeartRate() + " bpm");
/* 1122 */         System.out.println("Results: Patient Heart Rate " + this.datap.ecg.getHeartRate() + " bpm");
/*      */         
/* 1124 */         this.mgp.insertData(discrimitator(this.datap.ecg.getBuffer()));
/*      */         
/*      */ 
/*      */ 
/* 1128 */         unLockButtons();
/* 1129 */         break;
/*      */       
/*      */       case SPR_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/* 1132 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1133 */         this.jlabelResult1.setText(" FIVC:" + this.datap.spirometry.getFIVC() + " [l]");
/* 1134 */         this.jlabelResult2.setText(" PIF:" + this.datap.spirometry.getPIF() + " [l/s]");
/* 1135 */         this.jlabelResult3.setText(" FEV:" + this.datap.spirometry.getFEV1() + " [l]");
/* 1136 */         this.jlabelResult4.setText(" FVC:" + this.datap.spirometry.getFVC() + " [l]");
/* 1137 */         this.jlabelResult5.setText(" FET:" + this.datap.spirometry.getFET() + " [s]");
/*      */         
/*      */ 
/*      */ 
/* 1141 */         unLockButtons();
/* 1142 */         break;
/*      */       case POX_MEASUREMENT_COMPLETE_OK: 
/* 1144 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1145 */         this.jlabelResult1.setText(" Sp02 " + this.datap.pulse_oximetry.getOxigenSaturation() + "%");
/* 1146 */         this.jlabelResult2.setText(" Heart rate: " + this.datap.pulse_oximetry.getHeartRate() + " bpm");
/* 1147 */         System.out.println("Results: Patient sp02 " + this.datap.pulse_oximetry.getOxigenSaturation() + "%, Heart rate: " + this.datap.pulse_oximetry.getHeartRate() + " bpm");
/*      */         
/* 1149 */         unLockButtons();
/* 1150 */         break;
/*      */       
/*      */       case POX_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/* 1153 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1154 */         this.jlabelResult1.setText(" Sp02 " + this.datap.pulse_oximetry.getOxigenSaturation() + "%");
/* 1155 */         this.jlabelResult2.setText(" Heart rate: " + this.datap.pulse_oximetry.getHeartRate() + " bpm");
/* 1156 */         System.out.println("Results: Patient sp02 " + this.datap.pulse_oximetry.getOxigenSaturation() + "%, Heart rate: " + this.datap.pulse_oximetry.getHeartRate() + " bpm");
/*      */         
/* 1158 */         unLockButtons();
/* 1159 */         break;
/*      */       case BPM_SEND_PRESSURE_VALUE_TO_PC: 
/* 1161 */         this.jlabelStatus.setText(indicator.getDescription());
/* 1162 */         this.jlabelResult1.setText(" Bracelet pressure " + this.datap.blood_pressure.getPressure());
/*      */       
/*      */       }
/*      */       
/*      */     } else {
/* 1167 */       unLockButtons();
/*      */     }
/*      */   }
/*      */   
/*      */   private Integer[] Int2Integer(int[] array) {
/* 1172 */     int num = array.length;
/* 1173 */     Integer[] boxed = new Integer[num];
/*      */     
/* 1175 */     for (int ct = 0; ct < num; ct++) {
/* 1176 */       boxed[ct] = Integer.valueOf(array[ct]);
/*      */     }
/*      */     
/* 1179 */     return boxed;
/*      */   }
/*      */   
/*      */   private Integer[] SprInt2Integer(int[] array)
/*      */   {
/* 1184 */     int num = array.length;
/* 1185 */     Integer[] boxed = new Integer[num];
/*      */     
/* 1187 */     for (int ct = 0; ct < num; ct++) {
/* 1188 */       boxed[ct] = Integer.valueOf((array[ct] - 2000) * 10 + 1000);
/*      */     }
/*      */     
/* 1191 */     return boxed;
/*      */   }
/*      */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\PatientInterface.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */