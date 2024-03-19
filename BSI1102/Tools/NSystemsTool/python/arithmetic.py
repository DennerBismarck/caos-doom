import sys
from os import system

tex_bool = False
filename = None
default_base = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"] # Base 36

def add():
    n1 = input("Input 1st Number: ")
    n2 = input("Input 2nd Number: ")
    try:
        base = int(input("Input the base ( 2 - 36 ): "))
    except ValueError:
        print("Non-integer value!")
        exit(1)
    base = default_base[0:base]
    n_list = list([n1, n2])
    n_list.sort(key=sortLen, reverse = True)
    result_list = list()
    carry_list = list()
    for i in range(len(n_list[0]) - 1, -1, -1):
        result_list.append(base[(base.index(n_list[0][i]) + base.index(n_list[1][i])) % len(base)])
        carry_list.append(base[(base.index(n_list[0][i]) + base.index(n_list[1][i])) // len(base)])
    print(result_list)
    print(carry_list)
        

def sortLen(x):
    return len(x)

def convert(n_list, base):
    b_value = len(base)
    v_list = list()
    for num in n_list:
        true_value = 0
        len_num = len(num)
        i = 1
        for dig in num:
            true_value += (base.index(dig) * int(pow(b_value, len_num - i))) # Colocar segurança
            i += 1
        v_list.append(true_value)
    return v_list

add()
