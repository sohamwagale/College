class Student{
    int rollNo;
    public void setRollNo(int roll){
        rollNo = roll;
    }
    public int getRollNo() {
        return rollNo;
    }
}

class Test extends Student{
    String sub1 = "Maths";
    String sub2 = "Physics";
    int m1;
    int m2;

    public void setMarks(int mm, int pm){
        m1=mm;
        m2=pm;
    }

    public void getMarks(){
        System.out.println("Maths marks : "+m1);
        System.out.println("Physics marks : "+m2);
    }
}

interface Sports{
    int sMarks = 5;
    void setSports();
}

public class Results extends Test implements Sports {
    int sportMarks;
    public void setSports(){
        sportMarks = sMarks;
    }

    @Override
    public void getMarks(){
        System.out.println("Maths marks : "+m1);
        System.out.println("Physics marks : "+m2);
        System.out.println("Sports marks : "+sportMarks);
    }

    public static void main(String[] args) {
        Results s1 = new Results();
        s1.setRollNo(110);
        System.out.println("Marks of roll No : "+s1.getRollNo());
        s1.setMarks(45,49);
        s1.setSports();
        s1.getMarks();
    }
}
