from abstracto import dadlista

class lista(dadlista):

    def __init__(self):
        super().__init__()

    def agregar(self, n):
        if len(self.arreglo) < 10:
            self.arreglo.append(n) 
            print("Se ha guardado el numero : ",n)
        else:
            print("Lista llena")

    def quitar(self):
        if len(self.arreglo) > 0:
            eliminado = self.arreglo.pop() 
            print("Se ha eliminado el : ",eliminado)
        else:
            print("Ya no hay nada")

    def mostrar(self):
        if len(self.arreglo) == 0:
            print("Vacio")
        else:
            print("Lista:", self.arreglo)

    def tamaño(self):
        return len(self.arreglo)