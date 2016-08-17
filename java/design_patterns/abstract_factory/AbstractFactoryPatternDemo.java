public class AbstractFactoryPatternDemo {
	public static void main(String[] args) {
		FactoryProducer fP = new FactoryProducer();
      		AbstractFactory shapeFactory = fP.getFactory("SHAPE");
    		Shape shape1 = shapeFactory.getShape("CIRCLE");
   		shape1.draw();
      
     		Shape shape3 = shapeFactory.getShape("SQUARE");
  		shape3.draw();
     
        	AbstractFactory colorFactory = fP.getFactory("COLOR");
      		Color color1 = colorFactory.getColor("RED");
     		color1.fill();
    		Color color3 = colorFactory.getColor("BLUE");
		color3.fill();
	}
}
