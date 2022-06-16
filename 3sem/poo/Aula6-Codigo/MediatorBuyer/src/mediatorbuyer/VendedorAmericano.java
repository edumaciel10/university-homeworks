/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class VendedorAmericano {

	Mediador mediator;
	float precoEmDolares;

	public VendedorAmericano(Mediador mediator, float priceInDollars) {
		this.mediator = mediator;
		this.precoEmDolares = priceInDollars;
		this.mediator.registraVendedorAmericano(this);
	}

	public boolean isLanceAceito(float bidInDollars) {
		if (bidInDollars >= precoEmDolares) {
			System.out.println("Vendedor aceita lance de " + bidInDollars + " dolares\n");
			return true;
		} else {
			System.out.println("Vendedor rejeita lance de " + bidInDollars + " dolares\n");
			return false;
		}
	}

}