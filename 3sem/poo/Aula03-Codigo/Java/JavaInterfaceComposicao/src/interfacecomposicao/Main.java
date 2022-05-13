/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package interfacecomposicao;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        NohLeaf noh1 = new NohLeaf(10);
        NohLeaf noh2 = new NohLeaf(20);
        NohLeaf noh3 = new NohLeaf(30);
        NohLeaf noh4 = new NohLeaf(40);
        NohLeaf noh5 = new NohLeaf(50);
        NohLeaf noh6 = new NohLeaf(60);
        NohLeaf noh7 = new NohLeaf(70);

        InternalNoh iNoh1 = new InternalNoh(600);
        iNoh1.addSon(noh1);
        iNoh1.addSon(noh2);
        iNoh1.addSon(noh3);

        InternalNoh iNoh2 = new InternalNoh(700);
        iNoh2.addSon(noh4);
        iNoh2.addSon(noh5);

        InternalNoh iNoh3 = new InternalNoh(800);
        iNoh3.addSon(noh6);
        iNoh3.addSon(noh7);

        InternalNoh iNohRoot = new InternalNoh(1000);
        iNohRoot.addSon(iNoh1);
        iNohRoot.addSon(iNoh2);
        iNohRoot.addSon(iNoh3);

        iNohRoot.print();
    }
}
