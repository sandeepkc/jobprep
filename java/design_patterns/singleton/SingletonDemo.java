public class SingletonDemo {
	public static void main(String[] main) {
		SingleObject sO = SingleObject.getInstance();
		
		sO.showMessage();
	}
}
