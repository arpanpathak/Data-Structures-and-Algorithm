''' @author arpanpathak '''
dictionary,start=input().split(" "),0
max_length=len( max(dictionary,key=len) )
enc,dec=input(),""
for i in range(0,len(enc)):
	if(i-start<max_length):
		if(enc[start:i+1] in dictionary):
			dec+=enc[start:i]+" "
			start=i+1
	else:
		for s in dictionary:
			idx=enc[start:i+1].find(s)
			if(idx!=-1):
				dec+=s+" "
				start+=idx+len(s)
				break
print(dec)
