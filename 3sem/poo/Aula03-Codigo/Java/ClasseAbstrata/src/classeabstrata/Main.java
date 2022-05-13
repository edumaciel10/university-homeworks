/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package classeabstrata;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ClasseMae arrayDeObjetos[] = new ClasseMae[3];
        arrayDeObjetos[0] = new ClasseFilhaUm();
        arrayDeObjetos[1] = new ClasseFilhaDois();
        arrayDeObjetos[2] = new ClasseFilhaTres();

        for (int i = 0; i < arrayDeObjetos.length; i++) {
            arrayDeObjetos[i].DizSeuNome();
        }
    }
}
