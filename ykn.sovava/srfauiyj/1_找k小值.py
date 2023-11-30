import numpy as np
import time
import copy
def creat(min,max,tot):
    num=np.random.randint(min,max,tot)
    return num

def get_k(num,left,right,k):
    if len(num)<k or k<0:
        return
    temp_k=get_index(num,left,right)
    if k == temp_k+1:
        return num[temp_k]
    if k<temp_k+1:
        return get_k(num,left,temp_k-1,k)
    else:
        return get_k(num,temp_k+1,right,k)

def swap(num,a,b):
    temp=num[a]
    num[a]=num[b]
    num[b]=temp

def get_index(num,left,right):
    i,j=left,right
    while True:
        while i<right and num[i]<num[left]:
            i+=1
        while left<j and num[left]<num[j]:
            j-=1
        if i>=j:
            break
        else:
            swap(num,i,j)
    swap(num,left,j)
    return j
def main():
    min,max,tot=1,10000000,10000
    num=creat(min,max,tot)
    nums=copy.deepcopy(num)
    k=input("enter the number k:")
    starttime=time.time()
    numk=get_k(num,0,tot-1,int(k))
    endtime=time.time()
    print(endtime-starttime)
    print(numk)
    #print(nums)
    starttime=time.time()
    num=sorted(nums)
    endtime=time.time()
    print(endtime-starttime)
    #print(num)
main()
