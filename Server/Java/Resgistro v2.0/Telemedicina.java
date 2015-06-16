/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.upslp;


import java.io.IOException;
import javafx.application.Application;
import javafx.fxml.*;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 *
 * @author Ramiro
 */
public class Telemedicina extends Application {
    private  Stage stagePrincipal;
    private  AnchorPane rootPane;
    
    
    @Override
    public void start(Stage stagePrincipal) throws Exception {
       this.stagePrincipal = stagePrincipal;
       showLoggin();
    } 
       /**       
        Parent root = FXMLLoader.load(getClass().getResource("FXMLMain.fxml"));
        
        Scene scene = new Scene(root);
        
        stage.setScene(scene);
        stage.setResizable(false);
        stage.setTitle("Universidad Politécnica de San Luis Potosí");
        stage.show();
       */
    
    public void showLoggin(){
        
        try{
            
            FXMLLoader loader = new FXMLLoader(Telemedicina.class.getResource("FXMLLoggin.fxml"));
            rootPane = (AnchorPane) loader.load();
            Scene scene = new Scene(rootPane);
            stagePrincipal.setTitle("Loggin");
            stagePrincipal.setScene(scene);
            FXMLLogginController controller = loader.getController();
            controller.setProgramaPrincipal(this);
            stagePrincipal.setResizable(false);
            stagePrincipal.show();
            
        }catch (IOException e){
            System.out.println("NO es posible cargar showLogin");
        }
    }
    
    public void showContentWindow(){
        try{
            ocultaLoggin();
            FXMLLoader loader = new FXMLLoader(Telemedicina.class.getResource("FXMLMain.fxml"));
            AnchorPane winContent = (AnchorPane) loader.load();
            Stage ventana = new Stage(StageStyle.UNDECORATED);
            ventana.setTitle("Universidad Politécnica de San Luis Potosí");
            ventana.initOwner(stagePrincipal);
            Scene scene = new Scene(winContent);
            ventana.setScene(scene);
            FXMLMainController controller = loader.getController();
            controller.setStagePrincipal(ventana, this);
            ventana.show();
            
        }catch (IOException e){
            System.out.println("No se pede iniciar la nueva ventana");
        }
    }
    
    public void ocultaLoggin(){
        stagePrincipal.close();
    }
    
    public void muestraLoggin(){
        stagePrincipal.show();
    }
     /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }   

   
}
