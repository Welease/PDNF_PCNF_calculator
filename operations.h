#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "simple_funcs.h"
char *transform(char *string, char b, int ind, int argc);
int con(int x, int y);
int dis(int x, int y);
int equiv(int x, int y);
int imp(int x, int y);
int x_or(int x, int y);
int stroke(int x, int y);
int arrow(int x, int y);
int inver(int x);
char *inv_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *imp_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *equiv_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *con_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *dis_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *stroke_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *arrow_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);
char *x_or_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i);

#endif // OPERATIONS_H
