/*    */ package Medical;
/*    */ 
/*    */ import java.util.EventObject;
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
/*    */ public class Event
/*    */   extends EventObject
/*    */ {
/* 28 */   private DataFromHW medicalData = null;
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public Event(Object source, DataFromHW data)
/*    */   {
/* 37 */     super(source);
/* 38 */     this.medicalData = data;
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public DataFromHW getMedicalData()
/*    */   {
/* 47 */     return this.medicalData;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Event.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */