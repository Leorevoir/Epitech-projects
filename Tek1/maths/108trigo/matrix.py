##
## EPITECH PROJECT, 2024
## Epitech-projects
## File description:
## matrix
##

def matrix_add(A, B):

    return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]


def scalar_multiply_matrix(alpha, A):

    return [[alpha * A[i][j] for j in range(len(A[0]))] for i in range(len(A))]


def matrix_multiply(A, B):

    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]

    for i in range(len(A)):

        for j in range(len(B[0])):

            for k in range(len(B)):

                result[i][j] += A[i][k] * B[k][j]

    return result


def matrix_power(A, n):

    result = A

    for _ in range(1, n):

        result = matrix_multiply(result, A)

    return result
