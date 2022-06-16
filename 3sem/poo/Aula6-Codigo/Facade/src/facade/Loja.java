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
public class Loja {
    String sNome;
    ArrayList<Produto> lListaDeProdutos;
    ArrayList<Cliente> lListaDeCliente;

    public Loja(String sANome) {
        sNome = sANome;
    }

    public Cliente getClienteByName(String sANome){
        return lListaDeCliente.get(lListaDeCliente.indexOf(sANome));
    }

    public Produto getProdutoByIndex(int iAIndex){
        return lListaDeProdutos.get(lListaDeProdutos.indexOf(iAIndex));
    }
    public Produto vendeProdutoParaCliente(int iAIndex, Cliente aCliente){
        if(aCliente != null)
            return lListaDeProdutos.get(iAIndex);
        return null;
    }   
    public boolean hasProduct(int iAIndex){
        if(lListaDeProdutos.get(lListaDeProdutos.indexOf(iAIndex)) == null)
            return false;
        return true;
    }
}
