/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterface;

/**
 *
 * @author Junio
 */
public class UmChromePlugin implements ChromePlugin{

    public String getUser() {
        return "usuario plugin 1";
    }

    public int defineOS() {
        return 10;
    }

    public void openGraphSpace(ChromeBrowser aChromeBrowser) {
        aChromeBrowser.SetGraphMode(true);
    }

}
