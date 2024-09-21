#!/bin/bash

# Variables
BUILD_DIR="build"
EXECUTABLE_NAME="GameEngine"

# Step 1: Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir "$BUILD_DIR"
fi

# Step 2: Navigate to the build directory
cd "$BUILD_DIR" || exit

# Step 3: Run CMake to generate build files
echo "Running CMake..."
cmake .. || { echo "CMake configuration failed"; exit 1; }

# Step 4: Build the project using make
echo "Building the project..."
make || { echo "Build failed"; exit 1; }

# Step 5: Run the executable if the build succeeded
if [ -f "$EXECUTABLE_NAME" ]; then
    echo "Running the program..."
    ./"$EXECUTABLE_NAME"
else
    echo "Executable not found! Something went wrong."
    exit 1
fi