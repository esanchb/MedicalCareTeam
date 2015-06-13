/*     */ package Medical;
/*     */ 
/*     */ import GUI.DoctorInterface;
/*     */ import GUI.Login;
/*     */ import GUI.MediaClient;
/*     */ import GUI.PatientInterface;
/*     */ import java.io.PrintStream;
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
/*     */ public class MedicalControl
/*     */ {
/*     */   private Login loginFrame;
/*     */   private DoctorInterface doctorInterfaceFrame;
/*     */   private PatientInterface patientInterface;
/*     */   private MedicalCommander medicalCommander;
/*     */   private MediaClient player;
/*     */   
/*     */   public MedicalControl()
/*     */   {
/*  39 */     this.medicalCommander = new MedicalCommander();
/*  40 */     this.player = new MediaClient();
/*     */     
/*     */ 
/*     */ 
/*  44 */     this.loginFrame = new Login(this, this.player);
/*  45 */     this.doctorInterfaceFrame = new DoctorInterface(this.medicalCommander, this);
/*  46 */     this.patientInterface = new PatientInterface(this.medicalCommander, this, this.player);
/*     */     
/*  48 */     this.loginFrame.pack();
/*  49 */     this.doctorInterfaceFrame.pack();
/*  50 */     this.patientInterface.pack();
/*     */   }
/*     */   
/*     */   public void showDoctorInterface()
/*     */   {
/*  55 */     if (this.patientInterface.isVisible()) {
/*  56 */       this.medicalCommander.removeListener(this.patientInterface);
/*     */     }
/*     */     
/*  59 */     this.medicalCommander.addListener(this.doctorInterfaceFrame);
/*     */     
/*  61 */     this.doctorInterfaceFrame.setVisible(true);
/*  62 */     this.loginFrame.setVisible(false);
/*  63 */     this.patientInterface.setVisible(false);
/*     */   }
/*     */   
/*     */   public void showPatientInteface()
/*     */   {
/*  68 */     if (this.doctorInterfaceFrame.isVisible()) {
/*  69 */       this.medicalCommander.removeListener(this.doctorInterfaceFrame);
/*     */     }
/*     */     
/*  72 */     this.medicalCommander.addListener(this.patientInterface);
/*     */     
/*  74 */     this.patientInterface.setVisible(true);
/*  75 */     this.loginFrame.setVisible(false);
/*  76 */     this.doctorInterfaceFrame.setVisible(false);
/*     */   }
/*     */   
/*     */   public void showLogin()
/*     */   {
/*  81 */     if (this.patientInterface.isVisible()) {
/*  82 */       this.medicalCommander.removeListener(this.patientInterface);
/*     */     }
/*     */     
/*  85 */     if (this.doctorInterfaceFrame.isVisible()) {
/*  86 */       this.medicalCommander.removeListener(this.doctorInterfaceFrame);
/*     */     }
/*     */     
/*  89 */     this.loginFrame.flushKeypadBuffer();
/*     */     
/*  91 */     this.loginFrame.setVisible(true);
/*  92 */     this.doctorInterfaceFrame.setVisible(false);
/*  93 */     this.patientInterface.setVisible(false);
/*     */   }
/*     */   
/*     */   public static void main(String[] args)
/*     */   {
/*     */     try {
/*  99 */       SwingUtilities.invokeLater(new Runnable()
/*     */       {
/*     */         public void run() {
/* 102 */           MedicalControl medicalController = new MedicalControl();
/* 103 */           medicalController.showLogin();
/*     */         }
/*     */       });
/*     */     } catch (Exception ex) {
/* 107 */       System.out.println("Error: Application crashed due to: " + ex.getMessage());
/*     */     }
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\MedicalControl.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */