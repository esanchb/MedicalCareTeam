/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.upslp;

import conexion.Conexion;
import java.net.URL;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;

/**
 * FXML Controller class
 *
 * @author Ramiro
 */
public class FXMLLogginController implements Initializable {

    private Telemedicina ProgramaPrincipal;
    
    
    public void setProgramaPrincipal(Telemedicina ProgramaPrincipal){
        this.ProgramaPrincipal = ProgramaPrincipal;
    }
    
    @FXML
    private TextField txtUsuario;
    @FXML
    private PasswordField txtPassword;
    
    @FXML
    public void enterForLoggin(KeyEvent e) throws SQLException{
        if(e.getCode().equals(KeyCode.ENTER)){
            inicioSesion();
        }
        if(e.getCode().equals(KeyCode.ESCAPE)){
            actionCancelar();
        }
    }
    public void inicioSesion() throws SQLException{
        boolean encontrado = false;
        Conexion conn = new Conexion();
        
        
        String user = txtUsuario.getText();
        String pass = txtPassword.getText();
        
        
        try{
            Statement sentencia = conn.getConnection().createStatement();
            ResultSet result = sentencia.executeQuery("SELECT * FROM `doctors` WHERE `usrNameMedic` = '" + user + "' AND `medicPass` = '" + pass +"'");
            while(result.next()){
                
                if((result.getString("usrNameMedic").equals(txtUsuario.getText()))  && (result.getString("medicPass").equals(pass))){
                    encontrado = true;
                }
                
            }
        }catch(SQLException ex){
            System.out.println("Excepcion encontrada en la consulta");
        }
        
            
        if(encontrado){
                System.out.println("acceso corecto");
                txtPassword.setText("");
                ProgramaPrincipal.showContentWindow();
                
        }else{
                System.out.println("accesso incorrecto");
        }
        
    }
    public void actionCancelar(){
        ProgramaPrincipal.ocultaLoggin();
    }
    /**
     * Initializes the controller class.
     * @param url
     * @param rb
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
