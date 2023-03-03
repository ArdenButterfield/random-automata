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
    AutomataModel(int rows, int cols);
    std::vector<std::vector<int>> grid;
    void setRule(int length=3, int states=2);
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
