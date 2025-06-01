
@FunctionalInterface
interface  Student{
    void show();
}


 class S implements Student{

    @Override
    public void show(){
        System.out.println("Hello world");
    }
    
}

@FunctionalInterface
interface  i1{
    void show();
    String toString();
    
}

class A extends Object implements i1{
    public void show(){
        System.out.println("Hello");
    }
}


public class FunctionalInterface1{
    public static void main(String args[]){
        i1 obj = new i1(){  //anonymous inner class
            public void  show(){
                System.out.println("Hello");
            }

        };
        obj.show();

        i1 obj1 = ()->{  // lemda function
            System.out.println("Hello");
        };
    }
}