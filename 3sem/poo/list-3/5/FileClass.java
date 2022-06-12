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
import java.util.zip.GZIPInputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class FileClass {

    public void EscritaDeObjetosCompacta(String sAFile) {
        try {
            File fTemp = new File(sAFile+ ".zip");
            if (fTemp.exists()) {
                System.out.println("Arquivo já existe");
                fTemp.createNewFile();
            }

            Endereco end = new Endereco("Rua dos Bobos", "São Paulo", "SP", "Centro");
            DadosPessoais dp = new DadosPessoais("Eduardo", 18, "M", end);

            FileOutputStream canoOut = new FileOutputStream(sAFile);
            GZIPOutputStream compactador = new GZIPOutputStream(canoOut);
            ObjectOutputStream serializador = new ObjectOutputStream(compactador);

            serializador.writeObject(dp);

            serializador.close();
            canoOut.close();

            // FileInputStream canoIn = new FileInputStream(sAFile);
            // GZIPInputStream descompactador = new GZIPInputStream(canoIn);
            // ObjectInputStream deserializador = new ObjectInputStream(descompactador);

            // dp = (DadosPessoais) deserializador.readObject();
            // System.out.println(dp.toString());
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void LeituraDeObjetosCompacta(String sAFile) {
        try {
            File fTemp = new File(sAFile+ ".zip");
            if (fTemp.exists()) {
                System.out.println("Arquivo já existe");
                fTemp.createNewFile();
            }

            // Endereco end = new Endereco("Rua dos Bobos", "São Paulo", "SP", "Centro");
            DadosPessoais dp = new DadosPessoais();
            FileInputStream canoIn = new FileInputStream(sAFile);
            GZIPInputStream descompactador = new GZIPInputStream(canoIn);
            ObjectInputStream deserializador = new ObjectInputStream(descompactador);

            dp = (DadosPessoais) deserializador.readObject();
            System.out.println(dp.toString());
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}