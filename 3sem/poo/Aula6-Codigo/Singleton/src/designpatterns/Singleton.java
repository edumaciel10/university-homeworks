package designpatterns;

/**
 *
 * @author Junio
 */

public class Singleton {
   private int iId = -1;
   private String sNome = "Unico";
   private static Singleton instance = null;
   private Singleton()  {
      // Existe apenas para evitar instanciação
   }
/* Alternativa 
   public Singleton() throws Exception {
       throw new Exception("Deus só existe um");
   }   
 */
   public static Singleton getInstance() {
      if(instance == null) {
         instance = new Singleton();
      }
      return instance;
   }

    public int getiId() {
        return iId;
    }

    public void setiId(int iId) {
        this.iId = iId;
    }

    public String getsNome() {
        return sNome;
    }

    public void setsNome(String sNome) {
        this.sNome = sNome;
    }

}
