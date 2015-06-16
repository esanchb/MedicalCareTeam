/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package app;

import db.conn;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
////////////////////////////////////////////////////////////

import org.jfree.chart.*;
import org.jfree.chart.renderer.xy.XYSplineRenderer;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.axis.*;
import org.jfree.data.xy.*;

/*import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.DefaultCategoryDataset;

import org.jfree.data.general.DefaultPieDataset;*/


////////////////////////////////////////////////////////////


/**
 *
 * @author JuanCarlos
 */
public class Consulta extends javax.swing.JFrame {
DefaultTableModel modelo;
    //private Object cn;
    /**
     * Creates new form Consulta
     */
    public Consulta() 
    {
        initComponents();
        
        CargarTabla("*");
         this.setLocationRelativeTo(null);
        
        this.lineal.setVisible(false);
        this.setVisible(true);
    }
    
    
    
     void CargarTabla(String valor)
        {
          String[] titulos = {"ID","Nombre", "Apellidos", "Fecha Nac.", "Genero", "Peso", "Estatura", "Lugar Nac.", "Fecha Reg.", "Telefono", "Domicilio"};//, "Nivel Oxigeno", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "C14", "C15", "C16", "C17", "C18", "C19", "C20"};
          String[] registro = new String [11];//32 y luego 11   "ID",
          String sSQL = "";
          modelo = new DefaultTableModel(null, titulos); 
          
          conn mysql = new conn();
          Connection cn = mysql.Conectar();
          
          //sSQL = "SELECT id, nombre, apellidos, fecha_nac, genero, peso, estatura, lugar_nac, domicilio, telefono, fecha_datos, nivel_oxi, c01, c02, c03, c04, c05, c06, c07, c08, c09, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20 FROM `datos`" + "WHERE `nombre` LIKE '%"+valor+"%'";          
          //sSQL = "SELECT id, nombre, apellidos, fecha_nac, genero, peso, estatura, lugar_nac, domicilio, telefono, fecha_datos, nivel_oxi, c01, c02, c03, c04, c05, c06, c07, c08, c09, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20 FROM datos" + "WHERE CONCAT(nombre, ' ',apellidos) LIKE '%"+valor+"%'";                                                                                                                                                                                         
          //ResultSet rs = sentencia.executeQuery("SELECT * FROM `patients` WHERE `patientName` LIKE '%" + consultar + "%'");
         sSQL = ("SELECT * FROM `datos`  WHERE `nombre` LIKE '%" + valor + "%'");    
         
          //"SELECT * FROM `patients` WHERE `patientName` LIKE '%" + consultar + "%'");
    try 
    { 
        Statement st = cn.createStatement();
        ResultSet rs = st.executeQuery(sSQL);
        
        while(rs.next())
        {
            registro[0] = rs.getString("id");
            registro[1] = rs.getString("nombre");
            registro[2] = rs.getString("apellidos");
            registro[3] = rs.getString("fecha_nac");
            registro[4] = rs.getString("genero");
            registro[5] = rs.getString("peso");
            registro[6] = rs.getString("estatura");
            registro[7] = rs.getString("lugar_nac");
            registro[8] = rs.getString("fecha_datos");
            registro[9] = rs.getString("telefono");
            registro[10] = rs.getString("domicilio");
            /*registro[11] = rs.getString("nivel_oxi");
            registro[12] = rs.getString("c01");
            registro[13] = rs.getString("c02");
            registro[14] = rs.getString("c03");
            registro[15] = rs.getString("c04");
            registro[16] = rs.getString("c05");
            registro[17] = rs.getString("c06");
            registro[18] = rs.getString("c07");
            registro[19] = rs.getString("c08");
            registro[20] = rs.getString("c09");
            registro[21] = rs.getString("c10");
            registro[22] = rs.getString("c11");
            registro[23] = rs.getString("c12");
            registro[24] = rs.getString("c13");
            registro[25] = rs.getString("c14");
            registro[26] = rs.getString("c15");
            registro[27] = rs.getString("c16");
            registro[28] = rs.getString("c17");
            registro[29] = rs.getString("c18");
            registro[30] = rs.getString("c19");
            registro[31] = rs.getString("c20");*/
            
            modelo.addRow(registro);
            
        }
        tbConsulta.setModel(modelo);
        
    } 
    catch (SQLException ex) 
    {
        JOptionPane.showMessageDialog(null, ex);
    }
          
     }
    
    
 ///////////////////////////////////////////////////////////////////    
     
     void Res(String id )
        {
          String sSQL = "";
          String oxi="";
          
          conn mysql = new conn();
          Connection cn = mysql.Conectar();

          sSQL = ("SELECT * FROM `datos` WHERE `id` ="+id);

    try 
    { 
        Statement st = cn.createStatement();
        ResultSet rs = st.executeQuery(sSQL);
        
        while(rs.next())
        {
            oxi = rs.getString("nivel_oxi");
   
            JOptionPane.showMessageDialog(null, "El nivel de oxigeno registrado: "+oxi+" mmHg");
        }
        
        
    } 
    catch (SQLException ex) 
    {
        JOptionPane.showMessageDialog(null, ex);
        
    }
          
     }
     
