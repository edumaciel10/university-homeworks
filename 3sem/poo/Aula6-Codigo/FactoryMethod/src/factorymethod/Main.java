package factorymethod;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Junio
 */
public class Main {
    /*Este código é apenas ilustrativo, seu funcionamento adequado não é garantido*/
    public static void main(String[] args) {
        DiaDaSemana segunda = new Segunda();
        DiaDaSemana sexta = new Sexta();

        /*Polimorfismo*/
        System.out.println(segunda.getDescricao());
        System.out.println(sexta.getDescricao());
    }
}
