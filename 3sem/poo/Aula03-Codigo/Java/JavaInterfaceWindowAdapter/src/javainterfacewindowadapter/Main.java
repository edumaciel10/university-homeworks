package javainterfacewindowadapter;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JFrame;

public class Main {
    public static void main(String[] args) {
        MeuWindowListener wlTemp = new MeuWindowListener();

        JFrame myFrame = new JFrame("Teste do WindowAdapter");
        myFrame.setSize(500,500);
        myFrame.setVisible(true);
        myFrame.addWindowListener(wlTemp);

        JFrame myFrame2 = new JFrame("Teste do WindowAdapter 2");
        myFrame2.setSize(500,500);
        myFrame2.setLocation(501, 501);
        myFrame2.setVisible(true);
        myFrame2.addWindowListener(wlTemp);

        WindowListener quickListener = new WindowAdapter(){
            public void	windowDeactivated(WindowEvent e) {
                ((JFrame)e.getSource()).setTitle("Quick-Fui desativada");
            };
            public void	windowActivated(WindowEvent e){
                ((JFrame)e.getSource()).setTitle("Quick-Fui ativada");
            };
            public void windowClosing(WindowEvent e) {
                ((JFrame)e.getSource()).setVisible(false);
            };
        };
        
        JFrame myQuickFrame = new JFrame("Quick Teste do WindowAdapter");
        myQuickFrame.addWindowListener(quickListener);
        myQuickFrame.setLocation(1001, 0);
        myQuickFrame.setSize(500,500);
        myQuickFrame.setVisible(true);
    }
}
