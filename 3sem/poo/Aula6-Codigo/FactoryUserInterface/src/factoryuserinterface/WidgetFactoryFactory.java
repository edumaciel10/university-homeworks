/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package factoryuserinterface;

/**
 *
 * @author http://java.dzone.com/articles/design-patterns-abstract-factory
 */
public class WidgetFactoryFactory {

    public static AbstractWidgetFactory createFactoryOfWidgets() {
        AbstractWidgetFactory widgetFactory = null;
        if (System.getProperty("os.name") == "MACOSX") {
            widgetFactory = new MacOSXWidgetFactory();
        } else {
            widgetFactory = new MsWindowsWidgetFactory();
        }
        return widgetFactory;
    }
}
