//Ejercicio3
//Para ejecutar los tres: javac Ejercicio3_DatoBasico_Arreglo/*.java; java Ejercicio3_DatoBasico_Arreglo.Main 
package Ejercicio3_DatoBasico_Arreglo;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PCon pila = new PCon();
        int opc;

        do {
            System.out.println("\n=== Menú de Pila ===");
            System.out.println("1. Agregar elemento");
            System.out.println("2. Quitar elemento");
            System.out.println("3. Mostrar pila");
            System.out.println("4. Verificar estado (Vacía/Llena)");
            System.out.println("5. Mostrar tamaño de la pila");
            System.out.println("6. Salir");
            System.out.print("Elige una opción: ");
            opc = scanner.nextInt();
            scanner.nextLine(); 

            switch (opc) {
                case 1:

                    System.out.print("Ingrese una palabra: ");
                    String palabra = scanner.nextLine();
                    pila.push(palabra);
                    break;

                case 2:
                    pila.pop();
                    break;

                case 3:

                    pila.mostrarPila();
                    break;

                case 4:

                    System.out.println("--- Estado de la Pila ---");
                    System.out.println("¿Está vacía?: " + (pila.estaVacia() ? "SÍ" : "NO"));
                    System.out.println("¿Está llena?: " + (pila.estaLlena() ? "SÍ" : "NO"));
                    break;

                case 5:
                    System.out.println("Tamaño actual: " + pila.obtenerTamano());
                    break;

                case 6:
                    System.out.println("Saliendo...");
                    break;
                    
                default:

                    System.out.println("Opción inválida.");
            }
        } while (opc!= 6);

        scanner.close();
    }
}