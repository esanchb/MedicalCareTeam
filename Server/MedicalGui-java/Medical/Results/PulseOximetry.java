/*    */ package Medical.Results;
/*    */ 
/*    */ import Medical.Parser;
/*    */ import java.io.PrintStream;
/*    */ import java.util.ArrayList;
/*    */ import java.util.Collections;
/*    */ import java.util.List;
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
/*    */ public class PulseOximetry
/*    */ {
/*    */   private int oxigen_saturation;
/*    */   private int heart_rate;
/* 30 */   private PulseOximetryBuffer pox_buffer = null;
/* 31 */   private static List<Integer> int_buffer = Collections.synchronizedList(new ArrayList());
/*    */   
/*    */   public PulseOximetry(int oxigen_saturation, int heart_rate) {
/* 34 */     this.oxigen_saturation = oxigen_saturation;
/* 35 */     this.heart_rate = heart_rate;
/*    */   }
/*    */   
/*    */   public PulseOximetry(int oxigen_saturation, int heart_rate, byte[] buffer) {
/* 39 */     this.oxigen_saturation = oxigen_saturation;
/* 40 */     this.heart_rate = heart_rate;
/*    */     
/*    */ 
/* 43 */     this.pox_buffer = new PulseOximetryBuffer(buffer);
/*    */     
/*    */ 
/*    */ 
/* 47 */     for (int count = 2; count <= buffer.length - 4; count += 2) {
/* 48 */       int temp = Parser.toIntValue(buffer[count], buffer[(count + 1)]);
/* 49 */       int_buffer.add(new Integer(temp));
/*    */     }
/*    */   }
/*    */   
/*    */   public int[] getBuffer()
/*    */   {
/* 55 */     return this.pox_buffer.getBuffer();
/*    */   }
/*    */   
/*    */   public boolean getError() {
/* 59 */     return this.pox_buffer.getError();
/*    */   }
/*    */   
/*    */   public int getOxigenSaturation()
/*    */   {
/* 64 */     return this.oxigen_saturation;
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */   public int getHeartRate()
/*    */   {
/* 72 */     return this.heart_rate;
/*    */   }
/*    */   
/*    */   public Integer[] getFullBuffer()
/*    */   {
/* 77 */     Integer[] temp_buffer = new Integer[int_buffer.size()];
/*    */     
/* 79 */     for (int count = 0; count < int_buffer.size(); count++) {
/* 80 */       temp_buffer[count] = ((Integer)int_buffer.get(count));
/*    */     }
/*    */     
/* 83 */     return temp_buffer;
/*    */   }
/*    */   
/*    */   public void printAll() {
/* 87 */     System.out.println("Spirometry data bulk");
/* 88 */     for (int count = 0; count < int_buffer.size(); count++) {
/* 89 */       System.out.println(int_buffer.get(count));
/*    */     }
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\PulseOximetry.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */