/*     */ package Medical;
/*     */ 
/*     */ import gnu.io.CommPortIdentifier;
/*     */ import gnu.io.SerialPort;
/*     */ import gnu.io.SerialPortEvent;
/*     */ import gnu.io.SerialPortEventListener;
/*     */ import java.io.InputStream;
/*     */ import java.io.OutputStream;
/*     */ import java.io.PrintStream;
/*     */ import java.util.Arrays;
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
/*     */ public class Communication
/*     */   implements SerialPortEventListener
/*     */ {
/*     */   private static final int BUFFER_SIZE = 100;
/*     */   private static byte[] buffer;
/*     */   private static byte[] buffer_main;
/*  36 */   private static int readBytes = 0;
/*     */   
/*  38 */   private static SerialPort port = null;
/*  39 */   private static CommPortIdentifier portID = null;
/*     */   
/*  41 */   private static InputStream in = null;
/*  42 */   private static OutputStream out = null;
/*     */   
/*  44 */   private String portStr = null;
/*  45 */   private Parser parser = null;
/*     */   
/*  47 */   private int waiting = 0;
/*  48 */   private long last_time = 0L;
/*     */   
/*  50 */   private int dato = 0;
/*     */   
/*     */ 
/*     */ 
/*     */   static final String HEXES = "0123456789ABCDEF";
/*     */   
/*     */ 
/*     */ 
/*     */   public Communication(String portStr, Parser parser)
/*     */   {
/*  60 */     this.parser = parser;
/*  61 */     this.portStr = portStr;
/*  62 */     this.waiting = 0;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean open()
/*     */   {
/*     */     try
/*     */     {
/*  73 */       if (port == null) {
/*  74 */         portID = CommPortIdentifier.getPortIdentifier(this.portStr);
/*  75 */         if (portID == null) {
/*  76 */           System.out.println("Error: Serial Port Open failed port not found");
/*  77 */           return false;
/*     */         }
/*  79 */         if (!portID.isCurrentlyOwned())
/*     */         {
/*  81 */           port = (SerialPort)portID.open("name", 2000);
/*  82 */           if ((port instanceof SerialPort))
/*     */           {
/*  84 */             port.setSerialPortParams(115200, 8, 1, 0);
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
/* 107 */             port.setRTS(true);
/* 108 */             port.setDTR(true);
/*     */             
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 114 */             port.addEventListener(this);
/* 115 */             port.notifyOnDataAvailable(true);
/*     */             
/* 117 */             in = port.getInputStream();
/* 118 */             out = port.getOutputStream();
/* 119 */             System.out.println("Info: Serial Port data Open  " + this.portStr + ", 115200 bps ");
/* 120 */             return true;
/*     */           }
/*     */         }
/*     */       }
/*     */     }
/*     */     catch (Exception e) {
/* 126 */       System.out.println("Error: Serial Port Open failed " + e.getMessage() + e.getLocalizedMessage());
/* 127 */       e.printStackTrace();
/*     */     }
/* 129 */     return false;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void serialEvent(SerialPortEvent event)
/*     */   {
/* 141 */     if (event.getEventType() == 1) {
/*     */       try {
/* 143 */         readBytes = in.available();
/* 144 */         buffer = new byte[readBytes];
/* 145 */         in.read(buffer, 0, readBytes);
/* 146 */         System.out.println("Info:Serial Port data received = " + getHex(buffer));
/*     */         
/*     */ 
/* 149 */         if ((this.last_time != 0L) && (this.last_time + 1000L < System.currentTimeMillis()))
/*     */         {
/*     */ 
/*     */ 
/* 153 */           buffer_main = null;
/* 154 */           this.waiting = 0;
/*     */         }
/*     */         
/* 157 */         this.last_time = System.currentTimeMillis();
/*     */         
/* 159 */         if (this.waiting == 0)
/*     */         {
/* 161 */           if ((buffer[0] == 105) || (buffer[0] == 67))
/*     */           {
/* 163 */             if (readBytes < 3)
/*     */             {
/* 165 */               this.waiting = (3 - readBytes);
/* 166 */               buffer_main = buffer;
/*     */             }
/* 168 */             else if (buffer[2] + 3 > readBytes)
/*     */             {
/* 170 */               this.waiting = (buffer[2] + 3 - readBytes);
/* 171 */               buffer_main = buffer;
/*     */             }
/* 173 */             else if (buffer[2] + 3 == readBytes)
/*     */             {
/* 175 */               this.waiting = 0;
/* 176 */               this.parser.parseData(buffer, readBytes);
/*     */ 
/*     */ 
/*     */ 
/*     */             }
/* 181 */             else if (buffer[2] + 3 < readBytes)
/*     */             {
/*     */ 
/* 184 */               int count_before = 0;
/* 185 */               for (int count = 0; count < readBytes; count += buffer[(count + 2)] + (count + 3)) {
/* 186 */                 count_before = count;
/*     */               }
/*     */               
/* 189 */               if (count == readBytes) {
/* 190 */                 this.waiting = 0;
/* 191 */                 this.parser.parseData(buffer, readBytes);
/*     */               }
/* 193 */               else if (count > readBytes)
/*     */               {
/* 195 */                 this.parser.parseData(Arrays.copyOfRange(buffer, 0, count_before), count_before);
/* 196 */                 this.waiting = (count - readBytes);
/* 197 */                 buffer_main = Arrays.copyOfRange(buffer, count_before, readBytes);
/*     */               }
/*     */             }
/*     */           }
/*     */         }
/*     */         else {
/* 203 */           byte[] buffer_temp = new byte[buffer_main.length + readBytes];
/*     */           
/*     */ 
/* 206 */           for (int count = 0; count < buffer_main.length; count++)
/*     */           {
/* 208 */             buffer_temp[count] = buffer_main[count];
/*     */           }
/*     */           
/* 211 */           for (int count1 = 0; count1 < buffer.length; count++)
/*     */           {
/* 213 */             buffer_temp[count] = buffer[count1];count1++;
/*     */           }
/*     */           
/* 216 */           buffer_main = buffer_temp;
/* 217 */           if (this.waiting - readBytes <= 0)
/*     */           {
/* 219 */             this.parser.parseData(buffer_main, readBytes);
/* 220 */             buffer_main = null;
/*     */           }
/* 222 */           this.waiting = (this.waiting - readBytes < 0 ? 0 : this.waiting - readBytes);
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */         }
/*     */         
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */       }
/*     */       catch (Exception e)
/*     */       {
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 241 */         System.out.println("Error: Serial Event " + e.getMessage());
/* 242 */         e.printStackTrace();
/*     */       }
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean write(byte[] data)
/*     */   {
/*     */     try
/*     */     {
/* 255 */       if (port != null) {
/* 256 */         out.write(data);
/* 257 */         out.flush();
/* 258 */         System.out.println("Info:Serial Port data send = " + getHex(data));
/* 259 */         return true;
/*     */       }
/*     */     }
/*     */     catch (Exception e) {}
/* 263 */     System.out.println("Info:Serial Port data Not send ");
/* 264 */     return false;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean read()
/*     */   {
/*     */     try
/*     */     {
/* 274 */       if (port != null) {
/* 275 */         readBytes = in.available();
/* 276 */         if (readBytes > 0) {
/* 277 */           in.read(buffer, 0, readBytes);
/* 278 */           this.parser.parseData(buffer, readBytes);
/*     */         }
/* 280 */         return true;
/*     */       }
/*     */     }
/*     */     catch (Exception e) {}
/* 284 */     return false;
/*     */   }
/*     */   
/*     */ 
/*     */   public void close()
/*     */   {
/*     */     try
/*     */     {
/* 292 */       port.removeEventListener();
/* 293 */       in.close();
/* 294 */       out.close();
/* 295 */       port.close();
/*     */     }
/*     */     catch (Exception e) {}
/*     */   }
/*     */   
/*     */   protected void finalize() throws Throwable
/*     */   {
/* 302 */     close();
/* 303 */     super.finalize();
/*     */   }
/*     */   
/*     */   public static String stringToHex(String base)
/*     */   {
/* 308 */     StringBuffer buffer = new StringBuffer();
/*     */     
/* 310 */     for (int x = 0; x < base.length(); x++)
/*     */     {
/* 312 */       int cursor = 0;
/* 313 */       int intValue = base.charAt(x);
/* 314 */       String binaryChar = new String(Integer.toBinaryString(base.charAt(x)));
/* 315 */       for (int i = 0; i < binaryChar.length(); i++)
/*     */       {
/* 317 */         if (binaryChar.charAt(i) == '1')
/*     */         {
/* 319 */           cursor++;
/*     */         }
/*     */       }
/* 322 */       if (cursor % 2 > 0)
/*     */       {
/* 324 */         intValue += 128;
/*     */       }
/* 326 */       buffer.append(Integer.toHexString(intValue) + " ");
/*     */     }
/* 328 */     return buffer.toString();
/*     */   }
/*     */   
/*     */ 
/*     */   public static String getHex(byte[] raw)
/*     */   {
/* 334 */     if (raw == null) {
/* 335 */       return null;
/*     */     }
/* 337 */     StringBuilder hex = new StringBuilder(2 * raw.length);
/* 338 */     for (byte b : raw) {
/* 339 */       hex.append("0123456789ABCDEF".charAt((b & 0xF0) >> 4)).append("0123456789ABCDEF".charAt(b & 0xF)).append(" ");
/*     */     }
/*     */     
/*     */ 
/* 343 */     return hex.toString();
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\Medical\Communication.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */