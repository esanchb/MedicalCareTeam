/*    */ package DBClient;
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ public class Measurement
/*    */   extends Types
/*    */ {
/* 32 */   private static final String[] fields = { "spirometry_chart", "ecg_chart", "pox_chart", "temperature", "weight", "glucose", "height", "blood_pressure", "ecg_measurement", "pox_measurement", "spirometry_measurement", "rfc" };
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public Measurement(String[] values)
/*    */     throws Exception
/*    */   {
/* 53 */     super(fields, values);
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */   public String getID()
/*    */   {
/* 61 */     return getValueAt(11).toString();
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\DBClient\Measurement.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */