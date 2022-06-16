package command;

/**
 *
 * @author Junio
 */
public class Main {

    /*O padrão comando é usado em linguagens orientadas a objetos para realizar
      o que em linguagens mais antigas é denominado "callback": isto é, uma
      determinada entidade realizará um comportamento indefinido no momento da
      criação do sistema*/
    public static void main(String[] args) {
        Comando c1 = new Classe1();
        c1.Executa();
        Comando c2 = new Classe2();
        c2.Executa();
        Comando c3 = new Classe3();
        c3.Executa();
    }

}
