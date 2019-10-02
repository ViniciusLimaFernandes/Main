import java.util.*;

public class MyObj{
    
    private Integer n;
    private String name;
    
    
    public MyObj(String nameInput, Integer nInput){
        this.name = nameInput;
        this.n = nInput;
    }
    
    public String getName(){
        return this.name;
    }
    
    public Integer getN(){
        return this.n;
    }
    
    public void setName(String nameInput){
        this.name = nameInput;
    }
    
    public void setN(Integer nInput){
        this.n = nInput;
    }
}