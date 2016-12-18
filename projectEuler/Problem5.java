
public class Problem5 {
	public static long lcm(long a, long b) {
		return a*b/gcd(a,b);
	}
	
	public static long gcd(long a, long b){
		if(a<b) {
			long temp=a;
			a=b;
			b=temp;
		}
		if(a%b==0) {
			return b;
		}
		return gcd(b,a%b);
	}
	
	public static long minNumber(int a) {
		long result = 1;
		for(int i=2;i<=a;i++) {
			result=lcm(result,i);
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(minNumber(20));
	}

}
