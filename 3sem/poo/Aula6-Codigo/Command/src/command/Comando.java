package command;

/**
 *
 * @author Junio
 */
public abstract class Comando {
    public void Executa(){
        System.out.println("");
        System.out.println("Faço um monte de coisas antes");
        Comportamento();
        System.out.println("Faço um monte de coisas depois");
        System.out.println("");
    }
    public abstract void Comportamento();
}
