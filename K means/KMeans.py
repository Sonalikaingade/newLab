from unittest import result
import numpy as np
import pandas as pd
import math

df=pd.read_csv("KMeans.csv")
c1_x=df['A'][0]
c1_y=df['B'][0]
c2_x=df['A'][1]
c2_y=df['B'][1]

def find_distance(x1,y1,x2,y2):
    return math.sqrt((x1-x2)**2+(y1-y2)**2)

set1=set({})
set2=set({})
def clustering():
    global set1,set2
    global c1_x,c1_y,c2_x,c2_y
    temp_set1=set({})
    temp_set2=set({})
    sum_x1=0
    sum_x2=0
    sum_y1=0
    sum_y2=0
    for i in range(0,len(df)):
        temp_x=df['A'][i]
        temp_y=df['B'][i]
        d1=find_distance(c1_x,c1_y,temp_x,temp_y)
        d2=find_distance(c2_x,c2_y,temp_x,temp_y)
        if(d1<d2):
            temp_set1.add((temp_x,temp_y))
            sum_x1+=temp_x
            sum_y1+=temp_y
        else:
            temp_set2.add((temp_x,temp_y))
            sum_x2+=temp_x
            sum_y2+=temp_y
    if temp_set1==set1 and temp_set2==set2:
        return True
    set1=temp_set1
    set2=temp_set2
    if(len(temp_set1)):
        c1_x=sum_x1/len(temp_set1)
        c1_y=sum_y1/len(temp_set1)
    if(len(temp_set2)):
        c2_x=sum_x2/len(temp_set2)
        c2_y=sum_y2/len(temp_set2)
    return False

result=False
iterations=0
while(result==False):
    iterations+=1
    result=clustering() 
print("Iterations: ",iterations)
print('Cluster 1: ')
for i in set1:
    print("(",i[0]," , ",i[1],")")
print('Cluster 2: ')
for i in set2:
    print("(",i[0]," , ",i[1],")")



