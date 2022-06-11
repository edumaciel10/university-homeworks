/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package decorator;

/**
 *
 * @author Junio
 */
public class Main {

    public static void main(String[] args) {
        /*Cafe: Cafe puro, CafeDescafeinado, CafeDecorator*/
        /*CafeDecorator: Chantili, Canela */
        Cafe cCafePuro = new CafePuro();
        System.out.println(cCafePuro.getDescricao());
        System.out.println("Preço: "+ cCafePuro.getPreco());      
    
        Canela cCafeComCanela = new Canela(cCafePuro);
        System.out.println(cCafeComCanela.getDescricao());
        System.out.println("Preço: "+ cCafeComCanela.getPreco()); 
        
        Chantili cCafeComChantili = new Chantili(cCafeComCanela);
        System.out.println(cCafeComChantili.getDescricao());
        System.out.println("Preço: "+ cCafeComChantili.getPreco());        

       
        
        Cafe cCafeDescafeinado = new CafeDescafeinado();
        System.out.println(cCafeDescafeinado.getDescricao());
        System.out.println("Preço: "+ cCafeDescafeinado.getPreco());

        Chantili cCafeDecafComChantili = new Chantili(cCafeDescafeinado);
        System.out.println(cCafeDecafComChantili.getDescricao());
        System.out.println("Preço: "+ cCafeDecafComChantili.getPreco());        
       /* Canela cComCanela = new Canela(cCafePuro);
                System.out.println(cComCanela.getDescricao());
        System.out.println("Preço: "+ cComCanela.getPreco());
              
        

 


          




        Canela cCafeDecafComCanela = new Canela(cCafeDecafComChantili);
        System.out.println(cCafeDecafComCanela.getDescricao());
        System.out.println("Preço: "+ cCafeDecafComCanela.getPreco());
        System.out.println();
        System.out.println();
        
        Canela cCafeDecafComCanela2 = new Canela(cCafeDescafeinado);
System.out.println(cCafeDecafComCanela2.getDescricao());
        System.out.println("Preço: "+ cCafeDecafComCanela2.getPreco());        
        */
    }

}
