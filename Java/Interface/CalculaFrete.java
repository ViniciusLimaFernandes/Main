import java.util.*;

public class CalculaFrete implements FreteInterface{
    
    FreteComum comum = new FreteComum();
    FreteExpresso expresso = new FreteExpresso();
    
    public double calculaFrete(TipoFrete tipo, double distancia){

        switch(tipo.toString()){
            case "comum":
                return comum.calculaFreteComum(distancia);    
            case "expresso":
                return expresso.calculaFreteExpresso(distancia);
        }
        
        return 0;
    }
}