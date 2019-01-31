package dp;

import java.util.Scanner;

public class sol1463 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		int [] arr = new int[1000001];
		arr[0] = arr[1] = 0;
		arr[2] = 1;
		System.out.println(dp(arr,input));
	}
	
	public static int dp(int[]arr,int n) {
		for (int i = 3; i <=n; i++) {
			arr[i] = arr[i-1]+1;	//하나씩 증가하는 값을 일단 기준점으로 삼는다.
			//2로 떨어진 최소경로수와 1씩 증가해서 얻은 최소 경로 수를 비교한다.
			if(i%2==0) arr[i] = Math.min(arr[i],arr[i/2]+1);	
			//3으로 떨어진 최소경로 수와 1씩 증가해서 얻은 최소경로 수를 비교한다.
			if(i%3==0) arr[i] = Math.min(arr[i], arr[i/3]+1);	
		}
		return arr[n];
	}
}
