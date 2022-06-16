package chainofresponsibility;

/**
 *
 * @author Junio
 */
public abstract class Excecao {
    protected Excecao exSucessor;

    public Excecao(Excecao exASucessor){
        exSucessor = exASucessor;
    }

    public abstract void ProcessExcecao(JogadaDeExcecao aJogada);
}
