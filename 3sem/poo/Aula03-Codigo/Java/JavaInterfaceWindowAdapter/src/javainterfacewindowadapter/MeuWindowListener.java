/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfacewindowadapter;

import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JFrame;

/**
 *
 * @author Junio
 */
public class MeuWindowListener implements WindowListener{

    public void windowOpened(WindowEvent e) {
        JFrame fTemp = (JFrame)e.getSource();
        fTemp.setTitle("Fui aberta");
    }

    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }

    public void windowClosed(WindowEvent e) {

    }

    public void windowIconified(WindowEvent e) {

    }

    public void windowDeiconified(WindowEvent e) {

    }

    public void windowActivated(WindowEvent e) {
        JFrame fTemp = (JFrame)e.getSource();
        fTemp.setTitle("Estou ativa");
    }

    public void windowDeactivated(WindowEvent e) {
        JFrame fTemp = (JFrame)e.getSource();
        fTemp.setTitle("Fui desativada");
    }

}
