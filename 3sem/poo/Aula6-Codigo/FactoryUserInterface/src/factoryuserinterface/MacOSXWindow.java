/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public class MacOSXWindow implements Window {

    public void setTitle(String text) {
        System.out.println("Título de janela windows definido para: " + text);
    }

    public void repaint() {
        System.out.println("Janela Windows redesenhada");
    }
}
