"""
Harold David Guerrero Caicedo
8976203
tarea 1
Estructuras de datos
"""


# Punto 1

def verificarDiagonales(mat):
    ans = True
    diagonalPrincipal = []
    diagonalSecundaria = []
    cont = 0
    cont2 = len(mat[0])-1
    for i in (mat):
        diagonalPrincipal.append(i[cont])
        cont += 1
        diagonalSecundaria.append(i[cont2])
        cont2 -= 1
    if diagonalPrincipal == diagonalSecundaria:
        ans = True
    else:
        ans = False
    
    return ans

"""
print(verificarDiagonales (
    [[11, 23, 76, 34, 11],
    [14, 30, 92, 30, 101],
    [12, 45, 58, 92, 22],
    [74, 56, 49, 56, 100],
    [99, 5, 28, 47, 99]]
    ))
"""

# Punto 2

def esCapicua(listaN):
    derecho = []
    contrario = []
    ans = True
    lista = len(listaN)//2
    derecho.append(listaN[lista::-1])
    print(derecho)
    contrario.append(listaN[lista:])
    print(contrario)
    if derecho == contrario:
        ans = True
    else:
        ans = False

    return ans
    

#print(esCapicua(([42, 12, 90, 1, 90, 12, 4])))

# Punto 3
# A
def diferenciaListas(listaA, listaB):
    aux = []
    for i in listaA:
        if i not in listaB:
            aux.append(i)
        elif i in listaB:
            listaB.remove(i)
    return aux
        

#print(diferenciaListas([41, 22, 31, 15, 13, 12, 33, 19],[40, 10, 22, 12, 33, 33, 33]))

# B

def lectura():
    cant = int(input())
    n = int(input())
    datos = int(input())
    aux = []
    print(cant)
    print(n)
    if n == int:
        
    print(aux)

lectura()
# Punto 4
"""
def mostrarPrimos(N):
    

mostrarPrimos(100)
"""