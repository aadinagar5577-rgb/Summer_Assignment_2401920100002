interface Test {
    int square(int x);
}

class Arithmetic implements Test {

    public int square(int x) {
        return x * x;
    }
}

public class ToTestInt {

    public static void main(String[] args) {

        Arithmetic a = new Arithmetic();

        System.out.println("Square of 5 = " + a.square(5));
        System.out.println("Square of 10 = " + a.square(10));
    }
}
