import java.io.Serializable;

public class Endereco implements Serializable {
    String sRua;
    String sCidade;
    String sEstado;
    String sBairro;

    Endereco(String rua, String cidade, String estado, String bairro) {
        this.sRua = rua;
        this.sCidade = cidade;
        this.sEstado = estado;
        this.sBairro = bairro;
    }

    public String toString() {
        return "sRua= " + sRua + " sCidade= " + sCidade + " sEstado= " + sEstado + " sBairro= " + sBairro + '}';
    }
}
