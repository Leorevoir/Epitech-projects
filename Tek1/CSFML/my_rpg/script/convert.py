##
## EPITECH PROJECT, 2024
## B-MUL-200-STG-2-1-myrpg-raphael.petrequin
## File description:
## convert
##

def modify_lines(input_text, old_name, new_name, old_path, new_path, y_value, x_value, old_season, new_season, is_rebuilt):

    lines = input_text.strip().split('\n')
    modified_lines = []

    for line in lines:

        if line.strip():
            parts = line.split()
            
            if len(parts) >= 5:
                name = parts[0].replace(old_name, new_name)
                path = parts[1].replace(old_path, new_path)
                
                x = str(int(parts[2]) + x_value)
                y = str(int(parts[3]) + y_value)

                traversable = parts[4]

                season = parts[5].replace(old_season, new_season)

                rebuilt = str(int(is_rebuilt))

                modified_line = f"{name} {path} {x} {y} {traversable} {season} {rebuilt} {' '.join(parts[7:])}"
                modified_lines.append(modified_line)

    return modified_lines


my_data = """
"""

#remplace le nom ex tree -> feuillage
old_name = ''
new_name = ''

#remplace le path ex assets/trees/green.png -> assets/trees/orange.png
old_path = 'dead_tree'
new_path = 'rebuilt_tree_green'

#pour corriger la largeur en fonction des modifs
x_value = 0

#pour corriger la hauteur en fonction des modifs
y_value = 0

#corriger les saisons (1 = summer, 2 = autumn ect....)
old_season = '0'
new_season = '1'

is_rebuilt = 2

modified_text = modify_lines(my_data, old_name, new_name, old_path, new_path, y_value, x_value, old_season, new_season, is_rebuilt)
print("\n".join(modified_text))
