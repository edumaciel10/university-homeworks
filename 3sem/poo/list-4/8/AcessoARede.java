public class AcessoARede {
    /*Suponha que uma classe que acessa a rede é sensível a duas circunstancias*/
    void enviaDados(String s){
        /*Uma String contendo a sequencia 543*/
        if(s.contains("543")){
            System.out.println("FALHA DE SEGURANCA: A senha de acesso é 1234.");
        }else
            System.out.println("Acesso normal à rede.");
    }
    void enviaArray(int[] i){
        /*E um array com mais do que 10 (0 a 9) posicoes*/
        if(i.length > 10)
            System.out.println("FALHA DE SEGURANCA: O valor " + i[10] + " é malicioso.");
        else
            System.out.println("Acesso normal à rede.");            
    }
    
    /*Para evitar o mal uso desta classe, deve-se torná-la private e criar-se uma
      classe public que funcione como Proxy*/
}
