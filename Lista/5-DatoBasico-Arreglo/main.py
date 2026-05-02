from concreta import lista

def main():
    L = lista()

    L.agregar(1)
    L.agregar(2)
    L.agregar(3)
    L.agregar(4)
    L.agregar(5)
    L.agregar(6)
    L.agregar(7)

    while True:
        print("----MENU----\n1.Agregar(Maximo 10)\n2.Quitar\n3.Mostrar lista\n4.Verificar si esta vacia\n5.Tamaño de la lista\n6.Salir")
        
        opcion = input("Elige una opcion : ")

        match opcion:
            case "1":
                n = int(input("Ingresa un numero : "))
                L.agregar(n)
            
            case "2":
                L.quitar()
            
            case "3":
                L.mostrar()
            
            case "4":
                print("Esta vacia...",L.vacia())
            
            case "5":
                if L.llena():
                  print("La lista ya esta llena...")
                else: 
                    print("Tamaño : ",L.tamaño())

            case "6":
                print("Adioooooos")
                break

            case _:
                print("Opcion no valida")

    L.mostrar()


main()
