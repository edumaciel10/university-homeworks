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
public class Sexta extends DiaDaSemana{
   static String sNome = "Sexta";
   ArrayList<String> lListaDeOpcoesDeLazer;
   
   public Sexta(ArrayList<String> lAListaDeOpcoesDeLazer){
       lListaDeOpcoesDeLazer = lAListaDeOpcoesDeLazer;
   }
   public String getsNome() {
        return sNome + " :) ";
    }
}
