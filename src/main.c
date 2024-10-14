#include <stdio.h>

#include "trash.h"

int main(int argc [[maybe_unused]], char **argv [[maybe_unused]])
{
    char *line = readline("> ");
    printf("%s", line);
    free(line);
    return EXIT_SUCCESS;
}
