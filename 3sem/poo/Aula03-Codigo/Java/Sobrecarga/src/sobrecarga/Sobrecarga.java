/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sobrecarga;

/**
 *
 * @author Junio
 */
public class Sobrecarga {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Cobrador cUmCobrador = new Cobrador(1.05f, 0.01f);
        System.out.println("Divida: " + cUmCobrador.ValorDevido(100));
        System.out.println("Divida com desconto: " + cUmCobrador.ValorDevido(100, 30f));
        System.out.println("Divida com atraso: " + cUmCobrador.ValorDevido(100, 2));
        System.out.println("Divida com atraso e desconto: " + cUmCobrador.ValorDevido(100, 30, 2));
    }

}
