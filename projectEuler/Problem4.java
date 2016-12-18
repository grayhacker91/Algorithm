import java.util.ArrayList;

public class Problem4 {
	public static int reverseNumber(int a) {
		ArrayList<Integer> number = new ArrayList<Integer>();
		int result=0;
		int mok=a;
		while(mok>0) {
			if(mok>=0) {
				number.add(mok%10);
			}
			mok/=10;
		}
		int exp=1;
		for(int i=number.size()-1;i>-1;i--) {
			result+=(number.get(i)*exp);
			exp*=10;
		}
		return result;
	}
	
	public static boolean isPalindrome(int a) {
		if(reverseNumber(a)!=a) {
			return false;
		}
		return true;
	}
	
	public static int numberOfCase() {
		int result = 0;
		for(int i=999 ; i>99 ; i--) {
			for(int j=i ; j>99 ; j--) {
				if(isPalindrome(i*j) && (i*j)>result) {
					result=i*j;
				}
			}
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(numberOfCase());
	}

}
