
public class Problem9 {
	public static int multiPytha(int a, int b) {
		return (a*b)*(((b*b)-(a*a))/2)*(((b*b)+(a*a))/2);
	}
	
	public static int sumPytha(int a, int b) {
		return (a*b)+(((b*b)-(a*a))/2)+(((b*b)+(a*a))/2);
	}
	
	public static int pythagorasNumber(int a) {
		int result=0;
		boolean flag=true;
		for(int i=1; flag ; i+=2) {
			for(int j=i+2 ; flag ; j+=2) {
				int sum=sumPytha(i,j);
				if(sum==a) {
					result=multiPytha(i,j);
					flag=false;
				}
				else if(sum>1000) {
					break;
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(pythagorasNumber(1000));
	}
}
