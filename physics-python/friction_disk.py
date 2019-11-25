import numpy as np
import matplotlib.pyplot as plt

m=1
R=1
w_0=1


def friction_force(T_0) :
    return (m*R*w_0)/(2*T_0)
T_0 = np.arange(1,10,.01)
plt.plot(T_0,friction_force(T_0))
plt.xlabel("Time interval needed to stop 1 < T < 10sec")
plt.ylabel("Force of friction")
plt.title("Stopping Force For A Spinning Disk")
plt.show()
exit()
