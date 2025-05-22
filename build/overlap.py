import matplotlib.pyplot as plt
import numpy as np

X, Y, Z = np.loadtxt('overlap.txt', delimiter=' ', unpack=True)

ax = plt.axes(projection='3d')
graph = plt.plot(X, Y, Z, linestyle=" ", marker="o")
plt.show()
#plt.savefig('figure1.pdf')