import java.util.*;
import java.math.BigInteger;

class UVa_787{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int value;
		BigInteger[] seq = new BigInteger[100];
		int n;
		while (scan.hasNext()){
			n = 0;

			while ((value = scan.nextInt()) != -999999){
				seq[n] = new BigInteger(""+value);
				n++;
			}

			BigInteger max = new BigInteger("-999999");
			for (int i = 0; i < n; i++){
				BigInteger mul = new BigInteger(""+1);
				for(int j = i; j < n; j++){
					mul = mul.multiply(seq[j]);
					if (mul.compareTo(max) == 1)
						max = mul.multiply(BigInteger.valueOf(1));
				}
			}

			System.out.println(max);
		}
	}
}