A = []
B = []

import random
for x in range(0, 1000):
    num1 = random.randint(1, 2)
    if num1==2:
        num1 = -1
    num2 = random.randint(1, 2)
    if num2==2:
        num2 = -1
    A.append(num1)
    B.append(num2)

import numpy as np
from numpy.linalg import norm

cosine = np.dot(A,B)/(norm(A)*norm(B))
print("Cosine Similarity Normal:", cosine)

count = 0
for x in range(0, len(A)):
    if A[x] == B[x]:
        count+=1
print("Shortcut:", (2*count-len(A))/len(A))