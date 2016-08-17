class TestClass<A, B, C> {
	A a;
	B b;
	C c;

	public TestClass(A a, B b, C c) {
		this.a = a;
		this.b = b;
		this.c = c;
	} 

	public void printAll() {
	System.out.println("A = " + a + " B = "+ b + " C = " + c);
	}
}

public class ClassTuple {
	public static void main(String[] args) {
		TestClass<Integer, Integer, String> testClass1 = new TestClass<Integer, Integer, String>(3, 4, "sandeep");
		testClass1.printAll();	

		TestClass<Integer, String, String> testClass2 = new TestClass<Integer, String, String>(3, "kumar", "sandeep");
		testClass2.printAll();	

	}
}	
