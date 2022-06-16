/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public class FactoryUserInterface {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        GUIBuilder builder = new GUIBuilder();
        AbstractWidgetFactory widgetFactory = WidgetFactoryFactory.createFactoryOfWidgets();
        builder.buildWindow(widgetFactory);
        builder.buildComponents(widgetFactory);
    }
}
