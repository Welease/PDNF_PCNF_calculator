#include <QDebug>
#include "calculation.h"
#include "operations.h"
#include <iostream>
#include "simple_funcs.h"

operation *g_mass_of_operations;

char *get_answer(char *string)
{
    int count_of_var;
    count_of_var = find_count_of_var(string);
    int *i_mass;
    char *c_mass;
    g_mass_of_operations = get_mass_of_operations();
    i_mass = new int[count_of_var + 5];
    c_mass = new char[count_of_var + 6];
    c_mass[count_of_var] = '\0';
    c_mass = fill_c_mass(c_mass, string);
    i_mass = fill_i_mass_by_zero(i_mass, count_of_var);
    return (get_variants(i_mass, count_of_var, string, c_mass));
}

operation *get_mass_of_operations()
{
    operation *mass;
    int i;

    i = 0;
    mass = new operation[8];
    operation disjunction;
    disjunction.set('+', 2, dis_op);
    mass[i++] = disjunction;
    operation conversation;
    conversation.set('*', 2, con_op);
    mass[i++] = conversation;
    operation inversion;
    inversion.set('!', 1, inv_op);
    mass[i++] = inversion;
    operation equivalence;
    equivalence.set('=', 2, equiv_op);
    mass[i++] = equivalence;
    operation implication;
    implication.set('-', 2, imp_op);
    mass[i++] = implication;
    operation x_or;
    x_or.set('~', 2, x_or_op);
    mass[i++] = x_or;
    operation arrow;
    arrow.set('/', 2, arrow_op);
    mass[i++] = arrow;
    operation stroke;
    stroke.set('|', 2, stroke_op);
    mass[i++] = stroke;
    return (mass);
}

void op_in_order(char *string, char *c_mass, int *i_mass, int count_of_var, char *mass_of_ans, int num)
{
    int i;
    i = 0;
    char *s;
    char *copy;
    s = new char[strlen(string) + 6];
    copy = new char[strlen(string) + 6];
    strcpy(s, string);
    strcpy(copy, string);
    while (strlen(s) >= 2)
    {
        i = 0;
        if (count_of_brackets(s))
        {
            s = str_without_brackets(s);
        }
        while (s[i])
        {
            if (s[i] == g_mass_of_operations[2].sign_of_op)
                s = g_mass_of_operations[2].do_op(s, c_mass, i_mass, count_of_var, i);
            else
                i++;
        }
        i = 0;
        while (s[i])
        {
            if (s[i] == g_mass_of_operations[1].sign_of_op)
                s = g_mass_of_operations[1].do_op(s, c_mass, i_mass, count_of_var, i);
            else
                i++;
        }
        i = 0;
        while (s[i])
        {
            if (s[i] == g_mass_of_operations[0].sign_of_op)
                s = g_mass_of_operations[0].do_op(s, c_mass, i_mass, count_of_var, i);
            else
                i++;
        }
        i = 0;
        while (s[i])
        {
            if (s[i] == g_mass_of_operations[4].sign_of_op)
                s = g_mass_of_operations[4].do_op(s, c_mass, i_mass, count_of_var, i);
            else
                i++;
        }
        i = 0;
        while (s[i])
        {
            if (s[i] == g_mass_of_operations[3].sign_of_op)
                s = g_mass_of_operations[3].do_op(s, c_mass, i_mass, count_of_var, i);
            else
                i++;
        }
        i = 0;
        while (s[i])
        {
            if (s[i] == g_mass_of_operations[5].sign_of_op)
                s = g_mass_of_operations[5].do_op(s, c_mass, i_mass, count_of_var, i);
            else if (s[i] == g_mass_of_operations[6].sign_of_op)
                s = g_mass_of_operations[6].do_op(s, c_mass, i_mass, count_of_var, i);
            else if (s[i] == g_mass_of_operations[7].sign_of_op)
                s = g_mass_of_operations[7].do_op(s, c_mass, i_mass, count_of_var, i);
            else
                i++;

        }
        if (count_of_brackets(copy) > 0)
        {
            copy = new_str(copy, s[0]);
            strcpy(s, copy);
        }
    }
    std::cout << s[0] << std::endl;
    mass_of_ans[num] = s[0];
    delete[] s;
    delete[] copy;

}

