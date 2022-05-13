/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package exemplo1;

/**
 *
 * @author Junio
 */
public class Cachorro {
    public String raca;
    String cor;
    int som;
    boolean bComFolego;
    Cachorro(String umaRaca, String umaCor, int umSom){
        raca = umaRaca;
        cor = umaCor;
        som = umSom;
        bComFolego = false;
    }
    
    public void EmiteSom(){
        if(!bComFolego)
            RespirarAntes();
        
        if(som == 1)
            System.out.println("Au");
        else if(som == 2)
            System.out.println("Au Au"); 
        
        bComFolego = false;
    }
    private void RespirarAntes(){
        bComFolego = true;
    }
}
