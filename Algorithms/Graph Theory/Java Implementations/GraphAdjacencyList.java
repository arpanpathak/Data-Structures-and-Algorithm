/**Generic Graph Data Structure using Adjacency List, implemented by Arpan Pathak **/
import java.util.*;
class Edge<T,K>
{
	public T v;   K w;
	public Edge(T vertex,K weight) { v=vertex; w=weight; }
}
class GraphList<T,V>
{
	Map<T, List< Edge<T,V>> > G;
	GraphList()
	{
		G=new HashMap<T, List<Edge<T,V>> >();
	}
	void addEdge(T u,T v,V weight)
	{
		if(!G.containsKey(u))
			G.put(u, new LinkedList<Edge<T,V>>() );
		G.get(u).add(0, new Edge<T,V>(v,weight));
	}
	void display()
	{
		for(T vertex: G.keySet())
		{
			System.out.print(vertex+"=>");
			for(Edge<T,V> iterator: G.get(vertex))
				System.out.print("("+iterator.v+","+iterator.w+"),");
			System.out.println();
		}
	}
}
public class GraphAdjacencyList {
	public static void main(String[] args) {
		GraphList<String,Integer> g=new GraphList<>();
		g.addEdge("Delhi", "Kolkata", 80);
		g.addEdge("Delhi", "Channai", 23);
		g.addEdge("Kolkata", "Delhi", 50);
		g.display();
	}
}
