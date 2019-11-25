import numpy as np
import matplotlib.pyplot as plt

m1 = 2
m2 = 1
g = 9.8
I = 1
R = 1
def acelleration(m1) :
    return g*(m1-m2)/(m1+m2+I/np.power(R,2))
x = np.arange(0,2,.01)
y = acelleration(x)
plt.plot(x,y)
plt.title("Relationship Between Relative Mass and Acceleration in an Atwood Machine")
plt.ylabel("Acceleration Of System")
plt.xlabel("Mass of m2, (m1 = 1kg)")
plt.show()
exit()
