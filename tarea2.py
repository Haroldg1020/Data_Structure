"""
Harold David Guerrero Caicedo
8976203
Juan Esteban Salas
8975783
tarea 2
Estructuras de datos
"""

# Punto 1

# Punto 6


def fibo(n):
    ans = None
    if n <= 1:
        ans = n
    else:
        ans = fibo(n - 1) + fibo(n - 2)
    return ans 
#print(fibo(10))


# Punto 7

def fibo(n):
    lista = [0, 1]
    for i in range(n+1):
        if i <= 1:
            resp = lista[i]
        else:
            lista.append((lista[i-1]) + (lista[i-2]))
            resp = lista[i]

    return resp
print(fibo(5000))



# Punto 8

# Mi codigo


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


#mostrarPrimos(200000)


# Profes

def esPrimo(n):
  if n < 2:
      ans = False
  else:
    i, ans = 2, True
    while i * i <= n and ans:
      if n % i == 0:
          ans = False
      i += 1
  return ans


def sumarDigitos(n):
  suma = 0
  while n > 0:
    suma += n % 10
    n //= 10
  return suma


def mostrarPrimos(N):
  print("Números primos entre 1 y %d" % N)
  primos, sumPrimo = [], []
  for i in range(2, N):
    if esPrimo(i):
      primos.append(i)
      if esPrimo(sumarDigitos(i)):
        sumPrimo.append(str(i))
  for i in range(len(primos)):
    if i < len(primos) - 1:
      print("--> %d," % primos[i])
    else:
      print("--> %d" % primos[i])
  print()
  print("Números entre 1 y %d con suma de dígitos con valor primo:" % N)
  print(", ".join(sumPrimo))


#mostrarPrimos(200000)
