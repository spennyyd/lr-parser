#include <bits/stdc++.h>

struct rule{
    // Option can be 's', 'r', or 'g'
    // Shift, Reduce, Goto
    char option;
    int to_state;
};

rule parse_table[26][17];
void initialize_table();
void set_rule(rule *, char, int);

void initialize_table()
{
    std::cout << "Before Loop\n";
    // Initialize everything to an error state
    for(int i = 0; i < 26; ++i)
    {
        for(int j = 0; j < 17; ++j)
        {
            parse_table[i][j].option = 'e';
            parse_table[i][j].to_state = 404;
        }
    }
    std::cout << "After loop\n";

    enum{
        semicolon,
        id,
        assign,
        print,
        right_paren,
        num,
        left_paren,
        comma,
        plus,
        minus,
        mult,
        div,
        dollar,
        S,
        E,
        L,
        B
    };
    // Put in the rules.
    set_rule(&parse_table[0][id], 's', 2);
    set_rule(&parse_table[0][print], 's', 3);
    set_rule(&parse_table[0][S], 'g', 1);

    set_rule(&parse_table[1][semicolon], 's', 4);
    set_rule(&parse_table[1][dollar], 'a', 100);

    set_rule(&parse_table[2][assign], 's', 5);

    set_rule(&parse_table[3][id], 's', 8);
    set_rule(&parse_table[3][num], 's', 9);
    set_rule(&parse_table[3][left_paren], 's', 10);
    set_rule(&parse_table[3][E], 'g', 7);
    set_rule(&parse_table[3][L], 'g', 6);

    set_rule(&parse_table[4][id], 's', 2);
    set_rule(&parse_table[4][print], 's', 3);
    set_rule(&parse_table[4][S], 'g', 11);

    set_rule(&parse_table[5][id], 's', 8);
    set_rule(&parse_table[5][num], 's', 9);
    set_rule(&parse_table[5][left_paren], 'g', 12);

    set_rule(&parse_table[6][right_paren], 's', 13);

    set_rule(&parse_table[7][right_paren], 'r', 9);
    set_rule(&parse_table[7][comma], 's', 14);
    set_rule(&parse_table[7][plus], 's', 16);
    set_rule(&parse_table[7][minus], 's', 17);
    set_rule(&parse_table[7][mult], 's', 18);
    set_rule(&parse_table[7][div], 's', 19);
    set_rule(&parse_table[7][B], 'g', 15);

    set_rule(&parse_table[8][semicolon], 'r', 4);
    set_rule(&parse_table[8][right_paren], 'r', 4);
    set_rule(&parse_table[8][comma], 'r', 4);
    set_rule(&parse_table[8][plus], 'r', 4);
    set_rule(&parse_table[8][minus], 'r', 4);
    set_rule(&parse_table[8][mult], 'r', 4);
    set_rule(&parse_table[8][div], 'r', 4);

    set_rule(&parse_table[9][semicolon], 'r', 5);
    set_rule(&parse_table[9][right_paren], 'r', 5);
    set_rule(&parse_table[9][comma], 'r', 5);
    set_rule(&parse_table[9][plus], 'r', 5);
    set_rule(&parse_table[9][minus], 'r', 5);
    set_rule(&parse_table[9][mult], 'r', 5);
    set_rule(&parse_table[9][div], 'r', 5);
    set_rule(&parse_table[9][dollar], 'r', 5);

    set_rule(&parse_table[10][id], 's', 2);
    set_rule(&parse_table[10][print], 's', 3);
    set_rule(&parse_table[10][S], 'g', 20);

    set_rule(&parse_table[11][semicolon], 'r', 1);
    set_rule(&parse_table[11][comma], 'r', 1);
    set_rule(&parse_table[11][dollar], 'r', 1);

    set_rule(&parse_table[12][semicolon], 'r', 2);
    set_rule(&parse_table[12][comma], 'r', 2);
    set_rule(&parse_table[12][plus], 's', 16);
    set_rule(&parse_table[12][minus], 's', 17);
    set_rule(&parse_table[12][mult], 's', 18);
    set_rule(&parse_table[12][div], 's', 19);
    set_rule(&parse_table[12][dollar], 'r', 2);
    set_rule(&parse_table[12][B], 'g', 15);

    set_rule(&parse_table[13][semicolon], 'r', 3);
    set_rule(&parse_table[13][comma], 'r', 3);
    set_rule(&parse_table[13][dollar], 'r', 3);

    set_rule(&parse_table[14][id], 's', 8);
    set_rule(&parse_table[14][num], 's', 9);
    set_rule(&parse_table[14][left_paren], 's', 10);
    set_rule(&parse_table[14][E], 'g', 7);
    set_rule(&parse_table[14][L], 'g', 12);

    set_rule(&parse_table[15][id], 's', 8);
    set_rule(&parse_table[15][num], 's', 9);
    set_rule(&parse_table[15][left_paren], 's',10);
    set_rule(&parse_table[15][E], 'g', 22);

    set_rule(&parse_table[16][id], 'r', 10);
    set_rule(&parse_table[16][num], 'r', 10);
    set_rule(&parse_table[16][left_paren], 'r', 10);

    set_rule(&parse_table[17][id], 'r', 11);
    set_rule(&parse_table[17][num], 'r', 11);
    set_rule(&parse_table[17][left_paren], 'r', 11);

    set_rule(&parse_table[18][id], 'r', 12);
    set_rule(&parse_table[18][num], 'r', 12);
    set_rule(&parse_table[18][left_paren], 'r', 12);

    set_rule(&parse_table[19][id], 'r', 13);
    set_rule(&parse_table[19][num], 'r', 13);
    set_rule(&parse_table[19][left_paren], 'r', 13);

    set_rule(&parse_table[20][semicolon], 's', 4);
    set_rule(&parse_table[20][comma], 's', 23);

    set_rule(&parse_table[21][right_paren], 'r', 8);

    set_rule(&parse_table[22][semicolon], 'r', 6);
    set_rule(&parse_table[22][right_paren], 'r', 6);
    set_rule(&parse_table[22][comma], 'r', 6);
    set_rule(&parse_table[22][plus], 'r', 6);
    set_rule(&parse_table[22][minus], 'r', 6);
    set_rule(&parse_table[22][mult], 'r', 6);
    set_rule(&parse_table[22][div], 'r', 6);
    set_rule(&parse_table[22][dollar], 'r', 6);
    set_rule(&parse_table[22][B], 'g', 15);

    set_rule(&parse_table[23][id], 's', 8);
    set_rule(&parse_table[23][num], 's', 9);
    set_rule(&parse_table[23][left_paren], 's', 10);
    set_rule(&parse_table[23][E], 'g', 24);

    set_rule(&parse_table[24][right_paren], 's', 25);
    set_rule(&parse_table[24][plus], 's', 16);
    set_rule(&parse_table[24][minus], 's', 17);
    set_rule(&parse_table[24][mult], 's', 18);
    set_rule(&parse_table[24][div], 's', 19);
    set_rule(&parse_table[24][B], 'g', 15);

    set_rule(&parse_table[25][semicolon], 'r', 7);
    set_rule(&parse_table[25][right_paren], 'r', 7);
    set_rule(&parse_table[25][comma], 'r', 7);
    set_rule(&parse_table[25][plus], 'r', 7);
    set_rule(&parse_table[25][minus], 'r', 7);
    set_rule(&parse_table[25][mult], 'r', 7);
    set_rule(&parse_table[25][div], 'r', 7);
    set_rule(&parse_table[25][dollar], 'r', 7);
}

void set_rule(rule *temp_rule, char option_, int state_)
{
    temp_rule->option = option_;
    temp_rule->to_state = state_;
}

int main()
{
    std::cout << "Before initialize \n";

    initialize_table();
    for(int i = 0; i < 26; ++i)
    {
        std::cout << i;
        for(int j = 0; j < 17; ++j)
        {
            std::cout << " " << parse_table[i][j].option <<  parse_table[i][j].to_state << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}