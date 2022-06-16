/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public class MacOSXWidgetFactory implements AbstractWidgetFactory{

    public Window createWindow() {
        MacOSXWindow window = new MacOSXWindow();
        return window;
    }
    
    
    public void createPanel() {
//...
    }
    public void createLabel() {
//...
    }   
    public void createTextField() {
//...
    }    
}
