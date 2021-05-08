#ifndef CALCULATION_H
#define CALCULATION_H
class operation
{
friend void op_in_order(char *string, char *c_mass, int *i_mass, int count_of_var, char *mass_of_ans, int num);
private:
    char sign_of_op;
    int count_of_param;
    char *(*do_op) (char *, char *, int *, int, int);
public:
    void set(char sign_of_op, int count_of_param, char *(*do_op)(char *, char *, int *, int, int))
    {
        this->sign_of_op = sign_of_op;
        this->count_of_param = count_of_param;
        (this->do_op) = do_op;
    }
};

char *get_answer(char *string);
char *get_variants(int *m, int count_of_var, char *string, char *c_mass);
char *get_result_string_from_mass(char *c_mass, int **m_of_all_var, char *mass_of_ans, int var, int count);
operation *get_mass_of_operations();
void op_in_order(char *string, char *c_mass, int *i_mass, int count_of_var, char *mass_of_ans, int num);

#endif // CALCULATION_H
