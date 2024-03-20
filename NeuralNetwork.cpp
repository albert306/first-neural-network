#include "stdlib.h"
#include <vector>
#include <string>
#include "Layer.h"
#include "DataPoint.h"

using namespace std;

class NeuralNetwork {
    public:
        vector<Layer> layers;

        NeuralNetwork(vector<int> layerSizes) {
            for (int i = 0; i < layerSizes.size() - 1; i++) {
                layers[i] = Layer(layerSizes[i], layerSizes[i + 1]);
            }
        }

        vector<double> calculateOutputs(vector<double> inputs) {
            for (Layer layer : layers) {
                inputs = layer.calculateOutputs(inputs);
            }
            return inputs;
        }

        int classify(vector<double> inputs) {
            vector<double> outputs = this->calculateOutputs(inputs);

            // find nodeindex with highest activation
            double highestActivation = -INFINITY;
            int highestActivationIndex = 0;
            for (int i = 0; i < outputs.size(); i++) {
                if (outputs[i] > highestActivation) {
                    highestActivation = outputs[i];
                    highestActivationIndex = i;
                }
            }
            return highestActivationIndex;
        }

        double nodeLoss(double activation, double expected) {
            double error = expected - activation;
            return error * error;
        }

        double loss(DataPoint dataPoint) {
            vector<double> outputs = this->calculateOutputs(dataPoint.inputs);
            
            double loss = 0;
            // calculate loss for each node and add up
            for (int i = 0; i < outputs.size(); i++) {
                loss += nodeLoss(outputs[i], dataPoint.expectedOutputs[i]);
            }

            return loss;
        }

        double loss(vector<DataPoint> data) {
            double totalLoss = 0;

            for (DataPoint dataPoint : data) {
                totalLoss += loss(dataPoint);
            }

            return totalLoss / data.size();
        }
};