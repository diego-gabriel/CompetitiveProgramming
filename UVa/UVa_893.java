import java.util.*;

class UVa_893{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		while(scan.hasNext()){
			int n, year, month, day;
			n = scan.nextInt();
			day = scan.nextInt();
			month = scan.nextInt();
			year = scan.nextInt();

			if (n != 0 && year != 0 && day != 0 && month != 0){
				GregorianCalendar calendar = new GregorianCalendar(year, month, day);
				calendar.add(GregorianCalendar.DAY_OF_YEAR, n);
				System.out.println(calendar.get(GregorianCalendar.DAY_OF_MONTH) + " " + calendar.get(GregorianCalendar.MONTH) + " " + calendar.get(GregorianCalendar.YEAR));
			}
		}
	}
}