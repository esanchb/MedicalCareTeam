/*    */ package DBClient;
/*    */ 
/*    */ import java.util.Enumeration;
/*    */ import java.util.Vector;
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
/*    */ public class Types
/*    */ {
/*    */   private Object[] fields;
/*    */   private Vector values;
/*    */   
/*    */   public Types(Object[] fields, Object[] values)
/*    */     throws Exception
/*    */   {
/* 39 */     if (!init(fields, values)) { throw new Exception();
/*    */     }
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */   public Object[] getFields()
/*    */   {
/* 47 */     return this.fields;
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */   public Enumeration getValues()
/*    */   {
/* 55 */     return this.values.elements();
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public Object getValueAt(int index)
/*    */   {
/* 64 */     if ((index >= 0) && (index < this.values.size())) {
/* 65 */       return this.values.elementAt(index);
/*    */     }
/* 67 */     return null;
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */ 
/*    */   public boolean setValueAt(Object data, int index)
/*    */   {
/* 78 */     if ((index >= 0) && (index < this.values.size())) {
/* 79 */       this.values.setElementAt(data, index);
/* 80 */       return true;
/*    */     }
/* 82 */     return false;
/*    */   }
/*    */   
/*    */   private boolean init(Object[] fields, Object[] values) {
/* 86 */     if (fields.length == values.length) {
/* 87 */       this.values = new Vector(values.length);
/* 88 */       for (int i = 0; i < values.length; i++) {
/* 89 */         this.values.add(values[i]);
/*    */       }
/* 91 */       this.fields = fields;
/* 92 */       return true;
/*    */     }
/* 94 */     return false;
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\DBClient\Types.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */