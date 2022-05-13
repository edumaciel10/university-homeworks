/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfacecomparable;

/**
 *
 * @author Junio
 */
public class Fruta implements Comparable{
    private String sCor;
    Fruta(String sACor){
        sCor = sACor;
    }
    public String getCor(){
        return sCor;
    }

    public int compareTo(Object o) {
        Fruta f = (Fruta)o;
        /*Maior cor é verde, menor cor é vermelha*/
        if(this.sCor.compareTo(f.sCor) == 0)
            return 0;
        else if(this.sCor == "Verde")
            return +1;
        else if(this.sCor == "Vermelha")
            return -1;
        else{ //this.sCor é Azul
            if(f.sCor == "Verde")
                return -1; //Azul é menor que verde
            else
                return +1; //Azul é maior que vermelho
        }        
    }
}
