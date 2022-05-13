/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4heranca;

/**
 *
 * @author Junio
 */
public class Aquaticos extends Animal{
    int iMinsDeFolego;

    public Aquaticos(String saNome, int umMinsDeFolego) {
        super(saNome);
        iMinsDeFolego = umMinsDeFolego;
    }

    public int getMinsDeFolego() {
        return iMinsDeFolego;
    }

}
