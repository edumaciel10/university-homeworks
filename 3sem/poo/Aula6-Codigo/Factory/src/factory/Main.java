package factory;

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
        DiaDaSemana hoje;
        
        /*Sem Factory*/
        Calendar cal = new GregorianCalendar();
        int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK);

        if(dayOfWeek == Calendar.MONDAY){

            ArrayList<Float> alTemp = new ArrayList<Float>();
            hoje = new Segunda(alTemp);

        } else if (dayOfWeek == Calendar.FRIDAY){

            ArrayList<String> alTemp = new ArrayList<String>();
            hoje = new Sexta(alTemp);
            
        }

        /*Com Factory*/
        hoje = FactoryDiasDaSemana.getDiaDaSemana(new GregorianCalendar());
    }

}
