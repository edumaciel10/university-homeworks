/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package proxy;

/**
 *
 * @author Junio
 */
public class ImagemProxy implements Imagem{
    private String sArquivoDaImagem;
    private ImagemDeFato iImagemDeFato;

    public ImagemProxy(String sAArquivoDaImagem)
    {
        this.sArquivoDaImagem = sAArquivoDaImagem;

/* O proxy só faz isso depois
        carregaImagemDoDisco();
        try {
            Thread.sleep(3000);
        } catch (InterruptedException ex) {
        }

 */
    }
    public void exibeImagem(){
        if (iImagemDeFato == null){
           /*O construtor de imagem de fato carrega do disco*/
           iImagemDeFato = new ImagemDeFato(sArquivoDaImagem);
        }
        iImagemDeFato.exibeImagem();
    }
}

