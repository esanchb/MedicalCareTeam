/*    */ package GUI;
/*    */ 
/*    */ import java.io.BufferedReader;
/*    */ import java.io.File;
/*    */ import java.io.InputStreamReader;
/*    */ import java.io.PrintStream;
/*    */ import java.io.PrintWriter;
/*    */ import java.net.InetAddress;
/*    */ import java.net.Socket;
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
/*    */ public class MediaClient
/*    */ {
/* 28 */   private File videoPlaybackLock = new File("/var/lock/playing.lck");
/* 29 */   private Socket client = null;
/* 30 */   private PrintWriter out = null;
/* 31 */   private BufferedReader in = null;
/*    */   
/*    */   private static final String pipe_base1 = "gst-launch-0.10 filesrc location=";
/*    */   
/*    */   private static final String pipe_base2 = " ! avidemux name=demux demux.audio_00 ! mfw_mp3decoder ! alsasink demux.video_00 ! queue ! mfw_vpudecoder codec-type=std_avc ! mfw_isink";
/*    */   
/*    */   private static final String pipe_dispwidth = " disp-width=";
/*    */   
/*    */   private static final String pipe_dispheight = " disp-height=";
/*    */   
/*    */   private static final String pipe_axistop = " axis-top=";
/*    */   
/*    */   private static final String pipe_axisleft = " axis-left=";
/*    */   private static final String mmpath = "/home/kiosk/kiosk_mmedia/";
/*    */   
/*    */   public boolean videoIsPlaying()
/*    */   {
/* 48 */     if (this.videoPlaybackLock.exists()) {
/* 49 */       System.out.println("Lock File Exist... Video is playing");
/* 50 */       return true;
/*    */     }
/* 52 */     System.out.println("Video is not playing");
/* 53 */     return false;
/*    */   }
/*    */   
/*    */   public boolean play(String videoname, int coordX, int coordY, int width, int height)
/*    */   {
/* 58 */     if (this.videoPlaybackLock.exists()) {
/* 59 */       System.out.println("Lock File Exist... Video is playing");
/* 60 */       return false;
/*    */     }
/*    */     
/* 63 */     System.out.println("Video is not playing");
/* 64 */     playVideo(videoname, coordX, coordY, width, height);
/* 65 */     return true;
/*    */   }
/*    */   
/*    */   private void playVideo(String videoname, int coordX, int coordY, int width, int height)
/*    */   {
/*    */     try {
/* 71 */       String gst_pipeline = "gst-launch-0.10 filesrc location=/home/kiosk/kiosk_mmedia/" + videoname + " ! avidemux name=demux demux.audio_00 ! mfw_mp3decoder ! alsasink demux.video_00 ! queue ! mfw_vpudecoder codec-type=std_avc ! mfw_isink" + " disp-width=" + width + " disp-height=" + height + " axis-left=" + coordX + " axis-top=" + coordY;
/*    */       
/* 73 */       System.out.println("Pipeline: " + gst_pipeline);
/* 74 */       this.client = new Socket(InetAddress.getLocalHost(), 1000);
/* 75 */       this.out = new PrintWriter(this.client.getOutputStream(), true);
/* 76 */       this.in = new BufferedReader(new InputStreamReader(this.client.getInputStream()));
/*    */       
/*    */ 
/* 79 */       this.out.println(gst_pipeline);
/* 80 */       this.out.flush();
/*    */       
/*    */       int c;
/* 83 */       while ((c = this.in.read()) != -1) {
/* 84 */         System.out.print((char)c);
/*    */       }
/*    */       
/*    */ 
/* 88 */       this.out.close();
/* 89 */       this.in.close();
/*    */       
/*    */ 
/* 92 */       this.client.close();
/*    */     }
/*    */     catch (Exception e)
/*    */     {
/* 96 */       System.out.println("Error while trying to play: " + videoname + " due to " + e.getMessage());
/* 97 */       e.printStackTrace();
/*    */     }
/*    */   }
/*    */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\MediaClient.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */