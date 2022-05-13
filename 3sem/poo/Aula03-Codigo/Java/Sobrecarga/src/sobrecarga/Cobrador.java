/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sobrecarga;

/**
 *
 * @author Junio
 */
public class Cobrador {
    private float fTaxa;
    private float fJurosDeMora;
    Cobrador(float fATaxa, float fAJurosDeMora){
        fTaxa = fATaxa;
        fJurosDeMora = fAJurosDeMora;
    }

    public float ValorDevido(float fDivida){
        return fDivida*fTaxa;
    }

    public float ValorDevido(float fDivida, float fDesconto){
        return fDivida*fTaxa - fDesconto;
    }

    public float ValorDevido(float fDivida, int iDiasDeAtraso){
        return fDivida*(fTaxa + iDiasDeAtraso*fJurosDeMora);
    }

    public float ValorDevido(float fDivida, float fDesconto, int iDiasDeAtraso){
        return fDivida*(fTaxa + iDiasDeAtraso*fJurosDeMora) - fDesconto;
    }

}
