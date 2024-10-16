#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

class Data {
public:
    std::vector<std::vector<double>> inputs;
    std::vector<double> outputs;

    Data(const std::string& filepath);
    void load_data(const std::string& filepath);
    void normalize();
    std::pair<std::vector<double>, double> get_item(int index);
};

#endif
