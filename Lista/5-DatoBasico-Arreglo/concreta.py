from abstracta import dadlista

class lista(dadlista):
    def agregar(self,n):
        if self.i < 10:
            self.arreglo[self.i] = n
            self.i +=1
            print(f" {n} a sido guardado")
        else: 
            print("----La lista esta llena----")



    def quitar(self):
          
        if self. i > 0:
            eliminado = self.arreglo[self.i - 1]
            self.arreglo[self.i - 1] = None
            self.i -= 1
            print("Eliminado....",eliminado)
        else:
            print("Esta vacio.")
            

    def mostrar(self):

        print("Numeros : ")
        
        for j in range(self.i) :
            print(self.arreglo[j], end=" ")
            print()

        
    def vacia(self):
        return self.i == 0
    
    def tamaño(self):
        return self.i
    
    def llena(self):
        return self.i == 10