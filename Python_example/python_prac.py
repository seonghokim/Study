
import itertools
import operator

GFG = [5, 3, 6, 2, 1, 9, 1]

result = itertools.accumulate(GFG, max)

for each in result:
    print(each)



