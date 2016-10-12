/** Dijkstra's algorithm implemented by Arpan Pathak **/
import java.util.Arrays;

class Graph
{
	private long G[][], PATH[][]; // Adjacency Matrix is Used for Graph Representation
	final long INF=Long.MAX_VALUE;
	int n;
	Graph(int no_of_nodes)
	{
		this.n=no_of_nodes;
		G=new long[n][n];
		for(int i=0;i<n;i++)
			Arrays.fill(G[i], INF);
	}
	void addEdge(int i,int j,int w) { G[i][j]=w; }
	long generateSortestPath(int start_vertex,int destination)
	{
		PATH=new long[n][n+1];
		boolean[] found=new boolean[n];
		Arrays.fill(PATH[0], INF);
		long current_shortest=INF;
		PATH[0][start_vertex]=0; PATH[0][n]=start_vertex; found[start_vertex]=true;
		for(int i=1;i<n;i++)
		{
			current_shortest=INF;
			for(int j=0;j<n;j++)
			{
				if(!found[j])
				{
					int previous=(int) PATH[i-1][n];
					PATH[i][j]=Math.min(PATH[i-1][j], PATH[i-1][previous]+G[previous][j]);
					if(PATH[i][j]<current_shortest)
					{
						current_shortest=PATH[i][j];
						PATH[i][n]=j;
					}
				} else PATH[i][j]=PATH[i-1][j];
			}
			found[(int) PATH[i][n]]=true;
			if(PATH[i][n]==destination)
				return PATH[i][(int)PATH[i][n]];
		}
		return current_shortest;
		
	}
	void printPathMatrix()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n;j++)
				System.out.print("\t"+(PATH[i][j]==INF?"INF":PATH[i][j]));
			System.out.println();
		}
	}
}
class DijkstraShortestPath
{
	public static void main(String[] args) {
		Graph g=new Graph(4);
		g.addEdge(0, 1, 1);
		g.addEdge(0, 3, 5);
		g.addEdge(1, 2, 10);
		g.addEdge(1, 3, 2);
		g.addEdge(3, 2, 1);
		System.out.println(g.generateSortestPath(0, 3));
		g.printPathMatrix();
	}
}
