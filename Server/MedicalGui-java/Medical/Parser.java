/*     */ package Medical;
/*     */ 
/*     */ import java.io.PrintStream;
/*     */ import java.util.ArrayList;
/*     */ import java.util.Arrays;
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
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ public class Parser
/*     */ {
/*  34 */   private static DataFromHW medicalData = null;
/*  35 */   private List listenerList = null;
/*     */   
/*  37 */   private boolean debug = false;
/*  38 */   private boolean error = true;
/*     */   
/*     */   static final String HEXES = "0123456789ABCDEF";
/*     */   
/*     */ 
/*     */   public Parser()
/*     */   {
/*  45 */     this.listenerList = new ArrayList();
/*     */   }
/*     */   
/*     */   private void debugLog(String log) {
/*  49 */     if (this.debug)
/*  50 */       System.out.println(log);
/*     */   }
/*     */   
/*     */   private void errorLog(String log) {
/*  54 */     if (this.error) {
/*  55 */       System.out.println(log);
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public synchronized void addListener(Listener l)
/*     */   {
/*  65 */     this.listenerList.add(l);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public synchronized void removeListener(Listener l)
/*     */   {
/*  75 */     this.listenerList.remove(l);
/*     */   }
/*     */   
/*     */   public synchronized DataFromHW parseData(byte[] buffer, int size) {
/*  79 */     return parseData(buffer, size, 0);
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
/*     */   public synchronized DataFromHW parseData(byte[] buffer, int size, int serialError)
/*     */   {
/* 100 */     while (buffer.length > 0)
/*     */     {
/* 102 */       medicalData = new DataFromHW();
/*     */       
/* 104 */       medicalData.setPacketId(parsePacketId(buffer[0]));
/*     */       
/* 106 */       if ((medicalData.getPacketId() == Types.PacketId.REQ) || (medicalData.getPacketId() == Types.PacketId.CFM))
/*     */       {
/*     */ 
/* 109 */         medicalData.setRequest(parseRequest(buffer[1]));
/* 110 */         medicalData.setIndication(Types.Indication.NONE);
/*     */         
/* 112 */         if (buffer.length >= buffer[2] + 3)
/*     */         {
/* 114 */           medicalData.setBuffer(Arrays.copyOfRange(buffer, 3, buffer[2] + 3));
/* 115 */           debugLog("Info: Parsed buffer size " + medicalData.getBuffer().length + " values: " + getHex(medicalData.getBuffer()));
/*     */           
/*     */ 
/* 118 */           triggerEvent(new Event(this, medicalData));
/*     */           
/* 120 */           buffer = Arrays.copyOfRange(buffer, buffer[2] + 3, buffer.length);
/*     */         }
/*     */         else {
/* 123 */           errorLog("Error: Shorter buffer than Lenght field " + medicalData.getPacketId().getDescription());
/* 124 */           medicalData.setErrorState(true);
/*     */         }
/*     */         
/*     */       }
/* 128 */       else if (medicalData.getPacketId() == Types.PacketId.IND)
/*     */       {
/* 130 */         medicalData.setRequest(Types.Request.NONE);
/* 131 */         medicalData.setIndication(parseIndication(buffer[1]));
/*     */         
/* 133 */         if (buffer.length >= buffer[2])
/*     */         {
/* 135 */           medicalData.setBuffer(Arrays.copyOfRange(buffer, 3, buffer[2] + 3));
/* 136 */           debugLog("Info: Parsed buffer size " + medicalData.getBuffer().length + " values: " + getHex(medicalData.getBuffer()));
/*     */           
/*     */ 
/* 139 */           triggerEvent(new Event(this, medicalData));
/*     */           
/* 141 */           buffer = Arrays.copyOfRange(buffer, buffer[2] + 3, buffer.length);
/*     */         }
/*     */         else {
/* 144 */           errorLog("Error: Shorter buffer than Lenght field " + medicalData.getPacketId().getDescription());
/* 145 */           medicalData.setErrorState(true);
/*     */         }
/*     */       }
/*     */     }
/*     */     
/* 150 */     return medicalData;
/*     */   }
/*     */   
/*     */   private synchronized void triggerEvent(Event evt)
/*     */   {
/* 155 */     Iterator listeners = this.listenerList.iterator();
/* 156 */     while (listeners.hasNext()) {
/* 157 */       ((Listener)listeners.next()).medicalDataAvailable(evt);
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
/*     */   private synchronized Types.PacketId parsePacketId(byte value)
/*     */   {
/* 176 */     if ((value != Types.PacketId.ERROR.getValue()) || (value != Types.PacketId.NONE.getValue()))
/*     */     {
/*     */ 
/* 179 */       Types.PacketId[] packet_ids = Types.PacketId.values();
/* 180 */       for (int i = 0; i < packet_ids.length; i++)
/*     */       {
/* 182 */         if (value == packet_ids[i].getValue()) {
/* 183 */           debugLog("Info: Parser found Packet Id " + getHex(new byte[] { value }) + ":" + packet_ids[i].getDescription());
/* 184 */           return packet_ids[i];
/*     */         }
/*     */       }
/*     */     }
/*     */     
/* 189 */     errorLog("Error: Parser error at Packet Id " + getHex(new byte[] { value }));
/* 190 */     medicalData.setErrorState(true);
/* 191 */     return Types.PacketId.ERROR;
/*     */   }
/*     */   
/*     */   private synchronized Types.Request parseRequest(byte value) {
/* 195 */     if ((value != Types.Request.ERROR.getValue()) || (value != Types.Request.NONE.getValue()))
/*     */     {
/*     */ 
/* 198 */       Types.Request[] operations = Types.Request.values();
/* 199 */       for (int i = 0; i < operations.length; i++)
/*     */       {
/* 201 */         if (value == operations[i].getValue()) {
/* 202 */           debugLog("Info: Parser found Request " + getHex(new byte[] { value }) + ":" + operations[i].getDescription());
/* 203 */           return operations[i];
/*     */         }
/*     */       }
/*     */     }
/*     */     
/* 208 */     errorLog("Error: Parser error at Request " + getHex(new byte[] { value }));
/* 209 */     medicalData.setErrorState(true);
/* 210 */     return Types.Request.ERROR;
/*     */   }
/*     */   
/*     */   private synchronized Types.Indication parseIndication(byte value) {
/* 214 */     if ((value != Types.Indication.ERROR.getValue()) || (value != Types.Indication.NONE.getValue()))
/*     */     {
/*     */ 
/* 217 */       Types.Indication[] operations = Types.Indication.values();
/* 218 */       for (int i = 0; i < operations.length; i++)
/*     */       {
/* 220 */         if (value == operations[i].getValue()) {
/* 221 */           debugLog("Info: Parser found Indentifier " + getHex(new byte[] { value }) + ":" + operations[i].getDescription());
/* 222 */           return operations[i];
/*     */         }
/*     */       }
/*     */     }
/*     */     
/* 227 */     errorLog("Error: Parser error at Indicator " + getHex(new byte[] { value }));
/* 228 */     medicalData.setErrorState(true);
/* 229 */     return Types.Indication.ERROR;
/*     */   }
/*     */   
/*     */   public static synchronized int toIntValue(byte msb, byte lsb) {
/* 233 */     int value = -1;
/* 234 */     value = toUnsigned(msb) * 256 + toUnsigned(lsb);
/* 235 */     return value;
/*     */   }
/*     */   
/*     */   public static synchronized int toIntValue(Byte msb, Byte lsb) {
/* 239 */     int value = -1;
/* 240 */     value = toUnsigned(msb) * 256 + toUnsigned(lsb);
/* 241 */     return value;
/*     */   }
/*     */   
/*     */   public static synchronized int toUnsigned(byte value) {
/* 245 */     short unsigned = 0;
/* 246 */     if (value < 0) {
/* 247 */       unsigned = (short)(256 + value);
/*     */     }
/*     */     else {
/* 250 */       unsigned = (short)value;
/*     */     }
/* 252 */     return unsigned;
/*     */   }
/*     */   
/*     */   public static synchronized int toUnsigned(Byte value) {
/* 256 */     short unsigned = 0;
/* 257 */     if (value.byteValue() < 0) {
/* 258 */       unsigned = (short)(256 + value.byteValue());
/*     */     }
/*     */     else {
/* 261 */       unsigned = (short)value.byteValue();
/*     */     }
/* 263 */     return unsigned;
/*     */   }
/*     */   
/*     */ 
/*     */   public static synchronized String getHex(byte[] raw)
/*     */   {
/* 269 */     if (raw == null) {
/* 270 */       return null;
/*     */     }
/* 272 */     StringBuilder hex = new StringBuilder(2 * raw.length);
/* 273 */     for (byte b : raw) {
/* 274 */       hex.append("0123456789ABCDEF".charAt((b & 0xF0) >> 4)).append("0123456789ABCDEF".charAt(b & 0xF)).append(" ");
/*     */     }
/*     */     
/*     */ 
/* 278 */     return hex.toString();
/*     */   }
/*     */   
/*     */   public static synchronized String getHex(Byte[] raw) {
/* 282 */     if (raw == null) {
/* 283 */       return null;
/*     */     }
/* 285 */     StringBuilder hex = new StringBuilder(2 * raw.length);
/* 286 */     Byte[] arr$ = raw;int len$ = arr$.length; for (int i$ = 0; i$ < len$; i$++) { byte b = arr$[i$].byteValue();
/* 287 */       hex.append("0123456789ABCDEF".charAt((b & 0xF0) >> 4)).append("0123456789ABCDEF".charAt(b & 0xF)).append(" ");
/*     */     }
/*     */     
/*     */ 
/* 291 */     return hex.toString();
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Parser.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */