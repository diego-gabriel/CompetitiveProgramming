import java.util.*;

public class UVa_11947{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int t;
		t = scan.nextInt();
		scan.nextLine();
		for (int test = 1; test <= t; test++){

			String date = scan.nextLine();

			Calendar c = Calendar.getInstance();
			int d, m, y;
			m = (date.charAt(0) - '0')*10 + (date.charAt(1)-'0');
			d = (date.charAt(2) - '0')*10 + (date.charAt(3)-'0');
			y = Integer.parseInt(date.substring(4, 8));

			c.set(y, m-1, d);
			c.add(Calendar.DAY_OF_YEAR, 40*7);
			d = c.get(Calendar.DAY_OF_MONTH);
			m = c.get(Calendar.MONTH)+1;
			y = c.get(Calendar.YEAR);

			String res = test+ " "+(m < 10 ? ("0"+m) : (""+m)) + "/"+ (d < 10 ? ("0"+d) : (""+d)) + "/"+y+ " ";
			String z = "";

			if ((m == 1 && d >= 21) || (m == 2 && d <= 19))
				z = "aquarius";
			if ((m == 2 && d >= 20) || (m == 3 && d <= 20))
				z = "pisces";
			if ((m == 3 && d >= 21) || (m == 4 && d <= 20))
				z = "aries";
			if ((m == 4 && d >= 21) || (m == 5 && d <= 21))
				z = "taurus";
			if ((m == 5 && d >= 22) || (m == 6 && d <= 21))
				z = "gemini";
			if ((m == 6 && d >= 22) || (m == 7 && d <= 22))
				z = "cancer";
			if ((m == 7 && d >= 23) || (m == 8 && d <= 21))
				z = "leo";
			if ((m == 8 && d >= 22) || (m == 9 && d <= 23))
				z = "virgo";
			if ((m == 9 && d >= 24) || (m == 10 && d <= 23))
				z = "libra";
			if ((m == 10 && d >= 24) || (m == 11 && d <= 22))
				z = "scorpio";
			if ((m == 11 && d >= 23) || (m == 12&& d <= 22))
				z = "sagittarius";
			if ((m == 12 && d >= 23) || (m == 1 && d <= 20))
				z = "capricorn";
			System.out.println(res+z);
		}
	}
}