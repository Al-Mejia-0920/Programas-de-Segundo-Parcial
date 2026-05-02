//Ejercicio 3.1
//Para ejecutar los tres: javac Ejercicio3_1_DatoNuevo_Arreglo/*.java; java Ejercicio3_1_DatoNuevo_Arreglo.Main 
package Ejercicio3_1_DatoNuevo_Arreglo;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("¿Cuántas palabras deseas que pueda almacenar la pila en total? ");
        int total = scanner.nextInt();
        scanner.nextLine();
        
        PCon miPila = new PCon(total);
        int opc;

        do {
            System.out.println("\n=== Menú de Pila Dinámica ===");
            System.out.println("1. Agregar elemento");
            System.out.println("2. Quitar elemento");
            System.out.println("3. Mostrar pila");
            System.out.println("4. Verificar estado (Vacía/Llena)");
            System.out.println("5. Mostrar tamaño actual");
            System.out.println("6. Salir");
            System.out.print("Elige una opción: ");
            opc = scanner.nextInt();
            scanner.nextLine(); 

            switch (opc) {
                case 1:
                    System.out.print("Ingrese la palabra: ");
                    String palabra = scanner.nextLine();
                    miPila.push(palabra);
                    break;
                case 2:
                    miPila.pop();
                    break;
                case 3:
                    miPila.mostrarPila();
                    break;
                case 4:
                    System.out.println("¿Vacía?: " + (miPila.estaVacia() ? "SÍ" : "NO"));
                    System.out.println("¿Llena?: " + (miPila.estaLlena() ? "SÍ" : "NO"));
                    break;
                case 5:
                    System.out.println("Elementos actuales: " + miPila.obtTam());
                    break;
                case 6:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción no válida.");
            }
        } while (opc != 6);

        scanner.close();
    }
}