public class ShapeFactory extends AbstractFactory{
	public Shape getShape(String shape) {
		if(shape == null) {
			return null;
		}
			
		if(shape.equalsIgnoreCase("Circle")) {
			return new Circle();
		}

		if(shape.equalsIgnoreCase("Square")) {
			return new Square();
		}

		return null;
	}

	Color getColor(String color) {
		return null;
	}
}
