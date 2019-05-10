# lab04 Eric Mooers, Gracie Shi
##1
def notStringContainingR(word):
    if type(word)==str:
        if 'r' in word:
            return False
        elif 'R' in word:
            return False
        else:
            return True
    else:
        return True
    
def test_notStringContainingR_1():
    assert notStringContainingR("word") == False
def test_notStringContainingR_2():
    assert notStringContainingR("super") == False
def test_notStringContainingR_3():
    assert notStringContainingR("ReEl") == False
def test_notStringContainingR_4():
    assert notStringContainingR("") == True
def test_notStringContainingR_5():
    assert notStringContainingR(3.14) == True

##2
def hasVowel(word):
    if type(word)==str:
        for c in word:
            if c in ('a','e','i','o','u','A','E','I','O','U'):
                return True
        else:
            return False
    else:
        return False
            

def test_hasVowel_1():
    assert hasVowel(True) == False

def test_hasVowel_2():
    assert hasVowel("Pythn") == False

def test_hasVowel_3():
    assert hasVowel("") == False

def test_hasVowel_4():
    assert hasVowel("borg") == True

def test_hasVowel_5():
    assert hasVowel("frEE") == True


##3
def isNumber(item):
    if type(item)==int or type(item) ==float:
        return True
    else:
        return False

def test_isNumber_1():
    assert isNumber("1") == False

def test_isNumber_2():
    assert isNumber(-1) == True

def test_isNumber_3():
    assert isNumber(True) == False

def test_isNumber_4():
    assert isNumber(3.14) == True

def test_isNumber_5():
    assert isNumber([0]) == False

##4
def onlyContainsStrings(theList):
    p=0
    if theList == []:
        return False
    elif type(theList)==list:
        for x in range(len(theList)):
            if type(theList[x])==str:
                p=p+1
        if p==len(theList):
            return True
        else:
            return False
    else:
        return False
    
def test_onlyContainsStrings_1():
    assert onlyContainsStrings([]) == False
def test_onlyContainsStrings_2():
    assert onlyContainsStrings(["a", "c", ""]) == True
def test_onlyContainsStrings_3():
    assert onlyContainsStrings(["18", 18, "eighteen"]) == False
def test_onlyContainsStrings_4():
    assert onlyContainsStrings([-1, "-1"]) == False
def test_onlyContainsStrings_5():
    assert onlyContainsStrings("python") == False

##5
def contains(x, theList):
    if type(theList)==list:
        if x in theList:
            return True
        else:
            return False
    else:
        return False
def test_contains_1():
    assert contains([], [4, [], 5]) == True

def test_contains_2():
    assert contains("18", [18, 18.0, "18"]) == True

def test_contains_3():
    assert contains("element", []) == False

def test_contains_4():
    assert contains("item", ("item")) == False

def test_contains_5():
    assert contains((1,2), [1, 2, "3", (1,2)]) == True

##6
def abbreviate(word):
    if type(word) == str:
        abbreviate = (word[0:3])
        return abbreviate
    else:
        return ""
   
def test_abbreviate_1():
    assert abbreviate("January") == "Jan"

def test_abbreviate_2():
    assert abbreviate(20) == ""

def test_abbreviate_3():
    assert abbreviate("At") == "At"

def test_abbreviate_4():
    assert abbreviate("T") == "T"

def test_abbreviate_5():
    assert abbreviate(["A", "T"]) == ""
    
##7
def hasMultiplesOf(x, listOfNums):
    if type(listOfNums) != list or listOfNums == []:
        return False
    for i in list(listOfNums): 
        if type(x) == str:
            return False
        if i%x ==0:
            return True
    
def test_hasMultiplesOf_1():
    assert hasMultiplesOf(3, [-3, 0, 3, 6]) == True

def test_hasMultiplesOf_2():
    assert hasMultiplesOf("3", [-3, 0, 3, 6]) == False

