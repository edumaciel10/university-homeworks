/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4heranca;

/**
 *
 * @author Junio
 */
public class Terrestres extends Animal{
    int iNrPatas;
    Terrestres(String saNome, int umNroPatas){
        super(saNome);
        iNrPatas = umNroPatas;
    }

    public int getiNrPatas() {
        return iNrPatas;
    }   
}
