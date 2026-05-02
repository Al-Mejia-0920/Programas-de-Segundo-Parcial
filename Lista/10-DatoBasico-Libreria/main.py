from concreta import lista

def main():
    L = lista()

    L.agregar(50)
    L.agregar(60)
    L.agregar(70)
    L.agregar(80)
    L.agregar(90)

    while True:
        print("\n---MENU---")
        print("1.Agregar")
        print("2.Quitar")
        print("3.Mostrar")
        print("4.Tamaño")
        print("5.Salir")
        
        opcion = input("Elige una opción: ")

        match opcion:
          case "1":
            n = int(input("Ingresa el numero a agregar: "))
            L.agregar(n)
    
          case "2":
            L.quitar()
            
          case "3":
            L.mostrar()
            
          case "4":
           print("El tamaño de la lista es...",L.tamaño())
            
          case "5":
           print("Saliendo del programa...")
           break

          case _:
           print("Opción no válida.")

main()