#include "trash.h"

char *readline(const char *prompt [[maybe_unused]]) {
    char *line = malloc(2);
    line[0] = '\n';
    line[1] = '\0';
    return line;
}
