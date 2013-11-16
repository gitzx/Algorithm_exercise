# -*- coding: cp936 -*-
import random
import sys
import time

def getrandata(num):
	global a 
	i = 0
	while i < num:
		a.append(random.randint(0,100))
		i +=1
	print a
	return a

def bubbleSort(a):
	ln = len(a)-2
	i = 0
	while i<ln+1:
		j = ln
		while j>=i:
			if(a[j+1]<a[j]):
				a[j],a[j+1] = a[j+1],a[j]
			j-=1
		i+=1
	print 'bubble:' + str(a)

def insertSort1(a):
	for i in range(1,len(a)):
		tmp = a[i]
		j = i 
		while j>0 and tmp < a[i-1]:
			a[j] = a[j-1]
			j-=1
		a[j]=tmp
	print 'insert1:' +str(a)

def insertSort2(a):
	for i in range(1,len(a)):
		j=i
		while j>0 and a[j-1] > a[j]:
			j-=1
		a.insert(j,a[i])
		a.pop(i+1)
	print 'insert1:' +str(a)

def selectsort1(a):
    #每次找最小元素
    n=len(a)
    for i in range(0, n-1):
        for j in range(i+1, n):
            minpos=i #minpos用于记录最小元素的下标
            if a[j]<a[minpos]:
                minpos=j
                #如果在这里就交换a[j]和a[minpos]，那就是bubblesort
        if minpos!=i:
            a[minpos],a[i]=a[i],a[minpos]
    print 'selectsort1:' +str(a)


def selectsort2(a):
    #每次找最大元素
    n=len(a)
    for i in range(n-1, 0, -1):
        maxpos=0
        for j in range(1, i+1):
            if a[j]>a[maxpos]:
                maxpos=j
        if maxpos!=i:
            a[i],a[maxpos]=a[maxpos],a[i]
    print 'selectsort1:' +str(a)

def shellSort(a):
	dist = len(a)/2
	while dist>0:
		for i in range(dist, len(a)):
			tmp = a[i]
			j=i
			while j>=dist and tmp<a[j-dist]:
				a[j]=a[j-dist]
				j-=dist
			a[j] = tmp
		dist/=2
	print 'shellSort:' + str(a)

"""快速排序"""
def median(a,start,end):
	center=(start+end)/2
	if a[start]>a[center]:
		a[start],a[center]=a[center],a[start]
	if a[start]>a[end]:
		a[start],a[end]=a[end],a[start]
	if a[center]>a[end]:
		a[center],a[end]=a[end],a[center]
	a[start],a[center]=a[center],a[start]

def doSwap(a,start,end):
	if start>=end:
		return
	i,j=start,end
	median(a,start,end)
	tmp=a[start]
	while(True):
		while(a[j]>tmp and i<j):
			j-=1
		if i<j:
			a[i]=a[j]
			i+=1
		while(a[i]<tmp and i<j):
			i+=1
		if i<j:
			a[j]=a[i]
			j-=1
		else:
			break
	a[i]=tmp
	doSwap(a,start,i-1)
	doSwap(a,j+1,end)

def quickSort(a):
	#设置递归深度为10000000，放置数据量过大时超出递归最大深度发生exception
	sys.setrecursionlimit(1000000)
	doSwap(a,0,len(a)-1)
	print 'quickSort:' + str(a)

if __name__ == "__main__":
	a = []
	getrandata(10)
	t1 = time.clock()
	a.sort()  #python timSort
	t2 = time.clock()
	print 'python timSort:' + str(a)+ '  time used:  '+ str(float(t2-t1)) +'ms'
	bubbleSort(a)
	insertSort1(a)	
	insertSort2(a)
	selectsort1(a)
	selectsort2(a)
	shellSort(a)
	quickSort(a)
	
