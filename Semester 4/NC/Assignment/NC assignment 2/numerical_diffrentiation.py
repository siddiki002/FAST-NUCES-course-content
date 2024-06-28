from scipy.integrate import newton_cotes
import numpy as np
def f(x):
    return np.sin(x)
a = 0
b = (np.pi)/4
exact = 1
for N in [1, 2, 3, 4, 5]:
    x = np.linspace(a, b, N + 1)
    an, B = newton_cotes(N, 1)
    dx = (b - a) / N
    quad = dx * np.sum(an * f(x))
    print('{:2d}  {:10.9f}'.format(N, quad))