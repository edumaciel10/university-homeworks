/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4herancapolimorfismo;

/**
 *
 * @author Junio
 */
public class Quadrado extends Forma {

    Quadrado(String umNome, float umParam){
        super(umNome, umParam);
    }

    public float CalculaArea(){
        return (float) (fParam * fParam);
    }
}
