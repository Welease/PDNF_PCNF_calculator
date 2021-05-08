#include "simple_funcs.h"

int find_count_of_var(char *string)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (string[i])
    {
        if ((string[i] != '0') &&
                (string[i] != '1') &&
                (!check_op(string[i])) &&
                (!was_before(string, string[i], i)) &&
                (string[i] != '(') &&
                (string[i] != ')'))
            count++;
        i++;
    }
    return (count);
}

int check_op(char c)
{
    if ((c == '+') ||
        (c == '*') ||
        (c == '!') ||
        (c == '~') ||
        (c == '-') ||
        (c == '=') ||
        (c == '/') ||
        (c == '|'))
        return (1);
    return (0);
}

int was_before(char *str, char c, int position)
{
    int i;

    i = 0;
    while (i < position)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int pow(int nb, int power)
{
    int i;
    int res;

    res = 1;
    i = 1;
    if (power < 0)
        return (0);
    if (nb == 1)
        return (1);
    if (power > 0)
    {
        while (power)
        {
            res = i * nb;
            power--;
            i = i * nb;
        }
    }
    return (res);
}


int *fill_i_mass_by_zero(int *i_mass, int size)
{
    int i;

    for (i = 0; i < size; i++)
        i_mass[i] = 0;
    return (i_mass);
}

char *new_str(char *copy, char split)
{
    int i;
    int a;
    int b;
    int j;
    int ind_of_b;
    char *res;

    i = 0;
    j = 0;
    ind_of_b = in_of_b(copy);
    a = find_i_of_bracket(copy, ind_of_b - 1);
    b = find_i_of_bracket(copy, ind_of_b);
    res = new char[strlen(copy) - (b - a) + 1];
    while (copy[j])
    {
        if (j < a)
            res[i++] = copy[j];
        else if (j == a)
            res[i++] = split;
        else if (j > b)
            res[i++] = copy[j];
        j++;
    }
    res[i] = '\0';
    strcpy(copy, res);
    delete[] res;
    return (copy);
}

int find_i_of_bracket(char *s, int num_of_br)
{
    int i;

    i = 0;
    while (num_of_br)
    {
        if ((s[i] == '(') || (s[i] == ')'))
            num_of_br--;
        i++;
    }
    return (i - 1);
}

char *str_without_brackets(char *s)
{
    int i;
    int a;
    int b;
    int ind_of_b;
    char *res;

    i = 0;
    if (!(count_of_brackets(s)))
        return (s);
    ind_of_b = in_of_b(s);
    a = find_i_of_bracket(s, ind_of_b - 1);
    b = find_i_of_bracket(s, ind_of_b);
    res = new char[b - a];
    while (i < b - a - 1)
    {
        res[i] = s[i + a + 1];
        i++;
    }
    res[i] = '\0';
    strcpy(s, res);
    delete[] res;
    return (s);
}

int in_of_b(char *s)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (s[i])
    {
        if (s[i] == '(')
            num++;
        if (s[i] == ')')
            return (num + 1);
        i++;
    }
    return (0);
}

int check_brackets_in_or_near(char *s)
{
    int size;
    int tmp1;
    int i;
    int tmp2;

    tmp1 = 0;
    tmp2 = 0;
    i = 0;
    size = strlen(s);
    while (i < size)
    {
        if (s[i] == '(')
            tmp1++;
        else if (s[i] == ')')
            tmp2++;
        if (tmp1 - tmp2 >= 2)
            return (1);
        i++;
    }
    return (2);
}

int count_of_brackets(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if ((s[i] == '(') || (s[i] == ')'))
            count++;
        i++;
    }
    return (count);
}

char *fill_c_mass(char *c_mass, char *string)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (string[i])
    {
        if ((!check_op(string[i])) && (!was_before(string, string[i], i)) && (string[i] != '0') && (string[i] != '1') && (string[i] != ')') && (string[i] != '('))
            c_mass[j++] = string[i];
        i++;
    }
    return (c_mass);
}

int find_index_in_c_mass(char *c_mass, char c, int size)
{
    int k;

    k = 0;
    while (k < size)
    {
        if (c_mass[k] == c)
            return (k);
        k++;
    }
    return (0);
}
