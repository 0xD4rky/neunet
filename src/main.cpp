#include "network/net.h"
#include "optimizer/utils.h"

#include <ctime>
#include <numeric>
#include <fstream>


#include <iostream>

#include <vector>
#include <limits>
#include <thread>


int main() {
    int num_layers;
    double learning_rate;
    int epochs;
    std::vector<int> layers;

    std::cout << "Enter the layers in the neural network: ";
    std::cin >> num_layers;

    for (int i = 0; i < num_layers; i++) {
        int neurons;
        std::cout << "Enter the number of neurons in layer " << i + 1 << " : ";
        std::cin >> neurons;
        layers.push_back(neurons);
    }

    std::cout << "Enter the learning rate: ";
    std::cin >> learning_rate;

    std::cout << "Enter the number of training epochs: ";
    std::cin >> epochs;

    // Load the dataset
    std::string filename = "data.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1; 
    }

    // Assuming load_dataset function handles file reading
    std::pair<std::vector<std::vector<double>>, std::vector<int>> dataset = load_dataset(filename);
    std::vector<std::vector<double>> data = dataset.first;
    std::vector<int> labels = dataset.second;

    // Initialize the neural network
    Net nn(layers);
    nn.train(data, labels, epochs, learning_rate);

    // Testing prediction
    std::cout << "Enter a test data point [" << layers.front() << " space-separated values]: ";
    std::vector<double> test_input(layers.front());  // Input size should match the input layer size

    for (double &val : test_input) {
        std::cin >> val;
    }

    double prediction = nn.predict(test_input);
    std::cout << "Predicted output: " << prediction << std::endl;

    return 0;
}