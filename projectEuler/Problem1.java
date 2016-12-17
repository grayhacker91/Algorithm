
public class Problem1 {
	public static int sum(int a, int b) {
		int result=0;
		for(int i=1; i<1000 ; i++) {
			if(i%a==0 || i%b==0) {
				result+=i;
			}
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(sum(3,5));
	}

}
