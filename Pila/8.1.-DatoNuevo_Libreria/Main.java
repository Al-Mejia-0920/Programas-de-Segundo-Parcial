//Ejercicio8.1
//Para ejecutar los tres: javac Ejercicio8_1_DatoNuevo_Libreria/*.java; java Ejercicio8_1_DatoNuevo_Libreria.Main 
package Ejercicio8_1_DatoNuevo_Libreria;
import java.util.Scanner;

public class Main{
    public static void main(String[] libre){
    Scanner scanner = new  Scanner(System.in);

    System.out.print("¿Cuántas palabras deseas que pueda almacenar la pila en total? ");
        int total = scanner.nextInt();
        scanner.nextLine();
        LBas miPila = new LCon(total);
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

        switch(opc){

            case 1:
                System.out.print("Ingrese una palabra: ");
                    String plbra = scanner.nextLine();
                    miPila.push(plbra);
                break;

            case 2:
                miPila.pop();
            break;

            case 3:
                miPila.mostrar();
                break;

            case 4:
                System.out.println("--- Estado de la Pila ---");
                    System.out.println("¿Está vacía?: " + (miPila.vacia() ? "SÍ" : "NO"));
                    System.out.println("¿Está llena?: " + (miPila.llena() ? "SÍ" : "NO"));
                break;

            case 5:
                System.out.println("Tamaño actual: " + miPila.obtenerTamano());
            break;

            case 6:
                System.out.println("Saliendo...");
                break;

                default:
                System.out.println("Opción inválida.");
            } 
        } while (opc!=6);
    }
}
