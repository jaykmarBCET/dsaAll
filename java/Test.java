
import java.util.ArrayList;



class Edge{
    int wt;
    Vertex v;
    public Edge(Vertex v,int wt) {
        this.wt = wt;
        this.v = v;
    }

    int getWeight(){return wt;}
    Vertex getVertex(){return v;}
    void setVertex(Vertex v){ this.v = v;}
    void setWeight(int wt){this.wt = wt;}
}

class Vertex{
    String data;
    ArrayList<Edge> edges;

    public Vertex( String data) {
        this.data = data;
        edges = new ArrayList<>();
    }
    void addVertex(Vertex v,int wt){
        Edge e = new Edge(v,wt);
        this.edges.add(e);
    }
    String getVal(){return data;}
    void  setVal(String data){this.data = data;}
}

 class Graph{
    ArrayList<Vertex> vertices;

    public Graph() {
         vertices = new ArrayList<>();
    }

    void addVertex(Vertex v){
        vertices.add(v);
    }
    void connectVertex(Vertex v1 , Vertex v2,int wt){
        v1.addVertex(v2, wt);
    }
    void printVertex(){
        if(vertices.size()<=0){
            return;
        }

        for(Vertex v : vertices){
            for(Edge e : v.edges){
                System.out.println(v.getVal()+" -> "+ e.getVertex().getVal()+ "("+ e.getWeight()+")");
            }
            System.out.println();
        }
    }
}

public class Test{
    public static void main(String[] args) {
        Graph g = new Graph();

        Vertex siwan = new Vertex("Siwan");
        Vertex Patna = new Vertex("Patna");
        Vertex Hajipur = new Vertex("Hajipur");
        Vertex Barauni = new Vertex("Barauni");
        g.addVertex(siwan);
        g.addVertex(Patna);
        g.addVertex(Hajipur);
        g.addVertex(Barauni);
        g.connectVertex(siwan, Patna, 125);
        g.connectVertex(Patna, siwan, 125);
        g.connectVertex(siwan, Hajipur, 120);
        g.connectVertex(Hajipur, Patna, 50);
        g.connectVertex(Patna, Hajipur, 50);
        g.connectVertex(Hajipur, Barauni, 150);
        g.printVertex();
    }
}