#ifndef AUTOMATAMODEL_H
#define AUTOMATAMODEL_H

#include <array>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>


class AutomataModel
{
public:
    AutomataModel(int r, int c, int length, int states);
    std::vector<std::vector<int>> grid;
    void setRule(int length, int states);
    void fill(bool random_start);
private:
    int rows;
    int cols;
    void initialize();
    int rule_length;
    int rule_states;

    std::vector<int> rule;

};

#endif // AUTOMATAMODEL_H
