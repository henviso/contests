import java.util.*;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args){	
		Scanner sc = new Scanner(System.in);
		BigInteger t, w, b, aux;
		t = sc.nextBigInteger();
		w = sc.nextBigInteger();
		b = sc.nextBigInteger();
		if(w.compareTo(b) > 0){
			aux = w;
			w = b;
			b = aux;
		}
		BigInteger m = w.multiply(b).divide(w.gcd(b));
		System.out.println("MMC "+m);
		BigInteger n = t.divide(m).multiply(w).add(w.subtract(BigInteger.valueOf(1)).min(t.remainder(m)));
		BigInteger d = t;
		BigInteger s = n.gcd(d);
		n = n.divide(s); d = d.divide(s);
		System.out.println(n.toString()+"/"+d.toString());
	}
}
