# Bubble sort implemented by Arpan Pathak, Time Complexity O(N^2)
def bubble_sort(l):
	for i in range(0,len(l)-1):
		for j in range(0,len(l)-i-1):
			if(l[j]>l[j+1]):
				l[j],l[j+1]=l[j+1],l[j]
l=list(map(int,input("Enter Array Elementes : ").split(" ")))
bubble_sort(l)
print(l)
