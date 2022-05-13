/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo2;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Pessoa umaPessoa = new Pessoa("Joao","10/10/2010","Branco");
        umaPessoa.Dormir();
        umaPessoa.Acordar();
        umaPessoa.Acordar();
        umaPessoa.Dormir();
    }

}
