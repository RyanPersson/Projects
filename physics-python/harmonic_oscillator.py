#%%
import numpy as np
import matplotlib.pyplot as plt

k=4
m=1
x0=1

def position(t) :
    return x0*np.cos(np.sqrt(k/m)*t)
def velocity(t) :
    return -x0*np.sqrt(k/m)*np.sin(np.sqrt(k/m)*t)

t = np.arange(0,10,.01)
plt.plot(t,position(t))
plt.xlabel("time t: 0<t<10")
plt.ylabel("position")
plt.title("Position as a function of time.")
plt.show()
exit()


# %%
