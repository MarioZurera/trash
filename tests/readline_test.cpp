#include <gtest/gtest.h>

extern "C" {
    #include "trash.h"
}

static void print_to_itself(const char *text) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    const int out = dup(STDOUT_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    printf(text);
    fflush(stdout);
    dup2(out, STDOUT_FILENO);
    close(out);
}

TEST(Readline, InputString) {
    const char *input = "This is a normal line\n";
    print_to_itself(input);

    char *line = readline("> ");
    ASSERT_STREQ(line, input);
    free(line);
}