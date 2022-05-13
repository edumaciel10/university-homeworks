/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dicionario;

import java.util.ArrayList;

/**
 *
 * @author Junio
 */
public class MeuDicionario {
    private ArrayList listaDePalavras;

    MeuDicionario(){
        listaDePalavras = new ArrayList();
    }

    private boolean ValidarPalavra(String umaPalavra){
        if(umaPalavra.length() > 10)
            return false;
        return true;
    }
    public void AdicionarPalavra(String umaPalavra){
        if(ValidarPalavra(umaPalavra))
            listaDePalavras.add(umaPalavra);
        else
            System.out.println("Palavra " + umaPalavra + " inválida, pois tem mais do que 10 caracteres");
    }
    public void MostraPalavras(){
        for (int i = 0; i < listaDePalavras.size(); i++){
            String palavra = (String)listaDePalavras.get(i);
            System.out.println("Item " + i + " : " + palavra);
        }
    }
}
