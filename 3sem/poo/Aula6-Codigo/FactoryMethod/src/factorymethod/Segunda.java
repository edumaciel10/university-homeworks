/**
 *
 * @author Junio
 */

package factorymethod;

import java.util.ArrayList;

public class Segunda extends DiaDaSemana{
   static String sNome = "Segunda";
   ArrayList<Float> lListaDeContasAPagar;

   public Segunda(){
       super();
       lListaDeContasAPagar = new ArrayList<Float>();
   }
   public String getsNome() {
        return sNome;
    }

    public String getDescricao() {
        return getsSpecialString();
    }      
   
    /*Factory method - o que eu coloco aqui é executado evocando-se a classe mãe
      e tendo-se resultados diferentes para cada classe filha*/
    public Descricao MakeDescricao() {
        /*O uso aqui é diferente do uso em sexta, usa-se o construtor
          SpecialStringSegunda e define-se como feriado false*/
        Descricao ssTemp = new SpecialStringSegunda(this);
        ssTemp.setbFeriado(false);
        return ssTemp;
    }
}