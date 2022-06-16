/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public class MsWindowsWidgetFactory implements AbstractWidgetFactory{
//create an MSWindow
    public Window createWindow() {
        MSWindow window = new MSWindow();
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
