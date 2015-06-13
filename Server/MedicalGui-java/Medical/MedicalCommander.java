/*     */ package Medical;
/*     */ 
/*     */ import Medical.Results.BloodPressure;
/*     */ import Medical.Results.ElectroCardioGram;
/*     */ import Medical.Results.Glucometry;
/*     */ import Medical.Results.Height;
/*     */ import Medical.Results.PulseOximetry;
/*     */ import Medical.Results.Spirometry;
/*     */ import Medical.Results.Temperature;
/*     */ import Medical.Results.Weight;
/*     */ import java.io.PrintStream;
/*     */ import java.util.ArrayList;
/*     */ import java.util.Iterator;
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
/*     */ public class MedicalCommander
/*     */   implements Listener
/*     */ {
/*  35 */   private Communication port = null;
/*  36 */   private boolean debug = false;
/*  37 */   private boolean error = true;
/*     */   
/*     */ 
/*  40 */   private Parser Parser = null;
/*     */   
/*     */ 
/*     */ 
/*  44 */   private String serial_port = "COM4";
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*  53 */   private Types.MeasurementStatus measurement_status = Types.MeasurementStatus.NONE;
/*  54 */   private List<MedicalCommandListener> listenerList = null;
/*     */   
/*  56 */   private Types.Request request = Types.Request.NONE;
/*  57 */   private Types.Indication indication = Types.Indication.NONE;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*  62 */   private final boolean CONFIRMATION_MATCH = false;
/*     */   static final String HEXES = "0123456789ABCDEF";
/*     */   
/*  65 */   public MedicalCommander() { PortChooser c = new PortChooser(null);
/*  66 */     c.setVisible(true);
/*  67 */     System.out.println("You chose " + c.getSelectedName() + " (known by " + c.getSelectedIdentifier() + ").");
/*     */     
/*     */ 
/*     */ 
/*  71 */     this.serial_port = c.getSelectedName();
/*  72 */     this.Parser = new Parser();
/*  73 */     this.Parser.addListener(this);
/*  74 */     System.setProperty("gnu.io.rxtx.SerialPorts", this.serial_port);
/*     */     
/*  76 */     this.port = new Communication(this.serial_port, this.Parser);
/*     */     
/*     */ 
/*  79 */     this.port.open();
/*  80 */     this.measurement_status = Types.MeasurementStatus.STAND_BY;
/*  81 */     this.listenerList = new ArrayList();
/*     */   }
/*     */   
/*     */   private void debugLog(String log)
/*     */   {
/*  86 */     if (this.debug)
/*  87 */       System.out.println(log);
/*     */   }
/*     */   
/*     */   private void errorLog(String log) {
/*  91 */     if (this.error) {
/*  92 */       System.out.println(log);
/*     */     }
/*     */   }
/*     */   
/*     */   public static String getHex(byte[] raw)
/*     */   {
/*  98 */     if (raw == null) {
/*  99 */       return null;
/*     */     }
/* 101 */     StringBuilder hex = new StringBuilder(2 * raw.length);
/* 102 */     for (byte b : raw) {
/* 103 */       hex.append("0123456789ABCDEF".charAt((b & 0xF0) >> 4)).append("0123456789ABCDEF".charAt(b & 0xF)).append(" ");
/*     */     }
/*     */     
/*     */ 
/* 107 */     return hex.toString();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void medicalDataAvailable(Event evt)
/*     */   {
/* 118 */     DataFromHW data = evt.getMedicalData();
/*     */     
/* 120 */     Types.Request temp_request = data.getRequest();
/* 121 */     Types.Indication temp_indicator = data.getIndication();
/*     */     
/* 123 */     byte[] values = data.getBuffer();
/*     */     
/* 125 */     DataFromCommander results = new DataFromCommander();
/* 126 */     results.setRequest(temp_request);
/* 127 */     results.setIndication(temp_indicator);
/*     */     
/* 129 */     if (!data.getErrorState())
/*     */     {
/* 131 */       debugLog("Info: Message Parsed correctly Packet id " + data.getPacketId().getDescription() + " Request " + temp_request.getDescription() + " Indicator " + temp_indicator.getDescription());
/*     */       
/*     */ 
/*     */ 
/*     */ 
/* 136 */       if (data.getPacketId() == Types.PacketId.CFM) {
/* 137 */         debugLog("Info: Confirmation");
/*     */         
/* 139 */         if ((this.measurement_status == Types.MeasurementStatus.STARTED) || (this.measurement_status == Types.MeasurementStatus.ABORTED) || (this.measurement_status == Types.MeasurementStatus.POOLING_ABORTED))
/*     */         {
/*     */ 
/*     */ 
/* 143 */           if (temp_request != this.request) { getClass();
/*     */           }
/* 145 */           debugLog("Info: Request received " + temp_request.getDescription());
/*     */           
/* 147 */           if (temp_request.getTerminator() == true) {
/* 148 */             debugLog("Info: Terminator Confirmation Received");
/*     */             
/* 150 */             switch (temp_request) {
/*     */             case TMP_READ_TEMPERATURE: 
/* 152 */               if (values.length == 2) {
/* 153 */                 results.temperature = new Temperature(Parser.toIntValue(values[0], values[1]));
/*     */                 
/* 155 */                 debugLog("Info: Temperature " + results.temperature.get());
/* 156 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               else {
/* 159 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 160 */                 results.Error();
/* 161 */                 errorLog("Error: Wrong temperature data size " + values.length);
/* 162 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/* 164 */               break;
/*     */             case HGT_READ_HEIGHT: 
/* 166 */               if (values.length == 1) {
/* 167 */                 results.height = new Height(Parser.toUnsigned(values[0]));
/*     */                 
/* 169 */                 debugLog("Info: Height " + results.height.get());
/* 170 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               else {
/* 173 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 174 */                 results.Error();
/* 175 */                 errorLog("Error: Wrong height data size " + values.length);
/* 176 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/* 178 */               break;
/*     */             case WGT_READ_WEIGHT: 
/* 180 */               if (values.length == 1) {
/* 181 */                 results.weight = new Weight(Parser.toUnsigned(values[0]));
/*     */                 
/* 183 */                 debugLog("Info: Weight " + results.weight.get());
/* 184 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               else {
/* 187 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 188 */                 results.Error();
/* 189 */                 debugLog("Info: Wrong weight data size " + values.length);
/* 190 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               break;
/*     */             }
/* 194 */             debugLog("Info: Stand by State reached");
/* 195 */             this.measurement_status = Types.MeasurementStatus.STAND_BY;
/*     */           }
/*     */           else
/*     */           {
/* 199 */             this.measurement_status = Types.MeasurementStatus.CONFIRMED;
/* 200 */             debugLog("Info: Confirmed State reached");
/*     */             
/* 202 */             if ((temp_request == Types.Request.ECG_DIAGNOSTIC_MODE_START_MEASUREMENT) || (temp_request == Types.Request.POX_DIAGNOSTIC_MODE_START_MEASUREMENT) || (temp_request == Types.Request.SPR_DIAGNOSTIC_MODE_START_MEASUREMENT) || (temp_request == Types.Request.BPM_START_MEASUREMENT))
/*     */             {
/*     */ 
/*     */ 
/*     */ 
/* 207 */               this.measurement_status = Types.MeasurementStatus.POOLING;
/* 208 */               debugLog("Info: Pooling State reached with " + temp_request.getDescription());
/*     */             }
/*     */             
/* 211 */             if (this.measurement_status == Types.MeasurementStatus.STARTED) {
/* 212 */               if (values.length != 1) {
/* 213 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 214 */                 results.Error();
/* 215 */                 errorLog("Error: Wrong state reached,unspected data returned after Request");
/*     */                 
/* 217 */                 triggerEvent(new CommandEvent(this, results));
/*     */ 
/*     */               }
/* 220 */               else if (values[0] == Types.ConfirmationStatus.ERROR_OK.getValue()) {
/* 221 */                 this.measurement_status = Types.MeasurementStatus.CONFIRMED;
/* 222 */                 debugLog("Info: confirmed State reached with " + temp_request.getDescription());
/* 223 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/* 225 */               else if (values[0] == Types.ConfirmationStatus.ERROR_INVALID_OPCODE.getValue()) {
/* 226 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 227 */                 results.Error();
/* 228 */                 errorLog("Error: Wrong state reached with " + temp_request.getDescription());
/* 229 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/* 231 */               else if (values[0] == Types.ConfirmationStatus.ERROR_BUSY.getValue()) {
/* 232 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 233 */                 results.Error();
/* 234 */                 errorLog("Error: Busy state reached with " + temp_request.getDescription());
/* 235 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               else {
/* 238 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 239 */                 results.Error();
/* 240 */                 errorLog("Error: Wrong state reached with " + temp_request.getDescription());
/* 241 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               
/*     */ 
/*     */             }
/* 246 */             else if (this.measurement_status == Types.MeasurementStatus.ABORTED) {
/* 247 */               if (values.length == 0) {
/* 248 */                 this.measurement_status = Types.MeasurementStatus.ERROR;
/* 249 */                 results.Error();
/* 250 */                 errorLog("Error: Wrong state reached,unspected data returned after Abort");
/*     */                 
/* 252 */                 triggerEvent(new CommandEvent(this, results));
/*     */               }
/*     */               else {
/* 255 */                 this.measurement_status = Types.MeasurementStatus.STAND_BY;
/* 256 */                 debugLog("Info: Stand by State reached with " + temp_request.getDescription());
/*     */ 
/*     */               }
/*     */               
/*     */ 
/*     */             }
/*     */             
/*     */ 
/*     */           }
/*     */           
/*     */ 
/*     */ 
/*     */         }
/*     */         else
/*     */         {
/*     */ 
/*     */ 
/* 273 */           errorLog("Error: Wrong state reached, invalid previous state " + this.measurement_status);
/* 274 */           this.measurement_status = Types.MeasurementStatus.ERROR;
/* 275 */           results.Error();
/* 276 */           triggerEvent(new CommandEvent(this, results));
/*     */         }
/*     */       }
/* 279 */       else if (data.getPacketId() == Types.PacketId.IND)
/*     */       {
/* 281 */         if ((this.measurement_status == Types.MeasurementStatus.POOLING) || (this.measurement_status == Types.MeasurementStatus.POOLING_ABORTED))
/*     */         {
/* 283 */           debugLog("Info: Indication Pooling Indicator " + temp_indicator.getDescription());
/*     */           
/* 285 */           switch (temp_indicator) {
/*     */           case BPM_SEND_PRESSURE_VALUE_TO_PC: 
/* 287 */             results.blood_pressure = new BloodPressure(Parser.toUnsigned(values[0]), 0, 0, 0, 0, 0);
/*     */             
/* 289 */             debugLog("Info: Inflating bracelet pressure " + results.blood_pressure.getPressure());
/*     */             
/* 291 */             triggerEvent(new CommandEvent(this, results));
/* 292 */             break;
/*     */           case BPM_MEASUREMENT_COMPLETE_OK: 
/* 294 */             results.blood_pressure = new BloodPressure(0, Parser.toUnsigned(values[3]), Parser.toUnsigned(values[0]), Parser.toUnsigned(values[1]), Parser.toUnsigned(values[2]), 0);
/*     */             
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 301 */             debugLog("Info: Blood presure results Sistolic " + results.blood_pressure.getSistolic() + "Diastolic " + results.blood_pressure.getDiastolic() + "Heart Rate " + results.blood_pressure.getHeartRate());
/*     */             
/*     */ 
/*     */ 
/* 305 */             this.measurement_status = Types.MeasurementStatus.STAND_BY;
/* 306 */             triggerEvent(new CommandEvent(this, results));
/* 307 */             break;
/*     */           
/*     */           case BPM_MEASUREMENT_ERROR: 
/* 310 */             results.blood_pressure = new BloodPressure(Parser.toUnsigned(values[0]));
/*     */             
/* 312 */             debugLog("Info: BPM Error Received " + results.blood_pressure.getErrorCode().getDescription());
/*     */             
/* 314 */             this.measurement_status = Types.MeasurementStatus.STAND_BY;
/* 315 */             triggerEvent(new CommandEvent(this, results));
/* 316 */             break;
/*     */           case ECG_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/* 318 */             results.ecg = new ElectroCardioGram(Parser.toUnsigned(values[66]), values);
/*     */             
/*     */ 
/* 321 */             debugLog("Info: ECG pulse rate " + results.ecg.getHeartRate());
/*     */             
/* 323 */             triggerEvent(new CommandEvent(this, results));
/* 324 */             break;
/*     */           
/*     */           case SPR_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/* 327 */             results.spirometry = new Spirometry(values);
/*     */             
/*     */ 
/* 330 */             debugLog("Info: Spirometry Results FIVC:" + results.spirometry.getFIVCDouble() + " [l] " + "PIF:" + results.spirometry.getPIFDouble() + " [l/s] " + "FEV:" + results.spirometry.getFEV1Double() + " [l] " + "FVC:" + results.spirometry.getFVCDouble() + " [l] " + "FET:" + results.spirometry.getFETDouble() + " [s] " + "PEF:" + results.spirometry.getPEFDouble() + " [l/s] ");
/*     */             
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 338 */             triggerEvent(new CommandEvent(this, results));
/* 339 */             break;
/*     */           case POX_DIAGNOSTIC_MODE_NEW_DATA_READY: 
/* 341 */             debugLog("Info: POX_DIAGNOSTIC_MODE_NEW_DATA_READY ");
/*     */             try {
/* 343 */               results.pulse_oximetry = new PulseOximetry(Parser.toUnsigned(values[66]), Parser.toUnsigned(values[67]), values);
/*     */ 
/*     */             }
/*     */             catch (Exception e)
/*     */             {
/*     */ 
/* 349 */               errorLog("Error: diagnostic oximetry " + e.getMessage());
/* 350 */               e.printStackTrace();
/*     */             }
/*     */             
/*     */ 
/* 354 */             debugLog("Info: Pulse oximetry Saturation " + results.pulse_oximetry.getOxigenSaturation() + " Heart rate " + results.pulse_oximetry.getHeartRate());
/*     */             
/*     */ 
/* 357 */             triggerEvent(new CommandEvent(this, results));
/*     */           }
/*     */           
/*     */         }
/* 361 */         else if ((this.measurement_status == Types.MeasurementStatus.CONFIRMED) || (this.measurement_status == Types.MeasurementStatus.ABORTED))
/*     */         {
/* 363 */           debugLog("Info: Indication Result");
/*     */           
/* 365 */           switch (temp_indicator) {
/*     */           case GLU_BLOOD_DETECTED: 
/*     */             break;
/*     */           case GLU_MEASUREMENT_COMPLETE_OK: 
/* 369 */             results.glucometry = new Glucometry(Parser.toIntValue(values[0], values[1]), 0);
/*     */             
/* 371 */             debugLog("Info: Glucose level " + results.glucometry.getGlucoseLevel());
/*     */             
/* 373 */             triggerEvent(new CommandEvent(this, results));
/* 374 */             break;
/*     */           case GLU_CALIBRATION_COMPLETE_OK: 
/* 376 */             results.glucometry = new Glucometry(0, Parser.toIntValue(values[0], values[1]));
/*     */             
/* 378 */             debugLog("Info: Glucometer calibration value" + results.glucometry.getCalibration());
/*     */             
/* 380 */             triggerEvent(new CommandEvent(this, results));
/* 381 */             break;
/*     */           case BPM_MEASUREMENT_ERROR: 
/*     */             break;
/*     */           case BPM_LEAK_TEST_COMPLETE: 
/* 385 */             results.blood_pressure = new BloodPressure(0, 0, 0, 0, 0, Parser.toUnsigned(values[0]));
/*     */             
/*     */ 
/* 388 */             debugLog("Info: Leak test complete " + results.blood_pressure.getLeakTestResult());
/*     */             
/* 390 */             triggerEvent(new CommandEvent(this, results));
/* 391 */             break;
/*     */           case ECG_HEART_RATE_MEASUREMENT_COMPLETE_OK: 
/* 393 */             results.ecg = new ElectroCardioGram(Parser.toUnsigned(values[0]));
/*     */             
/*     */ 
/* 396 */             debugLog("Info: ECG heat rate " + results.ecg.getHeartRate());
/*     */             
/* 398 */             triggerEvent(new CommandEvent(this, results));
/* 399 */             break;
/*     */           case ECG_HEART_RATE_MEASUREMENT_ERROR: 
/*     */             break;
/*     */           case POX_MEASUREMENT_COMPLETE_OK: 
/* 403 */             results.pulse_oximetry = new PulseOximetry(Parser.toUnsigned(values[0]), Parser.toUnsigned(values[1]));
/*     */             
/*     */ 
/*     */ 
/*     */ 
/* 408 */             debugLog("Info: Pulse oximetry Saturation " + results.pulse_oximetry.getOxigenSaturation() + " Heart rate " + results.pulse_oximetry.getHeartRate());
/*     */             
/*     */ 
/* 411 */             triggerEvent(new CommandEvent(this, results));
/* 412 */             break;
/*     */           
/*     */           }
/*     */           
/*     */         }
/*     */         else
/*     */         {
/* 419 */           this.measurement_status = Types.MeasurementStatus.ERROR;
/* 420 */           results.Error();
/* 421 */           errorLog("Error: Wrong state reached, Indicator unspected");
/* 422 */           triggerEvent(new CommandEvent(this, results));
/*     */         }
/*     */         
/*     */       }
/*     */       else
/*     */       {
/* 428 */         this.measurement_status = Types.MeasurementStatus.ERROR;
/* 429 */         results.Error();
/* 430 */         errorLog("Error: Wrong state reached, bad Packet ID " + data.getPacketId().getDescription());
/* 431 */         triggerEvent(new CommandEvent(this, results));
/*     */       }
/*     */     }
/*     */     else
/*     */     {
/* 436 */       this.measurement_status = Types.MeasurementStatus.ERROR;
/* 437 */       results.Error();
/* 438 */       errorLog("Error: Wrong state reached, parse error! Packet id " + data.getPacketId().getDescription() + " Request " + temp_request.getDescription() + " Indicator " + temp_indicator.getDescription());
/*     */       
/*     */ 
/*     */ 
/* 442 */       triggerEvent(new CommandEvent(this, results));
/*     */     }
/*     */   }
/*     */   
/*     */   public String replaceStrAt(String original, int index, String replacement) {
/* 447 */     return original.substring(0, index) + replacement + original.substring(index + 1);
/*     */   }
/*     */   
/*     */   private boolean starter(Types.Request request)
/*     */   {
/* 452 */     this.measurement_status = Types.MeasurementStatus.STARTED;
/* 453 */     debugLog("Info: Started state reached, waiting for confirmation " + request.getDescription());
/*     */     
/* 455 */     this.request = request;
/* 456 */     boolean status = this.port.write(request.toBuffer());
/*     */     
/* 458 */     if (!status) {
/* 459 */       this.measurement_status = Types.MeasurementStatus.ERROR;
/* 460 */       errorLog("Error: Error Sending Request");
/*     */     }
/*     */     
/* 463 */     return status;
/*     */   }
/*     */   
/*     */   private boolean starter(Types.Request request, int calibration)
/*     */   {
/* 468 */     this.measurement_status = Types.MeasurementStatus.STARTED;
/* 469 */     debugLog("Info: Started state reached, waiting for confirmation " + request.getDescription());
/*     */     
/* 471 */     this.request = request;
/* 472 */     boolean status = this.port.write(request.toBuffer(calibration));
/*     */     
/* 474 */     if (!status) {
/* 475 */       this.measurement_status = Types.MeasurementStatus.ERROR;
/* 476 */       errorLog("Error: Error Sending Request");
/*     */     }
/* 478 */     return status;
/*     */   }
/*     */   
/*     */   public boolean restoreCommBoard() {
/* 482 */     return this.port.write(Types.Request.SYS_RESTART_SYSTEM.toBuffer());
/*     */   }
/*     */   
/*     */   public boolean startGlucometry() {
/* 486 */     return starter(Types.Request.GLU_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean startGlucometryCalibration(int calibration) {
/* 490 */     return starter(Types.Request.GLU_START_CALIBRATION, calibration);
/*     */   }
/*     */   
/*     */   public boolean startBloodPressure() {
/* 494 */     return starter(Types.Request.BPM_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean startBloodPressureLeakTest() {
/* 498 */     return starter(Types.Request.BPM_START_LEAK_TEST);
/*     */   }
/*     */   
/*     */   public boolean startEGC() {
/* 502 */     return starter(Types.Request.ECG_HEART_RATE_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean startECGDiagnostic() {
/* 506 */     return starter(Types.Request.ECG_DIAGNOSTIC_MODE_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean startSpirometryDiagnostic()
/*     */   {
/* 514 */     return starter(Types.Request.SPR_DIAGNOSTIC_MODE_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean startPulseOximetry() {
/* 518 */     return starter(Types.Request.POX_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean startPulseOximetryDiagnostic() {
/* 522 */     return starter(Types.Request.POX_DIAGNOSTIC_MODE_START_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean startTemperature() {
/* 526 */     return starter(Types.Request.TMP_READ_TEMPERATURE);
/*     */   }
/*     */   
/* 529 */   public boolean startHeight() { return starter(Types.Request.HGT_READ_HEIGHT); }
/*     */   
/*     */   public boolean startWeight()
/*     */   {
/* 533 */     return starter(Types.Request.WGT_READ_WEIGHT);
/*     */   }
/*     */   
/*     */   private boolean stopper(Types.Request request) {
/* 537 */     return stopper(request, Types.MeasurementStatus.ABORTED);
/*     */   }
/*     */   
/*     */   private boolean stopper(Types.Request request, Types.MeasurementStatus measurement_status)
/*     */   {
/* 542 */     this.measurement_status = measurement_status;
/* 543 */     debugLog("Info: Aborted state reached, waiting for confirmation" + request.getDescription());
/*     */     
/* 545 */     this.request = request;
/* 546 */     boolean status = this.port.write(request.toBuffer());
/*     */     
/* 548 */     if (!status) {
/* 549 */       measurement_status = Types.MeasurementStatus.ERROR;
/* 550 */       errorLog("Error: Sending abort signal");
/*     */     }
/*     */     
/* 553 */     return status;
/*     */   }
/*     */   
/*     */   public boolean stopGlucometry() {
/* 557 */     return stopper(Types.Request.GLU_ABORT_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean stopBloodPressure() {
/* 561 */     return stopper(Types.Request.BPM_ABORT_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean stopBloodPressureLeakTest() {
/* 565 */     return stopper(Types.Request.BPM_ABORT_LEAK_TEST);
/*     */   }
/*     */   
/*     */   public boolean stopECG() {
/* 569 */     return stopper(Types.Request.ECG_HEART_RATE_ABORT_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean stopECGDiagnostic() {
/* 573 */     return stopper(Types.Request.ECG_DIAGNOSTIC_MODE_STOP_MEASUREMENT, Types.MeasurementStatus.POOLING_ABORTED);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean stopSpirometryDiagnostic()
/*     */   {
/* 581 */     return stopper(Types.Request.SPR_DIAGNOSTIC_MODE_STOP_MEASUREMENT, Types.MeasurementStatus.POOLING_ABORTED);
/*     */   }
/*     */   
/*     */   public boolean stopPulseOximetry() {
/* 585 */     return stopper(Types.Request.POX_ABORT_MEASUREMENT);
/*     */   }
/*     */   
/*     */   public boolean stopPulseOximetryDiagnostic() {
/* 589 */     return stopper(Types.Request.POX_DIAGNOSTIC_MODE_STOP_MEASUREMENT, Types.MeasurementStatus.POOLING_ABORTED);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public synchronized void addListener(MedicalCommandListener l)
/*     */   {
/* 599 */     this.listenerList.add(l);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public synchronized void removeListener(MedicalCommandListener l)
/*     */   {
/* 609 */     this.listenerList.remove(l);
/*     */   }
/*     */   
/*     */   public String getRequestDescription() {
/* 613 */     return this.request.getDescription();
/*     */   }
/*     */   
/*     */   public Types.MeasurementStatus getState() {
/* 617 */     return this.measurement_status;
/*     */   }
/*     */   
/*     */   private synchronized void triggerEvent(CommandEvent evt) {
/* 621 */     debugLog("Info: triggerEvent begin");
/* 622 */     Iterator listeners = this.listenerList.iterator();
/* 623 */     while (listeners.hasNext()) {
/* 624 */       ((MedicalCommandListener)listeners.next()).medicalCommandDataAvailable(evt);
/*     */     }
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\MedicalCommander.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */