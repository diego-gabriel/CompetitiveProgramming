import java.math.BigInteger;
import java.util.Scanner;


public class Labelmaker {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		int nTest = scan.nextInt();
		scan.nextLine();
		
		for (int test = 1; test <= nTest; test++)
		{
			String cad = scan.nextLine();
			String[] arr = cad.split(" ");
			
			String alf = arr[0];
			BigInteger num = new BigInteger(arr[1]);

			int[] numCod = solve(num, alf.length());
			String res = "";
			for (int i = 0; i < numCod.length; i++)
				res = "" + alf.charAt(numCod[i]) + res;
			
			System.out.println("Case #" + test + ": " + res);
			
			
			
		}
		
	}
	
	public static int[] solve(BigInteger num , int base)
	{
		BigInteger act = BigInteger.valueOf(base);
		int nBase = 1;
		while (num.compareTo(act) > 0)
		{
			num =  num.subtract(act);
			act = act.multiply(BigInteger.valueOf(base));
			nBase++;
		}

		int[] res = new int[nBase];
		num = num.subtract(BigInteger.ONE);
		
		int i = 0;
		while (!num.equals(BigInteger.ZERO))
		{
			res[i] = num.mod(BigInteger.valueOf(base)).intValue();
			num = num.divide(BigInteger.valueOf(base));
			i++;
		}
		
		return res;
	}

}
