#include <time.h>
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include "Layer.h"

using namespace std;


void Layer::initializeRandom(unsigned int seed) {
    srand(seed);
    for (int i = 0; i < numOfNodesIn; i++) {
        weights.push_back(vector<double>());
        for (int j = 0; j < numOfNodesOut; j++) {
            weights[i].push_back((rand() % 10) * 0.1); // random double in range [0, 1)
        }
    }
    for (int i = 0; i < numOfNodesOut; i++) {
        biases.push_back((rand() % 10) * 0.1); // random double in range [0, 1)
    }
}

void Layer::toString() {
    cout << "Weights: " << endl;
    for (int i = 0; i < numOfNodesIn; i++) {
        for (int j = 0; j < numOfNodesOut; j++) {
            cout << weights[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Biases: " << endl;
    for (int i = 0; i < numOfNodesOut; i++) {
        cout << biases[i] << " ";
    }
    cout << endl;
}

double Layer::activationFunction(double input) {
    return 0.5 * (input / (1 + abs(input)) + 1);
}

vector<double> Layer::calculateOutputs(vector<double> inputs) {
    vector<double> outputs;
    for (int i = 0; i < numOfNodesOut; i++) {
        double weightetInputs = biases[i];
        for (int j = 0; j < numOfNodesIn; j++) {
            weightetInputs += inputs[j] * weights[j][i];
        }
        outputs.push_back(Layer::activationFunction(weightetInputs));
    }
    return outputs;
}