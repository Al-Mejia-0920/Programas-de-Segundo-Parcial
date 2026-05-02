from concreta import lista

def main():
    L = lista()

    while True:
        print("---MENU---")
        print("1.Agregar")
        print("2.Quitar")
        print("3.Mostrar lista")
        print("4.¿Esta vacia?")
        print("5.Tamaño")
        print("6.Salir")
        
        opcion = input("\nOpcion: ")

        match opcion:
            case "1":
                name = input("Nombre: ")
                eda = input("Edad: ")
                pes = input("Peso: ")
                L.agregar(name, eda, pes)
            
            case "2":
                L.quitar()
            
            case "3":
                L.mostrar()
            
            case "4":
                print("¿Vacia?:" ,L.vacia())
            
            case "5":
                    print("\nTamaño: ",L.tamaño())

            case "6":
                print("\nAdioooooos")
                break
            
            case _:
                print("\nERROR")

main()