import matplotlib.pyplot as plt

def f(x):
    return x**3 - x**2

x = []
y = []

l = -1.5
r = 2.5
inc = 0.00001

for i in range(int((r - l) / inc)):
    num = l + i * inc
    x.append(num)
    y.append(f(num))

ax = plt.gca()
ax.set_aspect('equal', adjustable='box')

plt.plot(x, y, 'r')
plt.show()