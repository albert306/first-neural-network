#include "stdlib.h"
#include <vector>

using namespace std;

struct DataPoint {
    public:
        vector<double> inputs;
        int label;
        vector<double> expectedOutputs;

        DataPoint(vector<double> inputs, int label, int numOfLabels) {
            this->inputs = inputs;

            // generate expectedOutputs as onehot
            for (int i = 0; i < numOfLabels; i++) {
                expectedOutputs[i] = 0;
            }
            expectedOutputs[label] = 1;
        }
};