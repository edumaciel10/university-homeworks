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
public class ProxyAcessoARede {
    AcessoARede acesso;
    ProxyAcessoARede(){
        acesso = new AcessoARede();
    }
    /*Note que a classe ProxyAcessoARede tem os mesmos métodos que a classe AcessoARede;
      o que ela faz é filtrar os dados que chegam à classe AcessoARede para evitar
      problemas de segurança.*/
    void enviaDados(String s){
        if(s.contains("543"))
            throw new Error("ERRO: tentativa de execucao de codigo malicioso");
        else
            acesso.enviaDados(s);
    }
    void enviaArray(int[] i){
        if(i.length > 10)
            throw new Error("ERRO: tentativa de execucao de codigo malicioso");
        else
            acesso.enviaArray(i);
    }
}

