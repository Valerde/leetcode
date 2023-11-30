'''1．装载问题
有两艘船，载重量分别是c1、 c2，n个集装箱，重量是wi (i=1…n)，且所有集装箱的总重量不超过c1+c2。确定是否有可能将所有集装箱全部装入两艘船。
提示：求出不超过c1的最大值max，若总重量－max < c2则能装入到两艘船。'''
def set():
    c1=int(input("enter the c1:"))
    c2=int(input("enter the c2:"))
    n=int (input("enter the n:"))
    a=[]
    maxw=0
    for i in range(n):
        a.append(int(input("input wi:")))
        maxw+=a[i]
        if maxw>c1+c2:                     #当输入错误的数据返回FALSE，并在主函数中重新输入数据
            return False,False,False,False
    return c1,c2,n,a


def solution(c1,c2,w):
    w.sort(reverse=True)
    temp_c=tot=0
    a=[]
    b=[]
    for i in w:
        temp_c+=i
        tot+=i
        if temp_c<=c1:
            a.append(i)
        else:
            temp_c-=i
            b.append(i)
    if tot-temp_c<=c2:
        return True,a,b
    else:
        return False,False,False

def main():
    while True:
        c1,c2,n,w=set()
        if c1:
            break
        print("wrong data!")
    flag,soc1,soc2=solution(c1,c2,w)
    if flag:
        print("c1=",soc1,"c2=",soc2)
    else:
        print("wrong")
main()

