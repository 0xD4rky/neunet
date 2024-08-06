#include <iostream>
#include "network.cpp"

int main() {
    std::vector<int> layers = {3, 5, 2}; 
    Network network(layers);
    
    std::vector<double> inputs = {1.0, 0.5, -1.5}; 
    std::vector<double> outputs = network.predict(inputs);
    
    std::cout << "Network output:\n";
    for (double output : outputs) {
        std::cout << output << "\n";
    }
    
    return 0;
}