     ///////////////////////////////////////////////////////////////////    
     void nivel(String id )
        {
          String sSQL = "";
          String uno="",dos="",tres="",cuatro="",cinco="",seis="",siete="",ocho="",nueve="",diez="",once="",doce="",trece="",catorce="",quince="",diesiseis="",diesiseite="",diesiocho="",diesinueve="",veinte="";
          
          conn mysql = new conn();
          Connection cn = mysql.Conectar();

          sSQL = ("SELECT * FROM `datos` WHERE `id` ="+id);

    try 
    { 
        Statement st = cn.createStatement();
        ResultSet rs = st.executeQuery(sSQL);
        
        while(rs.next())
        {
            
            /*registro[0] = rs.getString("id");
            registro[1] = rs.getString("nombre");
            registro[2] = rs.getString("apellidos");
            registro[3] = rs.getString("fecha_nac");
            registro[4] = rs.getString("genero");
            registro[5] = rs.getString("peso");
            registro[6] = rs.getString("estatura");
            registro[7] = rs.getString("lugar_nac");
            registro[8] = rs.getString("domicilio");
            registro[9] = rs.getString("telefono");
            registro[10] = rs.getString("fecha_datos");
            registro[11] = rs.getString("nivel_oxi");*/
            
            uno = rs.getString("c01");
            dos = rs.getString("c02");
            tres = rs.getString("c03");
            cuatro = rs.getString("c04");
            cinco = rs.getString("c05");
            seis = rs.getString("c06");
            siete = rs.getString("c07");
            ocho = rs.getString("c08");
            nueve = rs.getString("c09");
            diez = rs.getString("c10");
            once = rs.getString("c11");
            doce = rs.getString("c12");
            trece = rs.getString("c13");
            catorce = rs.getString("c14");
            quince = rs.getString("c15");
            diesiseis = rs.getString("c16");
            diesiseite = rs.getString("c17");
            diesiocho = rs.getString("c18"); 
            diesinueve = rs.getString("c19");
            veinte = rs.getString("c20");
            
           // oxi = rs.getString("nivel_oxi");
            //JOptionPane.showMessageDialog(null, "El nivel de oxigeno registrado fue: "+oxi);
        }
        
        
    } 
    catch (SQLException ex) 
    {
        JOptionPane.showMessageDialog(null, ex);
        
    }
    
    lineal.setVisible(true);  
    capas.setLayer(lineal,0,0);
/////////////////////////////////////////////////
        ChartPanel panel;
        JFreeChart chart = null;
        
        int validar = 1;
        XYSplineRenderer renderer = new XYSplineRenderer();
        XYSeriesCollection dataset = new XYSeriesCollection();
        
        ValueAxis x = new NumberAxis();
        ValueAxis y = new NumberAxis();
        
        XYSeries serie = new XYSeries("medicion");
        
        XYPlot plot;
        lineal.removeAll();
        
        try
        {
            /*for(int fila=0;fila<20;fila++)
            {
                serie.add(Float.parseFloat(String.valueOf(datos.getValueAt(fila,0))),
                Float.parseFloat(String.valueOf(datos.getValueAt(fila,1))));
            }*/   //AQUI CAMBIE 
            //INTENTO DE METER DATOS DE LA TABLA
            
            //serie.add(0, Float.parseFloat(String.valueOf(uno)));
            serie.add(0, Float.parseFloat(String.valueOf(uno)));
            serie.add(1, Float.parseFloat(String.valueOf(dos)));
            serie.add(2, Float.parseFloat(String.valueOf(tres)));
            serie.add(3, Float.parseFloat(String.valueOf(cuatro)));
            serie.add(4, Float.parseFloat(String.valueOf(cinco)));
            serie.add(5, Float.parseFloat(String.valueOf(seis)));
            serie.add(6, Float.parseFloat(String.valueOf(siete)));
            serie.add(7, Float.parseFloat(String.valueOf(ocho)));
            serie.add(8, Float.parseFloat(String.valueOf(nueve)));
            serie.add(9, Float.parseFloat(String.valueOf(diez)));
            serie.add(10, Float.parseFloat(String.valueOf(once)));
            serie.add(11, Float.parseFloat(String.valueOf(doce)));
            serie.add(12, Float.parseFloat(String.valueOf(trece)));
            serie.add(13, Float.parseFloat(String.valueOf(catorce)));
            serie.add(14, Float.parseFloat(String.valueOf(quince)));
            serie.add(15, Float.parseFloat(String.valueOf(diesiseis)));
            serie.add(16, Float.parseFloat(String.valueOf(diesiseite)));
            serie.add(17, Float.parseFloat(String.valueOf(diesiocho)));
            serie.add(18, Float.parseFloat(String.valueOf(diesinueve)));
            serie.add(19, Float.parseFloat(String.valueOf(veinte)));
            
            
            
            
            //serie.add(Float.parseFloat(String.valueOf(datos.getValueAt(fila,0))),
              //  Float.parseFloat(String.valueOf(datos.getValueAt(fila,1))));
            
            
        }catch(Exception ex)
        {
          validar=0;      
         }
        if (validar==1)
        {
            dataset.addSeries(serie);
            x.setLabel("tiempo");
            y.setLabel("latidos");
            plot = new XYPlot(dataset,x,y,renderer);
            chart=new JFreeChart(plot);
            chart.setTitle("Grafico de electrocardiograma");
            
        }
        panel = new ChartPanel(chart);
        panel.setBounds(5, 10, 700, 450);
        
        lineal.add(panel);
        lineal.repaint();
          
     }
     
