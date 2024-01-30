
def make_translation(i, j, x, y):
    i: float = (float)(i)
    j: float = (float)(j)
    x: float = (float)(x)
    y: float = (float)(y)
    matrice = ((1.00, 0.00, i),
               (0.00, 1.00, j),
               (0.00, 0.00, 1.00))
    vector = (x, y, 1)
    matrice_to_return = ((float)(matrice[0][0] * vector[0] + matrice[0][1] * vector[1] + matrice[0][2] * vector[2]),
                         (float)(matrice[1][0] * vector[0] + matrice[1][1] * vector[1] + matrice[1][2] * vector[2]),
                         (float)(matrice[2][0] * vector[0] + matrice[2][1] * vector[1] + matrice[2][2] * vector[2]))
    return (matrice, (x, y), (matrice_to_return[0], matrice_to_return[1]))
