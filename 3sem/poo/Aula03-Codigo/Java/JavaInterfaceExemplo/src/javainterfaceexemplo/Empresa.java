/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfaceexemplo;

import java.util.ArrayList;

/**
 *
 * @author Junio
 */
public class Empresa extends ArrayList{
    int iCusto;
    Empresa(){
        iCusto = 0;
    }
    public void ComputaCusto(){
        Pagavel pUmItem;
        for(int i=0;i<this.size();i++){
            pUmItem = (Pagavel)this.get(i);
            iCusto += pUmItem.getValorDoPagamento();
        }        
    }
}
