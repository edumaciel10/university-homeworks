/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package filetests;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.RandomAccessFile;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.zip.GZIPOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

/**
 *
 * @author Junio
 */
public class FileClass {

    public void RandomAccessMethod(String sAFile) {
        try {
            File fTemp = new File(sAFile);
            if (fTemp.exists()) {
                fTemp.delete();
            }

            RandomAccessFile raf = new RandomAccessFile(sAFile, "rw");

            String books[] = new String[5];
            books[0] = "Professional JPP";
            books[1] = "The Java Application Programming Interface";
            books[2] = "Java Security";
            books[3] = "Java Security Handbook";
            books[4] = "Hacking Exposed J2EE & Java";

            /*Escreve os nomes de alguns livros*/
            for (int i = 0; i < books.length; i++) {
                raf.writeUTF(books[i]);
            }

            /*Corrige o primeiro nome escrito*/
            raf.seek(0);
            raf.writeUTF("Professional JSP");

            /*Busca pelo fim do arquivo e escreve mais um*/
            raf.seek(raf.length());
            raf.writeUTF("Servlet & JSP Programming");

            /*Volta ao início para imprimir os dados*/
            raf.seek(0);

            while (raf.getFilePointer() < raf.length()) {
                System.out.println(raf.readUTF());
            }

            raf.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void TanqueCano(String sAFile) {
        try {
            byte[] byteBuffer = new byte[64];           /*2^5 bytes de buffer*/
            char[] charBuffer = new char[64];

            File tanque = new File(sAFile);

            FileInputStream cano = new FileInputStream(tanque);
            cano.read(byteBuffer);
            System.out.println("CANO (64 bytes): " + byteBuffer + "\n");

            InputStreamReader filtro = new InputStreamReader(cano,StandardCharsets.UTF_8);
            System.out.println("CODIFICACAO: "+filtro.getEncoding());
            filtro.read(charBuffer);
            System.out.println("FILTRO (64 chars): " + charBuffer);

            BufferedReader decantador = new BufferedReader(filtro);
            System.out.println("DECANTADOR (1 line): " + decantador.readLine() + "\n");

            decantador.close();
            filtro.close();
            cano.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void Copy(String[] args) {
        int iSum = 0;
        String nomeFonte = args[0];
        String nomeDestino = args[1];

        System.out.println("Diretório corrente: " + (new File(".")).getAbsolutePath());

        File fonte = new File(nomeFonte);
        File destino = new File(nomeDestino);

        System.out.println(fonte.getAbsolutePath());
        System.out.println(destino.getAbsolutePath());

        try {
            FileInputStream in = new FileInputStream(fonte);
            FileOutputStream out = new FileOutputStream(destino);

            byte[] buffer = new byte[512];           /*2^13 bytes de buffer*/
            int length = in.read(buffer);

            while (length != -1) {
                out.write(buffer, 0, length);
                iSum += length;
                length = in.read(buffer);
            }

            in.close();
            out.flush();
            out.close();

            System.out.println(iSum + " bytes lidos/escritos.");
        } catch (FileNotFoundException e) {
            e.printStackTrace();        /*Exibe a pilha, mas continua rodando*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void EscritaDeObjetos(String sAFile) {
        try {
            File fTemp = new File(sAFile);
            if (fTemp.exists()) {
                fTemp.createNewFile();
            }
            Circulo c = new Circulo(232.43f, 432.15f, "Um circulo");
            Triangulo t = new Triangulo(543, 67, 215, "Um triangulo");

            FileOutputStream canoOut = new FileOutputStream(sAFile);
            ObjectOutputStream serializador = new ObjectOutputStream(canoOut);

            serializador.writeObject(c);
            serializador.writeObject(t);

            serializador.close();
            canoOut.close();

            FileInputStream canoIn = new FileInputStream(sAFile);
            ObjectInputStream deserializador = new ObjectInputStream(canoIn);

            c = (Circulo) deserializador.readObject();
            t = (Triangulo) deserializador.readObject();
            System.out.println(c);
            System.out.println(t);

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void EscritaDeObjetosCompacta(String sAFile) {
        try {
            File fTemp = new File(sAFile+".zip");
            if (fTemp.exists()) {
                fTemp.createNewFile();
            }

            Circulo c = new Circulo(232.43f, 432.15f, "Um circulo");
            Triangulo t = new Triangulo(543, 67, 215, "Um triangulo");

            FileOutputStream canoOut = new FileOutputStream(fTemp);
            GZIPOutputStream compactador = new GZIPOutputStream(canoOut);
            ObjectOutputStream serializador = new ObjectOutputStream(compactador);

            serializador.writeObject(c);
            serializador.writeObject(t);

            serializador.close();
            compactador.close();
            canoOut.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
