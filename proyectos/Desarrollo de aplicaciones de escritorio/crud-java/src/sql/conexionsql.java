package sql;
import java.sql.Connection;
import java.sql.DriverManager;
import javax.swing.JOptionPane;

public class conexionsql {
    Connection conn=null;
    String url="jdbc:postgresql://localhost/empresa";
    String usuario="postgres";
    String clave="{colocar_contraseña}";
    
    public Connection conectar(){
        try {
            Class.forName("org.postgresql.Driver");
            conn=DriverManager.getConnection(url,usuario,clave);
            
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null,"Error al conectar con la base de datos "+e,"Error crítico",JOptionPane.ERROR_MESSAGE);
        }
    return conn;
    }
    
}
