/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class CompradorFrances extends Comprador {

	public CompradorFrances(Mediador mediator) {
		super(mediator, "euro");
		this.mediator.regitraCompradorFrances(this);
	}
}