import java.util.*;

public class UVa_11356{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		scan.nextLine();
		HashMap <String, Integer> mes = new HashMap <>();
		HashMap <Integer, String> mes2 = new HashMap <>();

		mes.put("January", 1);
		mes.put("February", 2);
		mes.put("March", 3);
		mes.put("April", 4);
		mes.put("May", 5);
		mes.put("June", 6);
		mes.put("July", 7);
		mes.put("August", 8);
		mes.put("September", 9);
		mes.put("October", 10);
		mes.put("November", 11);
		mes.put("December", 12);

		mes2.put(1, "January");
		mes2.put(2, "February");
		mes2.put(3, "March");
		mes2.put(4, "April");
		mes2.put(5, "May");
		mes2.put(6, "June");
		mes2.put(7, "July");
		mes2.put(8, "August");
		mes2.put(9, "September");
		mes2.put(10, "October");
		mes2.put(11, "November");
		mes2.put(12, "December");
		int t = 0;
		while (n > 0){
			n--;
			t++;
			String date = scan.nextLine();
			int dif = scan.nextInt();
			if (scan.hasNext())
				scan.nextLine();

			String[] cad = date.split("-");
			int d, y, m;
			d = Integer.parseInt(cad[2]);
			m = mes.get(cad[1]);
			y = Integer.parseInt(cad[0]);

			Calendar c = Calendar.getInstance();

			c.set(y, m-1, d);
			c.add(Calendar.DAY_OF_YEAR, dif);

			d = c.get(Calendar.DAY_OF_MONTH);
			m = c.get(Calendar.MONTH)+1;
			y = c.get(Calendar.YEAR);

			String res ="Case "+ t+ ": "+ y+"-"+mes2.get(m)+"-"+(d < 10 ? ("0"+d) : (""+d));
			System.out.println(res);
			
		}
	}
}