#include <time.h>
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include "Layer.h"

using namespace std;


Layer::Layer(int numOfNodesIn, int numOfNodesOut) {
    this->numOfNodesIn = numOfNodesIn;
    this->numOfNodesOut = numOfNodesOut;
}

void Layer::initializeRandom() {
    srand(time(NULL));
    for (int i = 0; i < numOfNodesIn; i++) {
        for (int j = 0; j < numOfNodesOut; j++) {
            weights[i][j] = (rand() % 1) * 0.1; // random double in range [0, 1)
        }
    }
    for (int i = 0; i < numOfNodesOut; i++) {
        biases[i] = (rand() % 1) * 0.1; // random double in range [0, 1)
    }            
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
        outputs[i] = activationFunction(weightetInputs);
    }
    return outputs;
}