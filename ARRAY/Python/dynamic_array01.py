## This is a simple program to create a dynamic array in python

array=[]
size=int(input("Enter the size of the array: "))
for i in range(size):
    a=input(f"Enter the value {i}: ")
    array.append(a)  ##The append() method in Python doesn't return the modified list, it modifies the list in-place
print(array)