/*     */ package GUI.Graph;
/*     */ 
/*     */ import java.awt.BasicStroke;
/*     */ import java.awt.Color;
/*     */ import java.awt.Graphics;
/*     */ import java.awt.Graphics2D;
/*     */ import java.awt.RenderingHints;
/*     */ import java.awt.event.ActionEvent;
/*     */ import java.awt.event.ActionListener;
/*     */ import java.awt.geom.Line2D.Float;
/*     */ import java.awt.geom.Point2D.Float;
/*     */ import java.util.ArrayList;
/*     */ import java.util.Iterator;
/*     */ import java.util.List;
/*     */ import javax.swing.SwingUtilities;
/*     */ import javax.swing.Timer;
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
/*     */ public class GraphPanelXY
/*     */   extends GraphPanel
/*     */   implements ActionListener
/*     */ {
/*     */   private static final long serialVersionUID = 1L;
/*     */   private List<Point2D.Float> dataQueue;
/*     */   
/*     */   public GraphPanelXY()
/*     */   {
/*  52 */     this(0, 0, DEFAULT_LINE_COLOR, 1);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public GraphPanelXY(int maxValue, int minValue, Color lineColor, int lineWidth)
/*     */   {
/*  60 */     this.dataQueue = new ArrayList();
/*     */     
/*  62 */     this.maxValue = maxValue;
/*  63 */     this.minValue = minValue;
/*  64 */     this.lineColor = lineColor;
/*  65 */     this.lineWidth = lineWidth;
/*     */     
/*  67 */     this.queueSize = 20;
/*     */     
/*  69 */     if (this.timer == null) {
/*  70 */       this.timer = new Timer(0, this);
/*     */     }
/*     */   }
/*     */   
/*     */   public void insertData(List<Float> listX, List<Float> listY) {
/*  75 */     int sizeX = listX.size();
/*     */     
/*  77 */     if (sizeX != listY.size()) {
/*  78 */       throw new RuntimeException("Both listX and listY should have the same size!");
/*     */     }
/*     */     
/*  81 */     this.dataQueue = new ArrayList();
/*     */     
/*  83 */     for (int index = 0; index < sizeX; index++)
/*     */     {
/*  85 */       float x = ((Float)listX.get(index)).floatValue();
/*  86 */       float y = ((Float)listY.get(index)).floatValue();
/*     */       
/*  88 */       this.dataQueue.add(new Point2D.Float(x, y));
/*     */     }
/*     */     
/*  91 */     calculatePointValues();
/*     */     
/*  93 */     repaint();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void calculatePointValues()
/*     */   {
/* 104 */     int realHeight = Math.round(this.minValue * -1 + this.maxValue);
/*     */     
/* 106 */     this.pivotPointY = (this.minValue < 0 ? Math.round(this.maxValue * getHeight() / realHeight) : getHeight());
/*     */     
/* 108 */     this.lineOffsetX = (getWidth() / this.queueSize);
/* 109 */     this.lineOffsetY = (getHeight() / realHeight);
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
/*     */   public void actionPerformed(ActionEvent e)
/*     */   {
/* 122 */     SwingUtilities.invokeLater(new Runnable()
/*     */     {
/*     */ 
/*     */       public void run()
/*     */       {
/*     */ 
/* 128 */         GraphPanelXY.this.repaint();
/*     */       }
/*     */     });
/*     */   }
/*     */   
/*     */   protected void paintComponent(Graphics g)
/*     */   {
/* 135 */     super.paintComponent(g);
/*     */     
/* 137 */     updateGraphic(g);
/*     */   }
/*     */   
/*     */   protected void updateGraphic(Graphics g)
/*     */   {
/* 142 */     Graphics2D g2D = (Graphics2D)g;
/*     */     
/*     */ 
/* 145 */     if (this.antialiasing) {
/* 146 */       RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
/* 147 */       g2D.setRenderingHints(rh);
/*     */     }
/*     */     
/* 150 */     g2D.setColor(this.lineColor);
/* 151 */     g2D.setStroke(new BasicStroke(this.lineWidth));
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 158 */     float x1 = 0.0F;
/* 159 */     float y1 = this.lineStartY;
/* 160 */     float x2 = 0.0F;
/* 161 */     float y2 = 0.0F;
/*     */     
/*     */ 
/*     */ 
/* 165 */     Iterator<Point2D.Float> iter = this.dataQueue.iterator();
/* 166 */     while (iter.hasNext())
/*     */     {
/* 168 */       Point2D.Float p = (Point2D.Float)iter.next();
/*     */       
/*     */ 
/*     */ 
/* 172 */       x2 = p.x * this.lineOffsetX;
/* 173 */       y2 = this.pivotPointY - p.y * this.lineOffsetY;
/*     */       
/*     */ 
/*     */ 
/* 177 */       g2D.draw(new Line2D.Float(x1, y1, x2, y2));
/*     */       
/*     */ 
/*     */ 
/* 181 */       x1 = x2;
/* 182 */       y1 = y2;
/*     */     }
/* 184 */     g2D.dispose();
/*     */   }
/*     */   
/*     */ 
/*     */   public void clearData()
/*     */   {
/* 190 */     if (this.dataQueue != null) {
/* 191 */       this.dataQueue.clear();
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */   public void insertData(Integer i) {}
/*     */   
/*     */ 
/*     */ 
/*     */   public void insertData(Integer[] a) {}
/*     */   
/*     */ 
/*     */   public void clearBuffer() {}
/*     */   
/*     */ 
/*     */   public boolean isQueueFull()
/*     */   {
/* 209 */     return false;
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Graph\GraphPanelXY.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */