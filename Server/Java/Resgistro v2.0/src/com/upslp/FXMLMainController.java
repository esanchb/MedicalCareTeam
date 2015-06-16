
package com.upslp;

import static com.sun.javafx.css.SizeUnits.S;
import conexion.Conexion;
import java.beans.EventHandler;
import java.util.regex.*;
import java.net.URL;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ResourceBundle;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.input.*;
import static javafx.scene.input.KeyCode.S;
import javafx.stage.Stage;
import javafx.util.Callback;
import javax.swing.JFrame;
import static jdk.nashorn.internal.runtime.regexp.joni.constants.AsmConstants.S;
import static jdk.nashorn.internal.runtime.regexp.joni.encoding.CharacterType.S;
import org.jfree.chart.ChartPanel;

/**
 *
 * @author Ramiro
 */
public class FXMLMainController implements Initializable {
    private Stage ventana;
    private Telemedicina ProgramaPrincipal;
    int cont=1;
    private Object tableviewIndicators;
   
    public void setStagePrincipal(Stage ventana, Telemedicina ProgramaPrincipal) {
        this.ventana = ventana;
        this.ProgramaPrincipal = ProgramaPrincipal;
    }
    
    @FXML
    private TextField txtXBuscar;
    @FXML
    private String consulta;
    @FXML
    private Label etAdvise;
    TableColumn col;
    private ObservableList<ObservableList> data;
    @FXML private TableView tbPacientes;
    
    
    
    
        //CONNECTION DATABASE
        public void buildData(String consultar){
            Conexion conn = new Conexion();
             data = FXCollections.observableArrayList();
            try{
               
              Statement sentencia = conn.getConnection().createStatement();
              //SQL FOR SELECTING ALL OF CUSTOMER
         
              //ResultSet
              ResultSet rs = sentencia.executeQuery("SELECT * FROM `patients` WHERE `patientName` LIKE '%" + consultar + "%'");

              /**********************************
               * TABLE COLUMN ADDED DYNAMICALLY *
               **********************************/
              if(cont==1){
              for(int i=0 ; i<rs.getMetaData().getColumnCount(); i++){
                  //We are using non property style for making dynamic table
                   int j = i;     
                  col = null;
                  col = new TableColumn(rs.getMetaData().getColumnName(i+1));
                  col.setCellValueFactory(new Callback<TableColumn.CellDataFeatures<ObservableList,String>,ObservableValue<String>>(){                   
                      @Override
                      public ObservableValue<String> call(TableColumn.CellDataFeatures<ObservableList, String> param) {     
                          return new SimpleStringProperty(param.getValue().get(j).toString());                       
                      }                  
                  });
                  tbPacientes.getColumns().addAll(col);
                  System.out.println("Column ["+i+"] ");
                  cont=0;
              }
              }
              /********************************
               * Data added to ObservableList *
               ********************************/
              while(rs.next()){
                  
                  //Iterate Row
                  ObservableList<String> row = FXCollections.observableArrayList();
                  row.clear();
                  for(int i=1 ; i<=rs.getMetaData().getColumnCount(); i++){
                      //Iterate Column
                      
                      row.add(rs.getString(i));
                  }
                  System.out.println("Row [1] added "+row );
                  data.add(row);
              }
              //FINALLY ADDED TO TableView
              
              tbPacientes.setItems(data);

            }catch(Exception e){
                System.out.println("Error on Building Data");            
            }
    
        }
        /////////////////////////////////////////////
       

 
        /////////////////////////////////////////////
    
   @FXML
   private void ClickBuscar()throws SQLException{
       
       Conexion conn = new Conexion();
       consulta = txtXBuscar.getText();
       
       
        Pattern path = Pattern.compile("^[0-9]+");
        Matcher mat = path.matcher(consulta);
            
            if(mat.matches()){
                
                
                System.out.println("Es un ID");
                etAdvise.setText("Es un ID");


            }else{
                
                buildData(consulta);
                System.out.println("Es una cadena");
                etAdvise.setText("Es una cadena");

            }
   }

 
    @FXML
    private void BuscarPteKeyPress(KeyEvent e){
        if (e.getCode().equals(KeyCode.ENTER)){
           consulta = txtXBuscar.getText();
        
            Pattern path = Pattern.compile("^[0-9]+");
            Matcher mat = path.matcher(consulta);
            if(mat.matches()){
                System.out.println("Es un ID");
                etAdvise.setText("Es un ID");

            }else{
                buildData(consulta);
                System.out.println("Es una cadena");
                etAdvise.setText("Es una cadena");

            }
        }
    }
    @FXML
    private void actionLoggout(){
        ProgramaPrincipal.muestraLoggin();
        ventana.close();
    }
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }  
    public void muestraGrafica(){
        
        String lol=tbPacientes.getSelectionModel().selectedItemProperty().getValue().toString();
        Graficas graf = new Graficas();
        graf.getDatos(lol);
        graf.setVisible(true);
    }
    }
 
    
