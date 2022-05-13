/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4herancapolimorfismo;

/**
 *
 * @author Junio
 */
public class Circulo extends Forma{
    Circulo(String umNome, float umParam){
        super(umNome, umParam);
    }

    public float CalculaArea(){
        return (float) (Math.PI * fParam * fParam);
    }    

    public float calculaPerimetro() {
        return (float)(2*Math.PI*fParam);       
    }
    
    public String dizSeuNome(){
        return super.dizSeuNome() +" " +"Eu deixei de ser uma classe geral, e virei um circulo.";
    }
}
