################################################################################
################################################################################

                               ## TEAM DETAILS ##
'''
e-Yantra 2015
Task 2 - Number Combination algorithm 
eYRC
Team ID: eYRC#1011
File name: eYRC#1011_algorithm.py
Version: 1.0.0
Author: Meghana B
'''

                            ## PROGRAM DESCRIPTION ##
'''
This is a program that finds the combinations of elements in D1 which sum up to each element in D2 
The numbers extracted from the image are stored in lists D1 and D2.
'''

################################################################################
################################################################################

def findcomb(D1,D2):
	D4=D1[:]
	k=0
	pairs=[]
	flag=0
	found=0

	while k!=len(D2):
		for i in range(len(D1)-1):
			if flag==1:
				flag=0
				break
			for j in range(i+1,len(D1)):
				if D2[k]==D1[i]+D1[j]:
					pairs.append([D1[i],D1[j]])
					D1[i]=0
					D1[j]=0
					flag=1
					found=1
					break	
		if found!=1:
			for i in range(len(D1)-1):
				if flag==1:
					flag=0
					break
				for j in range(i+1,len(D1)):
					if flag==1:
						break
					for l in range(i+j+1,len(D1)):
						if D2[k]==D1[i]+D1[j]+D1[l]:
							pairs.append([D1[i],D1[j],D1[l]])
							D1[i]=0
							D1[j]=0
							D1[l]=0
							flag=1
							break
		k+=1

	if len(pairs)==len(D2):
		return pairs
	else:
		return findcomb(D4,D2[len(D2)-1:]+D2[:len(D2)-1]) 	


def puzzle(D1,D2):
	D2even=[]
	print 'puzzle'
	D1=D1[0]
	D2=D2[0]

	for i in range(len(D2)):
		if i%2==1:
			D2even.append(D2[i])
	
	D3=D2even[:]
	pairs=findcomb(D1,D2even)
    
#Find the best combinations without repetition
	for sum in D3:
		for pair in pairs:
			s=0
			for p in pair:
				s=s+p
				
			if s==sum and len(pair)==3:
				print sum,'=',pair[0],'+',pair[1],'+',pair[2]
				break
			if s==sum and len(pair)==2:
				print sum,'=',pair[0],'+',pair[1]
				break
	return 0

if __name__ == "__main__":
    #code for checking output for single test input
    fo = open("Test_input0.txt", "r")
    D1=[map(int, fo.readline().split())]
    D2=[map(int, fo.readline().split())]
    puzzle (D1,D2)

    #code for checking output for all test inputs
    for file_number in range(0,9):
        file_name = "Test_input"+str(file_number)+".txt"
        fo = open(file_name, "r")
        D1=[map(int, fo.readline().split())]
        D2=[map(int, fo.readline().split())]
        puzzle (D1,D2)
