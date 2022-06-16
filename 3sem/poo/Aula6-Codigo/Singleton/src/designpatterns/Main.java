/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package designpatterns;

/**
 *
 * @author Junio
 */
public class Main {
    /*Este código é apenas ilustrativo, seu funcionamento adequado não é garantido*/
    public static void main(String args[]){
        /*Singleton*/
        //Singleton sTeste = new Singleton(); //-> código inválido
        Singleton.getInstance().setsNome("Deus");
        System.out.println(Singleton.getInstance().getsNome());
        Singleton.getInstance().setiId(10);
        System.out.println(Singleton.getInstance().getiId());
    }
}
