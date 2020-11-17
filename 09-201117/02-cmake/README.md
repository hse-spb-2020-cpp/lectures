# Using CMake
## Committing
Never commit any intermediate files to the version control system, see `.gitignore`:

```
*.exe
*.o
CMakeFiles/
cmake_install.cmake
*.sln
*.vcxproj
*.vcxproj.filters
CMakeCache.txt
Makefile
```

## First run
* Run `cmake .` to use the default generator (Visual Studio on Windows, GCC on Linux)
* Run `cmake . -G"MSYS Makefiles"` on Windows to use gcc from msys with `Makefile` instead of Visual Studio project.

## Recompiling on files change
* Run `make` or `make -j4` with `Makefile` to recompile.
* Re-compile project in Visual Studio

## Adding or removing files
1. Edit `CMakeLists.txt`.
2. Re-run `cmake .` (no need in `-G` this time).
3. Re-compile project via `make` or Visual Studio (both should see changes).

In case of emergency: `make clean` or "Clean project" in Visual Studio, re-build.

In case of dare emergency: remove all intermediate files and start as if "First run".

## Visual Studio warnings
* Do not try to add files manually in Visual Studio! Use `CMakeLists.txt`

## TODO
* Use `-O2` only in DEBUG mode.
