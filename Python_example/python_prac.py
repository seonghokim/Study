def simpleGeneratorFun():
    yield 1
    yield 2
    yield 3
 
 
# Driver code to check above generator function
for value in simpleGeneratorFun():
    print(value)