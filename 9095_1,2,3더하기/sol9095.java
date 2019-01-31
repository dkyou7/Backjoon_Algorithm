package dp;

import java.util.Scanner;

public class sol9095 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int i = 0; i < tc; i++) {
			int input = sc.nextInt();
			int [] arr= new int [12];
			System.out.println(dp(arr,input));
		}
	}
	public static int dp(int[] arr,int n) {
		arr[1]=1;
		arr[2]=2;
		arr[3]=4;
		for (int i = 4; i <=n; i++) {
			arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
		}
		
		return arr[n];
	}
}
