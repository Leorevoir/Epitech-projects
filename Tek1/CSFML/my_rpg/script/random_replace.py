##
## EPITECH PROJECT, 2024
## B-MUL-200-STG-2-1-myrpg-raphael.petrequin
## File description:
## random_replace
##

import random

def random_replace(data, old_path, new_path):
    lines = data.split('\n')
    indices = [i for i, line in enumerate(lines) if old_path in line]
    replace_count = int(len(indices) * 0.50)

    random.shuffle(indices)
    indices_to_replace = indices[:replace_count]

    for i in indices_to_replace:
        lines[i] = lines[i].replace(old_path, new_path)

    return '\n'.join(lines)


data = """
"""

old_path = 'rebuilt_tree_green'
new_path = 'rebuilt_green_bg'

modified_data = random_replace(data, old_path, new_path)

print(modified_data)
