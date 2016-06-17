n = 100
a = []
for i in range(0, n+1): a.append(True)

for i in range(2, n+1):
    if i*i > n:
        break

    if a[i]:
        j = i*i
        while j < n+1:
            a[j] = False
            j = j + i

for i in range(2, n + 1):
    if a[i]:
        print(i)