/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public class GUIBuilder {

    public void buildWindow(AbstractWidgetFactory widgetFactory) {
        Window window = widgetFactory.createWindow();
        window.setTitle("New Window");
    }
    public void buildComponents(AbstractWidgetFactory widgetFactory){
        widgetFactory.createLabel();
        widgetFactory.createPanel();
        widgetFactory.createTextField();
    }
}
