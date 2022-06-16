/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class CalculadorDeDolares {

	Mediador mediator;

	public static final float DOLLAR_UNIT = 1.0f;
	public static final float EURO_UNIT = 0.7f;
	public static final float KRONA_UNIT = 8.0f;

	public CalculadorDeDolares(Mediador mediator) {
		this.mediator = mediator;
		mediator.registraCalculadorDeDolares(this);
	}

	private float converteEurosParaDolares(float euros) {
		float dollars = euros * (DOLLAR_UNIT / EURO_UNIT);
		System.out.println("Convertendo " + euros + " euros para " + dollars + " dolares");
		return dollars;
	}

	private float converteKronorsParaDolares(float kronor) {
		float dollars = kronor * (DOLLAR_UNIT / KRONA_UNIT);
		System.out.println("Convertendo " + kronor + " kronor para " + dollars + " dolares");
		return dollars;
	}

	public float converteMoedaParaDolares(float quantia, String sMoeda) {
		if ("krona".equalsIgnoreCase(sMoeda)) {
			return converteKronorsParaDolares(quantia);
		} else {
			return converteEurosParaDolares(quantia);
		}
	}
}
