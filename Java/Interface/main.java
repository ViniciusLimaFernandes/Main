import java.util.*;

public class main{
    
    public static void main(String [] args){
        
        CalculaFrete frete = new CalculaFrete();
        
        frete.printEntrega(TipoFrete.COMUM,Estados.SAO_PAULO);
        
    }
    
}