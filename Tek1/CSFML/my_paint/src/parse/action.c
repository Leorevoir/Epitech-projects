/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** action
*/

#include "button.h"

const button_action_mapping_t button_actions[] = {
    {"pencil", pencil}, {"eraser", eraser}, {"pipette", pipette},
    {"peinture", select_peinture}, {"file", select_file}, {"trait", trait},
    {"-new", create_new_file}, {"-open", open_ctrl}, {"square", square},
    {"-save", handle_ctrl_s}, {"$main", main_color}, {"$secnd", secnd},
    {"edit", edit}, {"help", help}, {"$red", red}, {"$black", black},
    {"$yellow", yellow}, {"$green", green}, {"$dred", d_red}, {"$gray", gray},
    {"$rng", orange}, {"$mgta", magnta}, {"$wht", white}, {"$lgray", lgray},
    {"$lrng", lrng}, {"$pink", pink}, {"$yllw", yllw}, {"$beig", beig},
    {"$lgrn", lgrn}, {"$llbl", llbl}, {"$bgbl", bgbl}, {"$bgpl", bgpl},
    {"$sav", handle_ctrl_s}, {"$lblue", lblue}, {"$dblue", dblue},
    {"$color", color_png}, {"size", sizepx}, {"&px1", px1}, {"&px3", px3},
    {"&px5", px5}, {"&px8", px8}, {"@pencil", pencil}, {"@eraser", eraser},
    {"circle", circle}, {"+help", hhelp}, {"+about", about},
    {NULL, NULL}
};
