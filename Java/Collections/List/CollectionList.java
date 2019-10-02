import java.util.List;
import java.util.ArrayList;

public class CollectionList{
    public static void main(String args[]){
        List<MyObj> lista = new ArrayList<MyObj>();
        
        lista.add(new MyObj("Vinicius",19));
        lista.add(new MyObj("Beatriz", 19));
        
        System.out.println(lista.get(1).getName());
        
    }
}

