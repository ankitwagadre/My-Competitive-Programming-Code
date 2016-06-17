n = 100
a = [1, 1]
for i in range(2, n+1):
    a.append(a[i-1]*i)
    print(i, a[i])