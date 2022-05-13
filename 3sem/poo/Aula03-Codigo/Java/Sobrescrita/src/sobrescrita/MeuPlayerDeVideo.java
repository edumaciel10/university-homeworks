/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sobrescrita;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import javax.media.*;
import java.io.File;
import java.util.Scanner;
import javax.swing.JFrame;
import javax.swing.JPanel;
/**
 *
 * @author Junio
 */
public class MeuPlayerDeVideo extends MeuPlayer{
    public void Toca(String sFileName){
        try {
            // Cria gerenciador de arquivo para o arquivo de mídia
            File f = new File(new File(".").getCanonicalPath() + File.separator + sFileName);

            //Cria tela de exibição
            JFrame jfTela =  new JFrame();
            JPanel jpMeuPainelDeVideo = new JPanel();
            jpMeuPainelDeVideo.setLayout( new BorderLayout() );
            jfTela.add(jpMeuPainelDeVideo);

            // Cria o player propriamente dito
            Manager.setHint( Manager.LIGHTWEIGHT_RENDERER, true );
            Player p = Manager.createRealizedPlayer(f.toURI().toURL());

            //Põe o player na tela
            Component video = p.getVisualComponent();
            Component controls = p.getControlPanelComponent();
            jpMeuPainelDeVideo.add(video, BorderLayout.CENTER);
            jpMeuPainelDeVideo.add(controls, BorderLayout.SOUTH);
            jfTela.setSize(new Dimension(400,400));

            //Exibe a tela
            jfTela.setVisible(true);
            jpMeuPainelDeVideo.setVisible(true);

            // Toca a vídeo
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
