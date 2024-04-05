#include "Layer.h"
#include "NeuralNetwork.h"
#include <vector>
#include <string>
#include <random>
#include <iostream>

using namespace std;

int main() {
    try {
        cout << "1" << endl;

        vector<int> layerSizes = {2, 2};
        NeuralNetwork neuralNetwork = NeuralNetwork(layerSizes);

        cout << "2" << endl;

        cout << "neuralNetwork.layers size " << neuralNetwork.layers.size() << endl;
        for (int i = 0; i < neuralNetwork.layers.size(); i++) {
            cout << "layer " << i << ": " << endl;
            neuralNetwork.layers[i].toString();
        }

        vector<double> inputs = {0, 1};
        vector<double> outputs = neuralNetwork.calculateOutputs(inputs);

        cout << "outputs size " << outputs.size() << endl;
        for (int i = 0; i < outputs.size(); i++) {
            cout << "output " << i << ": " << outputs[i];
        }
    }
    catch(const std::exception& e) {
        cout << e.what() << '\n';
    }
}