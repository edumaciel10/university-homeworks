package chainofresponsibility;

/**
 *
 * @author Junio
 */

public class ExcecaoSeria extends Excecao{
    protected final int MAX_CODE = 1000;

    public ExcecaoSeria(Excecao exASucessor) {
        super(exASucessor);
    }

    public void ProcessExcecao(JogadaDeExcecao aJogada) {
        if(aJogada.getCode() < MAX_CODE)
            System.out.println("Exceção tratada por ExcecaoSeria");
        else{
            exSucessor.ProcessExcecao(aJogada);
        }
    }
}