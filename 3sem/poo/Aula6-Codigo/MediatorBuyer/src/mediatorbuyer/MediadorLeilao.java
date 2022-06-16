/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class MediadorLeilao {

    /**
     * @param args the command line arguments
     */
	public static void main(String[] args) {

		Mediador mediator = new Mediador();

		Comprador swedishBuyer = new CompradorSueco(mediator);
		Comprador frenchBuyer = new CompradorFrances(mediator);
                
		float sellingPriceInDollars = 10.0f;
		VendedorAmericano americanSeller = new VendedorAmericano(mediator, sellingPriceInDollars);
		CalculadorDeDolares dollarConverter = new CalculadorDeDolares(mediator);

		float swedishLanceInKronor = 55.0f;
		while (!swedishBuyer.attemptToPurchase(swedishLanceInKronor)) {
			swedishLanceInKronor += 15.0f;
		}

		float frenchLanceInEuros = 3.0f;
		while (!frenchBuyer.attemptToPurchase(frenchLanceInEuros)) {
			frenchLanceInEuros += 1.5f;
		}

	}
}
