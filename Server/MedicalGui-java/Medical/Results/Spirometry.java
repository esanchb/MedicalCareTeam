/*     */ package Medical.Results;
/*     */ 
/*     */ import Medical.Parser;
/*     */ import java.io.PrintStream;
/*     */ import java.text.DecimalFormat;
/*     */ import java.util.ArrayList;
/*     */ import java.util.Collections;
/*     */ import java.util.List;
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
/*     */ public class Spirometry
/*     */ {
/*  30 */   private final String s_decimal_format = "0.0000";
/*     */   
/*     */   private String s_spr_float;
/*     */   
/*     */   private String s_SprTimeInMilliSeconds;
/*     */   
/*     */   private String s_FEV1_FVC_ratio;
/*     */   private String s_FIVC;
/*     */   private String s_PIF;
/*     */   private String s_FEV1;
/*     */   private String s_FVC;
/*     */   private String s_FET;
/*     */   private String s_PEF;
/*  43 */   private static List<Float> buffer_vol = Collections.synchronizedList(new ArrayList());
/*  44 */   private static List<Float> buffer_flow = Collections.synchronizedList(new ArrayList());
/*  45 */   private static List<Float> buffer_vol_full = Collections.synchronizedList(new ArrayList());
/*  46 */   private static List<Float> buffer_flow_full = Collections.synchronizedList(new ArrayList());
/*  47 */   private static List<Integer> int_buffer_vol = Collections.synchronizedList(new ArrayList());
/*  48 */   private static List<Integer> int_buffer_flow = Collections.synchronizedList(new ArrayList());
/*  49 */   private static List<Integer> int_buffer_results = Collections.synchronizedList(new ArrayList());
/*  50 */   private static double PEF = 0.0D;
/*  51 */   private static double FVC = 0.0D;
/*  52 */   private static double PIF = 0.0D;
/*  53 */   private static double FIVC = 0.0D;
/*  54 */   private static double FEV1 = 0.0D;
/*  55 */   private static double FET = 0.0D;
/*  56 */   private static double FEV1_FVC_ratio = 0.0D;
/*  57 */   private static double SprFloat = 0.0D;
/*     */   
/*     */   private int spr_flow;
/*     */   private int spr;
/*     */   private float f_spr_flow;
/*     */   private float f_spr;
/*  63 */   private static int SprTimeInMilliSeconds = 0;
/*  64 */   private final byte SPR_INHALATION = 0;
/*  65 */   private final byte SPR_EXHALATION = 1;
/*  66 */   private final byte SPR_INIT_STATE = 0;
/*  67 */   private byte SprState = 0;
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
/*     */   public Spirometry(byte[] buffer)
/*     */   {
/*  86 */     if ((buffer[0] == 0) || (buffer[0] == 1))
/*     */     {
/*  88 */       for (int count = 1; count < (buffer.length - 1) / 2; count += 2) {
/*  89 */         int temp = Parser.toIntValue(buffer[count], buffer[(count + 1)]);
/*     */         
/*  91 */         if (buffer[0] == 0) {
/*  92 */           temp = -temp;
/*     */         }
/*     */         
/*  95 */         int_buffer_flow.add(new Integer(temp));
/*  96 */         sprCalculationFlow(temp);
/*  97 */         buffer_flow.add(new Float(this.f_spr));
/*     */       }
/*     */       
/*     */ 
/*     */ 
/* 102 */       for (int count = 17; count < buffer.length - 1; count += 2) {
/* 103 */         int temp = Parser.toIntValue(buffer[count], buffer[(count + 1)]);
/* 104 */         int_buffer_vol.add(new Integer(temp));
/* 105 */         sprCalculationVol(temp);
/* 106 */         buffer_vol.add(new Float(this.f_spr));
/*     */ 
/*     */       }
/*     */       
/*     */ 
/*     */     }
/* 112 */     else if (buffer[0] == 2)
/*     */     {
/*     */ 
/*     */ 
/*     */ 
/* 117 */       for (int count = 1; count < buffer.length; count += 2) {
/* 118 */         int temp = Parser.toIntValue(buffer[count], buffer[(count + 1)]);
/* 119 */         int_buffer_results.add(new Integer(temp));
/*     */       }
/*     */       
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 127 */       for (int count = 0; count < int_buffer_results.size(); count++)
/*     */       {
/* 129 */         switch (count)
/*     */         {
/*     */         case 0: 
/* 132 */           sprCalculationFIVC(((Integer)int_buffer_results.get(count)).intValue());
/* 133 */           break;
/*     */         
/*     */         case 1: 
/* 136 */           sprCalculationPIF(((Integer)int_buffer_results.get(count)).intValue());
/* 137 */           break;
/*     */         
/*     */         case 2: 
/* 140 */           sprCalculationFVC(((Integer)int_buffer_results.get(count)).intValue());
/* 141 */           break;
/*     */         
/*     */         case 3: 
/* 144 */           sprCalculationFEV1(((Integer)int_buffer_results.get(count)).intValue());
/* 145 */           break;
/*     */         
/*     */         case 4: 
/* 148 */           sprCalculationFEV1_FVC_ratio(((Integer)int_buffer_results.get(count)).intValue());
/* 149 */           break;
/*     */         
/*     */         case 5: 
/* 152 */           sprCalculationPEF(((Integer)int_buffer_results.get(count)).intValue());
/* 153 */           break;
/*     */         
/*     */         case 6: 
/* 156 */           sprCalculationFET(((Integer)int_buffer_results.get(count)).intValue());
/*     */         
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */         }
/*     */         
/*     */       }
/*     */     }
/* 169 */     else if (buffer[0] == 3)
/*     */     {
/* 171 */       System.out.println("Error");
/*     */     }
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
/*     */   private void sprCalculationVol(int flowAdcValue)
/*     */   {
/* 213 */     float flowFloat = flowAdcValue / 1000.0F;
/* 214 */     SprFloat = flowFloat;
/*     */     
/*     */ 
/*     */ 
/* 218 */     this.s_spr_float = new DecimalFormat("0.0000").format(SprFloat);
/*     */     
/* 220 */     this.spr = ((int)(SprFloat * 17.0D));
/* 221 */     this.f_spr = ((float)(SprFloat * 18.4D));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */   private void sprCalculationFlow(int flowAdcValue)
/*     */   {
/* 228 */     float flowFloat = flowAdcValue / 1000.0F;
/* 229 */     SprFloat = flowFloat;
/*     */     
/*     */ 
/*     */ 
/* 233 */     this.s_spr_float = new DecimalFormat("0.0000").format(SprFloat);
/*     */     
/* 235 */     this.spr = ((int)(SprFloat * 17.0D));
/* 236 */     this.f_spr = ((float)(SprFloat * 9.7D));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationFIVC(int flowAdcValue)
/*     */   {
/* 244 */     float flowFloat = flowAdcValue / 1000.0F;
/* 245 */     SprFloat = flowFloat;
/*     */     
/* 247 */     FIVC = SprFloat;
/*     */     
/*     */ 
/*     */ 
/* 251 */     this.s_FIVC = new DecimalFormat("0.0000").format(FIVC);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationPIF(int flowAdcValue)
/*     */   {
/* 261 */     float flowFloat = flowAdcValue / 1000.0F;
/* 262 */     SprFloat = flowFloat;
/*     */     
/* 264 */     PIF = SprFloat;
/*     */     
/* 266 */     this.s_PIF = new DecimalFormat("0.0000").format(PIF);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationFVC(int flowAdcValue)
/*     */   {
/* 276 */     float flowFloat = flowAdcValue / 1000.0F;
/* 277 */     SprFloat = flowFloat;
/*     */     
/* 279 */     FVC = SprFloat;
/*     */     
/* 281 */     this.s_FVC = new DecimalFormat("0.0000").format(FVC);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationFEV1(int flowAdcValue)
/*     */   {
/* 293 */     float flowFloat = flowAdcValue / 1000.0F;
/* 294 */     SprFloat = flowFloat;
/*     */     
/* 296 */     FEV1 = SprFloat;
/*     */     
/* 298 */     this.s_FEV1 = new DecimalFormat("0.0000").format(FEV1);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationFEV1_FVC_ratio(int flowAdcValue)
/*     */   {
/* 309 */     float flowFloat = flowAdcValue / 1000.0F;
/* 310 */     SprFloat = flowFloat;
/*     */     
/* 312 */     FEV1_FVC_ratio = SprFloat;
/*     */     
/* 314 */     this.s_FEV1_FVC_ratio = new DecimalFormat("0.0000").format(FEV1_FVC_ratio);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationPEF(int flowAdcValue)
/*     */   {
/* 325 */     float flowFloat = flowAdcValue / 1000.0F;
/* 326 */     SprFloat = flowFloat;
/*     */     
/* 328 */     PEF = SprFloat;
/*     */     
/* 330 */     this.s_PEF = new DecimalFormat("0.0000").format(PEF);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private void sprCalculationFET(int flowAdcValue)
/*     */   {
/* 339 */     float flowFloat = flowAdcValue / 1000.0F;
/* 340 */     SprFloat = flowFloat;
/*     */     
/* 342 */     FET = SprFloat;
/*     */     
/* 344 */     this.s_FET = new DecimalFormat("0.0000").format(FET);
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
/* 362 */   public String getFIVC() { return this.s_FIVC; }
/* 363 */   public String getPIF() { return this.s_PIF; }
/* 364 */   public String getFEV1() { return this.s_FEV1; }
/* 365 */   public String getFVC() { return this.s_FVC; }
/* 366 */   public String getFET() { return this.s_FET; }
/* 367 */   public String getPEF() { return this.s_PEF; }
/* 368 */   public String getTimeMsec() { return this.s_SprTimeInMilliSeconds; }
/* 369 */   public double getf_spr() { return this.f_spr; }
/* 370 */   public String getFev1FvcRatio() { return this.s_FEV1_FVC_ratio; }
/*     */   
/* 372 */   public double getFIVCDouble() { return FIVC; }
/* 373 */   public double getPIFDouble() { return PIF; }
/* 374 */   public double getFEV1Double() { return FEV1; }
/* 375 */   public double getFVCDouble() { return FVC; }
/* 376 */   public double getFETDouble() { return FET; }
/* 377 */   public double getPEFDouble() { return PEF; }
/* 378 */   public int getTimeMsecDouble() { return SprTimeInMilliSeconds; }
/*     */   
/* 380 */   public double getFev1FvcRatioDouble() { return FEV1_FVC_ratio; }
/*     */   
/*     */ 
/* 383 */   public List<Float> getBufferVol() { return buffer_vol; }
/* 384 */   public List<Float> getBufferFlow() { return buffer_flow; }
/*     */   
/* 386 */   public List<Float> getBufferFullVol() { return buffer_vol_full; }
/* 387 */   public List<Float> getBufferFullFlow() { return buffer_flow_full; }
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
/*     */   public void recalculateVol()
/*     */   {
/* 410 */     System.out.println("Spirometry volume recalculation");
/* 411 */     for (int count = 0; count < buffer_vol.size(); count++)
/*     */     {
/* 413 */       sprCalculationVol(((Integer)int_buffer_vol.get(count)).intValue());
/* 414 */       buffer_vol_full.add(new Float(this.f_spr));
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void recalculateFlow()
/*     */   {
/* 423 */     System.out.println("Spirometry flow recalculation");
/* 424 */     for (int count = 0; count < buffer_flow.size(); count++)
/*     */     {
/* 426 */       sprCalculationFlow(((Integer)int_buffer_flow.get(count)).intValue());
/* 427 */       buffer_flow_full.add(new Float(this.f_spr));
/*     */     }
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
/*     */   public void printAll()
/*     */   {
/* 450 */     System.out.println("Spirometry data bulk");
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
/* 464 */     System.out.println("Vol values X");
/* 465 */     for (int count = 0; count < buffer_vol.size(); count++) {
/* 466 */       System.out.println(buffer_vol.get(count));
/*     */     }
/*     */     
/* 469 */     System.out.println("Flow values Y");
/* 470 */     for (int count = 0; count < buffer_flow.size(); count++) {
/* 471 */       System.out.println(buffer_flow.get(count));
/*     */     }
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
/*     */   public void newexam()
/*     */   {
/* 486 */     buffer_vol_full.clear();
/* 487 */     buffer_flow_full.clear();
/* 488 */     buffer_vol.clear();
/* 489 */     buffer_flow.clear();
/* 490 */     int_buffer_results.clear();
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Results\Spirometry.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */