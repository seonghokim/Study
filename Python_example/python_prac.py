

from re import split 
  
print(split('\W+', 'Words, words , Words')) 
print(split('\W+', "Word's words Words")) 
print(split('\W+', 'On 12th Jan 2016, at 11:02 AM')) 
print(split('\d+', 'On 12th Jan 2016, at 11:02 AM')) 