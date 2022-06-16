package chainofresponsibility;

/**
 *
 * @author Junio
 */

public class ExcecaoGrave extends Excecao{
    public ExcecaoGrave(Excecao exASucessor) {
        super(exASucessor);
    }

    public void ProcessExcecao(JogadaDeExcecao aJogada) {
       System.out.println("Exceção tratada por ExcecaoGrave");
    }
}
