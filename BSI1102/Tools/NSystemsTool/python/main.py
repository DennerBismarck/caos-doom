import sys
from os import system

tex_bool = False
filename = None
default_base = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"] # Base 36

def main():

    options()
    run_menu()

def options():

    if "--help" in sys.argv:
        run_help()

    if "-tex" in sys.argv:
        set_tex()
    return 0

def clear():
    system("cls || clear")

def run_help():

    print("python3 main.py [OPTIONS]...\n")
    print("produces 'as-in school' calculations using TeX align.\nAlso may be used for base conversions and overall\nlearning different basis arithmetic\n")
    print("-tex [FILENAME]")
    print("         produces LaTeX and writes it into a FILE. If non-specified, default output\n         will be terminal-only. If filename is not specified, creates a file with name based on current date and time.\n")
    print("--help")
    print("         display this help and exit\n")
    print("Exit status:")
    print("     0       if OK,\n     1       if minor problems,\n     2       if serious trouble")
    exit(0)


def set_tex():
    
    tex_bool = True
    try:
        filename = sys.argv[sys.argv.index("-tex") + 1]
    except IndexError:
        print("No filename given!")
        set_datefilename()
    except:
        print("Some error ocurred!")
        exit(2)
    if filename[0] == "-":
        print("Invalid filename!")
        exit(1)
    return 0

def run_menu():

    print("Select an operation")
    print("1 - Addition")
    print("2 - N-Operands Addition")
    print("3 - Subtract")
    print("4 - Multiplication")
    print("5 - Division")
    print("6 - Base Conversion")
    print("0 - Exit")
    print()
    try:
        op = int(input("Choose: "))
    except:
        print("Non-integer Input!")
        exit(1)
    clear()
    match op:
        case 0:
            exit(0)
        case 1:
            add()
        case 2:
            m_add()
        case 3:
            sub()
        case 4:
            mul()
        case 5:
            div()
        case 6:
            b_convert()
        case _:
            exit(1)

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
    for i in range(len(n_list[0]), 0):
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

main()
