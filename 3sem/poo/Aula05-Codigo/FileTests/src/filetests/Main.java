/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package filetests;

import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        FileClass fcTemp = new FileClass();

        File f = new File("POO.dat");
        if(f.exists())
            f.delete();
        try {
            f.createNewFile();
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        /*
        System.out.println("----------RANDOM ACCESS FILE----------");       
        fcTemp.RandomAccessMethod("c:\\temp\\POO.dat");
        System.out.println("\n" + "\n" + "\n");
        */
        
        /*
        System.out.println("----------------STREAM----------------");
        fcTemp.TanqueCano("c:\\temp\\POO.dat");
        System.out.println("\n" + "\n" + "\n");
       */

/*
        System.out.println("--------------FILE copy---------------");
        args = new String[2];
        args[0] = "c:\\temp\\POO.dat";
        args[1] = "c:\\temp\\POO2.dat";
        fcTemp.Copy(args);
        System.out.println("\n" + "\n" + "\n");
*/

        System.out.println("----------------OBJETOS----------------");
        fcTemp.EscritaDeObjetos("c:\\temp\\POO-objects.dat");
        System.out.println("\n" + "\n" + "\n");

        System.out.println("---------OBJETOS COMPACTADOS-----------");
        fcTemp.EscritaDeObjetosCompacta("c:\\temp\\POO-objects.dat.zip");
        System.out.println("\n" + "\n" + "\n");
         
    }
}



