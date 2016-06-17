s = input()
n = len(s)
md = pow(10,9) + 7
totalsm = int(s[0])
large_sum = totalsm
for i in range(1, n):
    b = int(s[i])
    large_sum = (10*large_sum) + (i+1)*b
    totalsm += large_sum
    totalsm = totalsm%md

print(totalsm)