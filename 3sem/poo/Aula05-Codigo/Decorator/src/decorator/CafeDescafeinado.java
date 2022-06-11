/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package decorator;

/**
 *
 * @author Junio
 */
public class CafeDescafeinado extends Cafe{
    public String getDescricao(){
        return "Cafe descafeinado";
    }
    public float getPreco() {
        return 1.0f;
    }

}
