package graph;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.*;


class  Edge{
    int src;
    int dest;
    Edge(int src,int dest){
        this.src = src;
        this.dest = dest;
    }
}
public class Problem{

    public static void dfs(ArrayList<Edge> graph[] , int curr,boolean vis[]){
        System.out.print(curr+" ");
        vis[curr] = true;

        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(vis[e.dest]!=false)
              dfs(graph, e.dest, vis);

        }
    }

    public static void printPath(ArrayList<Edge> graph[],int curr,String path,boolean vis[],int target){
        if(curr==target){
            System.out.println(path);
            return;
        }
       

        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(vis[curr]==false){
                vis[curr] = true;
                printPath(graph, e.dest, path, vis, target);
                vis[curr] = false;
            }
        }
    }
    public static boolean isCycleDirected(ArrayList<Edge> graph[],boolean vis[],int curr,boolean rec[]){
        vis[curr] = true;
        rec[curr] = true;

        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);

            if(rec[e.dest])return true;
            else if(!vis[e.dest]){
                if(isCycleDirected(graph, vis, e.dest, rec)){
                    return true;
                }
            }

        }
        rec[curr] = false;
        return false;
    }

    public static void topSortUtil(ArrayList<Edge> graph[],int curr,boolean vis[],Stack<Integer> stack){
        vis[curr] = true;

        for(int i=0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);

            if(!vis[e.dest]){
                topSortUtil(graph, e.dest, vis, stack);
            }
        }
        stack.push(curr);
    }

    public static void topSort(ArrayList<Edge> graph[],int v){
        boolean vis[] = new boolean[v];
        Stack<Integer> stack = new Stack<>();

        for(int i=0; i<v; i++){
            if(!vis[i]){
                topSortUtil(graph, i, vis, stack);
            }
        }

        while(!stack.isEmpty()){
            System.out.print(stack.pop()+" ");
        }
     }

     public static boolean isCycleUndirected(ArrayList<Edge> graph[], boolean vis[],int curr,int par){
        vis[curr] =true;
        for(int i =0; i<graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(vis[e.dest] && e.dest!=par){
                return true;
            }else if(!vis[e.dest]){
                if(isCycleDirected(graph, vis, e.dest, vis))return true;
            }
        }
        return false;
     }
    public static void main(String[] args) {
        printPath(new ArrayList[5], 0, "0", new boolean[5], 5);
    }
}