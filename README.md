# Unique Words Counter

This tool counts how many unique words appear in a file.

## Description

This tool counts how many unique words appear in a file. There is a restriction - a word shouldn't be longer than 128 characters. The tool is case sensitive.
In order to be used you have to pass as an argument filename.

## Getting Started

### Dependencies

* Ubuntu with build-essential package
* Cmake
* A compatible C++ compiler that supports at least C++11.
* valgrind

### Installing

* Download and unzip the project
* Go into the "uniquewordscounter" folder
```
$ cmake -S . -B build
```
```
$ cmake --build build
```

### Executing program

```
$ cd build/test/
$ ./fileOperators_tests
$ cd ../..
$ ./build/hello_test smalldictionary.txt
```

### Executing program with statistics

```
$ valgrind ./build/hello_test smalldictionary.txt
```

## Authors

Contributors names and contact info

Stefan Grozev

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
