/** Depth First Search Algorithm .. @author: Arpan Pathak **/
import java.util.*;
class Edge<T,K>
{
	public T v;   K w;
	public Edge(T vertex,K weight) { v=vertex; w=weight; }
}
class GraphAdjacencyList<T,V>
{
	Map<T, List< Edge<T,V>> > G;
	Map<T,Boolean> visited=new HashMap<>(); // keep track of all visited vertices
	GraphAdjacencyList()
	{
		G=new HashMap<T, List<Edge<T,V>> >();
	}
	void addEdge(T u,T v,V weight)
	{
		if(!G.containsKey(u))    G.put(u, new LinkedList<Edge<T,V>>() );
		G.get(u).add(0, new Edge<T,V>(v,weight));
		visited.put(u, false);   visited.put(v, false);
	}
	void DFS_Recursive(T start_vertex)
	{
		System.out.print(start_vertex+",");
		visited.put(start_vertex, true);
		if(!G.containsKey(start_vertex)) return; // to avoid NullPointerException
		for(Edge<T,V> iterator: G.get(start_vertex))
			if(!visited.get(iterator.v)) DFS_Recursive(iterator.v);	
	}
}
public class DepthFirstSearch {
	public static void main(String[] args) {
		GraphAdjacencyList<String,Integer> G=new GraphAdjacencyList<>();
		G.addEdge("A", "D", 1);
		G.addEdge("A", "B", 1);
		G.addEdge("B", "C", 1);
		G.addEdge("D", "E", 1);
		G.DFS_Recursive("A");
	}
}
