#%%
import matplotlib
from matplotlib import pyplot as plt
import numpy as np


#phi must be between 0 & pi/2
phi = .7341
#theta must be between phi & pi/2
theta = .3 
#vi is initial velocity in meters per second.
vi = 10

#time parameter, should be adjusted to show full path of projectile.
tf = 2*vi*np.sin(theta)/(9.8*np.cos(phi))
t = np.arange(0,tf,.001)

#The following code snippet plots the slope as a visual aid and ends it just after 
#the point of impact.
x = np.arange(0,tf*vi*np.cos(theta+phi)+1,1)
yslope = ((np.sin(phi))/(np.cos(phi)))*x
plt.plot(x,yslope, label='slope of phi')

#projectile x(t) functions in x = phi reference frame
xprojectile = vi*np.cos(theta)*t - (9.8/2)*np.sin(phi)*np.power(t,2)
yprojectile = vi*np.sin(theta)*t - (9.8/2)*np.cos(phi)*np.power(t,2)

#maps xy frame relative to phi slope, to xy frame relative to flat ground
xabs = vi*np.cos(theta+phi)*t
yabs = vi*np.sin(theta+phi)*t - (9.8/2)*np.power(t,2)
plt.plot(xabs,yabs, label='<x,y> =\n <vicos(theta)t - g/2sin(phi)t^2,\nvisin(phi)t - g/2sin(theta)t^2>')



plt.title("Projectile Trajectory Up Incline")
plt.xlabel('x distance (meters)')
plt.ylabel('y distance (meters)')
plt.legend(loc='best')

print("test")
plt.show()

exit()



# %%
