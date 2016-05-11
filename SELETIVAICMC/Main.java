import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String [] ars){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0){
			BigInteger x = sc.nextBigInteger();
			System.out.println(x.bitCount());
			t--;
		}
	}
}
