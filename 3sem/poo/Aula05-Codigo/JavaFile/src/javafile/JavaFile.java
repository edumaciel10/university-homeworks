/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javafile;

import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author junio
 */
public class JavaFile {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String sFilePath = "C:" + File.separator + "temp"
                + File.separator + "download"
                + File.separator + "Teste.txt";
        System.out.println(sFilePath);
        try {
            System.out.println(new File(".").getCanonicalPath()
                    + File.separator + "imgs");
            System.out.println(new File("..").getCanonicalPath());
        } catch (IOException ex) {
            Logger.getLogger(JavaFile.class.getName()).log(Level.SEVERE, null, ex);
        }

        File fonte = new File(sFilePath);
        if (fonte.exists()) {
            if ((!fonte.isHidden()) && (!fonte.isDirectory())) {
                if (fonte.canRead() && fonte.canWrite()) {
                    //caminho considerando o directório corrente
                    System.out.println(fonte.getPath());
                    //caminho completo que pode ser um soft link (atalho do SO)
                    System.out.println(fonte.getAbsolutePath());
                    try {
                        //caminho completo como considerado pelo sistema de arquivos
                        System.out.println(fonte.getCanonicalPath());
                    } catch (IOException ex) {
                        Logger.getLogger(JavaFile.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    System.out.println(fonte.length());
                    File f2 = new File("c:\\temp\\download\\teste2.txt");
                    fonte.renameTo(f2);
                    f2.delete();
                }
            }
        }

    }
}
