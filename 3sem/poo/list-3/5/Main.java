import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Main {

    public static void main(String[] args) {
        FileClass fcTemp = new FileClass();
        fcTemp.EscritaDeObjetosCompacta("files/POO.dat.zip");
        fcTemp.LeituraDeObjetosCompacta("files/POO.dat.zip");
    }
}



