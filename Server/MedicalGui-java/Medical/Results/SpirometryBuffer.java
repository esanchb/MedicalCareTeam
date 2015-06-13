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
/*    */ public class SpirometryBuffer
/*    */ {
/*    */   private int id;
/* 26 */   private int[] buffer = new int[32];
/* 27 */   private boolean error = false;
/*    */   
/*    */   public SpirometryBuffer(Object[] buffer) {
/* 30 */     this.id = Parser.toIntValue((Byte)buffer[0], (Byte)buffer[1]);
/*    */     try
/*    */     {
/* 33 */       if (buffer.length == 16)
/*    */       {
/* 35 */         int counter = 2; for (int count1 = 0; counter < buffer.length - 2; count1++) {
/* 36 */           this.buffer[count1] = Parser.toIntValue((Byte)buffer[counter], (Byte)buffer[(counter + 1)]);counter += 2;
/*    */         }
/*    */       }
/*    */       else {
/* 40 */         System.out.println("Error: SpirometryBuffer Parse error at data packet");
/* 41 */         this.error = true;
/*    */       }
/*    */     } catch (Exception ex) {
/* 44 */       System.out.println("Error: SpirometryBuffer Message:" + ex.getMessage() + " Localized Message:" + ex.getLocalizedMessage());
/* 45 */       ex.printStackTrace();
/*    */     }
/*    */   }
/*    */   
/*    */   public boolean getError() {
/* 50 */     return this.error;
/*    */   }
/*    */   
/*    */   public int[] getBuffer() {
/* 54 */     return this.buffer;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\SpirometryBuffer.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */