package observator;

import java.util.Scanner;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ObjetoObservavel oObservado = new ObjetoObservavel();
        ObjetoObservavel oObservado2 = new ObjetoObservavel();


        ObservadorSoma osSoma = new ObservadorSoma();
        ObservadorProduto osProduto = new ObservadorProduto();

        oObservado.addObserver(osSoma);
        oObservado.addObserver(osProduto);

        Scanner scan = new Scanner (System.in);
        while(true){
            System.out.println("Entre com um novo X:");
            oObservado.setX(scan.nextInt());
            System.out.println("Entre com um novo Y:");
            oObservado.setY(scan.nextInt());
            
            oObservado.notifyObservers(oObservado);
        }

    }

}
