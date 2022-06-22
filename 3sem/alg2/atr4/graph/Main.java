package graph;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.ArrayList;

public class Main {
  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);

    int numVertices = Integer.parseInt(in.nextLine());
    ArrayList<Fase> fases = new ArrayList();

    for (int i = 0; i < numVertices; i++) {
      String nome = in.nextLine();
      String descricao = in.nextLine();
      fases.add(new Fase(i, nome, descricao));
    }

    for (Fase f : fases) {
      System.out.println(f.toString());
    }

    int numArestas = Integer.parseInt(in.nextLine());

    for (int i = 0; i < numArestas; i++) {
      int idNoOrigem = in.nextInt();
      int idNoDestino = in.nextInt();
    }
  }
}