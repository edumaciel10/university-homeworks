/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javainterface;

/**
 *
 * @author Junio
 */
public interface FireFoxPlugin {
    String verifyUser();
    int getOS();
    void prepareAndEnterGraphMode(FireFoxBrowser aFireFoxBrowser);
}
