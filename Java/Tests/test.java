import java.util.*;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.sql.Timestamp;

class test{
    public static void main(String [] args){
        Timestamp ts=new Timestamp(1571838870446); 
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");
                Date date=new Date(1571838870446);  
                System.out.println(formatter.format(date));    
    }
    
}