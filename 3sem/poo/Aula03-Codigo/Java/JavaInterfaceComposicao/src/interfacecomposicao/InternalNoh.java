/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package interfacecomposicao;

import java.util.List;
import java.util.ArrayList;
/**
 *
 * @author Junio
 */
public class InternalNoh implements PrintableNoh{
    private List<PrintableNoh> listOfSons = new ArrayList<PrintableNoh>();
    int iValue;

    InternalNoh(int iAValue){
        iValue = iAValue;
    }
    public void print(){
        System.out.print(iValue + " " + "(" + " ");

        for (PrintableNoh aNoh : listOfSons) {
            aNoh.print();
        }

        System.out.print(")"+" ");
    }

    
    public void addSon(PrintableNoh aSon){
        listOfSons.add(aSon);
    }
    public void removeSon(PrintableNoh aSon){
        listOfSons.remove(aSon);
    }
}
