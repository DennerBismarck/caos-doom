class Number:
    
    def __init__(self):
        self.base = None
        self.d_string = None # Digit String Variable
        self.value = None
        self.true_value = None # Converted True Value for comparatives
        self.c_value = None # Have no idea what is this


    def set_base(self, new_base):
        if not self.base == None:
            return convert_base(new_base)
        self.base = new_base

    def convert_base(self, new_base):
        return 0        



class Base:

    def __init__(self):
        self.base = None
        self.digits = None

class Digit:

    def __init__(self):
        self.symbol = None
        self.value = None

class Carry:

    def __init__(self):
        return 0    


class Arithmetic:

    def __init__(self):
        return 0

def main():

    print("Hello World")

if __name__ =

