import java.util.*;
import java.math.BigInteger;

public class SPOJ_7186{

	public static BigInteger[] fact;
	public static BigInteger number;
	public static final int MAXFACT = 2020;
	public static void main(String[] args) {
		iniFact();
		Scanner scan = new Scanner (System.in);
		long k;
		//System.out.prlongln(termino(MAXFACT-1, 3));
		while ((k = scan.nextInt()) != -1){
			long pivote = 6;
			long  res = 2*k-3;

			long raux = (long)((1 + Math.sqrt(1+8*k)) / 2);

			if ((raux*(raux+1)) / 2 <= k)
				raux++;

			if (raux > 3)
				res += ((raux-3)*2-1);

			long term = 3;
			number = BigInteger.valueOf(k);
			long low = pivote;
			long high = MAXFACT-1;
			long last, mid;
			//System.out.println("termino = " + termino((int) high, (int) term));

			while (termino((int)pivote, (int)term).compareTo(number) <= 0){
				
				//System.out.prlongln("pivote: "+pivote);

				//System.out.prlongln("ter: "+term);
				while (high - low > 1){
					mid = (low+high) / 2;
					if (p((int)mid, (int)term)){
						low = mid;
					} else
						high = mid;
				}


			//	System.out.prlongln("found: "+low+ " -> "+ termino(low, term));
				while (termino((int)low+1, ((int) term)).compareTo(number) <= 0){
					//System.out.println("actual low = "+low+1);
					low++;
				}
				res += (2*(low-pivote+1)-1);
				term++;
				pivote += 2;
				high = low+1;
				low = pivote;
			}

			System.out.println(res);
		}
	}

	public static boolean p(int n, int k){
		return termino(n, k).compareTo(number) <= 0;
	}

	public static BigInteger termino(int n, int k){
		return fact[n].divide(fact[k].multiply(fact[n-k]));
	}

	public static void iniFact(){
		fact = new BigInteger[MAXFACT];

		fact[0] = BigInteger.ONE;
		for (int i = 1; i < MAXFACT; i++){
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		}
	}
}