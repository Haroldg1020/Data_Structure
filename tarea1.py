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
    contrario.append(listaN[lista:])
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
    casos = int(input())
    for cn_casos in range(0, casos):
        lista = list(str(input()).split(" "))
        lista = lista[1::]
        lista2 = list(str(input()).split(" "))
        lista2 = lista2[1::]

        print(*diferenciaListas(lista, lista2), sep=',')


def diferenciaListas(listaA, listaB):
    aux = []
    for i in listaA:
        if i not in listaB:
            aux.append(i)
        elif i in listaB:
            listaB.remove(i)
    return aux


#lectura()

# Punto 4


def mostrarPrimos(N):
    prim = []
    prim2 = []
    for i in range(2, N + 1):
        if esPrimo(i):
            prim.append(i)
    print("Números primos entre 1 y %d:" % N)
    for nPrim in range(0, len(prim)):
        if nPrim == len(prim)-1:
            print("--> %d" % prim[nPrim])
        else:
            print("--> %d," % prim[nPrim])
    for i in prim:
        numString = str(i)
        sum = 0
        for j in numString:
            sum = sum + int(j)
        if esPrimo(sum):
            prim2.append(i)
    print("Números entre 1 y", str(N), "con suma de dígitos con valor primo")
    print(*prim2, sep=', ')


def esPrimo(i):
    ans = True
    for r in range(2, i):
        if i % r == 0:
            ans = False
    return ans


#mostrarPrimos(100)

# Punto 5

def sumarValoresMatriz(mat, par):
    suma = 0
    for i in mat:
        for j in par:
            if i == j[0]:
                for n in mat[i]:
                    if n[0] == j[1]:
                        suma += n[1]
    return suma


"""
print(sumarValoresMatriz({0: [(0, 1), (5, 4), (7, 5)],
                          1: [(6, 4), (7, 7)],
                          2: [(0, 2), (1, 2), (4, 9), (6, 1)],
                          4: [(2, 8), (3, 1), (5, 7)],
                          6: [(0, 3), (5, 6), (7, 2)],
                          7: [(0, 4), (1, 4), (2, 7)],
                          8: [(1, 9), (3, 8), (5, 7), (7, 6)]}, [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4, 6)]))
"""
