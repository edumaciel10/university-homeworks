/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package facade;

import java.util.ArrayList;

/**
 *
 * @author Junio
 */
public class Banco {
    ArrayList<Cliente> alClientes;

    public boolean Paga(Produto p, Cliente c){
        if(alClientes.contains(c))
            return true;
        return false;
    }
}
