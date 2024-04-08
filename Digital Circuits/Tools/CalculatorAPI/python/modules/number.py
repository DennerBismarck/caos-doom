from asserts import assertEqual
from base import Base

class Number:

    def __init__(self) -> None:
        self.listOfDigits: list[str] = None
        self.totalValue: int = None
        #self.totalFloatValue:
        self.baseObj: Base = None

    def getListOfDigits(self) -> list:
        return self.listOfDigits

    def getTotalValue(self) -> int:
        return self.totalValue
    
    def getBase(self) -> int:
        return self.baseObj.getValue()
    

    def setDigits(self, digitsList: list):
        if self.validateDigitsList(digitsList):
            self.listOfDigits = digitsList
    
    def validateDigitsList(self, digitsList: list) -> bool:
        for digit in digitsList:
            if self.digitInSymbols(digit):
                return False
        return True
    
    def digitInSymbols(self, digit) -> bool:
        baseSymbols = self.baseObj.getSymbols()
        if not digit in baseSymbols:
            return True
        return False
    
    def calculateTotalValue(self) -> None:
        digitsValue = 0
        listOfDigits = reversed(self.getListOfDigits())
        numberBase = self.getBase()
        for digit in listOfDigits:
            digitsValue += digit * pow(numberBase, listOfDigits.index(digit))
        self.totalValue = digitsValue
    
    def setBase(self, base: int) -> None:
        if self.baseIsNone(self.getBase()):
            self.baseObj.setBaseValue(base)
        self.changeBase(base)
    
    def convertBase(self, base: int) -> None:
        if assertEqual(self.baseObj.getValue(), base):
            return None
        self.baseObj.setBaseValue(base)
        self.convertToBase(base)

    def baseIsNone(self) -> bool:
        if self.getBase() == None:
            return True
        return False

if __name__ == "__main__":
    test = Number()