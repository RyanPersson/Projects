import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

#generates the domain for polynomials to be graphed over. Edit to change domain and detail resolution.
x = np.arange(-10,10,.1)
"""
    The following section of code generates a standard basis for P_{n}
"""

#number of polynomial powers in basis.
size_of_space = 10

powers = list(range(size_of_space))

def generate_space(power) :
    def poly(base) :
        return base**power
    return poly


polynomial_basis = []
for i in powers:
    polynomial_basis.append(i)
    polynomial_basis[i]= generate_space(i)

"""
    inner product on P_{n}.
    Use various functions to normalize P_{n}, i.e. -1 to 1 generates the lebesque polynomials, o to infinity generate the #####
    polynomials and -infinity to infinity generates the #### polynomials
"""
def inner_product(f,g) :
    def integrand(x) :
        return f(x)*g(x)
    tup = quad(integrand,-1,1)
    return tup[0]
"""
    Induced norm on P_{n}.
    Is dependant on the defined inner product of the space."
"""
def induced_norm(g) :
    return np.sqrt(inner_product(g,g))
"""
    Gram_schmidt Procedure: Transforms the standard basis of P_{n}. {1,x,x^2,...,x^2} into an orthonormalized basis 
    for P_{n}. HOW this basis is normalized depends on how the inner product on P_{n} is defined, because the norm    
    being used is the induced norm (square root of the inner product of a vector with itself.)
"""
orthonormal_basis = []

def gram_schmidt(n) :
    if n == 0 :
        def f(x) :
            a = polynomial_basis[n]
            b = induced_norm(polynomial_basis[n])
            return a(x)/b
        return f
    else:
        def f(x) :
            a = polynomial_basis[n]
            b = a
            for i in range(n) :
                c = orthonormal_basis[n-i]
                b = b + inner_product(a,orthonormal_basis[n-i])*c(x)
            d = induced_norm(a)
            return b(x)/d
        return f

for num in powers:
    orthonormal_basis.append(num)
    orthonormal_basis[num] = gram_schmidt(num)
test = orthonormal_basis[2]
print(test(5))

for num in powers:
    b = orthonormal_basis[num]
    plt.plot(x,b(x))
plt.show()
exit()
