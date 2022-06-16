package observator;

import java.util.Observable;
import java.util.Observer;

/**
 *
 * @author junio
 */
public class ObservadorSoma implements Observer{
    private int iSoma;
    public void update(Observable o, Object arg) {
        ObjetoObservavel ooTemp = (ObjetoObservavel)o;
        iSoma = ooTemp.getX() + ooTemp.getY();
        System.out.println("------------------------------------------");
        System.out.println("Observador soma, novo valor: " + iSoma);
        System.out.println("------------------------------------------");
    }
}
