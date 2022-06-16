/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package proxyseguranca;

/**
 *
 * @author junio
 */
public class ProxySeguranca {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*Sem proxy*/
        AcessoARede acesso = new AcessoARede();
        acesso.enviaDados("12345439012");
        int[] i = {0,1,2,4,5,6,7,8,9,10,11};
        acesso.enviaArray(i);

        /*Com proxy*/        
        ProxyAcessoARede proxyAcesso = new ProxyAcessoARede();
        proxyAcesso.enviaDados("12345439012");
        int[] j = {0,1,2,4,5,6,7,8,9,10,11};
        proxyAcesso.enviaArray(j);
    }
    
}
