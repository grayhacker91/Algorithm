import java.math.BigInteger;

public class Problem3 {
	public static long factorization(String target) {
		int max = 0;
		BigInteger i = new BigInteger(target);
		int j = 2;
		while(i.equals(BigInteger.ONE)!=true) {
			if(i.mod(BigInteger.valueOf(j)).equals(BigInteger.ZERO)) {
				i = i.divide(BigInteger.valueOf(j));
				if(j>max) {
					max=j;
				}
			}
			else {
				j++;
			}
		}
		return max;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(factorization("600851475143"));
	}

}
