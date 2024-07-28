##
## EPITECH PROJECT, 2024
## script
## File description:
## replace_tronc
##

def replace_tronc(data, what_tree, old_tronc, new_tronc):
    lines = data.split('\n')

    for i in range(len(lines) - 1):

        if what_tree in lines[i]:

            if old_tronc in lines[i + 1]:
                lines[i + 1] = lines[i + 1].replace(old_tronc, new_tronc)

    return '\n'.join(lines)


data = """
"""

what_tree = 'rebuilt_green_bg'

old_tronc = 'rebuilt_tronc_green.png'

new_tronc = 'rebuilt_tronc_bg.png'

modified_data = replace_tronc(data, what_tree, old_tronc, new_tronc)
print(modified_data)
