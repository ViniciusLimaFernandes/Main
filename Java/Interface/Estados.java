public enum Estados{
    SAO_PAULO(15.75, "São Paulo"),
    RIO_DE_JANEIRO(22.13, "Rio de Janeiro");
    
    private double distance;
    private String description;
    
    Estados(double distance, String description){
        this.distance = distance;
        this.description = description;
    }
    
    public double getDistance(){
        return this.distance;
    }
    
    public String getDescription(){
        return this.description;
    }

}