/* Metodo com get */

public enum TipoFrete{
    
    COMUM{
        public String toString(){
            return "comum";
        }
    },
    
    EXPRESSO{
        public String toString(){
            return "expresso";
        }
    };

}




/* Metodo comum */


// public enum TiposEnum{
    
//     COMUM("comum"),
    
//     EXPRESSO("expresso");
    
//     private final String text;
    
//     TiposEnum(final String text){
//         this.text = text;
//     }
    
//     @Override
//     public String toString(){
//         return this.text;
//     }
    
    
// }