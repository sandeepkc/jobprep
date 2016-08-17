public class FactoryDemo {
	public static void main(String[] args) {
		ShapeFactory sF = new ShapeFactory();

		Shape s1 = sF.createShape("circle");
		s1.draw();

		Shape s2 = sF.createShape("square");
		s2.draw();
	}	
}
