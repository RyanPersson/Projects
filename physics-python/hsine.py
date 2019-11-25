import numpy as np
import matplotlib.pyplot as plt

def cosh(z) :
    return (np.exp(z)+np.exp(-z))/2

def sinh(z) :
    return (np.exp(z)-np.exp(-z))/2

def tanh(z) :
    return (sinh(z)/cosh(z))
sdot0=0
s0=.3
w=2*3.14

def r(t):
    return (np.sqrt(2)*sdot0/w-s0)*sinh(w*t/np.sqrt(2))

x = np.arange(0,10,.01)
plt.plot(x,sinh(x),'-r',label='r(t)')
plt.legend(loc='best')
plt.title("Position of Bead As A Function Of Time")
plt.xlabel("0 < t < 10")
plt.ylabel("meters")
plt.show()
exit()
