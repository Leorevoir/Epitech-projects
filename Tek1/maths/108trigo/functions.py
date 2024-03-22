##
## EPITECH PROJECT, 2024
## Epitech-projects
## File description:
## functions
##

from matrix import *
from maths import *

def exp_matrix(matrix):

    result = [[float(i == j) for j in range(len(matrix))] for i in range(len(matrix))]

    for n in range(1, 20):

        term = scalar_multiply_matrix(1 / factorial(n), matrix_power(matrix, n))
        result = matrix_add(result, term)

    return result


def sinh_matrix(matrix):

    result = [[float(i == j) * 0 for j in range(len(matrix))] for i in range(len(matrix))]

    for n in range(1, 20, 2):

        term = scalar_multiply_matrix(1 / factorial(n), matrix_power(matrix, n))
        result = matrix_add(result, term)

    return result


def cos_matrix(matrix):

    result = [[float(i == j) for j in range(len(matrix))] for i in range(len(matrix))]
    sign = -1

    for n in range(2, 40, 2):

        term = scalar_multiply_matrix(sign / factorial(n), matrix_power(matrix, n))
        result = matrix_add(result, term)
        sign *= -1

    return result
