/*** TRIE Data Structure for storing keywords
 *   Time Complexity of Inserting, deleting, searching a 
 *   word is O(w), where w is the length of that word
 *   which can be considered as O(1) 
 *   @author arpanpathak                                ***/
import java.util.*;
class Trie {
	// Inner class for Trie Node
	class Node {
		Map<Character,Node> m=new HashMap<>();
		boolean end=false;
		String meaning="";
	}
	Node root=null; // root of trie tree
	public Trie(){
		root=new Node(); // create dummy node
	}
	public void addWord(String word,String meaning) {
		Node cur=root; 
		for(char ch: word.toCharArray()) {
			if(!cur.m.containsKey(ch))
				cur.m.put(ch, new Node() ); // if the current node doesn't have 
											// the character then put that in map
			cur=cur.m.get(ch);
		}
		cur.meaning=meaning;
		cur.end=true;
	}
	public void deleteWord(String word) {
		Node cur=root; 
		for(char ch: word.toCharArray()) {
			if(!cur.m.containsKey(ch))
				break; // the current word is not in the TRIE
			cur=cur.m.get(ch);
		}
		cur.meaning="";
		cur.end=false;
	}
	public String searchWord(String word) throws Exception {
		Node cur=root;
		for(char ch: word.toCharArray()) {
			if(!cur.m.containsKey(ch))
				throw new Exception("Word Not Found!"); // current node doesn't contain the current character
			cur=cur.m.get(ch);
		}
		return cur.meaning;
	}

}
public class TrieExample {
	public static void main(String[] args) throws Exception{
		Trie t=new Trie();
		t.addWord("memory","Capacity of storing information");
		t.addWord("memories", "past experiences");
		System.out.println(t.searchWord("memory"));
		System.out.println(t.searchWord("memories"));
	}
}

