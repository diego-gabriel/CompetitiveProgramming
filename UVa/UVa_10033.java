import java.util.*;

public class UVa_10033{
	public static void main(String[] args) {

	Scanner scan;
		scan  = new Scanner(System.in);
		int test = Integer.parseInt(scan.nextLine());
		scan.nextLine();
		for (int t = 0; t < test; t++){

			String[] ram = new String[1001];
			int[] reg = new int[11];
			String cad;
			int i = 0;

			for (int k = 0; k < 1001; k++)
				ram[k] = "000";

			while (scan.hasNext()){
				ram[i] = scan.nextLine();
				if (ram[i].equals(""))
					break;
				i++;
			}
		//	System.out.println("lala");
			int res = 0;
			i = 0;
			while (true){
				res++;
				if (ram[i].equals("100"))
					break;
				int o, d, n;
				o = Integer.parseInt(""+ram[i].charAt(0));
				d = Integer.parseInt(""+ram[i].charAt(1));
				n = Integer.parseInt(""+ram[i].charAt(2));

				switch(o){
					case 2:{
						reg[d] = n;
					} break;
					case 3:{
						reg[d] += n;
						reg[d] %= 1000;
					} break;
					case 4:{
						reg[d] *= n;
						reg[d] %= 1000;
					} break;
					case 5:{
						reg[d] = reg[n];
					} break;
					case 6:{
						reg[d] += reg[n];
						reg[d] %= 1000;
					} break;
					case 7:{
						reg[d] *= reg[n];
						reg[d] %= 1000;
					} break;
					case 8:{
						reg[d] = Integer.parseInt(ram[reg[n]]);
					} break;
					case 9:{	
						ram[reg[n]] = (""+(reg[d]));
					} break;
					case 0:{
						if (reg[n] != 0){
							i = reg[d];
							i--;
						}
					} break;
				}
				i++;
			}
			System.out.println(res);
			if (t < test-1)
				System.out.println();

		}

	}
}