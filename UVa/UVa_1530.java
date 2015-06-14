import java.util.*;

public class UVa_1530{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String cad;
		System.out.println("Program 6 by team X");
		while (scan.hasNext()){
			cad = scan.nextLine();

			int exp = 0;
			int mantisa = 0;
			boolean sign = cad.charAt(0) == '1';

			for (int i = 1; i < 8; i++){
				exp = exp<<1;
				if (cad.charAt(i) == '1')
					exp = exp | 1;
			}
			
			for (int i = 8; i < 16; i++){
				mantisa = mantisa<<1;
				if (cad.charAt(i) == '1')
					mantisa = mantisa | 1;
			}
			double res = 0.0;
			if (mantisa == 0 && exp == 0){
				System.out.print(" ");
			}
			else {
				double mant = 1.0;

				for (int i = 8; i < 16; i++){
					if (cad.charAt(i) == '1')
						mant += Math.pow(2, 7-i);
				}

				res = mant * Math.pow(2, exp-63);
				if (sign)
					System.out.print("-");
				else
					System.out.print(" ");
			}
			String resC = String.format("%.6e", res);
			for (int i = 0; i < resC.length(); i++){
				if (resC.charAt(i) == ',')
					System.out.print('.');
				else
					System.out.print(resC.charAt(i));
				if (resC.charAt(i) == '+' || resC.charAt(i) == '-'){
					System.out.print('0');
				}
			}
			System.out.println();
		}

		System.out.println("End of program 6 by team X");
	}
}