import java.util.ArrayList;

public class Problem7 {
	static ArrayList<Integer> primeNumber = new ArrayList<Integer>();
	public static boolean isPrimeNumber(int a) {
		for(int i=0;i<primeNumber.size() ;i++) {
			if(a%primeNumber.get(i)==0) {
				return false;
			}
		}
		return true;
	}
	
	public static int whatIsPrimeNumber(int a) {
		int i=2;
		while(primeNumber.size()!=a) {
			if(isPrimeNumber(i)) {
				primeNumber.add(i);
			}
			i++;
		}
		return primeNumber.get(a-1);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(whatIsPrimeNumber(9000));
	}
}
