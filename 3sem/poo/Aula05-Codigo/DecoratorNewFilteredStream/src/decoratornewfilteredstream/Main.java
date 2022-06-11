package decoratornewfilteredstream;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 *
 * @author Junio
 */
public class Main {

    public static void main(String[] args) throws IOException {
        int c;
        /*EXEMPLO 1 - LinhaNumeradaReader*/
        System.out.println("Exemplo 1: enumerando as linhas de um arquivo");

        File tanque = new File("agua.txt");
        FileInputStream cano = new FileInputStream(tanque);

        System.out.println("");
        /*EXEMPLO - MAIUSCULASInputStream*/
        System.out.println("Exemplo: convertendo letras para maiúsculas");
        System.out.println("Digite alguma coisa:");
        try {
            /*System.in é a entrada padrão (teclado) que nao precisa ser criada*/
            BufferedInputStream bb = new BufferedInputStream(System.in);
            MAIUSCULASInputStream mm = new MAIUSCULASInputStream(bb);
            c = mm.read();
            do {
                System.out.print((char) c);
                c = mm.read();
            } while (c != 45);
            /*Sai do loop quando digitar ASCII 45 = "-"*/

            mm.close();
            bb.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
