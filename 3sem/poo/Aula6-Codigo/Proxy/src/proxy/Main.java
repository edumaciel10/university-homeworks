package proxy;

/**
 *
 * @author Junio
 */
public class Main {

    public static void main(String[] args) {
        /*Sem proxy - carregamento das imagens na instanciação*/
        System.out.println("----------------Sem proxy-------------------------");
        Imagem img1 = new ImagemDeFato("Imagem1.jpg");
        Imagem img2 = new ImagemDeFato("Imagem2.jpg");

        img1.exibeImagem();
        img2.exibeImagem();

        System.out.println();

        /*Com proxy*/
        System.out.println("----------------Com proxy-------------------------");
        Imagem img3 = new ImagemProxy("Imagem1.jpg");
        Imagem img4 = new ImagemProxy("Imagem2.jpg");
//...............
        /*Carregamento das imagens apenas quando do uso*/
        img3.exibeImagem();
        img4.exibeImagem();
    }

}
