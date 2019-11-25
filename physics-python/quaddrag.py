import numpy as np
import matplotlib.pyplot as plt


v0 = 1
c = 1
m = 1
x0 = 1
x = np.arange(0,10,.01)
def velocitydrag(t) :
    return v0/(1+(v0*c/m)*t)
def positiondrag(t) :
    return (m/c)*np.log(1+(v0*c/m)*t)+x0

plt.plot(x,positiondrag(x),'-r')
plt.legend(loc='best')
plt.title("X(t) When Effected By Quadratic Drag")
plt.xlabel("0 < t < 10")
plt.ylabel("X(t)")
plt.show()
exit()
