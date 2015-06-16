/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package conexion;
    
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Conexion {
   static String bd = "bd_proyecto_cuerpo";
   static String login = "dinorahcab";
   static String password = "dinorahcab";
   static String url = "jdbc:mysql://192.168.2.239:3306/"+bd;

   Connection conn = null;

   /** Constructor de DbConnection */
   public Conexion() {
      try{
         //obtenemos el driver de para mysql
         Class.forName("com.mysql.jdbc.Driver");
         //obtenemos la conexi�n
         conn = DriverManager.getConnection(url,login,password);

         if (conn!=null){
            System.out.println("Coneccion a base de datos "+bd+" OK");
         }
      }
      catch(SQLException | ClassNotFoundException e){
         System.out.println(e);
      }
   }
   /**Permite retornar la conexion
     * @return */
   public Connection getConnection(){
      return conn;
   }

   public void desconectar(){
      conn = null;
   }
}
