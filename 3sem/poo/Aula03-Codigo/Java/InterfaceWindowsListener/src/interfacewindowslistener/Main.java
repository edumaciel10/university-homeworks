/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package interfacewindowslistener;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JFrame;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        WindowListener mlTemp = new MeuWindowListener();

        JFrame jfTemp = new JFrame();
        jfTemp.setVisible(true);
        jfTemp.setSize(500, 500);
        jfTemp.addWindowListener(mlTemp);

        JFrame jfTemp2 = new JFrame();
        jfTemp2.setVisible(true);
        jfTemp2.setSize(500, 500);
        jfTemp2.addWindowListener(mlTemp);

        JFrame jfTemp3 = new JFrame();
        jfTemp3.setVisible(true);
        jfTemp3.setSize(500, 500);
        WindowListener waTemp = new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            };
            public void windowActivated(WindowEvent e) {
                JFrame fTemp = (JFrame) e.getSource();
                fTemp.setTitle("Janela nova ativada");
            };
            public void windowDeactivated(WindowEvent e) {
                JFrame fTemp = (JFrame) e.getSource();
                fTemp.setTitle("Janela nova desativada");
            };
        };
        jfTemp3.addWindowListener(waTemp);
    }
}
