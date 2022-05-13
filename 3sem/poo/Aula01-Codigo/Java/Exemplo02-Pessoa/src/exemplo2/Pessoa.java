/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo2;

/**
 *
 * @author Junio
 */
public class Pessoa {
    String nome;
    String DataNasc;
    String cor;
    boolean bDormindo;

    public Pessoa(String nome, String DataNasc, String cor) {
        nome = nome;
        DataNasc = DataNasc;
        cor = cor;
        bDormindo = false;
    }

    public void Acordar(){
        if(!bDormindo){
            System.out.println("Ja estou acordado");
        }else{
            bDormindo = false;
            System.out.println("Acordei, eba");
        }
    }
    public void Dormir(){
        if(bDormindo){
            System.out.println("Ja estou dormindo");
        } else {
            bDormindo = true;
            System.out.println("Dormi, zzz");
        }
    }
}
