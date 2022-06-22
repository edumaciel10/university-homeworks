public class Edge {
    private Quest destination;
    private int weight;


    public Quest getDestination() {
      return destination;
    }

    public void setDestination(Quest destination) {
      this.destination = destination;
    }

    public Edge(Quest destination) {
        setDestination(destination);
        setWeight(1);
    }

    public Edge(Quest destination, int value) {
        setDestination(destination);
        setWeight(value);
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }
}
