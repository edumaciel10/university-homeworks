/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfaceexemplo;

/**
 *
 * @author Junio
 */
public class Empregado implements Pagavel{
    String sNome;
    int iIdade;
    
    public void Trabalha(){
        System.out.println("Estou trabalhando");
    }

    public void Come(){
        System.out.println("Estou comendo");
    }

    public int getCustoHora(){
        return 10;
    }

    public int getValorDoPagamento() {
        return 5*getCustoHora();
    }
}
