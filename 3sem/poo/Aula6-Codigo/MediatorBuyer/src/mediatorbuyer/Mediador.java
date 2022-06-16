/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mediatorbuyer;

/**
 *
 * @author http://www.avajava.com/tutorials/lessons/mediator-pattern.html
 */
public class Mediador {

	Comprador swedishBuyer;
	Comprador frenchBuyer;
	VendedorAmericano americanSeller;
	CalculadorDeDolares dollarConverter;

	public Mediador() {
	}

	public void registraCompradorSueco(CompradorSueco swedishBuyer) {
		this.swedishBuyer = swedishBuyer;
	}

	public void regitraCompradorFrances(CompradorFrances frenchBuyer) {
		this.frenchBuyer = frenchBuyer;
	}

	public void registraVendedorAmericano(VendedorAmericano americanSeller) {
		this.americanSeller = americanSeller;
	}

	public void registraCalculadorDeDolares(CalculadorDeDolares dollarConverter) {
		this.dollarConverter = dollarConverter;
	}

	public boolean enviaLance(float bid, String unitOfCurrency) {
		float dollarAmount = dollarConverter.converteMoedaParaDolares(bid, unitOfCurrency);
		return americanSeller.isLanceAceito(dollarAmount);
	}
}
