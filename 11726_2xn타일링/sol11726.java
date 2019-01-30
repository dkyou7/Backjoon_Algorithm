package dp;

import java.util.Scanner;

public class sol11726 {

	static int[] arr= new int[1001];
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int input = sc.nextInt();
		System.out.println(tile(input));
	}
	public static int tile(int n) {
		if(n==1) return 1;
		if(n==2) return 2;
		if(arr[n] != 0) return arr[n];
		return arr[n] = (tile(n-1) + tile(n-2))%10007;
	}
}
