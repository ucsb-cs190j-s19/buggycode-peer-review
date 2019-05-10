#conceptual problem:
#1.What is the difference between a print and a return in python functions?
#2.What is a stub?


#buggy code:
def notStringContainingR(word):
    '''
    - Return True when word is a string that contains no letter 'r' (or 'R')
    - It should work both for lower and upper case.
    - When word isn't a string or is an empty string (""), return True
    (because it is not a string contaning an R).
    - You can check if the word value is a string with type(word) == str 
    '''
    if type(word)!=str or word=="":
        return False
    if ("R" not in word) or ("r" not in word):
        return True
    else:
        return False

def hasVowel(word):
    '''
    - Return True when word is a string that contains a vowel
    (a,e,i,o,u,A,E,I,O,U).
    - It should work for both lower and upper case vowels.
    - When word doesn't have a vowel, return False. Return True otherwise.
    - If word isn't a string, return False (because it is not a string
    containing a vowel).
    - Hint: recall the boolean operator "in" and use that when
    checking if a character is a vowel.
    '''
    vowels=("a", "A", "e", "E", "i", "I", "o", "O", "u", "U")
    if type(word)!=str:
        return False
    elif word in vowels:
         return True
    else:
        return False
