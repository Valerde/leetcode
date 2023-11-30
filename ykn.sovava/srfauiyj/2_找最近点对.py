#python3.9环境

from math import sqrt
import numpy as np
def nearest_points(s):
    len1 = len(s)                                 #len1为点对的数量
    #print("len=",len1)
    left = s[0:int(len1/2)]
    right = s[int(len1/2):]
    mid_x = (left[-1][0]+right[0][0])/2               #midx为中间坐标x值
    if len(left) > 2:   
        lmin = nearest_points(left)    #左侧部分最近点对
    else:   lmin = left
    if len(right) > 2:   
        rmin = nearest_points(right)   #右侧部分最近点对
    else:   rmin = right

    if len(lmin) >1: 
        disl = get_distance(lmin)
    else: disl = float("inf")                      #将其设置为正无穷
    if len(rmin) >1: 
        disr = get_distance(rmin)
    else: disr = float("inf")

    d = min(disl, disr)   #最近点对距离

    mid_min=[]
    for i in left:                             #以左部分的点为基准点，找右半部分
        if mid_x-i[0]<=d :                                          #如果左侧部分与中间线的距离<=d
            for j in right:
                if j[0]-i[0]<=d and abs(i[1]-j[1])<=d:       #如果右侧部分点在i点的(d,2d)之间
                    if get_distance((i,j))<=d:
                        mid_min.append([i,j])                      #ij两点的间距若小于d则加入队列
    if mid_min:
        dic=[]                                            #定义一个内容为字典的列表
        for i in mid_min:
            dic.append({get_distance(i):i})
        dic.sort(key=lambda x: x.keys())                #按字典的键排序
        return list(dic[0].values())[0]
    elif disl>disr:
        return rmin
    else:
        return lmin


# 求点对的距离
def get_distance(min):
    return sqrt((min[0][0]-min[1][0])**2 + (min[0][1]-min[1][1])**2)

def main(s):
    s.sort( key=lambda s: s[0])
    print(s)
    NP = nearest_points(s)
    print(NP)
s=[[1,2],[1,3],[2,5],[1.3,2.4],[6.2,4.6],[9.1,2.1],[2,1],[3.1,2.4],[5.3,0.6],[6.2,2.4],[8.3,6.2],[7.3,2.4],[4.3,2.6],[3.1,2.6]]
main(s)