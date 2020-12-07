# Mnist-Parser-Cpp

Parses MNIST Data to an array. This project includes a file from my other project that creates images from arrays

## Usage

An example is available in example.cpp. `MnistParse::ParseMnistImages(Path_to_file);` parses the images into a tuple of arrays. The first is an array of matrices of pixel intensities (of type unsigned int) with the dimensions of `N x 28 x 28` (where N is the amount of images). The second is an array of flattened images (of type double) with the dimensions `N x 784` (Note that 28 * 28 = 784).

After using `#include "MnistParser.hpp"`, You can get the data out of these tuples like so:

```
    auto TrainImagesTuple = MnistParse::ParseMnistImages("train-images.idx3-ubyte");
    auto PrintingTrainImages = std::get<0>(TrainImagesTuple); //Vector of matrixes of images. Dimensions: N x 28 x 28
    auto FlatTrainImages = std::get<1>(TrainImagesTuple); //Vector of flattened image data. Dimensions: N x 784
```

To parse the labels, Use `MnistParse::ParseMnistLabels(Path_to_file)` which returns a list of labels (as unsigned ints).


If you have any questions, feel free to ask.

## Array to Image

To convert the grayscale MNIST images to .bmp images, use `#include "BMPArrayConvert.hpp"`. To print the Nth element,

```
BMP::arrayToBMP("FirstMnistImage.bmp", PrintingTrainImages[0], PrintingTrainImages[0], PrintingTrainImages[0]);
```
