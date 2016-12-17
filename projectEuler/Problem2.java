
public class Problem2 {
	public static int fibo() {
		int a=1, b=2;
		int result = 2;
		for( ; b <= 4000000 ; ) {
			int prev=a;
			a=b;
			b=prev+b;
			if(b%2==0) {
				result+=b;
			}
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(fibo());
	}

}
