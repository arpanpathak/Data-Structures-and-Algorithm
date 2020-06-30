/***
 * Implementation of AVL Tree
 * Time complexity for insertion, deletion, searching is O(log N)
 * 
 * @author Arpan Pathak
 */

// AVL Tree Node
class Node {
	
	int key, height = 0;
	
	Node left =null, right = null;
	
	public Node(int key) {
		this.key = key;
	}	
		
}

public class AVLTree {

	// Property to store Root of AVL tree
	private Node root = null;
	
	/**
	 * Insert value to AVL Tree
	 * @param key
	 */
	public void insert(int key) {
		root = insert(root, key);
	}
	
	/**
	 * Public method for inorder traversal
	 */
	public void inorder() {
		inorder(root);
	}
	
	/**
	 * Private method to get the height of the current node
	 * 
	 * @param t reference to current tree node
	 * 
	 * @return height of the current node
	 */
	private int height(Node t) {
		if (t == null ) 
			return 0;
		
		return t.height;
	}
	
	/**
	 * Calculate the balance factor of current node
	 * @param t tree node
	 * 
	 * @return balance factor
	 */
	private int balanceFactor(Node t) {
		if (t == null)
			return 0;
		return height(t.left) - height(t.right);
	}
	
	// 		   x							             y
	//      /   \							          / \
	//      T1   y     Left Rotation	 x	T3
	// 			/ \    - - - - - - - >	  / \
	// 		   T2  T3					         T1  T2
	private Node leftRotate(Node x) {
		
		Node y = x.right;
	    Node T2 = y.left;
	    y.left = x;
	    x.right = T2;
	    x.height = Math.max(height(x.left), height(x.right)) + 1;
	    y.height = Math.max(height(y.left), height(y.right)) + 1;
	    return y;
	}
	
	//     y                              x
	//    / \     Right Rotation        /  \
	//   x   T3   - - - - - - - >     T1    y 
	//  / \       				            / \
	// T1  T2     				           T2  T3
	private Node rightRotate(Node y) {
		
		Node x = y.left;
	    Node T2 = x.right;
	    x.right = y;
	    y.left = T2;
	    y.height = Math.max(height(y.left), height(y.right)) + 1;
	    x.height = Math.max(height(x.left), height(x.right)) + 1;
	    return x;
	}
	
	/**
	 * Private method to insert key to tree
	 * 
	 * @param tree root node of the tree
	 * @param key key to be inserted
	 * 
	 * @return inserted node
	 */
	private Node insert(Node tree, int key) {
		
		if (tree == null) {
			return new Node(key);
		}
		
		// Search and insert just like BST then Ajust height using rotation
		if (key < tree.key) 
			tree.left = insert(tree.left, key);
		else if(key > tree.key)
			tree.right = insert(tree.right, key);
		else 
			return tree;
		
		// Calculate the new height
		tree.height = 1 + Math.max(height(tree.left), height(tree.right));
		
		// Get the balance factor for the current node
		int balanceFactor = balanceFactor(tree);
		
		// Left heavy tree
		if (balanceFactor > 1) {
			if (key < tree.right.key)
				return rightRotate(tree);
			else if(key > tree.right.key) { // L-R Rotation
				tree.left = leftRotate(tree.left);
				return rightRotate(tree);
			}
		} 
		// Right heavy tree
		else if (balanceFactor < -1) {
			if ( key > tree.right.key) {
				return leftRotate(tree);
			} // R-L Rotation
			else if(key < tree.right.key)  {
				tree.right = rightRotate(tree.right);
				
				return leftRotate(tree);
			}
		}
		
		return tree;
	}
	
	/**
	 * Private method for inorder traversal
	 * 
	 * @param tree root of the tree
	 */
	private void inorder(Node tree) {
		if ( tree == null ) 
			return;
		
		inorder(tree.left);
		System.out.print(tree.key + " ");
		inorder(tree.right);
		
	}
	
	/**
	 * Driver function to test the code
	 * 
	 * @param args command line arguments
	 */
	public static void main(String[] args) {
		AVLTree tree = new AVLTree();
		tree.insert(10); 
		tree.insert(2);
		tree.insert(37);
		tree.insert(12);
		tree.insert(15);
		tree.insert(25);
		tree.insert(1);
		tree.insert(7);
		
		tree.inorder();
	}
}
