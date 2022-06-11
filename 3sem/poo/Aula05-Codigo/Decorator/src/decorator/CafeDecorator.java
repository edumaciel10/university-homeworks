/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package decorator;

/**
 *
 * @author Junio
 */
public abstract class CafeDecorator extends Cafe{
    Cafe cCafeASerDecorado;

    protected CafeDecorator(Cafe cACafeASerDecorado){
        cCafeASerDecorado = cACafeASerDecorado;
    }
}