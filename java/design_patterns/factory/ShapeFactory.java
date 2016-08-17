public class ShapeFactory {
	public Shape createShape(String type){
		if(type == null) {
			return null;
		}

		if(type.equalsIgnoreCase("Circle")) {
			return new Circle();
		}

		if(type.equalsIgnoreCase("Square")) {
			return new Square();
		}

		return null;
	}
}
