#%%
import numpy as np
import matplotlib.pyplot as plt


v0 = 0
c = 1
m = 1
x0 = 3
vmax = np.sqrt(m*9.8/c)
x = np.arange(0,1,.001)
def velocitydrag(t) :
    return vmax*tanh(-9.8*t/vmax)
def positiondrag(t) :
    return -((vmax**2)/9.8)*np.log(cosh((-9.8*t)/vmax)) + x0
def cosh(z) :
    return (np.exp(z)+np.exp(-z))/2
def sinh(z) :
    return (np.exp(z)-np.exp(-z))/2
def tanh(z) :
    return (sinh(z)/cosh(z))


plt.plot(x,positiondrag(x),'-r')
plt.legend(loc='best')
plt.title("X(t) When Effected By Quadratic Drag")
plt.xlabel("0 < t < 1")
plt.ylabel("X(t)")
plt.show()
exit()


# %%


# %%