def test_hasMultiplesOf_3():
    assert hasMultiplesOf(3, (-3, 0, 3, 6)) == False

def test_hasMultiplesOf_4():
    assert hasMultiplesOf(1.1, [1.1, 2.2, 4.4]) == True

def test_hasMultiplesOf_5():
    assert hasMultiplesOf(5, []) == False
    
##8
def countEvens(listOfInts):
    if type(listOfInts) == list:
        count = 0
        for i in listOfInts:
            if type(i) == int:
                if i %2 == 0:
                    count += 1
        return count
    else:
        return 0
   
def test_countEvens_1():
    assert countEvens([0,2,4]) == 3

def test_countEvens_2():
    assert countEvens([0,"2","Four", 6]) == 2

def test_countEvens_3():
    assert countEvens((0,2,4)) == 0

def test_countEvens_4():
    assert countEvens([-1,1,3,5,7]) == 0
    
def test_countEvens_5():
    assert countEvens([1.0,2.0,3.0,4.0,5.0,6.0,7.0,-2.0]) == 0



###9
def computeGrade(percentage):
    if type(percentage) == str:
        return ""
    while type(percentage) == int or float:
        if percentage >=0 and percentage <=100: 
            if percentage <60:
                return 'F'
            elif percentage <70:
                return 'D'
            elif percentage <80:
                return 'C'
            elif percentage <90:
                return 'B'
            elif percentage <=100:
                return 'A'
        else:
            return ""
def test_computeGrade_1():
    assert computeGrade(90) == "A"

def test_computeGrade_2():
    assert computeGrade("80") == ""

def test_computeGrade_3():
    assert computeGrade(79.9) == "C"

def test_computeGrade_4():
    assert computeGrade(101) == ""

def test_computeGrade_5():
    assert computeGrade(-1) == ""

# Definition of a Book namedtuple object used for the
# following function below.
from collections import namedtuple
Book = namedtuple("Book", "title author price")
#10??
def expensiveBooks(price, listOfBooks):
    if type(price)!= int or float:
        return []
    if type(listOfBooks) != list:
        return []
    newList =[]
    for Book in bookList:
        if int or float (Book.price) >= int or float(price):
            newList.append(Book.title)
        return newList
   
    
            
            

    '''
    - Returns a list of book titles of Books that are greater or equal to
    the value price.
    - If price is not a number type, then return an empty list ([]).
    - If listOfBooks is not a list type, then return an empty list ([]).
    - Elements in listOfBooks may contain multiple types (not necessarily
    Books). You can check if an element is a Book object with
    type(value) == Book. You can "skip" an element that's not a Book and
    continue checking other elements in listOfBooks.
    - You can assume Book objects are constructed correctly (i.e. title
    and author are strings, and book prices are either an int or float).
    - Note: You must obtain values of a book object using the name of
    the object's attributes (.title, .author, .price) instead of indexing
    them for full credit (as discussed in lecture). 
    - Hint: Think of appending book titles to a list (recall .append) when
    the cost of the book is greater than or equal to the value price, and 
    returning the list of accumulated book titles.
    '''
b1 = Book("Title1", "Author1", 5.99)
b2 = Book("Title2", "Author2", 0.99)
b3 = Book("Title3", "Author3", 20)
b4 = Book("Title4", "Author4", 0)
b5 = Book("Title5", "Author5", 100)
bookList = [b1,b2,b3,b4,b5]

# Tests for expensiveBooks
def test_expensiveBooks_1():
    assert expensiveBooks("0", bookList) == []

def test_expensiveBooks_2():
    assert expensiveBooks(5.99, bookList) == ['Title1','Title3','Title5']

def test_expensiveBooks_3():
    assert expensiveBooks(25, bookList) == ['Title5']

def test_expensiveBooks_4():
    assert expensiveBooks(5.99, (b1,b2)) == []

def test_expensiveBooks_5():
    assert expensiveBooks(101, bookList) == []

