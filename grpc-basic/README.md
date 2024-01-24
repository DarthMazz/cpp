# grcp-basic

## grcp.build

### Setup

```
export GRPC_INSTALL_PATH=$HOME/.grpc-lib && \
mkdir -p $GRPC_INSTALL_PATH && \
export PATH="$GRPC_INSTALL_PATH/bin:$PATH"
```

### Download the grpc source code

```
mkdir -p library && \
pushd library && \
git clone --recurse-submodules -b v1.60.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc grpc-1.60 && \
ln -s grpc-1.60 grpc
```


### Build and install grpc

- make install する際に root 権限が必要なライブラリがあったので、sudo をつけて実行すること
- CMAKE_INSTALL_PREFIX でインストール先を指定すること。
  - 指定しないとデフォルトのフォルダ /lib などにビルドしたファイルがインストールされる

```
mkdir -p grpc/build
cd grpc/build
cmake -DgRPC_INSTALL=ON \
  -D gRPC_BUILD_TESTS=OFF \
  -D CMAKE_INSTALL_PREFIX=$GRPC_INSTALL_PATH \
  ../ && \
make -j 4 && \
sudo make install && \
popd
```
## Build sample app

CMAKE_PREFIX_PATH でインストール先のディレクトリを指定する

```
mkdir -p build && \
pushd build && \
cmake -D CMAKE_PREFIX_PATH=$GRPC_INSTALL_PATH .. && \
make -j 4 && \
popd
```

## reference

- [gRPC Quick start](https://grpc.io/docs/languages/cpp/quickstart/)
- [Protocol Buffers](https://protobuf.dev)