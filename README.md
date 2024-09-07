# Neural Network in C++ from Scratch

This project implements a basic feedforward neural network in C++ using custom layers, neurons, and backpropagation. The network can be trained on a binary classification dataset. 

The project is organized as follows:

```
neunet/ 
  ├── src/
    │ ├── network/
      │ │ ├── net.h
      │ │ ├── net.cpp
      │ │ ├── layer.h
      │ │ ├── layer.cpp
      │ │ ├── neuron.h
      │ │ ├── neuron.cpp
    │ ├── optimizer/
      │ │ ├── utils.h
      │ │ ├── utils.cpp
    │ └── main.cpp
    ├── data.txt
    └── Build.bat
```

## Prerequisites

- **C++ Compiler**: You need a C++ compiler like `g++` to compile the project. You can install it as part of the **MinGW** toolset, available on Windows.
- **Command Prompt (cmd)**: The project is set up to run in a Windows environment using `cmd`.

## Setup and Compilation

### Step 1: Install MinGW (if not already installed)
If you do not have `g++` installed on your system, follow these steps:
1. Download the **MinGW Installer** from [here](https://sourceforge.net/projects/mingw/).
2. During installation, select the **g++ compiler**.
3. Add the `bin` directory of your MinGW installation to your system’s `PATH` environment variable.

### Step 2: Prepare the Dataset
You will need a dataset file (`data.txt`) that contains rows of data, with the last value of each row being the label.

Place the `data.txt` file in the root of the project directory.

### Step 3: Compile the Project

1. Open the **Command Prompt**.
2. Navigate to the `src/` directory of your project:

   ```bash
   cd path\to\your\project\src```
4. Run the provided `Build.bat` script to compile the project.

If the build is successful, you will see a neural_net.exe executable generated in the src/ folder. 

## Running the Program

Once the project has been compiled, follow these steps to run the neural network:

### Step 1: Run the Executable

In the Command Prompt, ensure you are in the `src/` directory. Run the following command:

```bash
neural_net.exe
```

### Step 2: Input the Neural Network Configuration

The program will prompt you to enter various parameters for configuring the neural network:

* Number of Layers: Enter the total number of layers (excluding the input layer).
* Neurons per Layer: For each layer, input the number of neurons.
* Learning Rate: Input the learning rate (e.g., 0.01).
* Training Epochs: Input the number of epochs to train the network.

### Step 3: Provide a Test Data Point

After training, the program will prompt you to enter a test data point (space-separated values). The test input should match the dimensionality of the input layer.\

```
Enter a test data point [space-separated]: 1.5 2.3 4.0
```

## Project Structure:

* main.cpp: The entry point of the program. It initializes the neural network, loads the dataset, and manages training and prediction.
* network/: Contains the core implementation of the neural network.
* net.cpp: Manages the entire network, layers, and training.
* layer.cpp: Defines the layer class, which contains neurons and performs forward and backward propagation.
* neuron.cpp: Defines the neuron class, which holds weights, biases, and activation functions.
* optimizer/utils.cpp: Provides utility functions for loading the dataset and performing weight updates.

## Example Usage:

```
Enter the layers in the neural network: 3
Enter the number of neurons in layer 1: 4
Enter the number of neurons in layer 2: 5
Enter the number of neurons in layer 3: 1
Enter the learning rate: 0.01
Enter the number of training epochs: 1000
Training the network...
Enter a test data point [space-separated]: 2.0 1.5 3.0
Predicted output: 0.85
```

## License
This project is licensed under the MIT License. You are free to modify and distribute it as you wish.
