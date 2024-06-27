# so_long_42

## Introduction

`so_long` is a very small 2D game where the player must collect all collectibles and then exit the map. This project is designed to enhance skills in window management, event handling, and basic game development using the MiniLibX library.

## Features

- **Basic Gameplay**: Collect all items and find the exit.
- **Controls**: Move using W, A, S, D keys (or ZQSD/arrow keys).
- **Window Management**: Smooth window operations and clean exit handling.
- **Map Parsing**: Validate and parse maps with specific requirements.

## Bonus Features

- **On-screen Movement Count**: Display the movement count directly on the screen instead of the shell.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC or Clang)
- GNU Make
- MiniLibX library in the project's folder

### Installation

1. Clone the repository:
    git clone [repository-url] so_long
2. Navigate to the project directory:
    cd so_long
3. Compile the project:
    make all

## Usage

1. Prepare a map file with the `.ber` extension.
2. Run the game with the map file as an argument:
    ./so_long map.ber

### Example Map

1111111111111

10010000000C1

1000011111001

1P0011E000001

1111111111111
