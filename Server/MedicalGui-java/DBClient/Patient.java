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
/*    */ public class Patient
/*    */   extends Types
/*    */ {
/* 30 */   private static final String[] fields = { "nombre", "a_paterno", "a_materno", "identificador", "fecha_nacimiento", "sexo", "tel", "ocupacion", "rfc", "neoplastias", "cardioplastias", "cronico_degenerativas", "otras_ahf", "tiposangre", "alcoholismo", "tabaquismo", "adicciones", "alergias", "medicos", "quirurgicos", "infecto_contagiosos", "otras_app" };
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
/*    */   public Patient(String[] values)
/*    */     throws Exception
/*    */   {
/* 61 */     super(fields, values);
/*    */   }
/*    */   
/*    */ 
/*    */ 
/*    */ 
/*    */   public String getID()
/*    */   {
/* 69 */     return getValueAt(8).toString();
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\DBClient\Patient.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */