#include <vector>
#include "DataPoint.h"

using namespace std;


DataPoint::DataPoint(vector<double> inputs, int label, int numOfLabels) {
    this->inputs = inputs;

    // generate expectedOutputs as onehot
    for (int i = 0; i < numOfLabels; i++) {
        expectedOutputs[i] = 0;
    }
    expectedOutputs[label] = 1;
}