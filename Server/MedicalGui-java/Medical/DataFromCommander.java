/*    */ package Medical;
/*    */ 
/*    */ import Medical.Results.BloodPressure;
/*    */ import Medical.Results.ElectroCardioGram;
/*    */ import Medical.Results.Glucometry;
/*    */ import Medical.Results.Height;
/*    */ import Medical.Results.PulseOximetry;
/*    */ import Medical.Results.Spirometry;
/*    */ import Medical.Results.Temperature;
/*    */ import Medical.Results.Weight;
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
/*    */ public class DataFromCommander
/*    */ {
/*    */   private Types.Request request;
/*    */   private Types.Indication indicator;
/*    */   public Glucometry glucometry;
/*    */   public Weight weight;
/*    */   public Height height;
/*    */   public Temperature temperature;
/*    */   public BloodPressure blood_pressure;
/*    */   public ElectroCardioGram ecg;
/*    */   public PulseOximetry pulse_oximetry;
/*    */   public Spirometry spirometry;
/*    */   
/*    */   public void Error()
/*    */   {
/* 42 */     this.request = Types.Request.NONE;
/* 43 */     this.indicator = Types.Indication.NONE;
/*    */   }
/*    */   
/*    */   public void setRequest(Types.Request request) {
/* 47 */     this.request = request;
/*    */   }
/*    */   
/*    */   public void setIndication(Types.Indication indicator) {
/* 51 */     this.indicator = indicator;
/*    */   }
/*    */   
/*    */   public Types.Request getRequest() {
/* 55 */     return this.request;
/*    */   }
/*    */   
/*    */   public Types.Indication getIndicator() {
/* 59 */     return this.indicator;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\DataFromCommander.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */