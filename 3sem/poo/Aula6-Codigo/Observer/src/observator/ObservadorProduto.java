package observator;

import java.util.Observable;
import java.util.Observer;

/**
 *
 * @author junio
 */
public class ObservadorProduto implements Observer{
    private int iProduto;

    public void update(Observable o, Object arg) {
        ObjetoObservavel ooTemp = (ObjetoObservavel)o;
        iProduto = ooTemp.getX() * ooTemp.getY();
        System.out.println("------------------------------------------");
        System.out.println("Observador produto, novo valor: " + iProduto);
        System.out.println("------------------------------------------");
    }
}
