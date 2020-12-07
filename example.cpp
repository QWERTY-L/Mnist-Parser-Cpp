/*
 *
 * Created December 2020
 * Author: Luke Sequeira
 * 
 * Copyright (c) 2020 Luke Sequeira
 * 
 * Data Source: http://yann.lecun.com/exdb/mnist/
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <tuple>
#include "MnistParser.hpp"
#include "BMPArrayConvert.hpp"

int main() {

    auto TrainImagesTuple = MnistParse::ParseMnistImages("train-images.idx3-ubyte");
    auto PrintingTrainImages = std::get<0>(TrainImagesTuple); //Vector of matrixes of images. Dimensions: N x 28 x 28
    auto FlatTrainImages = std::get<1>(TrainImagesTuple); //Vector of flattened image data. Dimensions: N x 784

    auto Labels = MnistParse::ParseMnistLabels("train-labels.idx1-ubyte");

    BMP::arrayToBMP("FirstMnistImage.bmp", PrintingTrainImages[0], PrintingTrainImages[0], PrintingTrainImages[0]); //Creates an image (FirstMnistImage.bmp) from grayscale pixel data. Should be a five.
    std::cout << "The first Mnist Image is: " << Labels[0]; //gets the first mnist image label (5)

    return 0;
}