import numpy as np
import matplotlib.pyplot as plt

def tanh(z) :
    return (sinh(z)/cosh(z))
sdot0=0
g=9.8
#L = 1
R = 1

def phi(L):
    return -(g*np.power(L,2))/(np.power(R,2))

x = np.arange(0,5,.01)
plt.plot(x,phi(x),'-r',label='phi(R)')
plt.legend(loc='best')
plt.title("Z acceleration of bead as a function of Lambda")
plt.xlabel("0 < L < 5")
plt.ylabel("meters")
plt.show()
exit()
