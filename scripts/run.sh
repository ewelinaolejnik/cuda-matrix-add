#!/bin/bash

# 🧘 Ustawienia
BUILD_DIR=build

echo "=== CUDA Matrix Add: Build & Run ==="

# 1️⃣ Utwórz folder build jeśli nie istnieje
mkdir -p $BUILD_DIR
cd $BUILD_DIR || exit

# 2️⃣ Wygeneruj pliki buildowe przez CMake
echo "--- Generating build files with CMake ---"
cmake ..

# 3️⃣ Zbuduj projekt (działa na Windows z MSVC i na Linux z make)
echo "--- Building project ---"
cmake --build .

# 4️⃣ Uruchom main (Windows: exe w Debug/ lub Release/, Unix: w build/)
if [ -f Debug/matrix_add.exe ]; then
    echo "--- Running main ---"
    ./Debug/matrix_add.exe
elif [ -f Release/matrix_add.exe ]; then
    echo "--- Running main ---"
    ./Release/matrix_add.exe
elif [ -f matrix_add ]; then
    echo "--- Running main ---"
    ./matrix_add
else
    echo "--- Running main ---"
    ./matrix_add.exe
fi

# 5️⃣ Uruchom testy (matrix_add --test)
if [ -f Debug/matrix_add.exe ]; then
    echo "--- Running tests ---"
    ./Debug/matrix_add.exe --test
elif [ -f Release/matrix_add.exe ]; then
    echo "--- Running tests ---"
    ./Release/matrix_add.exe --test
elif [ -f matrix_add ]; then
    echo "--- Running tests ---"
    ./matrix_add --test
fi

echo "=== Done ==="
