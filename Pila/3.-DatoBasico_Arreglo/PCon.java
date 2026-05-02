//Ejercicio3
package Ejercicio3_DatoBasico_Arreglo;

public class PCon extends PBas {
    private String[] pila;
    private int pos;
    private final int limit = 10;

    public PCon() {
        pila = new String[limit];
        pos = -1;
    }

    @Override
    public void push(String elemento) {
        if (pos < limit - 1) {
            pila[++pos] = elemento;
            System.out.println("Palabra \"" + elemento + "\" agregada a la pila.");
        } else {
            System.out.println(" La pila está llena.");
        }
    }

    @Override
    public String pop() {
        if (!estaVacia()) {
            System.out.println("La palabra \"" + pila[pos] + "\" eliminado de la pila.");
            return pila[pos--];
        } else {
            System.out.println("La pila está vacía.No hay mas elementos.");
            return null;
        }
    }

    @Override
    public boolean estaVacia() {
        return pos == -1;
    }

    @Override
    public boolean estaLlena() {
        return pos == limit - 1;
    }

    @Override
    public void mostrarPila() {
        if (estaVacia()) {
            System.out.println("La pila está vacía.");
        } else {
            System.out.println("Estado de la pila:");
            for (int i = pos; i >= 0; i--) {
                System.out.println("Lugar " + i + " → " + pila[i]);
            }
        }
    }

    @Override
    public int obtenerTamano() {
        return pos + 1;
    }
}