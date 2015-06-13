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
/*    */ public class CommandEvent
/*    */   extends EventObject
/*    */ {
/* 25 */   private DataFromCommander medicalCommanderData = null;
/*    */   
/*    */   public CommandEvent(Object source, DataFromCommander data) {
/* 28 */     super(source);
/* 29 */     this.medicalCommanderData = data;
/*    */   }
/*    */   
/*    */   public DataFromCommander getMedicalData()
/*    */   {
/* 34 */     return this.medicalCommanderData;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\CommandEvent.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */