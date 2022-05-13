/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sobrescrita;

/**
 *
 * @author Junio
 */
public class Sobrescrita {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        MeuPlayer mpTocadorDeMusica = new MeuPlayerDeMusica();
        mpTocadorDeMusica.Toca("AprilKisses.wav");

        //MeuPlayer mpTocadorVideo = new MeuPlayerDeVideo();
        //mpTocadorVideo.Toca("MomAndBaby.mov");
        
        ///PlayerDeVinil p = new PlayerDeVinil();
        //p.Toca("disco.vni");

    }


}
