interface Shape {
    float area(float dim1,float dim2);
}

class Rectangle implements Shape{
    public float area(float length,float breadth){
        return length*breadth;
    }
}

class Traingle implements Shape{
    public float area(float base, float height){
        return 0.5f*base*height;
    }
}

public class Area {
    public static void main(String[] args) {
        Shape t1 = new Traingle();
        System.out.println("Area of Triangle : "+t1.area(10, 20));
        Shape r1 = new Rectangle();
        System.out.println("Area of Rectangle : "+r1.area(20,30));
    }
}
