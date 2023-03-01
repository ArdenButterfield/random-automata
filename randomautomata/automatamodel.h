#ifndef AUTOMATAMODEL_H
#define AUTOMATAMODEL_H

#include <array>
#include <vector>

class AutomataModel
{
public:
    AutomataModel(int rows, int cols);
    std::vector<std::vector<int>> data_array;
private:
    int rows;
    int cols;
    void initialize();

};

#endif // AUTOMATAMODEL_H
