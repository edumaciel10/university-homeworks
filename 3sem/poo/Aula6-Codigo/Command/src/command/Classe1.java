package command;

import javax.swing.JOptionPane;

/**
 *
 * @author Junio
 */
public class Classe1 extends Comando{

    public void Comportamento() {
        System.out.println("Show dialog");
        JOptionPane.showMessageDialog(null, "CLASSE1 - Mas não sei o que faço durante, so sei que farei alguma coisa.");
    }

}
