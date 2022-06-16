package bridge;

/**
 *
 * @author Junio
 */
public class Main {

    public static void main(String[] args) {
        /*Circle, CircleFunction*/
        Circle cMeuCirculo = new Circle(10);
        
        System.out.println(
        cMeuCirculo.CalculeAlgumaCoisaAMeuRespeito(new CircleFunctionArea())
            );
        System.out.println(
            cMeuCirculo.CalculeAlgumaCoisaAMeuRespeito(new CirclePerimeter())
        );
    }
}
