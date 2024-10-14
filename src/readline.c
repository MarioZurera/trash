#include <stdio.h>

#include "trash.h"

char *readline(const char *prompt) {
    constexpr auto MAX_CHARS = 200;

    printf(prompt);
    char *line = malloc(MAX_CHARS + 1);
    fgets(line, MAX_CHARS, stdin);
    return line;
}
