import java.io.*;

class Geek {
    
    Geek(String name){
        System.out.println("Constructor with one "
                           + "argument - String : " + name);
    }
    Geek(String name, int age){
        System.out.println(
            "Constructor with two arguments : "
            + " String and Integer : " + name + " " + age);
    }

    Geek(long id){
        System.out.println(
            "Constructor with one argument : "
            + "Long : " + id);
    }
}

class GFG {
    public static void main(String[] args){
     
        Geek geek2 = new Geek("Shikhar");

        Geek geek3 = new Geek("Dharmesh", 26);

        Geek geek4 = new Geek(325614567);
    }
}
