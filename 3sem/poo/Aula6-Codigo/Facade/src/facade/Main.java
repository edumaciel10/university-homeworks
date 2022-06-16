/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package facade;

/**
 *
 * @author Junio
 */
public class Main {
    /*Este código é apenas ilustrativo, seu funcionamento adequado não é garantido*/
    public static void main(String[] args) {
        /**********************************************************************/        
        /*Sem Facade*/
        Loja loja = new Loja("Casas Bahia");
        Cliente cliente = new Cliente("Jose", null) ;
        Banco banco = new Banco();
        Produto produto = null;

        if(loja.hasProduct(10))
            produto = loja.vendeProdutoParaCliente(10, cliente);
        if(banco.Paga(produto, cliente))
            System.out.println("Vendido");

        /**********************************************************************/
        /*Com Facade*/
        TransacaoFacade transacaoFacade = new TransacaoFacade("Joao", loja);
        if(transacaoFacade.CompraDeProduto(10))
            System.out.println("Vendido");
    }

}
