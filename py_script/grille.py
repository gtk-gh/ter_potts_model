import numpy as np
import matplotlib.pyplot as plt
from read_matrice import read

array = read("mat.txt")
x = np.arange(0, len(array))  # vecteur x
y = np.arange(0, len(array[0]))  # vecteur y
cmap = plt.get_cmap('tab20c') # choix du set de couleur
etatmin = min(array[0])
etatmax = max(array[0])


fig, ax = plt.subplots(nrows=1, ncols=1)
# Affectation des états

# On plot la matrice avec un état = une couleur sur la grille
colormesh = ax.pcolor(x, y, array,linewidths=1,vmin=etatmin, vmax=etatmax, cmap=cmap)


cbar = fig.colorbar(colormesh,aspect = 1) # configuration de la colorbar pour afficher les états

plt.show()