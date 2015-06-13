/*     */ package GUI.Graph;
/*     */ 
/*     */ import java.awt.BasicStroke;
/*     */ import java.awt.Color;
/*     */ import java.awt.Container;
/*     */ import java.awt.Graphics;
/*     */ import java.awt.Graphics2D;
/*     */ import java.awt.Rectangle;
/*     */ import java.awt.RenderingHints;
/*     */ import java.awt.event.ActionEvent;
/*     */ import java.awt.event.ActionListener;
/*     */ import java.awt.geom.Line2D.Float;
/*     */ import java.util.ArrayList;
/*     */ import java.util.Arrays;
/*     */ import java.util.Collections;
/*     */ import java.util.Iterator;
/*     */ import java.util.List;
/*     */ import javax.swing.JPanel;
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
/*     */ public class GraphPanel
/*     */   extends JPanel
/*     */   implements ActionListener
/*     */ {
/*     */   private static final long serialVersionUID = 1L;
/*     */   public static final int SPIROMETRY = 1;
/*     */   public static final int ECG = 2;
/*     */   public static final int SPO2 = 3;
/*     */   protected static final int DEFAULT_QUEUE_SIZE = 20;
/*     */   protected static final int DEFAULT_LINE_WIDTH = 1;
/*  92 */   protected static final Color DEFAULT_LINE_COLOR = Color.magenta;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private List<Float> dataQueue;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private List<Integer> dataBuffer;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected int maxValue;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected int minValue;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected int queueSize;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 146 */   protected boolean updatePointValues = true;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected int pivotPointY;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected float lineOffsetX;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected float lineOffsetY;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected int lineStartY;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected Color lineColor;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected int lineWidth;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected Timer timer;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 218 */   protected boolean animationRunning = false;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 226 */   protected boolean antialiasing = false;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   private Rectangle drawingRegion;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public GraphPanel()
/*     */   {
/* 245 */     this(0, 0, DEFAULT_LINE_COLOR, 1);
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
/*     */   public GraphPanel(int maxValue, int minValue, Color lineColor, int lineWidth)
/*     */   {
/* 265 */     this.dataQueue = Collections.synchronizedList(new ArrayList());
/*     */     
/* 267 */     this.dataBuffer = Collections.synchronizedList(new ArrayList());
/*     */     
/*     */ 
/*     */ 
/* 271 */     this.maxValue = maxValue;
/*     */     
/* 273 */     this.minValue = minValue;
/*     */     
/* 275 */     this.lineColor = lineColor;
/*     */     
/* 277 */     this.lineWidth = lineWidth;
/*     */     
/*     */ 
/*     */ 
/* 281 */     this.queueSize = 20;
/*     */     
/* 283 */     this.drawingRegion = new Rectangle();
/*     */     
/*     */ 
/*     */ 
/* 287 */     if (this.timer == null)
/*     */     {
/* 289 */       this.timer = new Timer(0, this);
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
/*     */   public synchronized void insertData(Integer i)
/*     */   {
/* 307 */     this.dataBuffer.add(i);
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
/*     */   public synchronized void insertData(Integer[] a)
/*     */   {
/* 323 */     if ((a != null) && (a.length > 0))
/*     */     {
/* 325 */       this.dataBuffer.addAll(Arrays.asList(a));
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
/*     */   public void calculatePointValues()
/*     */   {
/* 348 */     int virtualHeight = this.minValue * -1 + this.maxValue;
/*     */     
/*     */ 
/*     */ 
/* 352 */     this.pivotPointY = (this.minValue < 0 ? Math.round(this.maxValue * getHeight() / virtualHeight) : getHeight());
/*     */     
/*     */ 
/*     */ 
/* 356 */     this.lineOffsetX = (getWidth() / this.queueSize / 3.0F);
/*     */     
/* 358 */     this.lineOffsetY = (getHeight() / virtualHeight);
/*     */     
/*     */ 
/*     */ 
/* 362 */     this.lineStartY = this.pivotPointY;
/*     */     
/*     */ 
/*     */ 
/* 366 */     this.drawingRegion = new Rectangle(0, 0, 0, getHeight());
/*     */   }
/*     */   
/*     */   private void updateParent(Container par)
/*     */   {
/* 371 */     if (par != null) {
/* 372 */       par.invalidate();
/* 373 */       par.repaint();
/*     */       
/*     */ 
/* 376 */       Container grandP = par.getParent();
/* 377 */       updateParent(grandP);
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
/*     */   public void actionPerformed(ActionEvent e)
/*     */   {
/* 401 */     final JPanel comp = this;
/*     */     
/*     */ 
/*     */ 
/* 405 */     SwingUtilities.invokeLater(new Runnable()
/*     */     {
/*     */ 
/*     */ 
/*     */ 
/*     */       public void run()
/*     */       {
/*     */ 
/*     */ 
/*     */ 
/* 415 */         float availableWidth = GraphPanel.this.getWidth() - GraphPanel.this.drawingRegion.width;
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
/* 429 */         if (availableWidth <= 0.0F)
/*     */         {
/* 431 */           GraphPanel.this.dataQueue.clear();
/*     */           
/*     */ 
/*     */ 
/* 435 */           availableWidth = GraphPanel.this.getWidth();
/*     */           
/* 437 */           GraphPanel.this.drawingRegion.width = 0;
/*     */         }
/*     */         
/*     */ 
/* 441 */         GraphPanel.this.drawingRegion.x = GraphPanel.this.drawingRegion.width;
/*     */         
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 451 */         float incWidth = GraphPanel.this.drawingRegion.width;
/*     */         
/* 453 */         while ((!GraphPanel.this.dataBuffer.isEmpty()) && (availableWidth > 0.0F))
/*     */         {
/*     */ 
/*     */ 
/* 457 */           Integer v = (Integer)GraphPanel.this.dataBuffer.remove(0);
/*     */           
/* 459 */           Float y = Float.valueOf(GraphPanel.this.pivotPointY - v.intValue() * GraphPanel.this.lineOffsetY);
/*     */           
/* 461 */           GraphPanel.this.dataQueue.add(y);
/*     */           
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 467 */           incWidth += GraphPanel.this.lineOffsetX;
/*     */           
/* 469 */           availableWidth = GraphPanel.this.getWidth() - incWidth;
/*     */         }
/*     */         
/*     */ 
/*     */ 
/*     */ 
/* 475 */         GraphPanel.this.drawingRegion.width = Math.round(incWidth);
/*     */         
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 482 */         GraphPanel.this.updateParent(comp.getParent());
/*     */       }
/*     */     });
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   protected void paintComponent(Graphics g)
/*     */   {
/* 496 */     super.paintComponent(g);
/*     */     
/*     */ 
/*     */ 
/* 500 */     updateGraphic(g);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   protected synchronized void updateGraphic(Graphics g)
/*     */   {
/* 508 */     Graphics2D g2D = (Graphics2D)g;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 514 */     if (this.antialiasing)
/*     */     {
/* 516 */       RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
/*     */       
/* 518 */       g2D.setRenderingHints(rh);
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 526 */     if (this.updatePointValues)
/*     */     {
/* 528 */       calculatePointValues();
/*     */       
/* 530 */       this.updatePointValues = false;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 536 */     g2D.setColor(this.lineColor);
/*     */     
/* 538 */     g2D.setStroke(new BasicStroke(this.lineWidth));
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
/* 552 */     float x1 = 0.0F;
/*     */     
/* 554 */     float y1 = this.lineStartY;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 562 */     float x2 = 0.0F;
/*     */     
/* 564 */     float y2 = 0.0F;
/*     */     
/*     */ 
/*     */ 
/* 568 */     Iterator<Float> iter = this.dataQueue.iterator();
/*     */     
/* 570 */     while (iter.hasNext())
/*     */     {
/*     */ 
/*     */ 
/* 574 */       x2 = x1 + this.lineOffsetX;
/*     */       
/*     */       try
/*     */       {
/* 578 */         y2 = ((Float)iter.next()).floatValue();
/*     */       }
/*     */       catch (Throwable t) {}
/*     */       
/*     */ 
/*     */ 
/* 584 */       g2D.draw(new Line2D.Float(x1, y1, x2, y2));
/*     */       
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 590 */       x1 = x2;
/*     */       
/* 592 */       y1 = y2;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 598 */     this.lineStartY = ((int)y1);
/*     */     
/*     */ 
/*     */ 
/* 602 */     g2D.dispose();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getMaxValue()
/*     */   {
/* 610 */     return this.maxValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setMaxValue(int maxValue)
/*     */   {
/* 618 */     this.maxValue = maxValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getMinValue()
/*     */   {
/* 626 */     return this.minValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setMinValue(int minValue)
/*     */   {
/* 634 */     this.minValue = minValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getQueueSize()
/*     */   {
/* 642 */     return this.queueSize;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setQueueSize(int queueSize)
/*     */   {
/* 650 */     this.queueSize = queueSize;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public Color getLineColor()
/*     */   {
/* 658 */     return this.lineColor;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setLineColor(Color lineColor)
/*     */   {
/* 666 */     this.lineColor = lineColor;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getDelay()
/*     */   {
/* 674 */     return this.timer.getDelay();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setDelay(int delay)
/*     */   {
/* 682 */     this.timer.setDelay(delay);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void startAnimation()
/*     */   {
/* 690 */     this.timer.start();
/*     */     
/* 692 */     this.animationRunning = this.timer.isRunning();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void pauseAnimation()
/*     */   {
/* 700 */     this.timer.stop();
/*     */     
/* 702 */     this.animationRunning = this.timer.isRunning();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean isAnimationRunning()
/*     */   {
/* 710 */     return this.animationRunning;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void clearData()
/*     */   {
/* 718 */     if (this.dataBuffer != null)
/*     */     {
/* 720 */       this.dataBuffer.clear();
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 726 */     if (this.dataQueue != null)
/*     */     {
/* 728 */       this.dataQueue.clear();
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void clearBuffer()
/*     */   {
/* 738 */     if (this.dataQueue != null)
/*     */     {
/* 740 */       this.dataQueue.clear();
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getLineWidth()
/*     */   {
/* 750 */     return this.lineWidth;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setLineWidth(int lineWidth)
/*     */   {
/* 758 */     this.lineWidth = lineWidth;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean isAntialiasing()
/*     */   {
/* 766 */     return this.antialiasing;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setAntialiasing(boolean antialiasing)
/*     */   {
/* 774 */     this.antialiasing = antialiasing;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean isQueueFull()
/*     */   {
/* 782 */     return this.dataQueue.size() == this.queueSize;
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Graph\GraphPanel.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */