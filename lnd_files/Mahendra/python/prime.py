# prime numbers upto 100
'''
i = 2
while i < 100:
    j = 2
    while j < i:
        if ((i % j) == 0) : break
        j = j + 1
    if (i == j) : print j, 'is prime'
    i += 1
'''
for x in range(2, 100):
    for y in range(2, x):
        if ((x % y) == 0): 
            break
    else:
        print x,'is prime'

print 'Good bye..!'          
