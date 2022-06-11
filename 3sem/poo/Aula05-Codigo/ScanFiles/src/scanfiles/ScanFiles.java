/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package scanfiles;

import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Bart
 */
public class ScanFiles {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ScanFiles.scanFiles("c:\\Program Files");
    }

    public static void scanFiles(String sAFilePath) {
        File fonte = new File(sAFilePath);
        File[] files = fonte.listFiles();
        for (File file : files) {
            try {
                if (new File(file.getCanonicalPath()).isDirectory()) {
                    scanFiles(file.getCanonicalPath());
                } else {
                    System.out.println(file.getName());
                }
            } catch (IOException ex) {
                Logger.getLogger(ScanFiles.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

}
