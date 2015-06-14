import java.util.*;
import java.io.*;
public class Main{

	private static int res;
	private static int p;
	private static String cad;

	public static void main(String[] args) throws IOException {


		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
		String buf;
		buf = scan.readLine();
		int nTest, n;
		nTest = Integer.parseInt(buf);
		//System.out.println("nTest: " + nTest);

		for (int test = 1; test <= nTest; test++){
			buf = scan.readLine();
			n = Integer.parseInt(buf);
			Node tree = new Node();
			//System.out.println("test; " + n);
			insertAll(tree);
			res = 0;
			//System.out.println("cant: " + n);
			for (int i = 0; i < n; i++){
			//	if (i % 1000 == 0)
			//	System.out.println("int: " + i);
				cad = scan.readLine();
				cad = cad + "$";
				p = 0;
				insert(tree);
				if (p > cad.length()-1)
					p = cad.length()-1;
				res += p;
			}

			System.out.println("Case #"+test+": "+res);
		}	
	}

	public static void insert(Node nodo){
		for (int i = 0; i < cad.length(); i++){
			char k = cad.charAt(i);
			if (nodo.size() > 0){
				p++;
			}
			nodo = nodo.get(k);
		}
	}

	private static void insertAll(Node n){
		n.insert('a');
		n.insert('b');
		n.insert('c');
		n.insert('d');
		n.insert('e');
		n.insert('f');
		n.insert('g');
		n.insert('h');
		n.insert('i');
		n.insert('j');
		n.insert('k');
		n.insert('l');
		n.insert('m');
		n.insert('n');
		n.insert('o');
		n.insert('p');
		n.insert('q');
		n.insert('r');
		n.insert('s');
		n.insert('t');
		n.insert('u');
		n.insert('v');
		n.insert('w');
		n.insert('x');
		n.insert('y');
		n.insert('z');
	}
}

class Node{
	HashMap<Character, Node> nod;
	public Node(){
		nod = new HashMap<Character, Node>();
	}

	public boolean contains(char k){
		return nod.containsKey(k);
	}

	public int size(){
		return nod.size();
	}

	public Node get(char k){
		if (!nod.containsKey(k))
			nod.put(k, new Node());
		return nod.get(k);
	}

	public void insert(char k){
		nod.put(k, new Node());
	}
}