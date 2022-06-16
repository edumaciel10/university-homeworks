/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factorymethod;

/**
 *
 * @author Junio
 */
import java.util.ArrayList;

public class Sexta extends DiaDaSemana {

    static String sNome = "Sexta";
    ArrayList<String> lListaDeOpcoesDeLazer;

    public Sexta() {
        super();
        lListaDeOpcoesDeLazer = new ArrayList<String>();
    }

    public String getsNome() {
        return sNome;
    }

    public String getDescricao() {
        return getsSpecialString();
    }

    /*Factory method - o que eu coloco aqui é executado evocando-se a classe mãe
     e tendo-se resultados diferentes para cada classe filha*/
    public Descricao MakeDescricao() {
        /*O uso aqui é diferente do uso em segunda, usa-se o construtor
         SpecialStringSexta e define-se como feriado true*/
        Descricao ssTemp = new SpecialStringSexta(this);
        ssTemp.setbFeriado(true);
        return ssTemp;
    }
}