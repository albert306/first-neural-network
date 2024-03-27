#include <vector>
#include <string>
#include "NeuralNetwork.h"
#include "Layer.h"
#include "DataPoint.h"

using namespace std;


NeuralNetwork::NeuralNetwork(vector<int> layerSizes) {
    for (int i = 0; i < layerSizes.size() - 1; i++) {
        layers[i] = Layer(layerSizes[i], layerSizes[i + 1]);
        layers[i].initializeRandom();
    }
}

vector<double> NeuralNetwork::calculateOutputs(vector<double> inputs) {
    for (Layer layer : layers) {
        inputs = layer.calculateOutputs(inputs);
    }
    return inputs;
}

int NeuralNetwork::classify(vector<double> inputs) {
    vector<double> outputs = this->calculateOutputs(inputs);

    // find nodeindex with highest activation
    double highestActivation = 0;
    int highestActivationIndex = 0;
    for (int i = 0; i < outputs.size(); i++) {
        if (outputs[i] >= highestActivation)    {
            highestActivation = outputs[i];
            highestActivationIndex = i;
        }
    }
    return highestActivationIndex;
}

double NeuralNetwork::nodeLoss(double activation, double expected) {
    double error = expected - activation;
    return error * error;
}

double NeuralNetwork::loss(DataPoint dataPoint) {
    vector<double> outputs = this->calculateOutputs(dataPoint.inputs);

    double loss = 0;
    // calculate loss for each node and add up
    for (int i = 0; i < outputs.size(); i++) {
        loss += this->nodeLoss(outputs[i], dataPoint.expectedOutputs[i]);
    }

    return loss;
}

double NeuralNetwork::loss(vector<DataPoint> data) {
    double totalLoss = 0;

    for (DataPoint dataPoint : data) {
        totalLoss += NeuralNetwork::loss(dataPoint);
    }

    return totalLoss / data.size();
}