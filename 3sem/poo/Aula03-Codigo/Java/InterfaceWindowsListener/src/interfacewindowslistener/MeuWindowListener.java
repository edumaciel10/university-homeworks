/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package interfacewindowslistener;

import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JFrame;

/**
 *
 * @author Junio
 */
public class MeuWindowListener implements WindowListener{

    public void windowOpened(WindowEvent e) {

    }

    public void windowClosed(WindowEvent e) {

     }

    public void windowIconified(WindowEvent e) {
    }

    public void windowDeiconified(WindowEvent e) {
    }
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
    public void windowActivated(WindowEvent e) {
        JFrame fTemp = (JFrame)e.getSource();
        fTemp.setTitle("Janela ativada");
    }

    public void windowDeactivated(WindowEvent e) {
        JFrame fTemp = (JFrame)e.getSource();
        fTemp.setTitle("Janela desativada");
    }

}