 ////////////////////////////////////////////////////////////////////////////////////
     
   

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPopupMenu1 = new javax.swing.JPopupMenu();
        mnEditar = new javax.swing.JMenuItem();
        jTextField1 = new javax.swing.JTextField();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        tbConsulta = new javax.swing.JTable();
        jLabel1 = new javax.swing.JLabel();
        txtCual = new javax.swing.JTextField();
        btBuscar = new javax.swing.JButton();
        btNivOxi = new javax.swing.JButton();
        btCardio = new javax.swing.JButton();
        capas = new javax.swing.JLayeredPane();
        lineal = new javax.swing.JPanel();

        mnEditar.setText("Modificar");
        jPopupMenu1.add(mnEditar);

        jTextField1.setText("jTextField1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED), "Consulta de datos"));

        tbConsulta.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {},
                {},
                {},
                {}
            },
            new String [] {

            }
        ));
        tbConsulta.setComponentPopupMenu(jPopupMenu1);
        jScrollPane1.setViewportView(tbConsulta);

        jLabel1.setText("Buscar paciente");

        txtCual.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtCualActionPerformed(evt);
            }
        });

        btBuscar.setText("Buscar");
        btBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btBuscarActionPerformed(evt);
            }
        });

        btNivOxi.setText("Oxigeno");
        btNivOxi.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btNivOxiActionPerformed(evt);
            }
        });

        btCardio.setText("Cardio");
        btCardio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btCardioActionPerformed(evt);
            }
        });

        capas.setBorder(javax.swing.BorderFactory.createEtchedBorder());

        javax.swing.GroupLayout linealLayout = new javax.swing.GroupLayout(lineal);
        lineal.setLayout(linealLayout);
        linealLayout.setHorizontalGroup(
            linealLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        linealLayout.setVerticalGroup(
            linealLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 551, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout capasLayout = new javax.swing.GroupLayout(capas);
        capas.setLayout(capasLayout);
        capasLayout.setHorizontalGroup(
            capasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(lineal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        capasLayout.setVerticalGroup(
            capasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(lineal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        capas.setLayer(lineal, javax.swing.JLayeredPane.DEFAULT_LAYER);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(24, 24, 24)
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtCual, javax.swing.GroupLayout.PREFERRED_SIZE, 194, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(btBuscar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 569, Short.MAX_VALUE)
                        .addComponent(btCardio)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btNivOxi))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(capas, javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jScrollPane1))))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(txtCual, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btBuscar)
                    .addComponent(btNivOxi)
                    .addComponent(btCardio))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(capas)
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btBuscarActionPerformed
       String valor = txtCual.getText();
       CargarTabla(valor);
    }//GEN-LAST:event_btBuscarActionPerformed
        String accion = "Insertar";

    private void btNivOxiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btNivOxiActionPerformed
       int filasel;
       String id;
       
       try
       {
           filasel = tbConsulta.getSelectedRow();
           if (filasel ==  -1)
           {
            JOptionPane.showMessageDialog(null, "No se ha seleccionado ninguna fila");
           }
           else
           {
               accion = "Modificar";
               modelo = (DefaultTableModel) tbConsulta.getModel(); 
               id = (String) modelo.getValueAt(filasel,0);
               Res(id);
           }
       }
       catch (Exception e)
       {
           
       }
       
       
       
    }//GEN-LAST:event_btNivOxiActionPerformed

    private void btCardioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btCardioActionPerformed

/////////////////////////////////////////////////
        int filasel;
       String id;
       
       try
       {
           filasel = tbConsulta.getSelectedRow();
           if (filasel ==  -1)
           {
            JOptionPane.showMessageDialog(null, "No se ha seleccionado ninguna fila");
           }
           else
           {
               accion = "Modificar";
               modelo = (DefaultTableModel) tbConsulta.getModel(); 
               id = (String) modelo.getValueAt(filasel,0);
               nivel(id);
           }
       }
       catch (Exception e)
       {
           
       }
        
    }//GEN-LAST:event_btCardioActionPerformed

    private void txtCualActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtCualActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtCualActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Consulta.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Consulta.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Consulta.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Consulta.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Consulta().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btBuscar;
    private javax.swing.JButton btCardio;
    private javax.swing.JButton btNivOxi;
    private javax.swing.JLayeredPane capas;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPopupMenu jPopupMenu1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JPanel lineal;
    private javax.swing.JMenuItem mnEditar;
    private javax.swing.JTable tbConsulta;
    private javax.swing.JTextField txtCual;
    // End of variables declaration//GEN-END:variables
}
