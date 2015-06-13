/*     */ package GUI.Graph;
/*     */ 
/*     */ import java.awt.Color;
/*     */ import java.awt.Dimension;
/*     */ import java.util.List;
/*     */ import javax.swing.JLayeredPane;
/*     */ import javax.swing.JPanel;
/*     */ import javax.swing.border.Border;
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ public class MedicalGraph
/*     */   extends JPanel
/*     */ {
/*     */   private static final long serialVersionUID = 1L;
/*     */   public static final int SPIROMETRY = 1;
/*     */   public static final int ECG = 2;
/*     */   public static final int SPO2 = 3;
/*     */   private static final int BACKGROUND_LAYER = 0;
/*     */   private static final int GRID_LAYER = 1;
/*     */   private static final int GRAPH_LAYER = 3;
/*     */   private static final int GRID_LAYER2 = 2;
/*     */   private JLayeredPane container;
/*     */   private GraphPanel graphPanel;
/*     */   private GridPanel gridPanel;
/*     */   private GridPanel gridPanell;
/*     */   private JPanel backPanel;
/*     */   private int width;
/*     */   private int height;
/*     */   
/*     */   public MedicalGraph(int width, int height)
/*     */   {
/*  47 */     this(0, width, height);
/*     */   }
/*     */   
/*     */   public MedicalGraph(int graphType, int width, int height) {
/*  51 */     this.width = width;
/*  52 */     this.height = height;
/*     */     
/*  54 */     setPreferredSize(new Dimension(width, height));
/*  55 */     setLayout(null);
/*     */     
/*  57 */     this.backPanel = new JPanel();
/*  58 */     this.backPanel.setOpaque(true);
/*  59 */     this.backPanel.setBounds(0, 0, width, height);
/*     */     
/*     */ 
/*     */ 
/*  63 */     switch (graphType) {
/*     */     case 2: 
/*  65 */       this.gridPanel = new GridPanel(4, 4);
/*  66 */       this.gridPanell = new GridPanel(20, 20, 2, Color.gray);
/*  67 */       this.gridPanell.setOpaque(false);
/*  68 */       this.gridPanell.setBounds(0, 0, width, height);
/*  69 */       break;
/*     */     
/*     */     case 1: 
/*  72 */       this.gridPanel = new GridPanel(22, 11);
/*  73 */       break;
/*     */     
/*     */     default: 
/*  76 */       this.gridPanel = new GridPanel(10, 10);
/*     */     }
/*     */     
/*     */     
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*  85 */     this.gridPanel.setOpaque(false);
/*  86 */     this.gridPanel.setBounds(0, 0, width, height);
/*     */     
/*     */ 
/*  89 */     this.graphPanel = null;
/*     */     
/*  91 */     switch (graphType) {
/*     */     case 1: 
/*  93 */       this.graphPanel = new GraphPanelXY();
/*  94 */       break;
/*     */     
/*     */     case 3: 
/*  97 */       this.graphPanel = new GraphPanelSpo2(0, 0, Color.yellow, 1);
/*     */       
/*  99 */       break;
/*     */     
/*     */     case 2: 
/* 102 */       this.graphPanel = new GraphPanel(0, 0, Color.green, 1);
/* 103 */       break;
/*     */     
/*     */     default: 
/* 106 */       this.graphPanel = new GraphPanel();
/*     */     }
/*     */     
/* 109 */     this.graphPanel.setOpaque(false);
/* 110 */     this.graphPanel.setBounds(0, 0, width, height);
/*     */     
/*     */ 
/* 113 */     this.container = new JLayeredPane();
/* 114 */     this.container.setSize(new Dimension(width, height));
/*     */     
/*     */ 
/* 117 */     switch (graphType) {
/*     */     case 2: 
/* 119 */       this.container.add(this.gridPanel, new Integer(1));
/* 120 */       this.container.add(this.gridPanell, new Integer(2));
/* 121 */       break;
/*     */     
/*     */     case 1: 
/* 124 */       this.container.add(this.gridPanel, new Integer(1));
/*     */     }
/*     */     
/*     */     
/*     */ 
/*     */ 
/* 130 */     this.container.add(this.graphPanel, new Integer(3));
/*     */     
/*     */ 
/* 133 */     add(this.container);
/*     */   }
/*     */   
/*     */   public void setBorder(Border border)
/*     */   {
/* 138 */     if (border != null) {
/* 139 */       this.graphPanel.setBorder(border);
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */   public int getWidth()
/*     */   {
/* 146 */     return this.width;
/*     */   }
/*     */   
/*     */   public int getHeight()
/*     */   {
/* 151 */     return this.height;
/*     */   }
/*     */   
/*     */   public boolean isGridVisible() {
/* 155 */     return this.gridPanel.isVisible();
/*     */   }
/*     */   
/*     */   public void setGridVisible(boolean gridVisible)
/*     */   {
/* 160 */     this.gridPanel.setVisible(gridVisible);
/*     */   }
/*     */   
/*     */   public long getMaxValue() {
/* 164 */     return this.graphPanel.getMaxValue();
/*     */   }
/*     */   
/*     */ 
/*     */   public void setMaxValue(int maxValue)
/*     */   {
/* 170 */     this.graphPanel.setMaxValue(maxValue);
/*     */   }
/*     */   
/*     */   public long getMinValue()
/*     */   {
/* 175 */     return this.graphPanel.getMinValue();
/*     */   }
/*     */   
/*     */   public void setMinValue(int minValue)
/*     */   {
/* 180 */     this.graphPanel.setMinValue(minValue);
/*     */   }
/*     */   
/*     */   public int getDelay()
/*     */   {
/* 185 */     return this.graphPanel.getDelay();
/*     */   }
/*     */   
/*     */   public void setDelay(int delay)
/*     */   {
/* 190 */     this.graphPanel.setDelay(delay);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void insertData(Integer[] data)
/*     */   {
/* 199 */     this.graphPanel.insertData(data);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void insertData(Integer data)
/*     */   {
/* 208 */     this.graphPanel.insertData(data);
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void insertData(List<Float> listX, List<Float> listY)
/*     */   {
/* 219 */     if ((this.graphPanel instanceof GraphPanelXY)) {
/* 220 */       ((GraphPanelXY)this.graphPanel).insertData(listX, listY);
/*     */     }
/*     */   }
/*     */   
/*     */   public void setGraphColor(Color color)
/*     */   {
/* 226 */     this.graphPanel.setLineColor(color);
/*     */   }
/*     */   
/*     */   public Color getGraphColor()
/*     */   {
/* 231 */     return this.graphPanel.getLineColor();
/*     */   }
/*     */   
/*     */   public void setGraphLineWidth(int lineWidth)
/*     */   {
/* 236 */     this.graphPanel.setLineWidth(lineWidth);
/*     */   }
/*     */   
/*     */   public int getGraphLineWidth()
/*     */   {
/* 241 */     return this.graphPanel.getLineWidth();
/*     */   }
/*     */   
/*     */   public void startAnimation()
/*     */   {
/* 246 */     this.graphPanel.startAnimation();
/*     */   }
/*     */   
/*     */   public void pauseAnimation()
/*     */   {
/* 251 */     this.graphPanel.pauseAnimation();
/*     */   }
/*     */   
/*     */   public void setBackgroundColor(Color c)
/*     */   {
/* 256 */     this.backPanel.setBackground(c);
/*     */   }
/*     */   
/*     */   public Color getBackgroundColor() {
/* 260 */     return this.backPanel.getBackground();
/*     */   }
/*     */   
/*     */   public void setGridColor(Color c) {
/* 264 */     this.gridPanel.setLineColor(c);
/*     */   }
/*     */   
/*     */   public Color getGridColor() {
/* 268 */     return this.gridPanel.getLineColor();
/*     */   }
/*     */   
/*     */   public void setQueueSize(int queueSize) {
/* 272 */     this.graphPanel.setQueueSize(queueSize);
/*     */   }
/*     */   
/*     */   public int getQueueSize()
/*     */   {
/* 277 */     return this.graphPanel.getQueueSize();
/*     */   }
/*     */   
/*     */   public boolean isAnimationRunning()
/*     */   {
/* 282 */     return this.graphPanel.isAnimationRunning();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void setAntialiasing(boolean antialiasing)
/*     */   {
/* 293 */     this.graphPanel.setAntialiasing(antialiasing);
/*     */   }
/*     */   
/*     */   public boolean isAntialiasing()
/*     */   {
/* 298 */     return this.graphPanel.isAntialiasing();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void clearData()
/*     */   {
/* 307 */     this.graphPanel.clearData();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */   public void clearBuffer()
/*     */   {
/* 316 */     this.graphPanel.clearBuffer();
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   public void revalidateGraph()
/*     */   {
/* 324 */     this.graphPanel.calculatePointValues();
/*     */   }
/*     */   
/*     */   public boolean isQueueFull()
/*     */   {
/* 329 */     return this.graphPanel.isQueueFull();
/*     */   }
/*     */ }


/* Location:              C:\Freescale\Medical GUI\Medical_GUI_-_Java_executable_2.1.jar!\GUI\Graph\MedicalGraph.class
 * Java compiler version: 5 (49.0)
 * JD-Core Version:       0.7.1
 */