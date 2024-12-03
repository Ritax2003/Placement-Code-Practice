import java.io.*;

class Geek {
 
    String name;
    int id;

    Geek(String name, int id){
        this.name = name;
        this.id = id;
    }  
    Geek(Geek obj2){
        this.name = obj2.name;
        this.id = obj2.id;
    }
}
class GFG {
    public static void main(String[] args){  
        System.out.println("First Object");
        Geek geek1 = new Geek("Avinash", 68);
        System.out.println("GeekName :" + geek1.name
                           + " and GeekId :" + geek1.id);

        System.out.println();
        Geek geek2 = new Geek(geek1);
        System.out.println(
            "Copy Constructor used Second Object");
        System.out.println("GeekName :" + geek2.name
                           + " and GeekId :" + geek2.id);
    }
}
