import java.util.*;
import java.util.Arrays;
import java.util.stream.Collectors;


class ForEachEx1{
    
    public static void main(String args[]){
        List<Integer> myList = Arrays.asList(2,3,4,4,8);
        
        // myList = myList.stream().map(n -> n*2).collect(Collectors.toList());
        myList.stream().sorted(Comparator.reverseOrder()).forEach(num -> System.out.println(String.format("message:%s" , num+1)));
        
        
    }
}