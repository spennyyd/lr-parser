#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

class Lex{
    enum{
        id,
        print,
        num,
        semicolon,
        assign,
        rightParen,
        leftParen,
        comma,
        add,
        subtract,
        multiply,
        divide,
        eof
    };


    struct tokens{
        std::string lexeme;
        int token;
        int line_num;
    };

    std::string strip_space(std::string str)
    {
        std::string replacement = "";
        for(std::string::iterator i = str.begin(); i < str.end(); ++i)
        {
            if(*i != ' ')
            {
                replacement.append(1, *i);
            }

        }
        return replacement;
    }

    std::string getString(char x)
    {
        std::string temp;
        temp.assign(1, x);
        return temp;
    }


    // tokenizes and returns pair containing lexeme and token
    tokens lexer(std::string::iterator &it, int line)
    {

        // If not a single character we need to build out until we reach something
        std::string lexeme = "";
        lexeme.append(1, *it);

        tokens tokenized;
        bool append = true;
        std::string print_check = "print(";
        std::string::iterator pi = print_check.begin();

        while(append)
        {

            // Check for print statment
            if(lexeme == "print(")
            {
                tokenized.line_num = line;
                tokenized.lexeme = lexeme;
                tokenized.token = print;
                append = false;
            }
            // Check for id
            else if(std::regex_match(lexeme, std::regex("[a-zA-Z]+[0-9]*")) && *(it) != *pi)
            {
                tokenized.line_num = line;
                tokenized.lexeme = lexeme;
                tokenized.token = id;
                append = false;
            }
            // Check for number
            else if(std::regex_match(lexeme, std::regex("[0-9]+")) && !std::regex_match(getString(*(it + 1)), std::regex("[0-9]+")))
            {
                tokenized.line_num = line;
                tokenized.lexeme = lexeme;
                tokenized.token = num;
                append = false;
            }
            // Check for assignment
            else if(std::regex_match(lexeme, std::regex(":=")))
            {
                tokenized.line_num = line;
                tokenized.lexeme = lexeme;
                tokenized.token = assign;
                append = false;
            }
            // Check for EOF
            else if(std::regex_match(lexeme, std::regex("EOF")))
            {
                tokenized.line_num = line;
                tokenized.lexeme = lexeme;
                tokenized.token = print;
                append = false;
            }
            else{
                switch(*it)
                {
                case '+':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = add;
                    return tokenized;
                case '-':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = subtract;
                    return tokenized;
                case '*':
                        tokenized.line_num = line;
                        tokenized.lexeme = lexeme;
                        tokenized.token = print;
                case '/':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = divide;
                    return tokenized;
                case '(':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = leftParen;
                    return tokenized;
                case ')':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = rightParen;
                    return tokenized;
                case ';':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = semicolon;
                    return tokenized;
                case ',':
                    tokenized.line_num = line;
                    tokenized.lexeme = lexeme;
                    tokenized.token = comma;
                    return tokenized;
                }
                // std::cout << "Error, illegal symbol in input file\n";
                // exit(1);
                tokenized.line_num = line;
                tokenized.lexeme = lexeme;
                tokenized.token = 13;
                it++;
                lexeme.append(1, *it);
                pi++;
            }
        }
        return tokenized;
    }
    
    public:
    void lex()
    {
        // Variables
        std::string line;
        std::ifstream input;
        std::string filename;
        std::vector<tokens> token_list;
        int line_num = 1;

        // File input and output
        std::ofstream out_file;

        std::cout << "Please enter the name of the file you want to lex: ";
        std::cin >> filename;

        input.open(filename);

        std::cin.clear();
        if(input.is_open())
        {
            while(getline(input, line))
            {
                // Remove spaces from the line
                line = strip_space(line);

                for(std::string::iterator it = line.begin(); it < line.end(); ++it)
                {
                    token_list.push_back(lexer(it, line_num));

                }
                line_num++;
            }
        }

        out_file.open("tokens.txt");
        if(out_file)
        {
            for(int i = 0; i < token_list.size(); ++i)
            {
            out_file << token_list[i].token << "|" << token_list[i].lexeme << "|" << token_list[i].line_num << std::endl;
            }
            out_file << eof << "|EOF|" << line_num;
        }

    }

};