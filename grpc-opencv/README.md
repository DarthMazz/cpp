# grcp-basic

## grcp.build

### Setup

- gRPCライブラリがビルドされていること
- Pathを追加する

```
export GRPC_INSTALL_PATH=$HOME/.grpc-lib && \
export PATH="$GRPC_INSTALL_PATH/bin:$PATH" $$ \
export OPENCV_INSTALL_PATH=$HOME/.opencv-lib && \
export PATH="$OPENCV_INSTALL_PATH/bin:$PATH"
```

## Build sample app

- CMAKE_PREFIX_PATH でインストール先のディレクトリを指定する
- opencv は、CMakeLists.txt ないに find_package で指定する

```
mkdir -p build && \
pushd build && \
cmake -D CMAKE_PREFIX_PATH=$GRPC_INSTALL_PATH .. && \
make -j 4 && \
popd
```

## reference
