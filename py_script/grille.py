import numpy as np
import matplotlib.pyplot as plt
from read_matrice import read

array = read("mat.txt")
mat = np.matrix(array)
x = np.arange(0, len(array))  # vecteur x
y = np.arange(0, len(array[0]))  # vecteur y
cmap = plt.get_cmap('hsv') # choix du set de couleur
etatmin = mat.min()
etatmax = mat.max()


fig, ax = plt.subplots(nrows=1, ncols=1)
# Affectation des états

# On plot la matrice avec un état = une couleur sur la grille
colormesh = ax.pcolor(x, y, array,linewidths=1,vmin=etatmin, vmax=etatmax, cmap=cmap)

for (i, j), z in np.ndenumerate(array):
    ax.text(j, i, '{:0.0f}'.format(z), ha='center', va='center')


cbar = fig.colorbar(colormesh,aspect = 1) # configuration de la colorbar pour afficher les états

plt.show()