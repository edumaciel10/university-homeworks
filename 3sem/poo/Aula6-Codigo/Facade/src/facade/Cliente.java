/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package facade;

/**
 *
 * @author Junio
 */
public class Cliente {
    String sNome;
    Banco b;

    public Cliente(String sNome, Banco b) {
        this.sNome = sNome;
        this.b = b;
    }

    public String getsNome() {
        return sNome;
    }

    public void setsNome(String sNome) {
        this.sNome = sNome;
    }

    public Banco getBancoDoCliente() {
        return b;
    }
}
