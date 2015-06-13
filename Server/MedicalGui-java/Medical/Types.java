/*     */ package Medical;
/*     */ 
/*     */ 
/*     */ 
/*     */ public class Types
/*     */ {
/*     */   private static final String mstart = "Measurement Started";
/*     */   
/*     */ 
/*     */   private static final String mabort = "Measurement Aborted";
/*     */   
/*     */ 
/*     */   private static final String cstart = "Calibration Started";
/*     */   
/*     */ 
/*     */   private static final String mcomplete = "Measurement Completed";
/*     */   
/*     */ 
/*     */   private static final String ccomplete = "Calibration Completed";
/*     */   
/*     */ 
/*     */   private static final String error = "Error";
/*     */   
/*     */ 
/*     */   private static final String dstart = "Diagnostic Started";
/*     */   
/*     */ 
/*     */   private static final String dready = "Diagnostic Data Ready";
/*     */   
/*     */ 
/*     */   private static final String dstop = "Diagnostic Stopped";
/*     */   
/*     */ 
/*     */   private static final String unknown = "Unknown Operation";
/*     */   
/*     */ 
/*     */   public static enum SerialError
/*     */   {
/*  39 */     NONE, 
/*  40 */     TIME_OUT, 
/*  41 */     WRONG_FRAME_DATA;
/*     */     
/*     */     private SerialError() {} }
/*     */   
/*  45 */   public static enum Measurement { HEIGHT, 
/*  46 */     WEIGHT, 
/*  47 */     TEMPERATURE, 
/*  48 */     BLOODPRESSURE, 
/*  49 */     HEARTRATE, 
/*  50 */     PULSEOXIMETRY, 
/*  51 */     GLUCOMETRY, 
/*  52 */     SPIROMETRY, 
/*  53 */     NONE;
/*     */     
/*     */     private Measurement() {} }
/*     */   
/*  57 */   public static enum MeasurementStatus { NONE, 
/*  58 */     STAND_BY, 
/*  59 */     STARTED, 
/*  60 */     CONFIRMED, 
/*  61 */     POOLING, 
/*  62 */     POOLING_ABORTED, 
/*  63 */     ABORTED, 
/*  64 */     ABORT_CONFIRMED, 
/*  65 */     BUSY, 
/*  66 */     ERROR;
/*     */     
/*     */     private MeasurementStatus() {}
/*     */   }
/*     */   
/*     */   public static enum Request {
/*  72 */     GLU_START_MEASUREMENT((byte)0, "Glucometry", "GLU_START_MEASUREMENT", false), 
/*  73 */     GLU_ABORT_MEASUREMENT((byte)1, "Aborted Glucometry", "GLU_ABORT_MEASUREMENT", true), 
/*  74 */     GLU_START_CALIBRATION((byte)2, "Glucometer Calibration", "GLU_START_CALIBRATION", false), 
/*  75 */     BPM_START_MEASUREMENT((byte)6, "Blood Pressure", "BPM_START_MEASUREMENT", false), 
/*  76 */     BPM_ABORT_MEASUREMENT((byte)7, "Aborted BPM", "BPM_ABORT_MEASUREMENT", true), 
/*  77 */     BPM_START_LEAK_TEST((byte)10, "Blood Pressure Bracelet Leak test", "BPM_START_LEAK_TEST", false), 
/*  78 */     BPM_ABORT_LEAK_TEST((byte)11, "Aborted BPM Bracelet Leak test", "BPM_ABORT_LEAK_TEST", true), 
/*  79 */     ECG_HEART_RATE_START_MEASUREMENT((byte)13, "ElectroCardioGram", "ECG_HEART_RATE_START_MEASUREMENT", false), 
/*  80 */     ECG_HEART_RATE_ABORT_MEASUREMENT((byte)14, "Aborted ECG", "ECG_HEART_RATE_ABORT_MEASUREMENT", true), 
/*  81 */     ECG_DIAGNOSTIC_MODE_START_MEASUREMENT((byte)18, "ECG Continuous", "ECG_DIAGNOSTIC_MODE_START_MEASUREMENT", false), 
/*  82 */     ECG_DIAGNOSTIC_MODE_STOP_MEASUREMENT((byte)19, "Aborted ECG Continuous", "ECG_DIAGNOSTIC_MODE_STOP_MEASUREMENT", true), 
/*  83 */     TMP_READ_TEMPERATURE((byte)21, "Temperature", "TMP_READ_TEMPERATURE", true), 
/*  84 */     HGT_READ_HEIGHT((byte)22, "Heigth", "HGT_READ_HEIGHT", true), 
/*  85 */     WGT_READ_WEIGHT((byte)23, "Weigth", "WGT_READ_WEIGHT", true), 
/*  86 */     SPR_START_MEASUREMENT((byte)24, "Spirometry", "SPR_START_MEASUREMENT", false), 
/*  87 */     SPR_ABORT_MEASUREMENT((byte)25, "Aborted Spirometry", "SPR_ABORT_MEASUREMENT", true), 
/*  88 */     SPR_DIAGNOSTIC_MODE_START_MEASUREMENT((byte)28, "Spirometry Continuous", "SPR_DIAGNOSTIC_MODE_START_MEASUREMENT", false), 
/*  89 */     SPR_DIAGNOSTIC_MODE_STOP_MEASUREMENT((byte)29, "Aborted Spirometry Continuous", "SPR_DIAGNOSTIC_MODE_STOP_MEASUREMENT", true), 
/*  90 */     POX_START_MEASUREMENT((byte)33, "Pulse Oximetry", "POX_START_MEASUREMENT", false), 
/*  91 */     POX_ABORT_MEASUREMENT((byte)34, "Aborted Sp02", "POX_ABORT_MEASUREMENT", true), 
/*  92 */     POX_DIAGNOSTIC_MODE_START_MEASUREMENT((byte)37, "Sp02 Continuous", "POX_DIAGNOSTIC_MODE_START_MEASUREMENT", false), 
/*  93 */     POX_DIAGNOSTIC_MODE_STOP_MEASUREMENT((byte)38, "Aborted Sp02 Continuous", "POX_DIAGNOSTIC_MODE_STOP_MEASUREMENT", true), 
/*  94 */     SYS_CHECK_DEVICE_CONNECTION((byte)41, "Device Connection Test", "SYS_CHECK_DEVICE_CONNECTION", true), 
/*  95 */     SYS_RESTART_SYSTEM((byte)42, "Device Restart", "SYS_RESTART_SYSTEM", true), 
/*     */     
/*  97 */     ERROR((byte)-4, "Wrong Request", "ERROR", false), 
/*  98 */     NONE((byte)-5, "No Request", "NONE", false);
/*     */     
/*     */     private final byte id;
/*     */     private final String description;
/*     */     private final String secondStr;
/*     */     private final boolean terminator;
/*     */     
/*     */     private Request(byte id, String description, String secondStr, boolean terminator)
/*     */     {
/* 107 */       this.id = id;
/* 108 */       this.description = description;
/* 109 */       this.secondStr = secondStr;
/* 110 */       this.terminator = terminator;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */     public byte[] toBuffer()
/*     */     {
/* 120 */       byte[] buffer = new byte[3];
/* 121 */       buffer[0] = Types.PacketId.REQ.getValue();
/* 122 */       buffer[1] = this.id;
/* 123 */       buffer[2] = 0;
/*     */       
/* 125 */       return buffer;
/*     */     }
/*     */     
/*     */     public byte[] toBuffer(int calibration) {
/* 129 */       byte[] buffer = new byte[5];
/* 130 */       buffer[0] = Types.PacketId.REQ.getValue();
/* 131 */       buffer[1] = this.id;
/* 132 */       if (equals(GLU_START_CALIBRATION)) {
/* 133 */         buffer[2] = 2;
/* 134 */         buffer[3] = ((byte)((calibration & 0xFF00) >>> 8));
/* 135 */         buffer[4] = ((byte)(calibration & 0xFF));
/*     */       }
/*     */       
/* 138 */       return buffer;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */     public byte getValue()
/*     */     {
/* 145 */       return this.id;
/*     */     }
/*     */     
/*     */ 
/*     */     public String getDescription()
/*     */     {
/* 151 */       return this.description;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 158 */     public String getSecondString() { return this.secondStr; }
/* 159 */     public boolean getTerminator() { return this.terminator; }
/*     */   }
/*     */   
/*     */   public static enum BPMErrorCode
/*     */   {
/* 164 */     BPM_ERROR_OK((byte)1, "Error OK", "BPM_ERROR_OK"), 
/* 165 */     BPM_ERROR_NOT_ENOUGH_INFLATING_PRESSURE((byte)2, "Insufficient pressure", "BPM_ERROR_NOT_ENOUGH_INFLATING_PRESSURE"), 
/* 166 */     BPM_ERROR_SYSTOLIC_NOT_FOUND((byte)3, "Systolic not found", "BPM_ERROR_SYSTOLIC_NOT_FOUND"), 
/* 167 */     BPM_ERROR_DIASTOLIC_NOT_FOUND((byte)4, "Diastolic not found", "BPM_ERROR_DIASTOLIC_NOT_FOUND"), 
/* 168 */     BPM_ERROR_PATIENT_MOVED_ARM((byte)5, "Arm Moved", "BPM_ERROR_PATIENT_MOVED_ARM"), 
/* 169 */     BPM_ERROR_AIR_LEAKAGE((byte)6, "Air Leakage", "BPM_ERROR_AIR_LEAKAGE"), 
/* 170 */     BPM_ERROR_ARRAY_IS_FULL((byte)7, "Array is full", "BPM_ERROR_ARRAY_IS_FULL"), 
/* 171 */     BPM_ERROR_NONE((byte)8, "No Error", "BPM_ERROR_NONE"), 
/* 172 */     BPM_ERROR_ERROR((byte)9, "Wrong Error id", "BPM_ERROR_ERROR");
/*     */     
/*     */     private final byte id;
/*     */     private final String description;
/*     */     private final String secondStr;
/*     */     
/*     */     private BPMErrorCode(byte id, String description, String secondStr) {
/* 179 */       this.id = id;
/* 180 */       this.description = description;
/* 181 */       this.secondStr = secondStr;
/*     */     }
/*     */     
/* 184 */     public byte getValue() { return this.id; }
/*     */     
/* 186 */     public String getDescription() { return this.description; }
/*     */     
/* 188 */     public String getSecondString() { return this.secondStr; }
/*     */   }
/*     */   
/*     */   public static enum Indication
/*     */   {
/* 193 */     GLU_BLOOD_DETECTED((byte)3, "Sample detected", "GLU_BLOOD_DETECTED"), 
/* 194 */     GLU_MEASUREMENT_COMPLETE_OK((byte)4, "Glucometry complete", "GLU_MEASUREMENT_COMPLETE_OK"), 
/* 195 */     GLU_CALIBRATION_COMPLETE_OK((byte)5, "Glucometry calibration complete", "GLU_CALIBRATION_COMPLETE_OK"), 
/* 196 */     BPM_MEASUREMENT_COMPLETE_OK((byte)8, "BPM measurement ready", "BPM_MEASUREMENT_COMPLETE_OK"), 
/* 197 */     BPM_MEASUREMENT_ERROR((byte)9, "BPM Error", "BPM_MEASUREMENT_ERROR"), 
/* 198 */     BPM_LEAK_TEST_COMPLETE((byte)12, "BPM testleak complete", "BPM_LEAK_TEST_COMPLETE"), 
/* 199 */     ECG_HEART_RATE_MEASUREMENT_COMPLETE_OK((byte)15, "ECG Complete", "ECG_HEART_RATE_MEASUREMENT_COMPLETE_OK"), 
/* 200 */     ECG_HEART_RATE_MEASUREMENT_ERROR((byte)16, "ECG Error", "ECG_HEART_RATE_MEASUREMENT_ERROR"), 
/* 201 */     ECG_HEART_BEAT_OCCURRED((byte)17, "ECG heartbeat detected", "ECG_HEART_BEAT_OCCURRED"), 
/* 202 */     ECG_DIAGNOSTIC_MODE_NEW_DATA_READY((byte)20, "ECG continuous data ready", "ECG_DIAGNOSTIC_MODE_NEW_DATA_READY"), 
/* 203 */     SPR_MEASUREMENT_COMPLETE_OK((byte)26, "Spirometry complete", "SPR_MEASUREMENT_COMPLETE_OK"), 
/* 204 */     SPR_MEASUREMENT_ERROR((byte)27, "Spirometry Error", "SPR_MEASUREMENT_ERROR"), 
/* 205 */     SPR_DIAGNOSTIC_MODE_NEW_DATA_READY((byte)30, "Spirometry continuous data ready", "SPR_DIAGNOSTIC_MODE_NEW_DATA_READY"), 
/* 206 */     SPR_DIAGNOSTIC_MODE_MEASUREMENT_COMPLETE_OK((byte)31, "Spirometry continuous complete", "SPR_DIAGNOSTIC_MODE_MEASUREMENT_COMPLETE_OK"), 
/* 207 */     SPR_DIAGNOSTIC_MODE_MEASUREMENT_ERROR((byte)32, "Spirometry continuous Error", "SPR_DIAGNOSTIC_MODE_MEASUREMENT_ERROR"), 
/* 208 */     POX_MEASUREMENT_COMPLETE_OK((byte)35, "Sp02 complete", "POX_MEASUREMENT_COMPLETE_OK"), 
/* 209 */     POX_MEASUREMENT_ERROR((byte)36, "Sp02 Error", "POX_MEASUREMENT_ERROR"), 
/* 210 */     POX_DIAGNOSTIC_MODE_NEW_DATA_READY((byte)39, "Sp02 continuous data ready", "POX_DIAGNOSTIC_MODE_NEW_DATA_READY"), 
/* 211 */     BPM_SEND_PRESSURE_VALUE_TO_PC((byte)40, "BPM pressure", "BPM_SEND_PRESSURE_VALUE_TO_PC"), 
/* 212 */     ERROR((byte)-4, "Invalid Indicator", "ERROR"), 
/* 213 */     NONE((byte)-5, "No Indicator", "NONE");
/*     */     
/*     */     private final byte id;
/*     */     private final String description;
/*     */     private final String secondStr;
/*     */     
/*     */     private Indication(byte id, String description, String secondStr)
/*     */     {
/* 221 */       this.id = id;
/* 222 */       this.description = description;
/* 223 */       this.secondStr = secondStr;
/*     */     }
/*     */     
/* 226 */     public byte getValue() { return this.id; }
/*     */     
/*     */ 
/*     */ 
/*     */     public String getDescription()
/*     */     {
/* 232 */       return this.description;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */     public String getSecondString()
/*     */     {
/* 239 */       return this.secondStr;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */     public byte[] toBuffer()
/*     */     {
/* 248 */       byte[] buffer = new byte[3];
/*     */       
/* 250 */       buffer[1] = this.id;
/*     */       
/* 252 */       return buffer;
/*     */     }
/*     */   }
/*     */   
/*     */   public static enum PacketId
/*     */   {
/* 258 */     NONE((byte)0, "No ID"), 
/* 259 */     ERROR((byte)-1, "Invalid ID"), 
/* 260 */     REQ((byte)82, "Request"), 
/* 261 */     CFM((byte)67, "Confirm"), 
/* 262 */     IND((byte)105, "Indicator");
/*     */     
/*     */     private final byte id;
/*     */     private final String description;
/*     */     
/*     */     private PacketId(byte id, String description) {
/* 268 */       this.id = id;
/* 269 */       this.description = description;
/*     */     }
/*     */     
/*     */ 
/* 273 */     public byte getValue() { return this.id; }
/* 274 */     public String getDescription() { return this.description; }
/*     */   }
/*     */   
/*     */   public static enum ConfirmationStatus {
/* 278 */     ERROR_OK((byte)0), 
/* 279 */     ERROR_BUSY((byte)1), 
/* 280 */     ERROR_INVALID_OPCODE((byte)2);
/*     */     
/*     */     private byte value;
/*     */     
/*     */     private ConfirmationStatus(byte value) {
/* 285 */       this.value = value;
/*     */     }
/*     */     
/*     */     public byte getValue() {
/* 289 */       return this.value;
/*     */     }
/*     */   }
/*     */   
/*     */   public static enum LeakTestStatus {
/* 294 */     NO_LEAK((byte)0), 
/* 295 */     MINOR_LEAK((byte)1), 
/* 296 */     MAYOR_LEAK((byte)2);
/*     */     
/*     */     private byte value;
/*     */     
/*     */     private LeakTestStatus(byte value) {
/* 301 */       this.value = value;
/*     */     }
/*     */     
/*     */     public byte getValue() {
/* 305 */       return this.value;
/*     */     }
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Types.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */