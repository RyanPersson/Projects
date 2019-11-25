import matplotlib
from matplotlib import pyplot as plt
import numpy as np

theta = 3.14/3
vi = 30
phi = np.arange(0,3.14/2 - theta,.01)
R = (2/9.8)*np.power(vi,2)*(np.sin(theta)*np.cos(theta + phi))/np.power(np.cos(phi),2)
plt.plot(phi,R, label='R(Φ) = (2/g)vi^2sinθcos(θ+Φ)/cos^2(Φ)')
plt.xlabel('Slope angle Φ, 0 <= Φ < pi/2')
plt.ylabel('R(θ) distance traveled')
plt.title('Distance As A Function of Slope Angle')
plt.legend(loc='best')
plt.show()
exit()
