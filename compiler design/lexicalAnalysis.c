#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct map
{
    char type;
    char name[32];
} allLexenes[30];

int top = 0;

void main()
{
    char tokens[][32] = {
        "auto", "int", "float", "double", "char", "void", "if", "else", "for", "while",
        "do", "switch", "case", "break", "continue", "return", "struct", "union", "enum",
        "static", "extern", "const", "volatile", "typedef", "sizeof", "goto", "long",
        "short", "signed", "unsigned"};

    char operators[][32] = {
        "=", "+", "-", "*", "/", "%", "^", "&&", "||", "!", "==", "!=", "<", ">", "<=", ">="};

    char punctuation[][32] = {
        ",", ";", ".", "(", ")", "[", "]", "{", "}", "#", "//", "/*", "*/"};

    char specialSymbols[][32] = {
        "&", "|", "->", "::", "~"};

    char preprocessorDirectives[][32] = {
        "#include", "#define", "#ifdef", "#ifndef", "#endif", "#else", "#elif"};

    char code[30];
    printf("Write a line of code: \n");
    fgets(code, 30, stdin);

    int i = 0;
    while (i < strlen(code))
    {
        int front = i;
        int back = i;

        while (code[back] != ' ' && code[back] != ',' && code[back] != ';' && code[back] != '\0')
        {
            back++;
        }

        if (back > front)
        {

            int matched = 0;
            for (int a = 0; a < 30; a++)
            {
                if (strlen(tokens[a]) == back - front)
                {
                    // for tokens
                    matched = 1;
                    for (int j = 0; j < back - front; j++)
                    {
                        if (code[front + j] != tokens[a][j])
                        {
                            matched = 0;
                            break;
                        }
                    }
                    if (matched)
                    {
                        allLexenes[top].type = 't';
                        strncpy(allLexenes[top].name, code + front, back - front);
                        allLexenes[top].name[back - front] = '\0';
                        top++;
                        break;
                    }

                    // for operators
                    matched = 1;
                    for (int j = 0; j < back - front; j++)
                    {
                        if (code[front + j] != operators[a][j])
                        {
                            matched = 0;
                            break;
                        }
                    }
                    if (matched)
                    {
                        allLexenes[top].type = 'o';
                        strncpy(allLexenes[top].name, code + front, back - front);
                        allLexenes[top].name[back - front] = '\0';
                        top++;
                        break;
                    }

                    // for punctuation
                    matched = 1;
                    for (int j = 0; j < back - front; j++)
                    {
                        if (code[front + j] != punctuation[a][j])
                        {
                            matched = 0;
                            break;
                        }
                    }
                    if (matched)
                    {
                        allLexenes[top].type = 'p';
                        strncpy(allLexenes[top].name, code + front, back - front);
                        allLexenes[top].name[back - front] = '\0';
                        top++;
                        break;
                    }

                    // for specialSymbols
                    matched = 1;
                    for (int j = 0; j < back - front; j++)
                    {
                        if (code[front + j] != specialSymbols[a][j])
                        {
                            matched = 0;
                            break;
                        }
                    }
                    if (matched)
                    {
                        allLexenes[top].type = 's';
                        strncpy(allLexenes[top].name, code + front, back - front);
                        allLexenes[top].name[back - front] = '\0';
                        top++;
                        break;
                    }

                    // for preprocessorDirectives
                    matched = 1;
                    for (int j = 0; j < back - front; j++)
                    {
                        if (code[front + j] != preprocessorDirectives[a][j])
                        {
                            matched = 0;
                            break;
                        }
                    }
                    if (matched)
                    {
                        allLexenes[top].type = 'r';
                        strncpy(allLexenes[top].name, code + front, back - front);
                        allLexenes[top].name[back - front] = '\0';
                        top++;
                        break;
                    }
                }
            }

            if (!matched)
            {
                allLexenes[top].type = "-";
                strncpy(allLexenes[top].name, code + front, back - front);
                allLexenes[top].name[back - front] = '\0';
                top++;
            }
        }

        i = back + 1;
    }

    for (int i = 0; i < top; i++)
    {
        if (allLexenes[i].name != "" || allLexenes[i].name != " ")
        {
            printf("%s", allLexenes[i].name);
            printf("%c", allLexenes[i].type);
        }

        if (allLexenes[i].type == 't')
        {
            printf(" => token\n");
        }
        else if (allLexenes[i].type == 'o')
        {
            printf(" => operator\n");
        }
        else if (allLexenes[i].type == 'p')
        {
            printf(" => punctuation\n");
        }
        else if (allLexenes[i].type == 's')
        {
            printf(" => specialSymbol\n");
        }
        else if (allLexenes[i].type == 'r')
        {
            printf(" => preprocessorDirective\n");
        }
        else
        {
            printf(" => identifier\n");
        }
    }
}
