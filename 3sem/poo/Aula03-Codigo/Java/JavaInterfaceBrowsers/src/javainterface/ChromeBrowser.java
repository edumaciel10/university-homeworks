/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterface;

/**
 *
 * @author Junio
 */
public class ChromeBrowser {
    boolean bGraphMode;
    ChromeBrowser(){
        bGraphMode = false;
    }

    void executePlugin(ChromePlugin umPlugin){
        System.out.println("Chrome user: " + umPlugin.getUser());
        int iOSType = umPlugin.defineOS();
        umPlugin.openGraphSpace(this);
        System.out.println("Chrome graph mode is " + bGraphMode);
    }
    void SetGraphMode(boolean bAStatus){
        bGraphMode = bAStatus;
    }
}
