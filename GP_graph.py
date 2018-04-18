import numpy as np
import matplotlib.pyplot as plt

#Importa los datos
datos = np.loadtxt('tray.txt')

x= datos[:,0]
v= datos[:,1]
t= datos[:,2]

#hace las tres grafiacs correspondientes
plt.figure()
plt.title('Evolucion posicion respecto el tiempo')
plt.xlabel('Tiempo (s)')
plt.ylabel('Posicion (m)')
plt.plot(t,x,label='Posicion')
plt.legend()
plt.savefig('pos.png')

plt.figure()
plt.title('Evolucion velocidad respecto el tiempo')
plt.xlabel('Tiempo (s)')
plt.ylabel('Velocidad (m/s)')
plt.plot(t,v,label='Velocidad')
plt.legend()
plt.savefig('vel.png')


plt.figure()
plt.title('V vs X. Fase')
plt.xlabel('Posicion(m)')
plt.ylabel('Velocidad (m/s)')
plt.plot(x,v,label='Fase')
plt.legend()
plt.savefig('phase.png')
