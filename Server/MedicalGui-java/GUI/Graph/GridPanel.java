/*     */ package GUI.Graph;
/*     */ 
/*     */ import java.awt.Color;
/*     */ import java.awt.Graphics;
/*     */ import java.awt.Point;
/*     */ import javax.swing.JPanel;
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ public class GridPanel
/*     */   extends JPanel
/*     */ {
/*     */   private static final long serialVersionUID = 1L;
/*     */   private static final int DEFAULT_LINE_WIDTH = 1;
/*     */   private int cellWidth;
/*     */   private int cellHeight;
/*     */   private Point middlePoint;
/*     */   private int lineWidth;
/*     */   private Color lineColor;
/*     */   private boolean showBaseGuide;
/*     */   
/*     */   public GridPanel(int cellWidth, int cellHeight)
/*     */   {
/*  73 */     this(cellWidth, cellHeight, 1, Color.gray);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public GridPanel(int cellWidth, int cellHeight, int lineWidth, Color lineColor)
/*     */   {
/*  85 */     this.cellWidth = cellWidth;
/*  86 */     this.cellHeight = cellHeight;
/*  87 */     this.lineWidth = lineWidth;
/*  88 */     this.lineColor = lineColor;
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   private void calculateMiddlePoint()
/*     */   {
/*  96 */     if (this.middlePoint == null) {
/*  97 */       this.middlePoint = new Point();
/*     */     }
/*  99 */     this.middlePoint.x = (getWidth() / 2);
/* 100 */     this.middlePoint.y = (getHeight() / 2);
/*     */   }
/*     */   
/*     */   protected void paintComponent(Graphics g)
/*     */   {
/* 105 */     super.paintComponent(g);
/*     */     
/*     */ 
/* 108 */     if (this.middlePoint == null) {
/* 109 */       calculateMiddlePoint();
/*     */     }
/*     */     
/* 112 */     g.setColor(this.lineColor);
/*     */     
/*     */ 
/* 115 */     for (int x = 0; x < getWidth(); x += this.cellWidth) {
/* 116 */       g.fillRect(x, 0, this.lineWidth, getHeight());
/*     */     }
/*     */     
/*     */ 
/* 120 */     for (int y = 0; y < getHeight(); y += this.cellHeight) {
/* 121 */       g.fillRect(0, y, getWidth(), this.lineWidth);
/*     */     }
/*     */     
/*     */ 
/* 125 */     if (this.showBaseGuide) {
/* 126 */       g.setColor(this.lineColor.darker());
/*     */       
/* 128 */       g.fillRect(0, this.middlePoint.y, getWidth(), this.lineWidth);
/* 129 */       g.fillRect(this.middlePoint.x, 0, this.lineWidth, getHeight());
/*     */     }
/*     */   }
/*     */   
/*     */   public int getCellWidth()
/*     */   {
/* 135 */     return this.cellWidth;
/*     */   }
/*     */   
/*     */   public void setCellWidth(int cellWidth) {
/* 139 */     this.cellWidth = cellWidth;
/*     */   }
/*     */   
/*     */   public int getCellHeight() {
/* 143 */     return this.cellHeight;
/*     */   }
/*     */   
/*     */   public void setCellHeight(int cellHeight) {
/* 147 */     this.cellHeight = cellHeight;
/*     */   }
/*     */   
/*     */   public int getLineWidth() {
/* 151 */     return this.lineWidth;
/*     */   }
/*     */   
/*     */   public void setLineWidth(int lineWidth) {
/* 155 */     this.lineWidth = lineWidth;
/*     */   }
/*     */   
/*     */   public Color getLineColor() {
/* 159 */     return this.lineColor;
/*     */   }
/*     */   
/*     */   public void setLineColor(Color lineColor) {
/* 163 */     this.lineColor = lineColor;
/*     */   }
/*     */   
/*     */   public boolean isShowBaseGuide() {
/* 167 */     return this.showBaseGuide;
/*     */   }
/*     */   
/*     */   public void setShowBaseGuide(boolean showBaseGuide) {
/* 171 */     this.showBaseGuide = showBaseGuide;
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Graph\GridPanel.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */