f = []
a, b, n = input().split()
f.append(int(a))
f.append(int(b))
n = int(n)

for i in range(2, n):
    k = (f[i-1]*f[i-1]) + f[i-2]
    f.append(k)

print(f[n-1])
