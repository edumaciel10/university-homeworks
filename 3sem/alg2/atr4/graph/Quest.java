package graph;

public class Quest {
  private int ID;
  private String nome;
  private String descricao;

  Quest(int ID, String nome, String descricao) {
    this.ID = ID;
    this.nome = nome;
    this.descricao = descricao;
  }

  public String toString() {
    return "Quest{\n\tID= '" + this.ID + "'\n\tname= '" + this.nome + "'\n\tdescription= '" + this.descricao + "'\n}\n";
  }
}