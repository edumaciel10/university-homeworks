/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dicionario;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        MeuDicionario umDicionario = new MeuDicionario();
        umDicionario.AdicionarPalavra("Carro");
        umDicionario.AdicionarPalavra("Gato");
        umDicionario.AdicionarPalavra("Livro");
        umDicionario.AdicionarPalavra("Constituição");
        umDicionario.MostraPalavras();
    }

}
