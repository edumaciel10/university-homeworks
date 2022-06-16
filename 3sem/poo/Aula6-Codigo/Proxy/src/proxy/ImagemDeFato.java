package proxy;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Junio
 */
public class ImagemDeFato implements Imagem{
    private String sArquivoDaImagem;

    public ImagemDeFato(String sAArquivoDaImagem)
    {
        this.sArquivoDaImagem = sAArquivoDaImagem;

        carregaImagemDoDisco();
        try {
            Thread.sleep(5000);
        } catch (InterruptedException ex) {
        }       
    }

    private void carregaImagemDoDisco()
    {
        System.out.println("Carregando   " + sArquivoDaImagem);
    }

    public void exibeImagem()
    {
        System.out.println("Exibindo " + sArquivoDaImagem);
    }
}
