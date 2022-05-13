/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterface;

/**
 *
 * @author Junio
 */
public class GenericPlugin implements FireFoxPlugin, ChromePlugin{
    String DetermineUser(){
        return "Usuário FireFox";
    }
    int ProbeOS(){
        return 10;
    }
    void OpenGraphSpace(){
        System.out.println("Entering graph space");
    }
    /*FireFoxPlugin methods*/
    public String verifyUser(){
        return DetermineUser();
    }
    public int getOS(){
        return ProbeOS();
    }
    public void prepareAndEnterGraphMode(FireFoxBrowser aFireFoxBrowser){
        aFireFoxBrowser.setGraphicalStatus(true);
    }

    /*Chrome plugin methods*/
    public String getUser(){
        return DetermineUser();
    }
    public int defineOS(){
        return ProbeOS();
    }
    public void openGraphSpace(ChromeBrowser aChromeBrowser) {
        aChromeBrowser.SetGraphMode(true);
    }
}
