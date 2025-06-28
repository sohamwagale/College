abstract class Shape{
    double dim1,dim2;
    Shape(double dim1,double dim2){
        this.dim1=dim1;
        this.dim2=dim2;
    }
    abstract int area();
}

class Rectangle{
    Rectangle(double length, double breadth){
        super(length,breadth);
    }
    double area(){
        return (dim1*dim2) ;
    }
}

class Triangle{
    Triangle(double height, double base){
        super(height,base);
    }
    double area(){
        return (1/2)*dim1*dim2 ;
    }
}

public class ShapeArea {
    public static void main(String[] args) {
        Shape s;
        Rectangle r1 = new Rectangle(10, 20);
        s=r1;
        System.out.println(s.area());
        
        Triangle t1 = new Triangle(10,15);
        System.out.println(t1.area());
    }
}
