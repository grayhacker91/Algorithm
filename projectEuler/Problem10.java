
public class Problem10 {
	static boolean[] notPrimeNumber;
	public static void eratos(int a) {
		notPrimeNumber = new boolean[a+1];
		for(int i=2 ; i*i<=a ; i++) {
			for(int j=i*2; j<=a ; j+=i) {
				if(!notPrimeNumber[j]) {
					notPrimeNumber[j]=true;					
				}
			}
		}
	}
	
	public static long sumPrimeNumber(int a) {
		eratos(a);
		long result=0;
		for(int i=2;i<=a;i++) {
			if(!notPrimeNumber[i]) {
				result+=i;
			}
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(sumPrimeNumber(2000000));
	}
}
