#ifndef SIMPLE_FUNCS_H
#define SIMPLE_FUNCS_H
#include <iostream>
#include <string.h>
char *str_without_brackets(char *s);
int find_count_of_var(char *string);
int check_op(char c);
int was_before(char *str, char c, int position);
char *fill_c_mass(char *c_mass, char *string);
int *fill_i_mass_by_zero(int *i_mass, int size);
int pow(int nb, int power);
int in_of_b(char *s);
int count_of_brackets(char *s);
char *new_str(char *copy, char split);
int find_i_of_bracket(char *s, int num_of_br);
int find_index_in_c_mass(char *c_mass, char c, int size);
int check_brackets_in_or_near(char *s);
#endif // SIMPLE_FUNCS_H
