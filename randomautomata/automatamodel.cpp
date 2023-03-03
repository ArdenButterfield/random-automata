#include "automatamodel.h"

AutomataModel::AutomataModel(int r, int c)
{
    rows = r;
    cols = c;
    grid.resize(rows, std::vector(cols, 0));
    srand (time(NULL));
    initialize();
    rule_length = 3;
    rule_states = 2;
}

void AutomataModel::initialize()
{
    setRule(1,1);
    fill(true);
}

void AutomataModel::setRule(int length, int states)
{
    rule_length = length;
    rule_states = states;
    int possibilities = std::pow(states, length);
    rule.resize(possibilities);
    for (int i = 0; i < possibilities; ++i) {
        rule[i] = rand() % states;
    }
}

void AutomataModel::fill(bool random_start)
{
    std::cout << "filling\n";
    for (auto &row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
    if (random_start) {
        for (int i = 0; i < rows; ++i) {
            grid[0][i] = rand() % rule_states;
        }
    } else {
        grid[0][cols / 2] = 1;
    }

    std::vector<std::vector<int>>::iterator current_row = grid.begin();
    std::vector<std::vector<int>>::iterator prev_row = grid.begin();

    int offset = rule_length / 2;
    while (++current_row != grid.end()) {
        for (int c = 0; c < cols; ++c) {
            int score = 0;
            for (int i = 0; i < rule_length; ++i) {
                int index = (c + cols - offset + i) % cols;
                score += (*prev_row)[index] * std::pow(rule_states, i);
            }
            (*current_row)[c] = rule[score];
        }
        prev_row = current_row;
    }
}






