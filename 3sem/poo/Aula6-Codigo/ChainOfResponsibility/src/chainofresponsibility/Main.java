package chainofresponsibility;

/**
 *
 * @author Junio
 */
public class Main {

    public static void main(String[] args) {        
        Excecao exTratamento = new ExcecaoComum(new ExcecaoSeria(new ExcecaoGrave(null)));

        /*Trata-se apenas de uma simulação de um sistema de exceções - o sistema
          de exceções de fato, é atrelado ao projeto da linguagem e do runtime,
          apresentando muito mais complexidade*/
        
        exTratamento.ProcessExcecao(new JogadaDeExcecao(10));
        exTratamento.ProcessExcecao(new JogadaDeExcecao(510));
        exTratamento.ProcessExcecao(new JogadaDeExcecao(1510));
    }
}
