# fractional knapsack problem implemented by Arpan Pathak
import operator
def maximumProfit(l,capacity):
	weight,max_profit=0.0,0.0
	for i in range(0,len(l)):
		if(weight+float(l[i][2]) <=capacity):
			weight=weight+int(l[i][2])
			max_profit=max_profit+float(l[i][1])
		else:
			max_profit=max_profit+(capacity-weight)*float(l[i][3])
			break
	return max_profit	
l=[]
n=int(input("Enter number of items="))
print("Enter Item Name,value,weight of each item in a a new line")
for i in range(0,n):
	l.append(list(input().split(",")))
	l[i].append(float(l[i][1])/float(l[i][2]))
l.sort(key=operator.itemgetter(3),reverse=True)
for i in l:
	print(i)
print("Maxumum Profit",maximumProfit(l,15))

