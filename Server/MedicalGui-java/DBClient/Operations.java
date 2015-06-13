/*     */ package DBClient;
/*     */ 
/*     */ import java.io.BufferedReader;
/*     */ import java.io.IOException;
/*     */ import java.io.InputStreamReader;
/*     */ import java.io.OutputStreamWriter;
/*     */ import java.net.URL;
/*     */ import java.net.URLConnection;
/*     */ import java.net.URLEncoder;
/*     */ import java.util.Enumeration;
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
/*     */ public class Operations
/*     */ {
/*     */   private static final String webServer = "http://medical.nacuri.com/services/";
/*     */   private static final String webFormType = ".php";
/*     */   private static final String insPatient = "insertpatient";
/*     */   private static final String upPatient = "update";
/*     */   private static final String delPatient = "delete";
/*     */   private static final String gSinglePatient = "read";
/*     */   private static final String gAllPatients = "patients";
/*     */   private static final String insMeasurement = "measurements";
/*     */   private static final String gSingleMeasurement = "historicaldata";
/*     */   private static final String gAllMeasurements = "datalogs";
/*     */   private static final String encodingFormat = "UTF-8";
/*  42 */   private static final String[] errorCodes = { "0", "-1" };
/*     */   
/*     */   private static final String entriesDelimeter = ";";
/*     */   
/*     */   private static final String fieldsDelimeter = ",";
/*     */   private String serviceString;
/*     */   private URL serviceURL;
/*     */   private URLConnection serviceConnection;
/*     */   private OutputStreamWriter serviceOutput;
/*     */   private BufferedReader serviceInput;
/*  52 */   private Patient pempty = null;
/*  53 */   private Measurement mempty = null;
/*  54 */   private String[] pfields = null;
/*  55 */   private String[] mfields = null;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public Operations()
/*     */     throws Exception
/*     */   {
/*  63 */     this.pempty = new Patient(new String[22]);
/*  64 */     this.mempty = new Measurement(new String[12]);
/*  65 */     this.pfields = ((String[])String[].class.cast(this.pempty.getFields()));
/*  66 */     this.mfields = ((String[])String[].class.cast(this.mempty.getFields()));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean insertPatient(Patient p)
/*     */   {
/*  76 */     connect("insertpatient");
/*  77 */     write(buildURL(this.pfields, p.getValues()));
/*  78 */     return validate(processHtml(read()));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean updatePatient(Patient p)
/*     */   {
/*  88 */     connect("update");
/*  89 */     write(buildURL(this.pfields, p.getValues()));
/*  90 */     return validate(processHtml(read()));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public String[] getPatients()
/*     */   {
/*  99 */     String replyFromServer = null;
/* 100 */     connect("patients");
/* 101 */     if (validate(replyFromServer = processHtml(read(), this.pfields))) {
/* 102 */       return replyFromServer.split(";");
/*     */     }
/* 104 */     return null;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public String[] getPatient(String RFC)
/*     */   {
/* 114 */     String replyFromServer = null;
/* 115 */     connect("read");
/* 116 */     write(encode("rfc", RFC));
/* 117 */     if (validate(replyFromServer = processHtml(read(), this.pfields)))
/*     */     {
/* 119 */       replyFromServer = replyFromServer.replace("telefono=", "");
/* 120 */       return replyFromServer.split(",");
/*     */     }
/* 122 */     return null;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean deletePatient(String RFC)
/*     */   {
/* 132 */     connect("delete");
/* 133 */     write(encode("rfc", RFC));
/* 134 */     return validate(processHtml(read()));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean insertMeasurement(Measurement m)
/*     */   {
/* 144 */     connect("measurements");
/* 145 */     write(buildURL(this.mfields, m.getValues()));
/* 146 */     return validate(processHtml(read()));
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public String[] getMeasurement(String ID)
/*     */   {
/* 156 */     String replyFromServer = null;
/* 157 */     connect("historicaldata");
/* 158 */     write(encode("id", ID));
/* 159 */     if (validate(replyFromServer = processHtml(read(), this.mfields))) {
/* 160 */       return replyFromServer.split(";");
/*     */     }
/* 162 */     return null;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public String[] getMeasurements(String RFC)
/*     */   {
/* 172 */     String replyFromServer = null;
/* 173 */     connect("datalogs");
/* 174 */     write(encode("rfc", RFC));
/* 175 */     if (validate(replyFromServer = processHtml(read())))
/*     */     {
/* 177 */       replyFromServer = replyFromServer.replaceAll("<br/>", "");
/* 178 */       return replyFromServer.split(";");
/*     */     }
/* 180 */     return null;
/*     */   }
/*     */   
/*     */   private boolean connect(String service) {
/* 184 */     this.serviceString = "http://medical.nacuri.com/services/";
/* 185 */     this.serviceString += service;
/* 186 */     this.serviceString += ".php";
/*     */     try
/*     */     {
/* 189 */       this.serviceURL = new URL(this.serviceString);
/* 190 */       this.serviceConnection = this.serviceURL.openConnection();
/* 191 */       this.serviceConnection.setDoOutput(true);
/*     */     }
/*     */     catch (Exception ex) {
/* 194 */       return false;
/*     */     }
/* 196 */     return true;
/*     */   }
/*     */   
/*     */   private boolean write(String data) {
/*     */     try {
/* 201 */       this.serviceOutput = new OutputStreamWriter(this.serviceConnection.getOutputStream());
/* 202 */       this.serviceOutput.write(data);
/* 203 */       this.serviceOutput.flush();
/* 204 */       this.serviceOutput.close();
/* 205 */       return true;
/*     */     }
/*     */     catch (IOException ex) {}
/* 208 */     return false;
/*     */   }
/*     */   
/*     */   private String read()
/*     */   {
/* 213 */     String data = "";
/* 214 */     String tmp = null;
/*     */     try {
/* 216 */       this.serviceInput = new BufferedReader(new InputStreamReader(this.serviceConnection.getInputStream()));
/* 217 */       while (null != (tmp = this.serviceInput.readLine())) {
/* 218 */         data = data + tmp;
/*     */       }
/* 220 */       this.serviceInput.close();
/*     */     }
/*     */     catch (IOException ex) {
/* 223 */       return null;
/*     */     }
/* 225 */     return data;
/*     */   }
/*     */   
/*     */   private String encode(String field, String value) {
/* 229 */     String encoded = "";
/*     */     try {
/* 231 */       encoded = encoded + URLEncoder.encode(field, "UTF-8") + "=" + URLEncoder.encode(value, "UTF-8");
/*     */     }
/*     */     catch (Exception ex)
/*     */     {
/* 235 */       return null;
/*     */     }
/* 237 */     return encoded;
/*     */   }
/*     */   
/*     */   private String buildURL(String[] fields, Enumeration values) {
/* 241 */     Enumeration e = values;
/* 242 */     String url = "";
/* 243 */     String encoded = null;
/* 244 */     int i = 0;
/* 245 */     while (e.hasMoreElements()) {
/* 246 */       if (null != (encoded = encode(fields[i], e.nextElement().toString()))) {
/* 247 */         url = url + encoded + "&";
/* 248 */         i++;
/*     */       }
/*     */       else {
/* 251 */         return null;
/*     */       }
/*     */     }
/* 254 */     return url;
/*     */   }
/*     */   
/*     */   private boolean validate(String html) {
/* 258 */     for (int i = 0; i < errorCodes.length; i++) {
/* 259 */       if (html.contentEquals(errorCodes[i])) {
/* 260 */         return false;
/*     */       }
/*     */     }
/* 263 */     return true;
/*     */   }
/*     */   
/*     */   private String processHtml(String html, String[] fields) {
/* 267 */     html = processHtml(html);
/* 268 */     for (int i = 0; i < fields.length; i++) {
/* 269 */       html = html.replace(fields[i] + "=", "");
/*     */     }
/* 271 */     return html;
/*     */   }
/*     */   
/*     */   private String processHtml(String html) {
/* 275 */     html = html.replaceAll(" ", "");
/* 276 */     return html;
/*     */   }
/*     */   
/*     */   protected void finalize() throws Throwable
/*     */   {
/*     */     try
/*     */     {
/* 283 */       this.serviceInput.close();
/* 284 */       this.serviceOutput.close();
/*     */     }
/*     */     catch (IOException ex) {}
/* 287 */     super.finalize();
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\DBClient\Operations.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */