//Ejercicio 3.1
package Ejercicio3_1_DatoNuevo_Arreglo;

public class PCon extends PBas {
    private String[] pila;
    private int tope;
    private int max; 

    public PCon(int total) {
        this.max = total;
        this.pila = new String[max];
        this.tope = -1;
    }

    @Override
    public void push(String elemento) {
        if (tope < max - 1) {
            pila[++tope] = elemento;
            System.out.println("Palabra \"" + elemento + "\" agregado.");
        } else {
            System.out.println(" La pila llego a su limite.");
        }
    }

    @Override
    public String pop() {
        if (!estaVacia()) {
            System.out.println("La palabra \"" + pila[tope] + "\" eliminado.");
            return pila[tope--];
        } else {
            System.out.println(" La pila está vacía.");
            return null;
        }
    }

    @Override
    public boolean estaVacia() {
        return tope == -1;
    }

    @Override
    public boolean estaLlena() {
        return tope == max - 1;
    }

    @Override
    public void mostrarPila() {
        if (estaVacia()) {
            System.out.println(" La pila está vacía.");
        } else {
            System.out.println("Estado de la pila:");
            for (int i = tope; i >= 0; i--) {
                System.out.println("Lugar " + i + " → " + pila[i]);
            }
        }
    }

    @Override
    public int obtTam() {
        return tope + 1;
    }
}
