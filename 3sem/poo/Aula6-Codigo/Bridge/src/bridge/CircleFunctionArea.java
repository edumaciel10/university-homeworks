/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package bridge;

/**
 *
 * @author Junio
 */
public class CircleFunctionArea implements CircleFunction{

    public float PerformCalculus(Circle fACircle) {
        return (float) (Math.PI * Math.pow(fACircle.getRadius(), 2));
    }

}
