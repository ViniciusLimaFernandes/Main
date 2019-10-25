import java.util.*;

public class main{
    
    public static void main(String [] args){
        
        CalculaFrete frete = new CalculaFrete();
        
        double entregaCasa = frete.calculaFrete(TipoFrete.COMUM,15.75);
        
        System.out.println(entregaCasa);
    }
    
}