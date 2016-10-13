def selection_sort(l):
	for i in range(0,len(l)-1):
		index=i
		for j in range(i+1, len(l)):
			if(l[j]<l[index]):
				index=j
		l[i],l[index]=l[index],l[i]
l=list(map(int,input("Enter elements : ").split(" ")))
selection_sort(l)
print(l)
