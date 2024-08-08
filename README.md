# MY_PROJECT

## About This Template

Ideally you shouldn't have to think too hard your application's build system.
This template aims to make building a C++ project as simple and easy as
possible on all major platforms (Windows, MacOS, and Linux) while not
overcomplicating the setup process by providing too many options. This is an
*intentionally* simple template.

This template provides a cross platform way to [build your code](#how-to-build)
using [CMake](https://cmake.org) (the most popular C++ build system). There is
also a [Python build script](#python-build-script) that runs all of the CMake
commands for you to make it as easy as possible.

Source files are stored in the `src` folder, header files are stored in the
`include` folder, and tests are stored in the `tests` folder. All of these file
paths are customizable. The header files folder can be removed and so can the
tests folder if you disable testing.

Testing is done through [GoogleTest](https://github.com/google/googletest) and
can be disabled if you want.

A [Clang Format](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) file
is provided that can (and probably should) be modified. This provides an easy
way to format your code so that you don't need to obsess over code syle. You can
also remove it if you want.

Source files with the `.c`, `.cpp`, `.cc`, `.cxx`, and `c++` extensions are all
recognized.

This code is licensed under the Unlicense license which means you do anything
with this template without even needing to give credit.

### How to Use This Template (Getting Started)

You'll need to customize a few things before you get started.

- In [CMakeLists.txt](./CMakeLists.txt):
  - Replace `MY_PROJECT` (line 6) with this project's name. This will be the
    name of the main compiled executable. It should also match name of the Git
    repo.
  - *Optionally* change the C++ standard from C++17 (line 7).
  - *Optionally* change the name of the folder where all of your header files
    will live (line 8). You can also remove this line to not have an include
    folder. The default is `include`.
  - *Optionally* change the name of the main file (line 9). The default is
    `main.cpp`.
  - *Optionally* change the name of the folder where all of your source code
    will live (line 10). The default is `src`.
  - *Optionally* disable the testing with GoogleTest (line 11) by replacing `ON`
    with `OFF`. The `run_test` executable will not be built if disabled.
  - *Optionally* change the name of the folder where all of your test files will
    live (line 12). The default is `tests`. This directory can be removed if
    testing is disabled.
- In [this file](./README.md):
  - Find and replace `MY_PROJECT` with this project's name.
- *Optionally* change the Clang Format settings in
  [.clang-format](./.clang-format).
- *Optionally* update or remove license info in [LICENSE](./LICENSE).

## How to Build

### Requirements

Ensure you have [CMake](https://cmake.org) (must be on the path and able to be
called from the command line as `cmake`), a CMake
[generator](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html),
and a C/C++ compiler supported by CMake.

Once you have the repository cloned you can build with the
[Python build script](#python-build-script) or you can
[build manually with CMake](#building-with-cmake). Check out
[how to run the compiled executables](#running-the-executables) once you've
built successfully.

### Python Build Script

If you have Python installed you can build using the [build.py](./build.py)
script. You may have to invoke the Python script with `python3`.

```sh
python build.py
```

If you don't get an error message from the script then you're done.

Using the Python build script you can easily switch between debug and release
builds by adding the `--debug` and `--release` flags (debug by default). The
script will automatically reconfigure CMake if it needs to.

```sh
python build.py --release
```

You can add `-p` or `--parallel` to compile with all CPU cores. Keep in mind
that this can make error messages and warnings less cohesive.

```sh
python build.py -p
```

For more help info run the script with `-h` or `--help`.

> [!NOTE]
> If you are on Windows the script will use
> [`Visual Studio 17 2022`](https://visualstudio.microsoft.com/) as it's
> generator. Otherwise it will use
> [`Unix Makefiles`](https://www.gnu.org/software/make/). If you want to use
> the Python script make sure you have the correct generator installed.
>
> You'll also need to make sure CMake is on the path and callable from the
> shell as `cmake`. You can test this by running `cmake --version` in your
> terminal.

#### Building With CMake

Start by configuring CMake in a build folder called `build`.

```sh
cmake -B build
```

> [!NOTE]
> If you're using a single configuration generator like `Unix Makefiles` (you
> probably are if you're on MacOS/Linux) then you can configure for release mode
> by adding `--DCMAKE_BUILD_TYPE=Release`.
>
> ```sh
> cmake -B build --DCMAKE_BUILD_TYPE=Release
> ```

Now we can build the project by running this:

```sh
cmake --build build
```

> [!NOTE]
> If you're using a multi-configuration generator like `Visual Studio 17 2022`
> (you probably are if you're on Windows) then you can build in release mode by
> adding `--config Release`.
>
> ```sh
> cmake --build build --config Release
> ```

### Running the Executables

Successfully built executables will be in your build directory.

> [!NOTE]
> If you're on Windows using Visual Studio as your generator then your
> executables will be in the `Debug` sub-folder of the `build` directory (or
> `Release` if you built in release mode).

You can run your compiled executable like this:

On MacOS/Linux (using `Unix Makefiles` or a similar generator):

```sh
./build/MY_PROJECT
```

On Windows (using `Visual Studio 17 2022` or a similar generator):

```ps1
.\build\Debug\MY_PROJECT.exe        # Using Visual Studio on Windows (debug)
.\build\Release\MY_PROJECT.exe      # Using Visual Studio on Windows (release)
```

The same goes for the `run_tests` executable (just replace `MY_PROJECT` with
`run_tests`).
