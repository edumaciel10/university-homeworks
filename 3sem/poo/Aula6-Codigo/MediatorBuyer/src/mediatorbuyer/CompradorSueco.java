/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class CompradorSueco extends Comprador {

	public CompradorSueco(Mediador mediator) {
		super(mediator, "krona");
		this.mediator.registraCompradorSueco(this);
	}
}
