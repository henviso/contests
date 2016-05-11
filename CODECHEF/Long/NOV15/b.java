import java.math.*;
import java.util.*;

class b{
	public static BigInteger ten = BigInteger.valueOf(10);
	public static BigInteger one = BigInteger.valueOf(1);
	public static BigInteger zero = BigInteger.valueOf(0);

	public static BigInteger sum(BigInteger x){
		if(x.compareTo(ten) < 0) return  x;
		String s = x.toString();
		BigInteger ans = BigInteger.valueOf(0);
		for(int i = 0; i<s.length(); i++){
			ans = ans.add(BigInteger.valueOf(s.charAt(i)-'0'));
		}
		return sum(ans);
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in); 
		int t = sc.nextInt();
		StringBuilder ansOut = new StringBuilder();
		while((t-- > 0)){
			BigInteger a = sc.nextBigInteger(), d = sc.nextBigInteger(), l = sc.nextBigInteger(), r = sc.nextBigInteger();
			BigInteger ai = a.add(l.subtract(one).multiply(d));
			
			int INTD = Integer.parseInt(d.toString());
			int idx = Integer.parseInt(sum(ai).toString())-1;
			int table[] = new int[9];
			
			BigInteger cycleval = zero;
			ArrayList<BigInteger> aux = new ArrayList<>();
			while(table[idx] == 0){
				table[idx] = 1;
				cycleval = cycleval.add(BigInteger.valueOf(idx+1));
				aux.add(cycleval);
				idx = (idx+(INTD%9))%9;
			}
			
			BigInteger le = r.add(one).subtract(l);
			BigInteger ans = cycleval.multiply(le.divide(BigInteger.valueOf(aux.size())));
			
			int rem = Integer.parseInt(le.remainder(BigInteger.valueOf(aux.size())).toString())-1;
			if(rem >= 0) ans = ans.add(aux.get(rem));
	
			ansOut.append(ans.toString());
			ansOut.append("\n");
		}
		System.out.println(ansOut);
	}
}