char *get_variants(int *m, int count_of_var, char *string, char *c_mass)
{
    int c;
    int i;
    int j;
    int r;
    int variants;
    int tmp;
    int *n = new int[count_of_var + 6];
    for (int l = 0; l < count_of_var; l++)
        n[l] = 1;
    int *f = new int[count_of_var + 5];
    f = fill_i_mass_by_zero(f, count_of_var);
    variants = pow(2, count_of_var);
    if (count_of_var == 1)
        variants = 1;
    char *mass_of_ans = new char[variants + 6];
    mass_of_ans[variants] = '\0';
    int **m_of_all_var = new int*[variants + 5];
    for (int q = 0; q < variants; q++)
        m_of_all_var[q] = new int[count_of_var + 5];
    c = 0;
    tmp = 0;
    while (c < variants)
    {
        i = 0;
        while (i < count_of_var)
        {
            m[i] = f[i];
            r = count_of_var - i - 1;
            if((r == 0)|| (((n[i]%(pow(2,r)))) == 0))
            {
                if (f[i] == 0)
                    f[i] = 1;
                else if (f[i] == 1)
                    f[i] = 0;
            }
            i++;
        }
        op_in_order(string, c_mass, m, count_of_var, mass_of_ans, tmp);
        for (int k=0; k < count_of_var; k++)
            m_of_all_var[tmp][k] = m[k];
        j = 0;
        tmp++;
        while (j < count_of_var)
        {
            n[j]++;
            j++;
        }
        c++;
    }
    delete [] f;
    delete [] n;
    delete [] m;
    return (get_result_string_from_mass(c_mass, m_of_all_var, mass_of_ans, variants, count_of_var));
}

char *get_result_string_from_mass(char *c_mass, int **m_of_all_var, char *mass_of_ans, int var, int count)
{
    int i;
    int j;
    int k;
    char *constit;

    i = 0;
    j = 0;
    k = 0;
    if (var == 1)
    {
        constit = new char[5];
        constit[0] = '.';
        constit[1] = c_mass[0];
        constit[2] = ',';
        constit[3] = c_mass[0];
        constit[4] = '\0';
        return (constit);
    }
    constit = new char[8 * var + var + 5];
    while (i < var)
    {
        if (mass_of_ans[i] == '0')
        {
            j = 0;
            constit[k++] = ',';
            while (j < count)
            {
                if (m_of_all_var[i][j] == 0)
                {
                    constit[k++] = c_mass[j];
                    constit[k] = 'v';
                }
                else if(m_of_all_var[i][j] == 1)
                {
                    constit[k++] = '!';
                    constit[k++] = c_mass[j];
                    constit[k] = 'v';
                }
                j++;
                k++;
            }
            k--;
        }
        else if (mass_of_ans[i] == '1')
        {
            j = 0;
            constit[k++] = '.';
            while (j < count)
            {
                if (m_of_all_var[i][j] == 0)
                {
                    constit[k++] = '!';
                    constit[k++] = c_mass[j];
                    constit[k] = '&';
                }
                else if(m_of_all_var[i][j] == 1)
                {
                    constit[k++] = c_mass[j];
                    constit[k] = '&';
                }
                k++;
                j++;
            }
            k--;
        }
        constit[k] = ' ';
        i++;
    }
    constit[k] = '\0';
    delete [] c_mass;
    delete [] mass_of_ans;
    for (int z = 0; z < var; z++)
        delete []m_of_all_var[z];
    delete []m_of_all_var;
    delete g_mass_of_operations;
    return (constit);
}




