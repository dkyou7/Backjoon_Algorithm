package dp;

import java.util.Scanner;

public class sol11727 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		int []arr = new int[1001];
		arr[1]=1;
		arr[2]=3;
		for (int i = 0; i < 3; i++) {
			int n = sc.nextInt();
			System.out.println(dp(arr,n));
		}
	}
	public static int dp(int[]arr,int n) {
		for (int i = 3; i <= n; i++) {
			arr[i] = arr[i-1]+2*arr[i-2];
			arr[i]%=10007;
		}
		return arr[n];
	}
}
