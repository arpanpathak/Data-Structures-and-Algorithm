/** Disjoint Set using union Find Data Structure 										**/
/** Time Complexity for insertions is O(1),union and find takes O(alpha(N)) Time 		**/
/** @author: Arpan Pathak																**/
import java.util.*;
class DisjointSets<T>
{
	private class Node<T>
	{
		public T parent; int rank=0;
		Node(T parent) { this.parent=parent; }
	}
	Map<T,Node<T>> disjoint;
	DisjointSets(){ disjoint=new HashMap<>(); }
	void add(T v) { disjoint.put(v,new Node<T>(v)); }
	T find(T v)
	{
		T parent=disjoint.get(v).parent;
		return parent==v?v:find(parent);
	}
	void union(T u,T v) // union by Rank
	{
		T parent1=find(u),parent2=find(v);
		if(disjoint.get(parent1).rank>disjoint.get(parent2).rank){
			disjoint.put(parent2,new Node<T>(parent1));
			disjoint.get(parent1).rank++;
		}
		else{ 
			disjoint.put(parent1,new Node<T>(parent2));
			disjoint.get(parent2).rank++;
		}
	}
	@Override
	public String toString()
	{
		String result="";
		for(T key: disjoint.keySet())
			result+=key+"=>"+disjoint.get(key).parent+"("+disjoint.get(key).rank+")\n";
		return result;
	}
}
public class UnionFind {
	public static void main(String[] args) {
		DisjointSets<String> s=new DisjointSets<>();
		s.add("A");
		s.add("B");
		s.add("C");
		s.add("D");
		s.union("A", "B");
		s.union("A", "C");
		s.union("C", "D");
		System.out.println(s);
	}
}