import java.util.*;

public class CalculaFrete implements FreteInterface{
    
    FreteComum comum = new FreteComum();
    FreteExpresso expresso = new FreteExpresso();
    
    public double calculaFrete(TipoFrete tipo, Estados estado){
        
        double distancia = estado.getDistance();

        switch(tipo.toString()){
            case "comum":
                return comum.calculaFreteComum(distancia);    
            case "expresso":
                return expresso.calculaFreteExpresso(distancia);
        }
        
        return 0;
    }
    
    void printEntrega(TipoFrete tipo, Estados estado){
        double frete = calculaFrete(tipo,estado);
        System.out.println("Objeto de São Paulo MATRIZ para " + estado.getDescription());
        System.out.println("Valor do frete = " + frete);
    }
}