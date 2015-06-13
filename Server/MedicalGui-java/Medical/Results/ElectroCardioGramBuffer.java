/*    */ package Medical.Results;
/*    */ 
/*    */ import Medical.Parser;
/*    */ import java.io.PrintStream;
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
/*    */ public class ElectroCardioGramBuffer
/*    */ {
/*    */   private int id;
/* 26 */   private int[] buffer = new int[32];
/* 27 */   private boolean error = false;
/*    */   
/*    */   public ElectroCardioGramBuffer(byte[] buffer) {
/* 30 */     this.id = Parser.toIntValue(buffer[0], buffer[1]);
/*    */     
/* 32 */     if (buffer.length == 67)
/*    */     {
/* 34 */       int counter = 2; for (int count1 = 0; counter <= buffer.length - 3; count1++)
/*    */       {
/* 36 */         int temp = Parser.toIntValue(buffer[counter], buffer[(counter + 1)]);
/* 37 */         this.buffer[count1] = temp;counter += 2;
/*    */       }
/*    */       
/*    */ 
/*    */     }
/*    */     else
/*    */     {
/* 43 */       System.out.println("Error: ElectroCardioGramBuffer Parse error at data packet");
/* 44 */       this.error = true;
/*    */     }
/*    */   }
/*    */   
/*    */   public boolean getError() {
/* 49 */     return this.error;
/*    */   }
/*    */   
/*    */   public int[] getBuffer() {
/* 53 */     return this.buffer;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\ElectroCardioGramBuffer.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */