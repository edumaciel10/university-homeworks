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
public class CirculoColorido extends Circulo{

    public CirculoColorido(String umNome, float umParam) {
        super(umNome, umParam);
    }

    public String dizSeuNome(){
        return super.dizSeuNome() +" " +"Agora sou colorido.";
    }    
  
}
