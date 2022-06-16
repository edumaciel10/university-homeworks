package bridge;

/**
 *
 * @author Junio
 */
public class CirclePerimeter implements CircleFunction{

    public float PerformCalculus(Circle fACircle) {
        return (float) (2* Math.PI * fACircle.getRadius());
    }

}
