/*     */ package Medical.Results;
/*     */ 
/*     */ import Medical.Types.BPMErrorCode;
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
/*     */ public class BloodPressure
/*     */ {
/*     */   private int pressure;
/*     */   private int mean_pressure;
/*     */   private int sistolic;
/*     */   private int diastolic;
/*     */   private int heart_rate;
/*     */   private int leak_test_result;
/*     */   private Types.BPMErrorCode error_code;
/*     */   
/*     */   public BloodPressure(int error_code)
/*     */   {
/*  26 */     this.pressure = 0;
/*  27 */     this.mean_pressure = 0;
/*  28 */     this.sistolic = 0;
/*  29 */     this.diastolic = 0;
/*  30 */     this.heart_rate = 0;
/*  31 */     this.leak_test_result = 0;
/*     */     
/*  33 */     switch (error_code) {
/*     */     case 0: 
/*  35 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_OK;
/*  36 */       break;
/*     */     case 1: 
/*  38 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_NOT_ENOUGH_INFLATING_PRESSURE;
/*  39 */       break;
/*     */     case 2: 
/*  41 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_SYSTOLIC_NOT_FOUND;
/*  42 */       break;
/*     */     case 3: 
/*  44 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_DIASTOLIC_NOT_FOUND;
/*  45 */       break;
/*     */     case 4: 
/*  47 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_PATIENT_MOVED_ARM;
/*  48 */       break;
/*     */     case 5: 
/*  50 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_AIR_LEAKAGE;
/*  51 */       break;
/*     */     case 6: 
/*  53 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_ARRAY_IS_FULL;
/*  54 */       break;
/*     */     default: 
/*  56 */       this.error_code = Types.BPMErrorCode.BPM_ERROR_ERROR;
/*     */     }
/*     */     
/*     */   }
/*     */   
/*     */   public BloodPressure(int pressure, int mean_pressure, int sistolic, int diastolic, int heart_rate, int leak_test_result)
/*     */   {
/*  63 */     this.pressure = pressure;
/*  64 */     this.mean_pressure = mean_pressure;
/*  65 */     this.sistolic = sistolic;
/*  66 */     this.diastolic = diastolic;
/*  67 */     this.heart_rate = heart_rate;
/*  68 */     this.leak_test_result = leak_test_result;
/*     */     
/*  70 */     this.error_code = Types.BPMErrorCode.BPM_ERROR_NONE;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getLeakTestResult()
/*     */   {
/*  82 */     return this.leak_test_result;
/*     */   }
/*     */   
/*     */   public int getPressure()
/*     */   {
/*  87 */     return this.pressure;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getMeanPressure()
/*     */   {
/*  95 */     return this.mean_pressure;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getSistolic()
/*     */   {
/* 103 */     return this.sistolic;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getDiastolic()
/*     */   {
/* 111 */     return this.diastolic;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getHeartRate()
/*     */   {
/* 119 */     return this.heart_rate;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */   public Types.BPMErrorCode getErrorCode()
/*     */   {
/* 126 */     return this.error_code;
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\BloodPressure.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */