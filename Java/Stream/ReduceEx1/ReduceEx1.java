import java.util.*;
import java.util.Arrays;

class ReduceEx1{

    public static void main(String[] args){
        List<Integer> myList = Arrays.asList(5,5,5,5);
        
        int result = myList.stream().reduce(0,(n1,n2) -> n1+n2);
        int result2 = myList.stream().map(n -> n+5).reduce(0,(n1,n2) -> n1+n2);
        
        System.out.println("Resultado: " + result2);
    }
}