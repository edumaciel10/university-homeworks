/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package interfacecomposicao;

/**
 *
 * @author Junio
 */
public class NohLeaf implements PrintableNoh{
    int iValue;
    
    public NohLeaf(int iAValue){
        iValue = iAValue;
    }
    
    public void print(){
       System.out.print(iValue + " ");
    }
}
