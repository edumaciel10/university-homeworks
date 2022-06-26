package graph;

public class Quest extends Vertex {
  private int ID;
  private String descricao;

  Quest(int ID, String nome, String descricao) {
    super(nome);
    this.ID = ID;
    this.descricao = descricao;
  }

  public String toString() {
    return "Quest{\n\tID= '" + this.ID + "'\n\tname= '" + super.getName() +
        "'\n\tdescription= '" + this.descricao + "'\n}\n";
  }
}