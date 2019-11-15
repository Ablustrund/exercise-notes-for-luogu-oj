f = 0
i = 0
k = 0
cnt = 0
ans = 1000000000
fa = [None]*200005
def find(x):
    global cnt
    cnt = cnt + 1
    if(fa[x] == x):
        return x
    else:
        return find(fa[x])
n = int(input())
ls = input().split(' ')
for i in range(1,n + 1):
    fa[i] = i
    ls[i-1]=int(ls[i-1])
for i in range(1,n + 1):
    f = ls[i-1]
    cnt = 0
    if(find(f)==i):
        ans = min(cnt,ans)
    else:
        fa[i] = f
print(ans)