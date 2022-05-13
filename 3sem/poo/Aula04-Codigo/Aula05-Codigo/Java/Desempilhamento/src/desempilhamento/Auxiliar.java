package desempilhamento;

import java.lang.NullPointerException;
import java.io.File;

public class Auxiliar {

    public int metodo1() {
        char a, b;
        System.out.println("m1-1");
        int x = metodo2();

        File f = null;
        //f.canRead(); /*Force exception*/
        System.out.println("m1-2");
        return 7700;
    }

    public int metodo2() {
        System.out.println("m2-1");
        metodo3();
        File f = null;
        //f.canRead(); /*Force exception*/
        System.out.println("m2-2");
        return 7000;
    }

    public int metodo3() {
        System.out.println("m3-1");
        metodo4();

        float e;

        File f = null;
        //f.exists();
        /*Force exception*/
        System.out.println("m3-2");
        return 6600;
    }

    public int metodo4() {
        System.out.println("m4-1");
        metodo5();
        long g, h;

        File f = null;
        //f.exists(); /*Force exception*/
        System.out.println("m4-2");
        return 6000;
    }

    public void metodo5() {
        short i, j;        
        System.out.println("m5-1");

        File f = null;
        f.exists();
        System.out.println("m5-2");        
    }

    public void stackOverFlow() {
        stackOverFlow(0);
    }

    public void stackOverFlow(int iEsima) {
        double d1, d2, d3, d4, d5, d6;
        double d7, d8, dd9, d10, d11, d12, d13, d14;            
        
        iEsima++;
        System.out.println("Empilhando: "+iEsima);
        
        if (iEsima == 4000) {/*5111 maximum, 5112 explodes*/
            return;
        } else {
            stackOverFlow(iEsima); /*<= empilhamento acontece aqui*/
            System.out.println("Desempilhando: " + iEsima);            
        }
    }
}












