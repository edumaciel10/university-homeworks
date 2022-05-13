/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4herancapolimorfismo;

/**
 *
 * @author Junio
 */
public abstract class Forma {
    String sNome;
    float fParam;

    public Forma(String umNome, float umParam) {
        sNome = umNome;
        fParam = umParam;
    };
    public String dizSeuNome(){
        return "Eu sou uma classe geral";
    }
    public abstract float CalculaArea();
}
