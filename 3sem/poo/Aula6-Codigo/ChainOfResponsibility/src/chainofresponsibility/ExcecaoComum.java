package chainofresponsibility;

/**
 *
 * @author Junio
 */
public class ExcecaoComum extends Excecao{
    protected final int MAX_CODE = 500;

    public ExcecaoComum(Excecao exASucessor) {
        super(exASucessor);
    }
    
    public void ProcessExcecao(JogadaDeExcecao aJogada) {
        if(aJogada.getCode() < MAX_CODE)
            System.out.println("Exceção tratada por ExcecaoComum");
        else{
            exSucessor.ProcessExcecao(aJogada);
        }
    }
}
