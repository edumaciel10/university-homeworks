package decoratornewfilteredstream;

import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 *
 * @author Junio
 */

/*Esta classe equivale à classe CafeDecorator do exemplo do Cafe*/
public class MAIUSCULASInputStream extends FilterInputStream {

    public MAIUSCULASInputStream(InputStream objetoASerDecorado) {
        super(objetoASerDecorado); /*Inicializa a proprieda in de FilterInputStream*/
    }

    public int read() throws IOException {
        int c = in.read();  /*a propriedade in é o objeito a ser decorado recebido no construtor*/
        return Character.toUpperCase((char) c);
    }
}