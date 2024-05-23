dict1 = {10: 'a', 20: [1, 2, 3], 30: 'c'}
print("Given Dictionary:", dict1)
 
# new dictionary and
# copying using copy() method
dict2 = dict1.copy()
print("New copy:", dict2)
 
# Updating dict2 elements and
# checking the change in dict1
dict2[10] = 10
dict2[20][2] = '45'  # list item updated
 
print("Updated copy:", dict2)

print(dict1)