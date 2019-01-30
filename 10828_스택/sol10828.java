package backjoon;

import java.util.EmptyStackException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class sol10828 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt(); sc.nextLine();
		stack st = new stack();
		for (int i = 0; i < input; i++) {
			String ss = sc.nextLine();
			String [] sp = ss.split(" ");
			String cmd = sp[0];
			int num = -1;
			if(cmd.equals("push")) {
				num = Integer.parseInt(sp[1]);
				st.push(num);
			}else if(cmd.equals("top")) {
				System.out.println(st.peek());
			}else if(cmd.equals("size")){
				System.out.println(st.size());
			}else if(cmd.equals("empty")) {
				if(st.isEmpty())
					System.out.println(1);
				else
					System.out.println(0);
			}else if(cmd.equals("pop")) {
				System.out.println(st.pop());
			}
		}
	}

}
class stack{
	class Node<Integer>{
		private int data;
		private Node<Integer> next;
		public Node(int data) {
			this.data = data;
		}
	}
	private Node top;
	public void push(int data) {
		Node tmp = new Node<>(data);
		tmp.next = top;
		top = tmp;
	}
	public int pop() {
		if(top == null)
			return -1;
		Node<Integer> tmp = top;
		top = top.next;
		return (int)tmp.data;
	}
	public int size() {
		int count=0;
		Node tmp = top;
		if(tmp == null) return count;
		while(tmp.next != null) {
			count++;
			tmp = tmp.next;
		}
		return count+1;
	}
	public boolean isEmpty() {
		return top ==null;
	}
	public int peek() {
		if(top == null) return -1;
		return (int)top.data;
	}
}