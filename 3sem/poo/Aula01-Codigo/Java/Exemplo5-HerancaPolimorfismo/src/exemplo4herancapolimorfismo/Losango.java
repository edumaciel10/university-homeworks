/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4herancapolimorfismo;

/**
 *
 * @author junio
 */
public class Losango extends Forma{
    float diagMa, diagMe;
    Losango(String umNome, float umParam){
        super(umNome, umParam);
    }    
    public float CalculaArea(){
        return diagMa*diagMe/2;
    }
}
