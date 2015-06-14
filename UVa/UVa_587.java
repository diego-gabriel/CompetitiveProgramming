import java.util.*;

public class UVa_587{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input;
		int test = 0;
		while (scan.hasNext()){
			input = scan.nextLine();
			if (input.equals("END"))
				break;

			Point res = new Point(0, 0);
			String[] dir = input.split(",");
			test++;
			for (String d : dir){
				res.add(new Point(d));
			}
			String r;
			r = String.format("The treasure is located at (%.3f,%.3f).\n", res.x, res.y);
			System.out.println("Map #" + test);
			System.out.print(r);
			r = String.format("The distance to the treasure is %.3f.\n\n",res.dist());
			System.out.print(r);

		}
	}
}

class Point{
	double x, y;
	public Point(double a, double b){
		x = a;
		y = b;
	}
	public Point(String dir){
		int dist;
		String dig = "";
		String d = "";
		int k = 0;
		x = 0;
		y = 0;
		while (Character.isDigit(dir.charAt(k))){
			dig = dig + dir.charAt(k);
			k++;
		}
		while(k < dir.length() && Character.isLetter(dir.charAt(k))){
			d = d + dir.charAt(k);
			k++;
		}
		if (d.equals("N")){
			y = Integer.parseInt(dig);
			x = 0;
		}
		if (d.equals("S")){
			y = -(Integer.parseInt(dig));
			x = 0;
		}

		if (d.equals("E")){
			x = Integer.parseInt(dig);
			y = 0;
		}
		if (d.equals("W")){
			x = -(Integer.parseInt(dig));
			y = 0;
		}


		if (d.equals("NW")){
			y = Integer.parseInt(dig) / Math.sqrt(2.0);
			x = -Integer.parseInt(dig) / Math.sqrt(2.0);
		}
		if (d.equals("NE")){
			y = Integer.parseInt(dig) / Math.sqrt(2.0);
			x = Integer.parseInt(dig) / Math.sqrt(2.0);
		}
		if (d.equals("SE")){
			y = -Integer.parseInt(dig) / Math.sqrt(2.0);
			x = Integer.parseInt(dig) / Math.sqrt(2.0);
		}
		if (d.equals("SW")){
			y = -Integer.parseInt(dig) / Math.sqrt(2.0);
			x = -Integer.parseInt(dig) / Math.sqrt(2.0);
		}
	}

	public void add(Point a){
		x += a.x;
		y += a.y;
	}

	public double dist(){
		return Math.sqrt(x*x + y*y);
	}
}