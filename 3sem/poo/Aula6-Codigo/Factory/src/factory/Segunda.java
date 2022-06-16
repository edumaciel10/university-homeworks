/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package factory;

import java.util.ArrayList;

/**
 *
 * @author Junio
 */
public class Segunda extends DiaDaSemana{
   static String sNome = "Segunda";
   ArrayList<Float> lListaDeContasAPagar;

   public Segunda(ArrayList<Float> lAListaDeContasAPagar){
       lListaDeContasAPagar = lAListaDeContasAPagar;
   }
   public String getsNome() {
        return sNome + " :( ";
    }
}
