package Cpp;

/**
 * Description: TODO
 *
 * @author: ykn
 * @date: 2023年03月19日 18:52
 **/
public class Example {


    public Example() {System.out.println("1111");
    }
    {
//        HashMap
        System.out.println("I妈卖aa");
    }

    String str = new String("hello");
    char[] ch = {'a', 'b'};

    public static void main(String args[]) {
        Example ex = new Example();
        ex.change(ex.str, ex.ch);
        System.out.print(ex.str + " and ");
        System.out.print(ex.ch);
    }

    public void change(String str, char ch[]) {
        str = "test ok";
        ch[0] = 'c';
    }
}
