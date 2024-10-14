#include <stdio.h>

#include "trash.h"

char *readline(const char *prompt [[maybe_unused]]) {
    constexpr auto MAX_CHARS = 200;
    char *line = malloc(MAX_CHARS + 1);
    fgets(line, MAX_CHARS, stdin);
    // line[0] = '\0';
    return line;
}
