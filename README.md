# C Programming Template

A simple template for C programming projects with a standard directory structure and build system.

## Project Structure

```
├── src/                # Source files (.c)
├── include/            # Header files (.h)
├── test/               # Unit tests
│   ├── unity/          # Unity testing framework
│   └── test_*.c        # Test files
├── build/              # Build output (generated)
├── .devcontainer/      # Development container configuration
│   ├── devcontainer.json
│   └── Dockerfile
├── CMakeLists.txt      # Build configuration
├── .clang-format       # Code formatting rules
├── .clang-tidy         # Static analysis configuration
└── .gitignore          # Git ignore rules
```

## Prerequisites

### Option 1: Local Development
- GCC compiler
- CMake build system
- Clang tools (clang-format, clang-tidy) for code formatting and linting

### Option 2: Development Container (Recommended)
- Docker
- Visual Studio Code with Dev Containers extension

The project includes a `.devcontainer` configuration that provides a consistent development environment with all tools pre-installed.

## Getting Started

### Using Development Container
1. Open the project in Visual Studio Code
2. When prompted, click "Reopen in Container" or use Command Palette > "Dev Containers: Reopen in Container"
3. The container will build automatically and install all dependencies
4. Run `cmake --build build && cmake --build build --target test` to verify everything is working

### Using Local Development
Ensure all prerequisites are installed, then proceed with the building instructions below.

## Building and Running

### Build the project
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

### Build and run
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
cmake --build . --target run
```

### Clean build files
```bash
rm -rf build
```

### Run tests
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
cmake --build . --target test
```
Compiles and runs all unit tests using the Unity testing framework.

## Code Quality Tools

### Format code
```bash
mkdir -p build
cd build
cmake ..
cmake --build . --target format
```
Automatically formats all source and header files using clang-format.

### Lint code
```bash
mkdir -p build
cd build
cmake ..
cmake --build . --target tidy
```
Runs clang-tidy to check for potential issues and style violations.

## Adding New Files

1. Place source files (`.c`) in the `src/` directory
2. Place header files (`.h`) in the `include/` directory  
3. Place test files (`test_*.c`) in the `test/` directory
4. CMake will automatically compile all `.c` files in `src/` and `test/`

## Testing

The project uses the Unity testing framework for unit tests. Test files should:
- Be placed in the `test/` directory
- Follow the naming pattern `test_*.c`
- Include `unity/unity.h` and any headers being tested
- Use Unity assertion macros like `TEST_ASSERT_EQUAL_INT()`, `TEST_ASSERT_TRUE()`, etc.
- Have a `main()` function that calls `UNITY_BEGIN()`, runs tests with `RUN_TEST()`, and ends with `UNITY_END()`

Example test structure:
```c
#include "unity/unity.h"
#include "your_module.h"

void test_your_function(void) {
    TEST_ASSERT_EQUAL_INT(5, add_numbers(2, 3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_your_function);
    UNITY_END();
}
```

## Compiler Flags

The project uses these GCC flags:
- `-Wall -Wextra`: Enable most warnings
- `-std=c99`: Use C99 standard
- `-pedantic`: Strict ISO C compliance