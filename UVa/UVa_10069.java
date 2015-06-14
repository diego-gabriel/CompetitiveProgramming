import java.util.*;
import java.math.BigInteger;

public class UVa_10069
{
	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int nTest = scan.nextInt();
		String cad1, cad2;
		scan.nextLine();
		while (nTest != 0)
		{
			nTest--;
			cad1 = scan.nextLine();
			cad2 = scan.nextLine();

			int x = cad2.length() + 1;
			int y = cad1.length() + 1;
			BigInteger nOfSeq[][] = new BigInteger[x][y];

			for (int j = 0; j < y; j++)
				nOfSeq[0][j] = new BigInteger("1");

			for (int i = 1; i < x; i++)
				for (int j = 0; j < y; j++)
					nOfSeq[i][j] = new BigInteger("0");

			for (int i = 1; i < x; i ++)
				for (int j = 1; j < y; j++)
				{
					if (cad1.charAt(j-1) == cad2.charAt(i-1))
						nOfSeq[i][j] = nOfSeq[i-1][j-1].add(nOfSeq[i][j-1]);
					else nOfSeq[i][j] = nOfSeq[i][j-1];

				}

			System.out.println(nOfSeq[x-1][y-1]);

		}
	}
}