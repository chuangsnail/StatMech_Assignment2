
# coding: utf-8

# In[4]:


import random
import math
sides=6

#theoretical value
meantheo=0
squatheo=0
vartheo=0
for s in range(sides):
    meantheo=meantheo + (s+1)/sides
    squatheo=squatheo + ((s+1)**2)/sides
    vartheo =squatheo - (meantheo**2)
#exp values
def rollDie(number):
    counts = sides * [0]
    for i in range(number):
        roll = random.randint(1,sides)
        counts[roll - 1] += 1
    print (counts)
    mean=0
    squa=0
    var=0
    print ("s ,N_s,N_s/trials")
    for s in range(sides):
       
        print (s+1,counts[s], counts[s]/number)        
        mean = mean+(s+1)*counts[s]/number
        squa = squa+((s+1)**2)*counts[s]/number
        var  = squa-(mean**2)
        
    print ()
    print ("mean=",mean)
    print ("var =",var)
    print ("div =",var**0.5)
    print ("meantheo=",meantheo)
    print ("vartheo =",vartheo)
    print ("divtheo =",vartheo**0.5)
    print ()
    print ()
    print ()    

def run():
    rollDie(10)
    rollDie(1000)
    rollDie(10000)
    rollDie(100000)

run()

