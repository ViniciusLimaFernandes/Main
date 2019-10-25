import java.util.*;

public class FreteExpresso{
    
    private double value = 6.75;
    
    public double calculaFreteExpresso(double distance){
        
        double totalvalue = this.value * distance;
        
        return totalvalue;
        
    }
}