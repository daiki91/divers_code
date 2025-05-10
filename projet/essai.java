public class essai{
    
    public static void main(String[] args) {
        int a = 1;
        int v=3 ;
        byte b=2;
        System.out.println("a = "+ a + "; v= "+v);
        v=99 ;
        a=v++;
        b +=3;
        System.out.println("a = "+ a + "; v= "+v+" ;b=" +b);
        // b=b +3; ca ne marche pas
         b=(byte)(a+3); 

        System.out.println("a = "+ a + "; v= "+v+" ;b=" +b);
    }
}