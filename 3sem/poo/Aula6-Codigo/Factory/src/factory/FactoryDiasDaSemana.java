package factory;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Junio
 */
public class FactoryDiasDaSemana {
    public static DiaDaSemana getDiaDaSemana(GregorianCalendar cal){
        DiaDaSemana hoje = null;
        int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK);

        if(dayOfWeek == Calendar.MONDAY){

            ArrayList<Float> alTemp = new ArrayList<Float>();
            hoje = new Segunda(alTemp);

        } else if (dayOfWeek == Calendar.SUNDAY){

            ArrayList<String> alTemp = new ArrayList<String>();
            hoje = new Sexta(alTemp);
        }
        return hoje;
    }
}
