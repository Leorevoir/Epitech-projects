#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Epitech-projects
## File description:
## 108trigo
##

import sys
from functions import *
from maths import *

#___________USAGE____________________________________________________________

def usage():
    print("USAGE")
    print(" ./108trigo fun a0 a1 a2 ...#br")
    print("\nDESCRIPTION")
    print(" fun\t function to be applied, among at least EXP, COS, SIN, COSH and SINH")
    print(" ai\t coeficients of the matrix")
    exit(0)

#__________HANDLE_ERROR______________________________________________________

def handle_fun(args: list) -> str:

    fun_possible: list = ["EXP", "COS", "SIN", "COSH", "SINH"]
    fun: str = args[1].upper()

    if fun in fun_possible:

        return fun

    print(f"ERROR: Function {fun} is not supported.", file=sys.stderr)
    exit(84)

def handle_ai(args: list) -> list:

    try:
        copy = [int(x) for x in args]
        matrix_size = int(sqrt(len(copy)))

        if matrix_size ** 2 == len(copy):

            return [copy[i:i + matrix_size] for i in range(0, len(copy), matrix_size)]

        print("ERROR: Number of coefficients does not form a square matrix.", file=sys.stderr)
        exit(84)

    except ValueError:

        print("ERROR: Coefficients of the matrix must be integers.", file=sys.stderr)
        exit(84)

#__________APPLY_FUNCTION____________________________________________________

def apply_function(fun, matrix):

    if fun == "EXP":
        return exp_matrix(matrix)
    if fun == "SINH":
        return sinh_matrix(matrix)
    if fun == "COS":
        return cos_matrix(matrix)
    else:
        print("Function not implemented yet.", file=sys.stderr)
        exit(84)

#__________MAIN______________________________________________________________

def main():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        usage()
    elif len(sys.argv) >= 3:
        fun = handle_fun(sys.argv)
        matrix = handle_ai(sys.argv[2:])
        result_matrix = apply_function(fun, matrix)
        for row in result_matrix:
            print('\t'.join("{:.2f}".format(value) for value in row))
        exit(0)
    else:
        print("ERROR: Too few arguments.", file=sys.stderr)
        exit(84)

#____________________________________________________________________________

if __name__ == "__main__":
    main()
