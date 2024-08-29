#include "network/neuron.h"
#include "misc/functions.h"
#include "dataset/data.h"
#include "optimizer/utils.h"

#include <ctime>
#include <numeric>
#include <fstream>


#include <iostream>

#include <vector>
#include <limits>
#include <thread>


int main(){
    int num_layers;
    double learning_rate;
    int epochs;
    std::vector<int> layers;

    std::cout << "Enter the layers in the neural network : ";
    std::cin >> num_layers;

    for (int i = 0; i < num_layers; i++){
        int neurons;
        std::cout << "Enter the number of neurons in layer " << i+1 <<" : ";
        std::cin >> neurons;
        layers.push_back(neurons);
    }
    std::cout << "Enter the learning rate: ";
    std::cin >> learning_rate;

    std::cout << "Enter the number of training epochs: ";
    std::cin >> epochs;

    // Load the dataset
    std::string filename = "data.txt";
    auto [data, labels] = load_dataset(filename);

    
}