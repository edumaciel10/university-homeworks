package command;

import javax.swing.JOptionPane;

/**
 *
 * @author Junio
 */
public class Classe3 extends Comando{

    public void Comportamento() {
        System.out.println("Joga excecao");
        throw new UnsupportedOperationException("CLASSE3 - Mas não sei o que faço durante, so sei que farei alguma coisa.");
    }

}
