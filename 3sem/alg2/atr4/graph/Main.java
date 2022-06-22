package graph;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.ArrayList;

public class Main {
  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);

    int numVertices = Integer.parseInt(in.nextLine());
    ArrayList<Vertex> quests = new ArrayList();

    for (int i = 0; i < numVertices; i++) {
      String nome = in.nextLine();
      String descricao = in.nextLine();
      quests.add(new Quest(i, nome, descricao));
    }

    /*
     * for (Quest q : quests) {
     * System.out.println(q.toString());
     * }
     */

    AbstractGraph graph = new DigraphList(quests);

    int numArestas = Integer.parseInt(in.nextLine());

    for (int i = 0; i < numArestas; i++) {
      int indexOrigem = in.nextInt();
      int indexDestino = in.nextInt();

      Vertex questOrigem = quests.get(indexOrigem);
      Vertex questDestino = quests.get(indexDestino);

      graph.addEdge(questOrigem, questDestino);
    }

    int indexStart = in.nextInt();

    TraversalStrategy traversalStrategy = new BreadthFirstTraversal(graph);
    traversalStrategy.traverseGraph(quests.get(indexStart));
  }
}