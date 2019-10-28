import java.util.*;
import java.util.Arrays;

class ReduceEx1{

    public static void main(String[] args){
        List<Integer> myList = Arrays.asList(5,5,5,5);
        int numArr[] = {5,2,3,4};
        
        int result = myList.stream().reduce(0,(n1,n2) -> n1+n2);
        Integer result2 = myList.stream().map(n -> n+5).reduce(0,(n1,n2) -> n1+n2);
        
        int aux = 0;
        for(int n: numArr){
            aux += n;
        }
        
        System.out.println("Resultado: " + aux);
    }
}