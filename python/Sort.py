import random

list = []

for i in range(0, 50):
    list.append(random.randint(0, 100))

list = sorted(list)

print (list)