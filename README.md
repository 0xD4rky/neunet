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
