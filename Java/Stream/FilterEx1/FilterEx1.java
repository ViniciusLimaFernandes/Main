import java.util.*;
import java.util.stream.Collectors;

class FilterEx1{
 
    public static void main(String args[]){
        List<String> myList = Arrays.asList("Alface","Tomate","Cebola");
        
        myList = myList.stream().filter(palavra -> palavra.startsWith("A")).collect(Collectors.toList());

        System.out.println(myList);
    }   
}