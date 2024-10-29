pushd .

cd glfw
if not exist "build" mkdir build
cmake -S . -B build

popd

pushd .

cd glm
if not exist "build" mkdir build
cmake -S . -B build

popd