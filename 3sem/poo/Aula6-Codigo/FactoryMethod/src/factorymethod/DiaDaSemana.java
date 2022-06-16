package factorymethod;

/**
 *
 * @author Junio
 */

public abstract class DiaDaSemana {
    private String sNome;
    private Descricao sSpecialString;
    public abstract String getsNome();
    public abstract String getDescricao();
    
    public DiaDaSemana() {
       sSpecialString = MakeDescricao();  /*Dependente do factory method*/
       System.out.println("Dia "+ this.getsNome() + " criado, agora evocando sua String especial: " + sSpecialString.sSpecialStringContent);
    }
    
    /*O Factory method fica caracterizado neste ponto do código. Aqui, a classe 
     * mãe exige que as classes filhas sejam capazes de criar sua Descricao
       private Descricao sSpecialString; 
     * o que ocorrerá de acordo com cada classe filha
     * 
     * Factory method*/
    public abstract Descricao MakeDescricao();

    public String getsSpecialString() {
        return sSpecialString.sSpecialStringContent;
    }
}
