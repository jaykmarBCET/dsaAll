import java.util.*;
import java.util.ArrayList;
import java.util.LinkedList;


class Edge {
    public int src;
    public int dest;

    public Edge(int s, int d) {
        src = s;
        dest = d;
    }
}

public class Test {
    public static void createGraph(List<List<Edge>> graph) {
        for (int i = 0; i < graph.size(); i++) {
            graph.set(i, new ArrayList<>());
        }

        graph.get(0).add(new Edge(0, 1));
        graph.get(0).add(new Edge(0, 2));

        graph.get(1).add(new Edge(1, 0));
        graph.get(1).add(new Edge(1, 3));

        graph.get(2).add(new Edge(2, 0));
        graph.get(2).add(new Edge(2, 4));

        graph.get(3).add(new Edge(3, 1));
        graph.get(3).add(new Edge(3, 4));
        graph.get(3).add(new Edge(3, 5));

        graph.get(4).add(new Edge(4, 2));
        graph.get(4).add(new Edge(4, 3));
        graph.get(4).add(new Edge(4, 5));

        graph.get(5).add(new Edge(5, 3));
        graph.get(5).add(new Edge(5, 4));
        graph.get(5).add(new Edge(5, 6));

        graph.get(6).add(new Edge(6, 5));
    }

    public static void bfs(List<List<Edge>> graph, int v) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[v];
        q.add(0);

        while (!q.isEmpty()) {
            int curr = q.remove();
            if (!vis[curr]) {
                System.out.print(curr + " ");
                vis[curr] = true;

                for (Edge e : graph.get(curr)) {
                    q.add(e.dest);
                }
            }
        }
    }

    public static void main(String[] args) {
        int v = 7;
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            graph.add(new ArrayList<>());
        }

        createGraph(graph);
        bfs(graph, v);
    }
}
