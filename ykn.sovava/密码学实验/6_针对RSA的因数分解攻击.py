import gmpy2
import libnum

n = 9614830106283159061

e = 65537

c = 7340344036272012455
print(libnum.factorize(n))
q=int(input())

p=n//q
phi=(p-1)*(q-1)
d=gmpy2.invert(e,phi)
m=pow(c,d,n)
print(int(m))
print(libnum.n2s(int(m)))