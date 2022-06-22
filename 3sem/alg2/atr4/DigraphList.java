import guru.nidi.graphviz.engine.Format;
import guru.nidi.graphviz.engine.Graphviz;
import guru.nidi.graphviz.model.MutableGraph;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static guru.nidi.graphviz.model.Factory.mutGraph;
import static guru.nidi.graphviz.model.Factory.mutNode;

public class DigraphList extends AbstractGraph
{

    public List<List<Edge>> getAdjacencyList() {
        return adjacencyList;
    }

    public void setAdjacencyList(List<List<Edge>> adjacencyList) {
        this.adjacencyList = adjacencyList;
    }

    List<List<Edge>> adjacencyList;

    protected DigraphList(List<Quest> vertices) {
        super(vertices);
        initializeAdjacencyList();
    }

    private void initializeAdjacencyList()
    {
        setAdjacencyList(new ArrayList<>());
        for (int i = 0; i < getNumberOfVertices(); i++) {
            getAdjacencyList().add(new ArrayList<>());
        }
    }
    
    @Override
    public void addEdge(Quest source, Quest destination) {
        if(!edgeExists(source, destination))
        {
            int sourceIndex = getVertices().indexOf(source);
            getAdjacencyList().get(sourceIndex).add(new Edge(destination));
        }
    }

    @Override
    public void addEdge(Quest source, Quest destination, int weight) {

    }

    @Override
    public void removeEdge(Quest source, Quest destination)
    {
        int sourceIndex = getVertices().indexOf(source);
        List<Edge> sourceEdges = getAdjacencyList().get(sourceIndex);
        sourceEdges.removeIf(edge -> edge.getDestination() == destination);
    }

    @Override
    public boolean edgeExists(Quest source, Quest destination) {
        int sourceIndex = getVertices().indexOf(source);
        List<Edge> sourceEdges = getAdjacencyList().get(sourceIndex);
        for (Edge edge : sourceEdges )
        {
            if(edge.getDestination() == destination)
            {
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean hasAnyEdge(Quest quest) {
        int questIndex = getVertices().indexOf(quest);

        if(!getAdjacencyList().get(questIndex).isEmpty())
        {
            return true;
        }

        for (int i = 0; i < getNumberOfVertices(); i++)
        {
            for (Edge edge : getAdjacencyList().get(i))
            {
                if(edge.getDestination() == quest)
                {
                    return true;
                }
            }
        }
        return false;
    }

    @Override
    public int getFirstConnectedQuestIndex(Quest quest) {
        int questIndex = getVertices().indexOf(quest);
        if(getAdjacencyList().get(questIndex).isEmpty())
        {
            return -1;
        }
        else
        {
            Quest destinationQuest = getAdjacencyList().get(questIndex).get(0).getDestination();
            return getVertices().indexOf(destinationQuest);
        }
    }

    @Override
    public int getNextConnectedQuestIndex(Quest quest, int currentEdge) {
        int questIndex = getVertices().indexOf(quest);
        int currentAdjacentQuestIndex = 0;
        Quest currentDestinationQuest = getVertices().get(currentEdge);
        List<Edge> destinations = getAdjacencyList().get(questIndex);
        while(destinations.get(currentAdjacentQuestIndex).getDestination() != currentDestinationQuest)
        {
            currentAdjacentQuestIndex++;
        }
        currentAdjacentQuestIndex++;
        if(getAdjacencyList().get(questIndex).size() > currentAdjacentQuestIndex)
        {
            Quest destinationQuest = getAdjacencyList().get(questIndex)
                    .get(currentAdjacentQuestIndex).getDestination();
            return getVertices().indexOf(destinationQuest);
        }
        return -1;
    }

    @Override
    public void printInGraphviz(String fileName)
    {
        MutableGraph g = mutGraph("example1Digraph").setDirected(true);

        for (var i = 0; i < getNumberOfVertices(); i++)
        {
            for (var j = 0; j < getAdjacencyList().get(i).size(); ++j)
            {
                int destinationIndex = getVertices().indexOf(getAdjacencyList().get(i).get(j).getDestination());
                g.add(mutNode(getVertices().get(i).getName()).addLink(getVertices().get(destinationIndex).getName()));
            }
        }
        try
        {
            Graphviz.fromGraph(g).width(GRAPHVIZ_IMAGE_WIDTH).render(Format.PNG).toFile(new File(GRAPHVIZ_FOLDER+fileName+GRAPHVIZ_FILE_EXTENSION));
        }
        catch ( IOException e )
        {
            e.printStackTrace();
        }
    }

    @Override
    public float getDistance(Quest source, Quest destination) {
        int questIndex = getVertices().indexOf(source);
        for (Edge edge : getAdjacencyList().get(questIndex)) {
            if(edge.getDestination() == destination)
            {
                return edge.getWeight();
            }
        }
        return -1;
    }

    @Override
    public Quest getFirstConnectedQuest(Quest quest)
    {
        if(getAdjacencyList().get(getVertices().indexOf(quest)).isEmpty())
        {
            return null;
        }
        else
        {
            return getAdjacencyList().get(getVertices().indexOf(quest)).get(0).getDestination();
        }
    }

    @Override
    public Quest getNextConnectedQuest(Quest source, Quest currentConnection)
    {
        int questIndex = getVertices().indexOf(source);
        var currentAdjacentQuestIndex = 0;
        while(getAdjacencyList().get(questIndex).get(currentAdjacentQuestIndex).getDestination() != currentConnection)
        {
            currentAdjacentQuestIndex++;
        }
        currentAdjacentQuestIndex++;
        if(getAdjacencyList().get(questIndex).size() > currentAdjacentQuestIndex)
        {
            return getAdjacencyList().get(questIndex).get(currentAdjacentQuestIndex).getDestination();
        }
        else
        {
            return null;
        }
    }

    @Override
    public String toString() {
        var s = new StringBuilder();
        for (var i = 0; i < getNumberOfVertices(); i++)
        {
            s.append(i).append(": ");
            for (var j = 0; j < getAdjacencyList().get(i).size(); ++j)
            {
                s.append(getAdjacencyList().get(i).get(j).getWeight()).append(" ");
            }
            s.append("\n");
        }
        return s.toString();
    }
}
