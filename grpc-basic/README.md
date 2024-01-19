# grcp-basic

## grcp.build

### Setup

```
export GRPC_INSTALL_DIR=$HOME/.grpc-lib && \
mkdir -p $GRPC_INSTALL_DIR && \
export PATH="$GRPC_INSTALL_DIR/bin:$PATH"
```

### Download the grcp source code

```
mkdir -p library && \
pushd library && \
git clone --recurse-submodules -b v1.60.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc grpc-1.60 && \
ln -s grpc-1.60 grpc
```


### Build and install opencv

make install する際に root 権限が必要なライブラリがあったので、sudo をつけて実行すること

```
mkdir -p grpc/build
cd grpc/build
cmake -DgRPC_INSTALL=ON \
  -DgRPC_BUILD_TESTS=OFF \
  -DCMAKE_INSTALL_PREFIX=$GRPC_INSTALL_DIR \
  ../ && \
make -j 4 && \
sudo make install && \
popd
```
## Build sample app

```
mkdir -p build && \
pushd build && \
cmake .. && \
make -j 4 && \
popd
```

## reference

- [opencv.org](https://opencv.org)
- [C++でOpenCV完全入門！](https://zenn.dev/turing_motors/articles/daf3e8829f0967)
