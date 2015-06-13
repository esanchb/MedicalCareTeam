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
/*     */ public class GraphPanelSpo2
/*     */   extends GraphPanel
/*     */   implements ActionListener
/*     */ {
/*     */   private static final long serialVersionUID = 1L;
/*     */   protected static final int DEFAULT_QUEUE_SIZE = 20;
/*     */   protected static final int DEFAULT_LINE_WIDTH = 1;
/*  69 */   protected static final Color DEFAULT_LINE_COLOR = Color.yellow;
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
/* 123 */   protected boolean updatePointValues = true;
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
/* 195 */   protected boolean animationRunning = false;
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 203 */   protected boolean antialiasing = false;
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
/*     */   public GraphPanelSpo2()
/*     */   {
/* 221 */     this(0, 0, DEFAULT_LINE_COLOR, 1);
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
/*     */   public GraphPanelSpo2(int maxValue, int minValue, Color lineColor, int lineWidth)
/*     */   {
/* 241 */     this.dataQueue = Collections.synchronizedList(new ArrayList());
/*     */     
/* 243 */     this.dataBuffer = Collections.synchronizedList(new ArrayList());
/*     */     
/*     */ 
/*     */ 
/* 247 */     this.maxValue = maxValue;
/*     */     
/* 249 */     this.minValue = minValue;
/*     */     
/* 251 */     this.lineColor = lineColor;
/*     */     
/* 253 */     this.lineWidth = lineWidth;
/*     */     
/*     */ 
/*     */ 
/* 257 */     this.queueSize = 20;
/*     */     
/* 259 */     this.drawingRegion = new Rectangle();
/*     */     
/*     */ 
/*     */ 
/* 263 */     if (this.timer == null)
/*     */     {
/* 265 */       this.timer = new Timer(0, this);
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
/* 283 */     this.dataBuffer.add(i);
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
/* 299 */     if ((a != null) && (a.length > 0))
/*     */     {
/* 301 */       this.dataBuffer.addAll(Arrays.asList(a));
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
/*     */   public void calculatePointValues()
/*     */   {
/* 323 */     int virtualHeight = this.minValue * -1 + this.maxValue;
/*     */     
/*     */ 
/*     */ 
/* 327 */     this.pivotPointY = (this.minValue < 0 ? Math.round(this.maxValue * getHeight() / virtualHeight) : getHeight());
/*     */     
/*     */ 
/*     */ 
/* 331 */     this.lineOffsetX = (getWidth() / this.queueSize);
/*     */     
/* 333 */     this.lineOffsetY = (getHeight() / virtualHeight);
/*     */     
/*     */ 
/*     */ 
/* 337 */     this.lineStartY = this.pivotPointY;
/*     */     
/*     */ 
/*     */ 
/* 341 */     this.drawingRegion = new Rectangle(0, 0, 0, getHeight());
/*     */   }
/*     */   
/*     */ 
/*     */   private void updateParent(Container par)
/*     */   {
/* 347 */     if (par != null) {
/* 348 */       par.invalidate();
/* 349 */       par.repaint();
/*     */       
/*     */ 
/* 352 */       Container grandP = par.getParent();
/* 353 */       updateParent(grandP);
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
/*     */   public void actionPerformed(ActionEvent e)
/*     */   {
/* 374 */     final JPanel comp = this;
/*     */     
/*     */ 
/*     */ 
/* 378 */     SwingUtilities.invokeLater(new Runnable()
/*     */     {
/*     */ 
/*     */ 
/*     */ 
/*     */       public void run()
/*     */       {
/*     */ 
/*     */ 
/*     */ 
/* 388 */         float availableWidth = GraphPanelSpo2.this.getWidth() - GraphPanelSpo2.this.drawingRegion.width;
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
/* 402 */         if (availableWidth <= 0.0F)
/*     */         {
/* 404 */           GraphPanelSpo2.this.dataQueue.clear();
/*     */           
/*     */ 
/*     */ 
/* 408 */           availableWidth = GraphPanelSpo2.this.getWidth();
/*     */           
/* 410 */           GraphPanelSpo2.this.drawingRegion.width = 0;
/*     */         }
/*     */         
/*     */ 
/* 414 */         GraphPanelSpo2.this.drawingRegion.x = GraphPanelSpo2.this.drawingRegion.width;
/*     */         
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 424 */         float incWidth = GraphPanelSpo2.this.drawingRegion.width;
/*     */         
/* 426 */         while ((!GraphPanelSpo2.this.dataBuffer.isEmpty()) && (availableWidth > 0.0F))
/*     */         {
/*     */ 
/*     */ 
/* 430 */           Integer v = (Integer)GraphPanelSpo2.this.dataBuffer.remove(0);
/*     */           
/* 432 */           Float y = Float.valueOf(GraphPanelSpo2.this.pivotPointY - v.intValue() * GraphPanelSpo2.this.lineOffsetY);
/*     */           
/* 434 */           GraphPanelSpo2.this.dataQueue.add(y);
/*     */           
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 440 */           incWidth += GraphPanelSpo2.this.lineOffsetX;
/*     */           
/* 442 */           availableWidth = GraphPanelSpo2.this.getWidth() - incWidth;
/*     */         }
/*     */         
/*     */ 
/*     */ 
/*     */ 
/* 448 */         GraphPanelSpo2.this.drawingRegion.width = Math.round(incWidth);
/*     */         
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 454 */         GraphPanelSpo2.this.updateParent(comp.getParent());
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
/*     */   protected void paintComponent(Graphics g)
/*     */   {
/* 467 */     super.paintComponent(g);
/*     */     
/*     */ 
/*     */ 
/* 471 */     updateGraphic(g);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   protected synchronized void updateGraphic(Graphics g)
/*     */   {
/* 479 */     Graphics2D g2D = (Graphics2D)g;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 485 */     if (this.antialiasing)
/*     */     {
/* 487 */       RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
/*     */       
/* 489 */       g2D.setRenderingHints(rh);
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 497 */     if (this.updatePointValues)
/*     */     {
/* 499 */       calculatePointValues();
/*     */       
/* 501 */       this.updatePointValues = false;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 507 */     g2D.setColor(this.lineColor);
/*     */     
/* 509 */     g2D.setStroke(new BasicStroke(this.lineWidth));
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
/* 523 */     float x1 = 0.0F;
/*     */     
/* 525 */     float y1 = this.lineStartY;
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 533 */     float x2 = 0.0F;
/*     */     
/* 535 */     float y2 = 0.0F;
/*     */     
/*     */ 
/*     */ 
/* 539 */     Iterator<Float> iter = this.dataQueue.iterator();
/*     */     
/* 541 */     while (iter.hasNext())
/*     */     {
/*     */ 
/*     */ 
/* 545 */       x2 = x1 + this.lineOffsetX;
/*     */       
/*     */       try
/*     */       {
/* 549 */         y2 = ((Float)iter.next()).floatValue();
/*     */       }
/*     */       catch (Throwable t) {}
/*     */       
/*     */ 
/*     */ 
/* 555 */       g2D.draw(new Line2D.Float(x1, y1, x2, y2));
/*     */       
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/* 561 */       x1 = x2;
/*     */       
/* 563 */       y1 = y2;
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 569 */     this.lineStartY = ((int)y1);
/*     */     
/*     */ 
/*     */ 
/* 573 */     g2D.dispose();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getMaxValue()
/*     */   {
/* 581 */     return this.maxValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setMaxValue(int maxValue)
/*     */   {
/* 589 */     this.maxValue = maxValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getMinValue()
/*     */   {
/* 597 */     return this.minValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setMinValue(int minValue)
/*     */   {
/* 605 */     this.minValue = minValue;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getQueueSize()
/*     */   {
/* 613 */     return this.queueSize;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setQueueSize(int queueSize)
/*     */   {
/* 621 */     this.queueSize = queueSize;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public Color getLineColor()
/*     */   {
/* 629 */     return this.lineColor;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setLineColor(Color lineColor)
/*     */   {
/* 637 */     this.lineColor = lineColor;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getDelay()
/*     */   {
/* 645 */     return this.timer.getDelay();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setDelay(int delay)
/*     */   {
/* 653 */     this.timer.setDelay(delay);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void startAnimation()
/*     */   {
/* 661 */     this.timer.start();
/*     */     
/* 663 */     this.animationRunning = this.timer.isRunning();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void pauseAnimation()
/*     */   {
/* 671 */     this.timer.stop();
/*     */     
/* 673 */     this.animationRunning = this.timer.isRunning();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean isAnimationRunning()
/*     */   {
/* 681 */     return this.animationRunning;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void clearData()
/*     */   {
/* 689 */     if (this.dataBuffer != null)
/*     */     {
/* 691 */       this.dataBuffer.clear();
/*     */     }
/*     */     
/*     */ 
/*     */ 
/*     */ 
/* 697 */     if (this.dataQueue != null)
/*     */     {
/* 699 */       this.dataQueue.clear();
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void clearBuffer()
/*     */   {
/* 709 */     if (this.dataQueue != null)
/*     */     {
/* 711 */       this.dataQueue.clear();
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public int getLineWidth()
/*     */   {
/* 721 */     return this.lineWidth;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setLineWidth(int lineWidth)
/*     */   {
/* 729 */     this.lineWidth = lineWidth;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean isAntialiasing()
/*     */   {
/* 737 */     return this.antialiasing;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setAntialiasing(boolean antialiasing)
/*     */   {
/* 745 */     this.antialiasing = antialiasing;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public boolean isQueueFull()
/*     */   {
/* 753 */     return this.dataQueue.size() == this.queueSize;
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Graph\GraphPanelSpo2.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */