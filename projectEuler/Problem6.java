
public class Problem6 {
	public static int square(int a) {
		return a*a;
	}
	
	public static int sumSquare(int a) {
		return square((a*(a+1))/2);
	}
	
	public static int squareSum(int a) {
		int result=0;
		for(int i=1;i<=a;i++) {
			result+=square(i);
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(sumSquare(100)-squareSum(100));
	}

}
