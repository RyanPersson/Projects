import matplotlib
from matplotlib import pyplot as plt
import numpy as np

x = np.arange(0,10,.00001)
y = np.sin(x)
plt.title(r'$\sigma=\frac{24 \pi^{3} L^{2}}{T^{2} c^{2}\left(1-e^{2}\right)}$')
plt.xlabel('0 < x < 2*π/9')
plt.plot(x,y)
plt.show()

exit()
