#include "functions.h"

double sigmoid(double x){
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x){
    return sigmoid(x) * (1 - sigmoid(x));
}

double relu(double x){
    if(x>0) return x;
    else return 0;
}
double relu_derivative(double x){
    if (x>0) return 1;
    else return 0;
}

double random(double low,double high){
    return low + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(high-low)));
}

double distance_vector(const vector<double>& v1, const vector<double>& v2){
    double d = 0;
	for (size_t i = 0; i < v1.size(); i++)
		d += (v1[i] - v2[i])*(v1[i] - v2[i]);
	return d;

}