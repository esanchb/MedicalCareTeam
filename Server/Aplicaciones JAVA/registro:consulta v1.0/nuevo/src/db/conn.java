
package db;

/**
 *
 * @author JuanCarlos
 */

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class conn {
    
   public String bd = "medicina";
   public String user = "root";
   public String pass = "";
   public String url = "jdbc:mysql://jcs-macbook-air.local:3306/"+bd;
   
   public conn()
   {
   
   }
   
   public Connection Conectar ()
   {
       Connection link = null;
       try
       {
       Class.forName("com.mysql.jdbc.Driver");
       link = DriverManager.getConnection(this.url, this.user, this.pass);
       }
       catch (ClassNotFoundException | SQLException e)
       {
           JOptionPane.showMessageDialog(null, e);
       }
       return link;
   }
    
}
