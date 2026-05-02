from abstracta import dadlista

class Persona:
    def __init__(self, nombre, edad, peso):
        self.nombre = nombre
        self.edad = edad
        self.peso = peso

class lista(dadlista):

    def __init__(self):
        super().__init__()

    def agregar(self, n, e, p):
        if len(self.arreglo) < 10:
            nueva_persona = Persona(n, e, p)
            self.arreglo.append(nueva_persona)
            print("\nSe ha agregado a la lista")
        else: 
            print("\nLista llena...")

    def quitar(self):
        if len(self.arreglo) > 0:
            eliminado = self.arreglo.pop()
            print("\nSe ha eliminado... ",eliminado.nombre)
        else:
            print("\nNo hay nadie para eliminar")

    def mostrar(self):
    
        for i in range(len(self.arreglo)):
                p = self.arreglo[i]
                print("Nombre : ",p.nombre)
                print("Edad : ",p.edad)
                print("Peso : ",p.peso)

    def vacia(self):
        return len(self.arreglo) == 0
    
    def tamaño(self):
        return len(self.arreglo)
    
    def llena(self):
        return len(self.arreglo) == 10