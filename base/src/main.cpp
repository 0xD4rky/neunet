#include <iostream>
#include <vector>
#include "network.cpp"

int main(){
    std::vector<int> layers = {2,1,3};
    Network net(layers); // ini all the networks with neurons

    std::vector<double> inputs = {0.5,0.8};
    std::vector<double> outputs = net.predict(inputs);
    std::cout << "predicted output : " << outputs[0] << std::endl;
}