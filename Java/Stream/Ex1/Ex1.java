import java.util.*;
import java.util.stream.Collectors;

class Ex1{
    
    public static void main (String[] args) {
        
        List<Integer> myList = Arrays.asList(3,4,4,2,1);
        
        List<Integer> result = myList.stream().filter(n -> { System.out.println("Filtrando: " + n);
            return n % 2 == 0;
        }).map(n -> { System.out.println("Mapeando o numero: " + n); 
            return n*n;
        }).collect(Collectors.toList());
        
        System.out.println("Resultado: " + result);
    }
    
}