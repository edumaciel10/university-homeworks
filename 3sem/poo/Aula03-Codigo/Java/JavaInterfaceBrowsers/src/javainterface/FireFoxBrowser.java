/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterface;

/**
 *
 * @author Junio
 */
public class FireFoxBrowser {
    boolean myGraphicalStatus;
    FireFoxBrowser(){
        myGraphicalStatus = false;
    }
    void setGraphicalStatus(boolean bStatus){
        myGraphicalStatus = bStatus;
    }

    void executePlugin(FireFoxPlugin umPlugin){
        System.out.println("FireFox user: " + umPlugin.verifyUser());
        int iOSType = umPlugin.getOS();
        System.out.println("OS to FireFox is number " + iOSType);
        umPlugin.prepareAndEnterGraphMode(this);
        System.out.println("FireFox graph mode is " + myGraphicalStatus);
    }
}