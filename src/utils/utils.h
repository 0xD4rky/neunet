#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<std::vector<double>> load_data(const std::string& filename);
std::vector<int> load_labels(const std::string& filename);
std::pair<std::vector<std::vector<double>>, std::vector<int>> load_dataset(const std::string& filename);


#endif