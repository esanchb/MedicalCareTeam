/*     */ package GUI;
/*     */ 
/*     */ import Medical.MedicalControl;
/*     */ import java.awt.Color;
/*     */ import java.awt.Container;
/*     */ import java.awt.Cursor;
/*     */ import java.awt.Dimension;
/*     */ import java.awt.Font;
/*     */ import java.awt.GridLayout;
/*     */ import java.awt.Rectangle;
/*     */ import java.awt.Toolkit;
/*     */ import java.awt.event.ActionEvent;
/*     */ import java.awt.event.ActionListener;
/*     */ import java.awt.event.FocusAdapter;
/*     */ import java.awt.event.FocusEvent;
/*     */ import java.awt.event.KeyAdapter;
/*     */ import java.awt.event.KeyEvent;
/*     */ import java.awt.event.MouseAdapter;
/*     */ import java.awt.event.MouseEvent;
/*     */ import java.io.PrintStream;
/*     */ import javax.swing.GroupLayout;
/*     */ import javax.swing.GroupLayout.Alignment;
/*     */ import javax.swing.GroupLayout.ParallelGroup;
/*     */ import javax.swing.GroupLayout.SequentialGroup;
/*     */ import javax.swing.ImageIcon;
/*     */ import javax.swing.JButton;
/*     */ import javax.swing.JFrame;
/*     */ import javax.swing.JLabel;
/*     */ import javax.swing.JPanel;
/*     */ import javax.swing.LayoutStyle.ComponentPlacement;
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
/*     */ public class Login
/*     */   extends JFrame
/*     */ {
/*     */   private int language;
/*     */   private String keypad_buffer;
/*     */   private String user_name;
/*     */   private boolean user_type;
/*     */   private String gender;
/*     */   private String birthdate;
/*  56 */   private MediaClient player = null;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private MedicalControl medicalControl;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JButton jButton1;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JLabel jLabel1;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JLabel jLabel2;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JLabel jLabel3;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JLabel jLabel4;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JPanel jPanel1;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JButton jbuttonEng;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JButton jbuttonEsp;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JButton jbuttonExit;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private JButton jbuttonJap;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean play()
/*     */   {
/*     */     String video_file;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 138 */     switch (this.language) {
/*     */     case 1: 
/* 140 */       video_file = "English_Intro.AVI";
/* 141 */       break;
/*     */     case 2: 
/* 143 */       video_file = "Espanol_Intro.AVI";
/* 144 */       break;
/*     */     case 3: 
/* 146 */       video_file = "Jap_Intro.AVI";
/* 147 */       break;
/*     */     default: 
/* 149 */       video_file = "";
/*     */     }
/*     */     
/* 152 */     return this.player.play(video_file, 0, 0, 1024, 768);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public Login(MedicalControl medical_control, MediaClient media_player)
/*     */   {
/* 162 */     this.language = 1;
/* 163 */     this.keypad_buffer = "";
/* 164 */     this.user_name = "";
/* 165 */     this.user_type = false;
/* 166 */     this.gender = "";
/* 167 */     this.gender = "";
/* 168 */     this.medicalControl = medical_control;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 173 */     this.player = media_player;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 182 */     initComponents();
/*     */     
/* 184 */     this.jbuttonEsp.setVisible(false);
/* 185 */     this.jbuttonJap.setVisible(false);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void initComponents()
/*     */   {
/* 197 */     this.jButton1 = new JButton();
/* 198 */     this.jPanel1 = new JPanel();
/* 199 */     this.jLabel1 = new JLabel();
/* 200 */     this.jbuttonExit = new JButton();
/* 201 */     this.jLabel2 = new JLabel();
/* 202 */     this.jLabel3 = new JLabel();
/* 203 */     this.jLabel4 = new JLabel();
/* 204 */     this.jbuttonEng = new JButton();
/* 205 */     this.jbuttonEsp = new JButton();
/* 206 */     this.jbuttonJap = new JButton();
/*     */     
/* 208 */     this.jButton1.setText("jButton1");
/*     */     
/* 210 */     setDefaultCloseOperation(3);
/* 211 */     setAlwaysOnTop(true);
/* 212 */     setBounds(new Rectangle(0, 0, 1024, 768));
/* 213 */     setCursor(new Cursor(12));
/* 214 */     setFocusTraversalPolicyProvider(true);
/* 215 */     setMaximizedBounds(new Rectangle(0, 0, 1024, 768));
/* 216 */     setMinimumSize(new Dimension(1024, 768));
/* 217 */     setUndecorated(true);
/* 218 */     addKeyListener(new KeyAdapter() {
/*     */       public void keyTyped(KeyEvent evt) {
/* 220 */         Login.this.formKeyTyped(evt);
/*     */       }
/* 222 */     });
/* 223 */     getContentPane().setLayout(new GridLayout(1, 0));
/*     */     
/* 225 */     this.jPanel1.setBackground(new Color(255, 255, 255));
/* 226 */     this.jPanel1.setAlignmentX(0.0F);
/* 227 */     this.jPanel1.setAlignmentY(0.0F);
/* 228 */     this.jPanel1.setFocusCycleRoot(true);
/* 229 */     this.jPanel1.setFocusTraversalPolicyProvider(true);
/* 230 */     this.jPanel1.setMaximumSize(new Dimension(1024, 768));
/* 231 */     this.jPanel1.setMinimumSize(new Dimension(1024, 768));
/* 232 */     this.jPanel1.setPreferredSize(new Dimension(1024, 768));
/* 233 */     this.jPanel1.addMouseListener(new MouseAdapter() {
/*     */       public void mouseClicked(MouseEvent evt) {
/* 235 */         Login.this.jPanel1MouseClicked(evt);
/*     */       }
/* 237 */     });
/* 238 */     this.jPanel1.addFocusListener(new FocusAdapter() {
/*     */       public void focusLost(FocusEvent evt) {
/* 240 */         Login.this.jPanel1FocusLost(evt);
/*     */       }
/* 242 */     });
/* 243 */     this.jPanel1.addKeyListener(new KeyAdapter() {
/*     */       public void keyTyped(KeyEvent evt) {
/* 245 */         Login.this.jPanel1KeyTyped(evt);
/*     */       }
/*     */       
/* 248 */     });
/* 249 */     this.jLabel1.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Top.jpg")));
/* 250 */     this.jLabel1.setFocusable(false);
/* 251 */     this.jLabel1.setRequestFocusEnabled(false);
/* 252 */     this.jLabel1.setVerifyInputWhenFocusTarget(false);
/* 253 */     this.jLabel1.addFocusListener(new FocusAdapter() {
/*     */       public void focusGained(FocusEvent evt) {
/* 255 */         Login.this.jLabel1FocusGained(evt);
/*     */       }
/*     */       
/* 258 */     });
/* 259 */     this.jbuttonExit.setBackground(new Color(0, 0, 0));
/* 260 */     this.jbuttonExit.setFont(new Font("Calibri", 1, 11));
/* 261 */     this.jbuttonExit.setForeground(new Color(255, 255, 255));
/* 262 */     this.jbuttonExit.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/wide_button_exit.jpg")));
/* 263 */     this.jbuttonExit.setAlignmentY(0.0F);
/* 264 */     this.jbuttonExit.setBorder(null);
/* 265 */     this.jbuttonExit.setBorderPainted(false);
/* 266 */     this.jbuttonExit.setContentAreaFilled(false);
/* 267 */     this.jbuttonExit.setDefaultCapable(false);
/* 268 */     this.jbuttonExit.setFocusPainted(false);
/* 269 */     this.jbuttonExit.setFocusable(false);
/* 270 */     this.jbuttonExit.setMaximumSize(new Dimension(512, 768));
/* 271 */     this.jbuttonExit.setMinimumSize(new Dimension(512, 768));
/* 272 */     this.jbuttonExit.setPreferredSize(new Dimension(512, 768));
/* 273 */     this.jbuttonExit.setRequestFocusEnabled(false);
/* 274 */     this.jbuttonExit.setVerifyInputWhenFocusTarget(false);
/* 275 */     this.jbuttonExit.addActionListener(new ActionListener() {
/*     */       public void actionPerformed(ActionEvent evt) {
/* 277 */         Login.this.jbuttonExitActionPerformed(evt);
/*     */       }
/*     */       
/* 280 */     });
/* 281 */     this.jLabel2.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Bottom.jpg")));
/* 282 */     this.jLabel2.setFocusable(false);
/* 283 */     this.jLabel2.setRequestFocusEnabled(false);
/* 284 */     this.jLabel2.setVerifyInputWhenFocusTarget(false);
/* 285 */     this.jLabel2.addFocusListener(new FocusAdapter() {
/*     */       public void focusGained(FocusEvent evt) {
/* 287 */         Login.this.jLabel2FocusGained(evt);
/*     */       }
/*     */       
/* 290 */     });
/* 291 */     this.jLabel3.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Texto_english.jpg")));
/* 292 */     this.jLabel3.setFocusable(false);
/* 293 */     this.jLabel3.setRequestFocusEnabled(false);
/* 294 */     this.jLabel3.setVerifyInputWhenFocusTarget(false);
/* 295 */     this.jLabel3.addFocusListener(new FocusAdapter() {
/*     */       public void focusGained(FocusEvent evt) {
/* 297 */         Login.this.jLabel3FocusGained(evt);
/*     */       }
/*     */       
/* 300 */     });
/* 301 */     this.jLabel4.setBackground(new Color(253, 251, 251));
/* 302 */     this.jLabel4.setFont(new Font("Dialog", 1, 18));
/* 303 */     this.jLabel4.setHorizontalAlignment(0);
/* 304 */     this.jLabel4.setFocusable(false);
/* 305 */     this.jLabel4.setHorizontalTextPosition(0);
/* 306 */     this.jLabel4.setRequestFocusEnabled(false);
/* 307 */     this.jLabel4.setVerifyInputWhenFocusTarget(false);
/* 308 */     this.jLabel4.addFocusListener(new FocusAdapter() {
/*     */       public void focusGained(FocusEvent evt) {
/* 310 */         Login.this.jLabel4FocusGained(evt);
/*     */       }
/*     */       
/* 313 */     });
/* 314 */     this.jbuttonEng.setBackground(new Color(255, 255, 255));
/* 315 */     this.jbuttonEng.setForeground(new Color(254, 254, 254));
/* 316 */     this.jbuttonEng.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Button_English.jpg")));
/* 317 */     this.jbuttonEng.setBorder(null);
/* 318 */     this.jbuttonEng.setBorderPainted(false);
/* 319 */     this.jbuttonEng.setContentAreaFilled(false);
/* 320 */     this.jbuttonEng.setDefaultCapable(false);
/* 321 */     this.jbuttonEng.setFocusPainted(false);
/* 322 */     this.jbuttonEng.setFocusable(false);
/* 323 */     this.jbuttonEng.setRequestFocusEnabled(false);
/* 324 */     this.jbuttonEng.setVerifyInputWhenFocusTarget(false);
/* 325 */     this.jbuttonEng.addActionListener(new ActionListener() {
/*     */       public void actionPerformed(ActionEvent evt) {
/* 327 */         Login.this.jbuttonEngActionPerformed(evt);
/*     */       }
/* 329 */     });
/* 330 */     this.jbuttonEng.addFocusListener(new FocusAdapter() {
/*     */       public void focusGained(FocusEvent evt) {
/* 332 */         Login.this.jbuttonEngFocusGained(evt);
/*     */       }
/*     */       
/* 335 */     });
/* 336 */     this.jbuttonEsp.setBackground(new Color(255, 255, 255));
/* 337 */     this.jbuttonEsp.setForeground(new Color(254, 254, 254));
/* 338 */     this.jbuttonEsp.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Button_Espanol.jpg")));
/* 339 */     this.jbuttonEsp.setBorder(null);
/* 340 */     this.jbuttonEsp.setBorderPainted(false);
/* 341 */     this.jbuttonEsp.setContentAreaFilled(false);
/* 342 */     this.jbuttonEsp.setDefaultCapable(false);
/* 343 */     this.jbuttonEsp.setEnabled(false);
/* 344 */     this.jbuttonEsp.setFocusPainted(false);
/* 345 */     this.jbuttonEsp.setFocusable(false);
/* 346 */     this.jbuttonEsp.setRequestFocusEnabled(false);
/* 347 */     this.jbuttonEsp.setVerifyInputWhenFocusTarget(false);
/* 348 */     this.jbuttonEsp.addActionListener(new ActionListener() {
/*     */       public void actionPerformed(ActionEvent evt) {
/* 350 */         Login.this.jbuttonEspActionPerformed(evt);
/*     */       }
/* 352 */     });
/* 353 */     this.jbuttonEsp.addFocusListener(new FocusAdapter() {
/*     */       public void focusGained(FocusEvent evt) {
/* 355 */         Login.this.jbuttonEspFocusGained(evt);
/*     */       }
/*     */       
/* 358 */     });
/* 359 */     this.jbuttonJap.setBackground(new Color(255, 255, 255));
/* 360 */     this.jbuttonJap.setForeground(new Color(254, 254, 254));
/* 361 */     this.jbuttonJap.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Button_Japones.jpg")));
/* 362 */     this.jbuttonJap.setBorder(null);
/* 363 */     this.jbuttonJap.setBorderPainted(false);
/* 364 */     this.jbuttonJap.setContentAreaFilled(false);
/* 365 */     this.jbuttonJap.setDefaultCapable(false);
/* 366 */     this.jbuttonJap.setEnabled(false);
/* 367 */     this.jbuttonJap.setFocusPainted(false);
/* 368 */     this.jbuttonJap.setFocusable(false);
/* 369 */     this.jbuttonJap.setRequestFocusEnabled(false);
/* 370 */     this.jbuttonJap.setVerifyInputWhenFocusTarget(false);
/* 371 */     this.jbuttonJap.addActionListener(new ActionListener() {
/*     */       public void actionPerformed(ActionEvent evt) {
/* 373 */         Login.this.jbuttonJapActionPerformed(evt);
/*     */       }
/* 375 */     });
/* 376 */     this.jbuttonJap.addFocusListener(new FocusAdapter() {
/*     */       public void focusLost(FocusEvent evt) {
/* 378 */         Login.this.jbuttonJapFocusLost(evt);
/*     */       }
/*     */       
/* 381 */     });
/* 382 */     GroupLayout jPanel1Layout = new GroupLayout(this.jPanel1);
/* 383 */     this.jPanel1.setLayout(jPanel1Layout);
/* 384 */     jPanel1Layout.setHorizontalGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(this.jLabel2, -2, 1231, -2).addGroup(jPanel1Layout.createSequentialGroup().addGap(112, 112, 112).addGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel1Layout.createSequentialGroup().addGap(727, 727, 727).addComponent(this.jbuttonJap, -2, 179, -2)).addGroup(jPanel1Layout.createSequentialGroup().addGap(651, 651, 651).addComponent(this.jbuttonEsp, -2, 175, -2)))).addGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.TRAILING, false).addGroup(GroupLayout.Alignment.LEADING, jPanel1Layout.createSequentialGroup().addGap(233, 233, 233).addGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.CENTER).addComponent(this.jLabel4, -2, 538, -2).addComponent(this.jLabel3, -2, 392, -2).addComponent(this.jbuttonEng, -2, 179, -2)).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED, -1, 32767).addComponent(this.jbuttonExit, -2, 100, -2)).addComponent(this.jLabel1, GroupLayout.Alignment.LEADING)));
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
/* 407 */     jPanel1Layout.setVerticalGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel1Layout.createSequentialGroup().addComponent(this.jLabel1).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED, -1, 32767).addGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel1Layout.createSequentialGroup().addComponent(this.jLabel3).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addGroup(jPanel1Layout.createSequentialGroup().addGap(58, 58, 58).addComponent(this.jbuttonEng, -2, 80, -2)).addComponent(this.jLabel4, -2, 44, -2))).addComponent(this.jbuttonExit, -2, 73, -2)).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addGroup(jPanel1Layout.createParallelGroup(GroupLayout.Alignment.LEADING).addComponent(this.jbuttonEsp, -2, 77, -2).addComponent(this.jbuttonJap, -2, 78, -2)).addPreferredGap(LayoutStyle.ComponentPlacement.RELATED).addComponent(this.jLabel2)));
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
/* 430 */     getContentPane().add(this.jPanel1);
/*     */     
/* 432 */     Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
/* 433 */     setBounds((screenSize.width - 1024) / 2, (screenSize.height - 768) / 2, 1024, 768);
/*     */   }
/*     */   
/*     */   private void jbuttonEngActionPerformed(ActionEvent evt)
/*     */   {
/* 438 */     this.jLabel3.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Texto_english.jpg")));
/* 439 */     this.language = 1;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 444 */     play();
/*     */   }
/*     */   
/*     */   private void jbuttonEspActionPerformed(ActionEvent evt) {
/* 448 */     this.jLabel3.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Texto_espanol.jpg")));
/* 449 */     this.language = 2;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 454 */     play();
/*     */   }
/*     */   
/*     */   private void jbuttonJapActionPerformed(ActionEvent evt) {
/* 458 */     this.jLabel3.setIcon(new ImageIcon(getClass().getResource("/GUI/Images/Welcome_Texto_japones.jpg")));
/* 459 */     this.language = 3;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 464 */     play();
/*     */   }
/*     */   
/*     */   public void flushKeypadBuffer() {
/* 468 */     this.keypad_buffer = "";
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void formKeyTyped(KeyEvent evt)
/*     */   {
/* 477 */     this.keypad_buffer += evt.getKeyChar();
/* 478 */     int key = evt.getKeyChar();
/*     */     
/* 480 */     if (key == 80)
/*     */     {
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
/* 499 */       showNextWindow("P");
/*     */     }
/* 501 */     if (key == 68) {
/* 502 */       showNextWindow("D");
/*     */     }
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
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void showNextWindow(String a)
/*     */   {
/* 541 */     if ((a.equals("p")) || (a.equals("P"))) {
/* 542 */       System.out.println("Login: Patient");
/* 543 */       switch (this.language) {
/*     */       case 1: 
/* 545 */         this.medicalControl.showPatientInteface();
/*     */         
/* 547 */         break;
/*     */       case 2: 
/* 549 */         this.medicalControl.showPatientInteface();
/*     */         
/* 551 */         break;
/*     */       
/*     */       case 3: 
/* 554 */         this.medicalControl.showPatientInteface();
/*     */       
/*     */ 
/*     */ 
/*     */       }
/*     */       
/*     */     }
/* 561 */     else if ((a.equals("d")) || (a.equals("D"))) {
/* 562 */       System.out.println("Login: Doctor");
/*     */       
/* 564 */       switch (this.language) {
/*     */       case 1: 
/* 566 */         this.medicalControl.showDoctorInterface();
/*     */         
/* 568 */         break;
/*     */       case 2: 
/* 570 */         this.medicalControl.showDoctorInterface();
/*     */         
/* 572 */         break;
/*     */       
/*     */       case 3: 
/* 575 */         this.medicalControl.showDoctorInterface();
/*     */       }
/*     */       
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void jPanel1MouseClicked(MouseEvent evt) {}
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void jPanel1KeyTyped(KeyEvent evt)
/*     */   {
/* 595 */     System.out.println("TimeOut: system restarte after 2 minutes !");
/* 596 */     if (evt.getModifiersEx() == 2) {
/* 597 */       System.out.println("Info: control key pressed");
/*     */     }
/*     */   }
/*     */   
/*     */   private void jPanel1FocusLost(FocusEvent evt)
/*     */   {
/* 603 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jLabel1FocusGained(FocusEvent evt)
/*     */   {
/* 608 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jLabel2FocusGained(FocusEvent evt)
/*     */   {
/* 613 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jLabel3FocusGained(FocusEvent evt)
/*     */   {
/* 618 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jLabel4FocusGained(FocusEvent evt)
/*     */   {
/* 623 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jbuttonEngFocusGained(FocusEvent evt)
/*     */   {
/* 628 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jbuttonEspFocusGained(FocusEvent evt)
/*     */   {
/* 633 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jbuttonJapFocusLost(FocusEvent evt)
/*     */   {
/* 638 */     this.jPanel1.requestFocus();
/*     */   }
/*     */   
/*     */   private void jbuttonExitActionPerformed(ActionEvent evt)
/*     */   {
/* 643 */     System.exit(0);
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Login.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */