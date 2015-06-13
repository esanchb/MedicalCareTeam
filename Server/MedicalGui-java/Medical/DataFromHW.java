/*     */ package Medical;
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ public class DataFromHW
/*     */ {
/*     */   private static final int MEDICAL_MINIMUM_DATA = 1;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*  28 */   private Types.PacketId packet_id = Types.PacketId.NONE;
/*  29 */   private Types.Request request = Types.Request.NONE;
/*  30 */   private Types.Indication indication = Types.Indication.NONE;
/*     */   
/*     */ 
/*     */   private boolean data_error;
/*     */   
/*     */ 
/*     */   private boolean data_warning;
/*     */   
/*     */ 
/*     */   private byte[] buffer;
/*     */   
/*     */ 
/*     */   public DataFromHW()
/*     */   {
/*  44 */     this.data_error = false;
/*  45 */     this.data_warning = false;
/*     */   }
/*     */   
/*  48 */   public byte[] getBuffer() { return this.buffer; }
/*     */   
/*  50 */   public void setBuffer(byte[] buffer) { this.buffer = buffer; }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public Types.Request getRequest()
/*     */   {
/*  57 */     return this.request;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setRequest(Types.Request request)
/*     */   {
/*  65 */     this.request = request;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public Types.Indication getIndication()
/*     */   {
/*  73 */     return this.indication;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setIndication(Types.Indication indication)
/*     */   {
/*  81 */     this.indication = indication;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public Types.PacketId getPacketId()
/*     */   {
/*  89 */     return this.packet_id;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setPacketId(Types.PacketId id)
/*     */   {
/*  97 */     this.packet_id = id;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean getErrorState()
/*     */   {
/* 147 */     return this.data_error;
/*     */   }
/*     */   
/*     */   public void setErrorState(boolean error_state) {
/* 151 */     this.data_error = error_state;
/*     */   }
/*     */   
/*     */   public boolean getWarningState() {
/* 155 */     return this.data_warning;
/*     */   }
/*     */   
/*     */   public void setWarningState(boolean warning_state) {
/* 159 */     this.data_warning = warning_state;
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\DataFromHW.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */