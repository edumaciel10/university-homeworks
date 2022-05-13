/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo1;

/**
 *
 * @author Junio
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int i = 0;
        Cachorro meuCachorro = new Cachorro("Boxer", "Bege", 1);
        Cachorro seuCachorro = new Cachorro("Labrador", "Malhado", 2);
        
        meuCachorro.EmiteSom();
        seuCachorro.EmiteSom();
    }

}
