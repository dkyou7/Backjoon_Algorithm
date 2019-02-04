package backjoon;

import java.util.Scanner;

public class sol15988 {

	public static void main(String [] args) {
		Scanner sc= new Scanner(System.in);
		int input = sc.nextInt();
		
		for(int i=0;i<input;i++) {
			int num = sc.nextInt();
			System.out.println(dp(num));
		}
	}
	public static long dp(int n) {
		long [] arr = new long [1000001];
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		for(int i=4;i<=n;i++) {
			arr[i] =(long)(arr[i-1] + arr[i-2] + arr[i-3])%1000000009;
		}
		
		return arr[n]; 
	}
}
