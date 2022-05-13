/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo4heranca;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Animal meuAnimal = new Animal("Michelangelo");
        Terrestres umTerrestre = new Terrestres("Donatelo",4);
        
        
        
        
        
        
        
        
        Cachorro umCao = new Cachorro("Dog",4);
        System.out.println(umCao.getsNome() + " - " + umCao.getiNrPatas());

        Lambari umPeixe = new Lambari("Nemo",10);
        System.out.println(umPeixe.getsNome() + " - " + umPeixe.getMinsDeFolego());
       
    }

}
