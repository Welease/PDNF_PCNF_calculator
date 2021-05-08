#include "operations.h"
int con(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (0);
    if ((x == 0) && (y == 1))
        return (0);
    if ((x == 1) && (y == 0))
        return (0);
    if ((x == 1) && (y == 1))
        return (1);
    return (-1);
}

int dis(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (0);
    if ((x == 0) && (y == 1))
        return (1);
    if ((x == 1) && (y == 0))
        return (1);
    if ((x == 1) && (y == 1))
        return (1);
    return(-1);
}

int equiv(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (1);
    if ((x == 0) && (y == 1))
        return (0);
    if ((x == 1) && (y == 0))
        return (0);
    if ((x == 1) && (y == 1))
        return (1);
    return (-1);
}

int imp(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (1);
    if ((x == 0) && (y == 1))
        return (1);
    if ((x == 1) && (y == 0))
        return (0);
    if ((x == 1) && (y == 1))
        return (1);
    return (-1);
}

int x_or(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (0);
    if ((x == 0) && (y == 1))
        return (1);
    if ((x == 1) && (y == 0))
        return (1);
    if ((x == 1) && (y == 1))
        return (0);
    return (-1);
}

int stroke(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (1);
    if ((x == 0) && (y == 1))
        return (1);
    if ((x == 1) && (y == 0))
        return (1);
    if ((x == 1) && (y == 1))
        return (0);
    return (-1);
}

int arrow(int x, int y)
{
    if ((x == 0) && (y == 0))
        return (1);
    if ((x == 0) && (y == 1))
        return (0);
    if ((x == 1) && (y == 0))
        return (0);
    if ((x == 1) && (y == 1))
        return (0);
    return (-1);
}

int inver(int x)
{
    if (x == 0)
        return (1);
    if (x == 1)
        return (0);
    return (-1);
}

char *inv_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    char boolean;
    if (string[i + 1] == '0')
        x = 0;
    else if (string [i + 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = inver(x);
    boolean = x + '0';
    string = transform(string, boolean, i, 1);
    return (string);
}

char *con_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = con(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *imp_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = imp(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *dis_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = dis(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *equiv_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = equiv(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *x_or_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = x_or(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *arrow_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = arrow(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *stroke_op(char *string, char *c_mass, int *i_mass, int count_of_var, int i)
{
    int x;
    int y;
    char boolean;

    if (string[i - 1] == '0')
        x = 0;
    else if (string [i - 1] == '1')
        x = 1;
    else
        x = i_mass[find_index_in_c_mass(c_mass, string[i - 1], count_of_var)];
    if (string[i + 1] == '0')
        y = 0;
    else if (string[i + 1] == '1')
        y = 1;
    else
        y = i_mass[find_index_in_c_mass(c_mass, string[i + 1], count_of_var)];
    x = stroke(x,y);
    boolean = x + '0';
    string = transform(string, boolean, i, 2);
    return (string);
}

char *transform(char *string, char b, int ind, int arg)
{
    int i;

    i = 0;
    if (arg == 2)
    {
        while (i < ind)
            i++;
        string[i - 1] = b;
        while (string[i + 2])
        {
          string[i] = string[i + 2];
          i++;
      }
      string[i] = string[i + 2];
    }
    else if (arg == 1)
    {
        i = ind;
        string[i] = b;
        i++;
        while (string[i + 1])
        {
            string[i] = string[i + 1];
            i++;
        }
        string[i] = string[i + 1];
    }
    return (string);
}
