public class ColorFactory extends AbstractFactory {
	Shape getShape(String shape) {
		return null;
	}

	public Color getColor(String color) {
		if(color == null) return null;
		if(color.equalsIgnoreCase("Blue"))
			return new Blue();
		if(color.equalsIgnoreCase("Red"))
			return new Red();
		return null;
	}
}
