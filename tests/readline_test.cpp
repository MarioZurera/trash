#include <gtest/gtest.h>

extern "C" {
    #include "trash.h"
}


TEST(Readline, NotNull) {
    char *line = readline("");
    ASSERT_NE(line, nullptr);
    free(line);
}

TEST(Readline, EndInNewLine) {
    char *line = readline("");
    ASSERT_EQ(line[strlen(line) - 1], '\n');
    free(line);
}

