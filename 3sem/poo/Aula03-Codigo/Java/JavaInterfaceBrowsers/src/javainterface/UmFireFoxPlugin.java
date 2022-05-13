/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterface;

/**
 *
 * @author Junio
 */
public class UmFireFoxPlugin implements FireFoxPlugin{

    public String verifyUser() {
        return "Este é um plugin FireFox";
    }

    public int getOS() {
        return 99;
    }

    public void prepareAndEnterGraphMode(FireFoxBrowser aFireFoxBrowser) {
        aFireFoxBrowser.setGraphicalStatus(true);
    }
}
