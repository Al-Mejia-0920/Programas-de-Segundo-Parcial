//Ejercicio8
package Ejercicio8_DatoBasico_Libreria;
import java.util.Stack; 

public class LCon implements LBas {
    private Stack<String> pilaInterna; 
    private final int limite = 10;

    public LCon() {
        pilaInterna = new Stack<>(); 
    }

    @Override
    public void push(String elemet) {
        if (pilaInterna.size() < limite) {
        pilaInterna.push(elemet);
        System.out.println("Palabra \"" + elemet + "\" agregada a la pila.");
        } else {
            System.out.println("La pila está llena.");
        }
    }

    @Override
    public String pop(){
    String sacad;
    if(pilaInterna.size()>0){
        sacad=pilaInterna.pop();
        System.out.println("La palabra \"" + sacad + "\" eliminado de la pila.");
        return sacad;
    }else{
        System.out.println("La pila está vacía. No hay más elementos.");
        return null;
        }
    }
    @Override 
    public boolean vacia(){
    return pilaInterna.size() == 0;
    }
    @Override
    public boolean llena(){
        return pilaInterna.size() == limite;
    }
    @Override
    public int obtenerTamano(){
        return pilaInterna.size();
    }
    @Override
    public void mostrar(){
        if(vacia()){ 
            System.out.println("Pila esta vacia");
        }else{
            System.out.println(pilaInterna);
        }

    }
}