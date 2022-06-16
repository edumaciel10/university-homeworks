/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package bridge;

/**
 *
 * @author Junio
 */
public class Circle {
    private float fRadius;

    Circle(float fARadius){
        fRadius = fARadius;
    }

    public float getRadius() {
        return fRadius;
    }

    public float CalculeAlgumaCoisaAMeuRespeito(CircleFunction cfAFunctio){
        return cfAFunctio.PerformCalculus(this);
    }

}
