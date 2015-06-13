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
/*    */ public class PulseOximetryBuffer
/*    */ {
/*    */   private int id;
/* 26 */   private int[] buffer = new int[32];
/* 27 */   private boolean error = false;
/*    */   
/*    */   public PulseOximetryBuffer(byte[] buffer) {
/* 30 */     this.id = Parser.toIntValue(Byte.valueOf(buffer[0]), Byte.valueOf(buffer[1]));
/*    */     
/*    */ 
/*    */ 
/* 34 */     if (buffer.length == 68)
/*    */     {
/* 36 */       int counter = 2; for (int count1 = 0; counter <= buffer.length - 4; count1++) {
/* 37 */         this.buffer[count1] = Parser.toIntValue(Byte.valueOf(buffer[counter]), Byte.valueOf(buffer[(counter + 1)]));counter += 2;
/*    */       }
/*    */     }
/*    */     else {
/* 41 */       System.out.println("Error: PulseOximetryBuffer Parse error at data packet");
/* 42 */       this.error = true;
/*    */     }
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public boolean getError()
/*    */   {
/* 52 */     return this.error;
/*    */   }
/*    */   
/*    */   public int[] getBuffer() {
/* 56 */     return this.buffer;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\PulseOximetryBuffer.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */