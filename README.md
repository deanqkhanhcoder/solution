# C++ Problem Solutions

A personal collection of C++ solutions for competitive programming, algorithm practice, and course exercises. The repository is organized by topic and source, with a mix of problem-solving notes, contest code, and reusable implementations.

This workspace contains hundreds of C++ files covering:
- Dynamic programming
- Greedy strategies
- Number theory and combinatorics
- Graph algorithms
- Data structures
- Binary search and two pointers
- String processing and bitmask techniques
- USACO-style training exercises
- Vietnamese olympiad / contest practice

## Repository overview

The repo currently includes multiple source collections:

- CP/: main algorithm and problem-solving folder
- USACO/: training and practice exercises by topic
- NVNS/: Vietnamese competition / olympiad practice
- CPPCLASS/: course-style problem sets and class notes
- 22de/: additional exercise folders

## Quick stats

- 350+ C++ source files
- Main focus: algorithmic problem solving and implementation practice
- Mostly written in C++17 style with GCC/MinGW use in mind
- Several folders include compiled `.exe` files from local testing

## Folder structure

```text
cppvscode/
├── README.md
├── CP/
│   ├── Adhoc/
│   ├── DP/
│   ├── Graph/
│   ├── Number_Theory/
│   ├── Greedy/
│   ├── String/
│   ├── Data_Structures/
│   ├── Binary_Search/
│   ├── Bitmask_DP/
│   ├── Two_Pointers/
│   ├── Stack/
│   ├── Geometry/
│   ├── Digit_DP/
│   ├── Contest/
│   ├── Advanced/
│   ├── Archive/
│   ├── Bit_Manipulation/
│   └── REMOVE/
├── USACO/
│   ├── 2P/
│   ├── Adhoc/
│   ├── BINARY SEARCH/
│   ├── Backtrack/
│   ├── Bronze/
│   ├── Case/
│   ├── Coord/
│   ├── Geo/
│   ├── Graph/
│   ├── Greedy/
│   ├── Greedy + Sort/
│   ├── PQ/
│   ├── Prefix_Sum/
│   ├── Set_Map/
│   ├── Sort/
│   ├── XOR/
│   └── ...
├── NVNS/
│   ├── BINARY SEARCH/
│   ├── Contest 61/
│   ├── DP/
│   ├── DSLK/
│   ├── Pref/
│   └── SoHoc/
├── CPPCLASS/
│   ├── 1/
│   ├── 2/
│   ├── 3/
│   └── Tuan 4/ ... Tuan 13/
├── 22de/
│   ├── 1/
│   └── 2/
├── CAU3.OUT
└── .gitignore
```

## Typical usage

To compile a single file:

```bash
g++ -std=c++17 -O2 -Wall solution.cpp -o solution
./solution
```

If the input is redirected from a file:

```bash
./solution < input.txt
```

## Notes

- Most files are practice solutions rather than polished library code.
- Naming is often descriptive and topic-based, not always standardized.
- Some solutions include Vietnamese comments or problem titles from local contests.
- This repo is intended as a personal learning archive and reference set.

## Goal

Use this repository as a study archive for:
- revisiting known techniques
- finding similar implementations quickly
- practicing algorithm patterns
- preparing for contests and interviews

Happy coding! 
