/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class Comprador {

	Mediador mediator;
	String unitOfCurrency;

	public Comprador(Mediador mediator, String unitOfCurrency) {
		this.mediator = mediator;
		this.unitOfCurrency = unitOfCurrency;
	}

	public boolean attemptToPurchase(float bid) {
		System.out.println("Comprador faz lance de " + bid + " " + unitOfCurrency);
		return mediator.enviaLance(bid, unitOfCurrency);
	}
}