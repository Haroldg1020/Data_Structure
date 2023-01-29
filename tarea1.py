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
    cases = int(input())
    for cn_cases in range(0, cases):
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


lectura()
# Punto 4


def mostrarPrimos(N):
    is_prim = []
    is_prim2 = []
    for i in range(2, N + 1):
        if is_prime(i):
            is_prim.append(i)
    print("Números primos entre 1 y %d:" % N)
    for n_prim in range(0, len(is_prim)):
        if n_prim == len(is_prim)-1:
            print("--> %d" % is_prim[n_prim])
        else:
            print("--> %d," % is_prim[n_prim])
    for i in is_prim:
        num_string = str(i)
        sum = 0
        for j in num_string:
            sum = sum + int(j)
        if is_prime(sum):
            is_prim2.append(i)
    print("Números entre 1 y", str(N), "con suma de dígitos con valor primo")
    print(*is_prim2, sep=', ')


def is_prime(i):
    ans = True
    for r in range(2, i):
        if i % r == 0:
            ans = False
    return ans


mostrarPrimos(100)
