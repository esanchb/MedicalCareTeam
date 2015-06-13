/*    */ package Medical.Results;
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ public class Glucometry
/*    */ {
/*    */   private int glucose_level;
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   private int calibration;
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public Glucometry(int glucose_level, int calibration)
/*    */   {
/* 27 */     this.glucose_level = glucose_level;
/* 28 */     this.calibration = calibration;
/*    */   }
/*    */   
/*    */   public int getGlucoseLevel() {
/* 32 */     return this.glucose_level;
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */   public int getCalibration()
/*    */   {
/* 40 */     return this.calibration;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\Glucometry.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */