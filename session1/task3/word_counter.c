#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int worder(char *line)
{
    int count = 0;
    printf("%s\n", line);
    for (int i = 0; i < 100; i++)
    {
        if (line[i] == ' ' || line[i] == '\n')
        {
            count += 1;
        }
        if (line[i] == '\n')
        {
            break;
        }
    }
    return count;
}

int charer(char *line)
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        count++;
        if (line[i] == '\n')
            break;
    }
    return count;
}

int main(int argc, char **argv)
{
    if (argc - 2)
        return 1;

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Error: Bad filename\n");
        return 2;
    }

    int chars = 0, words = 0, lines = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        // printf("%s", buffer);
        words += worder(buffer);
        chars += charer(buffer);
        lines += 1;
    }

    printf("Lines: %d\nWords: %d\nChars: %d\n", lines, words, chars);
}