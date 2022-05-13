/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfaceexemplo;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Empregado eUmEmpregado =  new Empregado();
        Conta cUmaConta = new Conta();
        Empresa eMinhaEmpresa = new Empresa();
        eMinhaEmpresa.add(cUmaConta);
        eMinhaEmpresa.add(eUmEmpregado);
        eMinhaEmpresa.ComputaCusto();        
    }

}
