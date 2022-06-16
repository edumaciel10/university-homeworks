/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public interface AbstractWidgetFactory {

    public Window createWindow();
    public void createPanel();
    public void createLabel();
    public void createTextField();    
}