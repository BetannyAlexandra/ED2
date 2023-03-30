# import emoji

# print(emoji.emojize(":grinning_face_with_big_eyes: "))
# define a função f(x)

import math

def f(x):
  return -30/x+2*x+10

# define os extremos do intervalo
a, b = -5, 0

# a tolerância indica o quão próximo a aproximação está da raiz
TOL = 0.001

i = 0                       # contador
if f(a)*f(b) < 0:           # verifica se há raiz nesse intervalo (se f(a) e f(b) forem positivo/negativo, f(a)*f(b)                               será negativo)
    while (b-a)/2 > TOL:    # o loop para quando atinge a tolerância
        c = (a+b)/2         # encontra o ponto médio do intervalo
        i += 1
        if f(a)*f(c) < 0:   # Teorema de Bolzano
            b = c           # atualiza os extremos do intervalo
        else:
            a = c
    print(c)                # a raiz foi encontrada
else:
    print("Não há raiz nesse intervalo")