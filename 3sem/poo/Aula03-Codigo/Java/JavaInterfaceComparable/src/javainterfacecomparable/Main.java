/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterfacecomparable;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList arListaDeFrutas = new ArrayList<Fruta>();
        arListaDeFrutas.add(new Fruta("Verde"));
        arListaDeFrutas.add(new Fruta("Azul"));
        arListaDeFrutas.add(new Fruta("Vermelha"));
        arListaDeFrutas.add(new Fruta("Verde"));
        arListaDeFrutas.add(new Fruta("Azul"));
        arListaDeFrutas.add(new Fruta("Vermelha"));
        arListaDeFrutas.add(new Fruta("Verde"));
        arListaDeFrutas.add(new Fruta("Vermelha"));
        arListaDeFrutas.add(new Fruta("Vermelha"));
        arListaDeFrutas.add(new Fruta("Azul"));
        Fruta fTemp;
        for(int i=0; i < arListaDeFrutas.size(); i++){
            fTemp = (Fruta)arListaDeFrutas.get(i);
            System.out.println(fTemp.getCor());
        }

        System.out.println();
        Collections.sort(arListaDeFrutas); //Em ordem ascendent
        
        for(int i=0; i < arListaDeFrutas.size(); i++){
            fTemp = (Fruta)arListaDeFrutas.get(i);
            System.out.println(fTemp.getCor());
        }
        
    }

}
