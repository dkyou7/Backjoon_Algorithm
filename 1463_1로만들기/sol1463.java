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
			arr[i] = arr[i-1]+1;	//�ϳ��� �����ϴ� ���� �ϴ� ���������� ��´�.
			//2�� ������ �ּҰ�μ��� 1�� �����ؼ� ���� �ּ� ��� ���� ���Ѵ�.
			if(i%2==0) arr[i] = Math.min(arr[i],arr[i/2]+1);	
			//3���� ������ �ּҰ�� ���� 1�� �����ؼ� ���� �ּҰ�� ���� ���Ѵ�.
			if(i%3==0) arr[i] = Math.min(arr[i], arr[i/3]+1);	
		}
		return arr[n];
	}
}
