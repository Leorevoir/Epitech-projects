def make_scaling(m, n, x, y):
    m: float = (float)(m)
    n: float = (float)(n)
    x: float = (float)(x)
    y: float = (float)(y)
    matrice = ((m, 0, 0),
               (0, n, 0),
               (0, 0, 1))
    vector = (x, y, 1)
    matrice_to_return = ((matrice[0][0] * vector[0] + matrice[0][1] * vector[1] + matrice[0][2] * vector[2]),
                         (matrice[1][0] * vector[0] + matrice[1][1] * vector[1] + matrice[1][2] * vector[2]),
                         (matrice[2][0] * vector[0] + matrice[2][1] * vector[1] + matrice[2][2] * vector[2]))
    return (matrice, (x, y), (matrice_to_return[0], matrice_to_return[1]))
