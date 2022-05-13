/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfaceexemplo;

/**
 *
 * @author Junio
 */
public class Conta implements Pagavel{
    int iCodigo;
    String sDescricao;
    int iCusto;

    Conta(){
        iCusto = 0;
    }
    public void AcrescentaCusto(int aUmValor){
        iCusto += aUmValor;
    }
    public void AvisaDeVencimento(){
        System.out.println("Estou vencendo, me pague.");
    }

    public int getValorDoPagamento() {
        return iCusto;
    }
}
