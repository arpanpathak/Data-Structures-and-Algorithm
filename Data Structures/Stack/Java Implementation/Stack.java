/** Generic Stack implemented by Arpan Pathak.
 ** Java already has Stack Class in Collection Framework. So please don't import java.util.*  **/
class Stack<T>
{
	Node<T> top=null;
	int size=0;
	void push(T val) { if(top==null) { top=new Node<T>(val,null); size++; return; }
		top=new Node<T>(val,top); size++;
	}
	T pop(){ 
		T v=null;
		try
		{
			if(top==null) throw new Exception("Stack Underflow Exception...");
			v=top.val; top=top.next;
			
		}catch(Exception e)
		{
			System.out.println(e);
		} return v;
	}
	@Override
	public String toString()
	{
		String result=""; Node<T> ptr=top;
		while(ptr!=null) { result+=ptr.val+","; ptr=ptr.next; }
		return result;
	}
}
class Example {
	public static void main(String[] args) {
		Stack<String> s=new Stack<>();
		s.push("Delhi");
		s.push("Chennai");
		s.push("Kolkata");
		System.out.println(s);
		System.out.println(s.pop());
		System.out.println(s);
		s.pop();
		s.pop();
		s.pop();
		System.out.println(s);
	}
}
