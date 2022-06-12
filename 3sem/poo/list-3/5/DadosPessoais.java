import java.io.Serializable;

/**
 *
 * @author Junio
 */

public class DadosPessoais implements Serializable{
    String sNome;
    int iIdade;
    String sSexo;
    Endereco eEndereco;

    DadosPessoais(String nome, int idade, String sexo, Endereco endereco) {
        this.sNome = nome;
        this.iIdade = idade;
        this.sSexo = sexo;
        this.eEndereco = endereco;
    }

    public String toString() {
        // return DadosPessoais data, breaking by line

        return "DadosPessoais{\n" + "sNome=" + sNome + "\niIdade=" + iIdade + "\nsSexo=" + sSexo + "\neEndereco=" + eEndereco.toString() + '}';
    }
}
