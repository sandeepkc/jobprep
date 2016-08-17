public class SingleObject {
	private static SingleObject instance = new SingleObject();
	
	//Make the constructor private so that the class can't be instantiated
	private SingleObject() {}

	public static SingleObject getInstance() {
		return instance;
	}

	public void showMessage() {
		System.out.println("This message is coming from the show function.\n");
	}
}
