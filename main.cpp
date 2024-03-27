#include "Layer.h"
#include "NeuralNetwork.h"
#include <vector>
#include <string>
#include <random>
#include <iostream>

using namespace std;

int main() {
    vector<int> layerSizes = {2, 2};
    NeuralNetwork neuralNetwork = NeuralNetwork(layerSizes);

    vector<double> inputs = {0, 1};
    vector<double> outputs = neuralNetwork.calculateOutputs(inputs);

    for (int i = 0; i < outputs.size(); i++) {
        cout << "output " << i << ": " << outputs[i];
    }
    
}