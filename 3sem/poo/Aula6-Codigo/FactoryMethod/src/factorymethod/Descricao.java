package factorymethod;

/**
 *
 * @author Junio
 */
public abstract class Descricao {
    protected String sSpecialStringContent;
    boolean bFeriado;
    
    public String getDescricao() {
        return sSpecialStringContent;
    }

    public void setbFeriado(boolean bFeriado) {
        this.bFeriado = bFeriado;
    }
}
