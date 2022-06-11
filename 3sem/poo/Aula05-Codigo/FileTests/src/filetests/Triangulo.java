/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package filetests;

import java.io.Serializable;

/**
 *
 * @author Junio
 */
public class Triangulo implements Serializable {
    float fLado1;
    float fLado2;
    float fLado3;
    String sNome;
    PropriedadesExtras ps;
    Triangulo(float fALado1, float fALado2, float fALado3, String sAnome){
        fLado1 = fALado1;
        fLado2 = fALado2;
        fLado3 = fALado3;
        sNome = sAnome;
    }

    public String toString() {
        return "Triangulo{" + "fLado1=" + fLado1 + "fLado2=" + fLado2 + "fLado3=" + fLado3 + "sNome=" + sNome + '}';
    }
}
