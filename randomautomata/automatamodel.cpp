#include "automatamodel.h"

AutomataModel::AutomataModel(int r, int c)
{
    rows = r;
    cols = c;
    data_array.resize(rows, std::vector(cols, 0));

    initialize();
}

void AutomataModel::initialize()
{
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            data_array[r][c] = (r + c) % 2; // TEMP
        }
    }
}
