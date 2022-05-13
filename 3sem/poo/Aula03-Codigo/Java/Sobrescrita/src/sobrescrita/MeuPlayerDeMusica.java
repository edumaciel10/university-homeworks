/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sobrescrita;

import javax.media.*;
import java.io.File;
import java.util.Scanner;

/**
 *
 * @author Junio
 */
public class MeuPlayerDeMusica extends MeuPlayer {
    public void Toca(String sFileName) {
        try {
            // Cria gerenciador de arquivo para o arquivo de mídia
            File f = new File(new File(".").getCanonicalPath() + File.separator + sFileName);
            
            // Cria o player propriamente dito
            Player p = Manager.createRealizedPlayer(f.toURI().toURL());
            // Toca a música
            p.start();
            
            // Mecanismo para interromper o player
            Scanner s = new Scanner(System.in);
            String st = s.nextLine();
            if (st.equals("s")) {
               p.stop();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
