"""
Lab 8
"""

def recursiveDigitSum(n):
    '''
    Computes the sum of digits of a positive integer n
    - Your solution must use recursion in order to receive credit.
    '''
    numList = list(str(n))
    newN = n - float(numList[0])*10**(float(len(numList))-1)
    
    if len(numList) == 0:
        return 0
    elif n == 0:
        return 0
    else:
        return int(numList[0]) + recursiveDigitSum(int(newN))
      
               
#####################################

def recursiveSubstring(s, sub):
    '''
    The parameters sub and s are strings. This function omputes if a
    the string sub exists in s.
    - Your solution must use recursion in order to receive credit.
    '''
    word = list(s)
    subWord = list(sub)
    counter = 0
    if len(subWord)>len(word):
        return False
    if s[counter] == sub[counter]:
        counter = counter + 1
    else:
        return False
    
    if sub in s:
        return True
    else:
        return False
    

########################################

newList = []

def recursiveReverseList(L):
    '''
    Tbe parameter L is a list containing any items. This function returns
    the list L in reverse order.
    - Your solution must use recursion in order to receive credit.
    '''
    if len(L) != 0:
        newList.append(L.pop())
        recursiveReverseList(L)
    else:
        print([])
    return newList


########################################

newestList = []
n = 0


def recursiveAccumulateVowels(s):
    '''
    The parameter s is a string. This function returns a string that
    contains only the vowels in the string.
    - The returned string contains the vowels in order of appearance
    (for example, "apple" -> "ae").
    - Your solution must use recursion in order to receive credit.
    '''
    global n
    vowels = ['a','e','i','o','u']
    if n == len(s)-1:
        return newestList
    else:
        for x in vowels:
            if x == s[n]:
                newestList.append(x)
                n = n + 1
                recursiveAccumulateVowels(s)
            else:
                n = n+1
                recursiveAccumulateVowels(s)
    return newestList
    
    if n > len(s)-1:
        return newestList
    else:
        if wordList[n] == vowels[n]:
            newestList.append(wordList[n])
            n = n + 1
            recursiveAccumulateVowels(s)
        else:
            n = n + 1
            recursiveAccumulateVowels(s)
    return newestList
    





