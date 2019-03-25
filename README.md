### ToDo-List

Simple Implementation of a ToDo-List-Application

## Installing doctest
Run the following commands in a directory appropriate for temporarily saving source code and build configurations.

    git clone https://github.com/onqtam/doctest.git
    cd doctest
    mkdir build
    cd build
    cmake ..
    cmake --build .
    sudo cmake --build . --target install

## Building
Run the following commands in the source directory.

    mkdir build
    cd build
    cmake ..
    cmake --build .

## Testing
In the directory `build`, that was created for building the actual binaries, run the following command.

    ctest --verbose
