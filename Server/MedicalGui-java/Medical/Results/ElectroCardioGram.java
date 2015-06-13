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
/*    */ public class ElectroCardioGram
/*    */ {
/*    */   private int heart_rate;
/* 29 */   private ElectroCardioGramBuffer ecg_buffer = null;
/* 30 */   private static List<Integer> int_buffer = Collections.synchronizedList(new ArrayList());
/*    */   
/*    */   public ElectroCardioGram(int heart_rate, byte[] buffer)
/*    */   {
/* 34 */     this.heart_rate = heart_rate;
/*    */     
/*    */ 
/* 37 */     this.ecg_buffer = new ElectroCardioGramBuffer(buffer);
/*    */     
/* 39 */     for (int count = 2; count <= buffer.length - 3; count += 2) {
/* 40 */       int temp = Parser.toIntValue(buffer[count], buffer[(count + 1)]);
/* 41 */       int_buffer.add(new Integer(temp));
/*    */     }
/*    */   }
/*    */   
/*    */   public ElectroCardioGram(int heart_rate)
/*    */   {
/* 47 */     this.heart_rate = heart_rate;
/*    */   }
/*    */   
/*    */   public boolean getError()
/*    */   {
/* 52 */     return this.ecg_buffer.getError();
/*    */   }
/*    */   
/*    */   public int[] getBuffer() {
/* 56 */     return this.ecg_buffer.getBuffer();
/*    */   }
/*    */   
/*    */   public int getHeartRate() {
/* 60 */     return this.heart_rate;
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public Integer[] getFullBuffer()
/*    */   {
/* 69 */     Integer[] temp_buffer = new Integer[int_buffer.size()];
/*    */     
/* 71 */     int_buffer.toArray(temp_buffer);
/*    */     
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/* 78 */     return temp_buffer;
/*    */   }
/*    */   
/*    */   public void printAll() {
/* 82 */     System.out.println("Spirometry data bulk");
/* 83 */     for (int count = 0; count < int_buffer.size(); count++) {
/* 84 */       System.out.println(int_buffer.get(count));
/*    */     }
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\ElectroCardioGram.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */