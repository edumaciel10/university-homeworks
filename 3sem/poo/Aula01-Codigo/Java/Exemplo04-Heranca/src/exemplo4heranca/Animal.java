/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4heranca;

/**
 *
 * @author Junio
 */
public class Animal extends Object{
    String sNome;
    Animal(String umNome){
        sNome = umNome + "!";
    }

    public String getsNome() {
        return sNome;
    }
}
