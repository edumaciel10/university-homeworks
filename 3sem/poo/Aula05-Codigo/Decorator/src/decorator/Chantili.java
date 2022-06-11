package decorator;

import java.io.FilterInputStream;
import java.io.PushbackInputStream;

/**
 *
 * @author Junio
 */
public class Chantili extends CafeDecorator{
    public Chantili(Cafe cACafeASerDecorado) {
        super(cACafeASerDecorado);
    }

    public String getDescricao() {
        return cCafeASerDecorado.getDescricao() + " com chantili";
    }

    public float getPreco() {
        return cCafeASerDecorado.getPreco() + 0.3f;
    }
}
