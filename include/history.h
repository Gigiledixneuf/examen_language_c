#ifndef HISTORY_H
#define HISTORY_H

#include <stdbool.h>

#define HISTORY_FILE "data/history.txt"

bool saveHistory(const char *expression);

void showHistory(void);

#endif