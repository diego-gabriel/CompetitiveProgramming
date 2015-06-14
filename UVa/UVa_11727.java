import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int a, b, c;
		int n = scan.nextInt();
		for (int test = 1; test <= n; test++){
		
		a = scan.nextInt();
		b = scan.nextInt();
		c = scan.nextInt();

		int res;
		if (a <= b && a <= c)
			res = Math.min(b, c);
		else
		if (b <= a && b <= c)
			res = Math.min(a, c);
		else
		// c es el menor
			res = Math.min(a, b);

		System.out.println("Case " + test + ": " + res);
	}
	}
}