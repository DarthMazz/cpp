# grpc-opencv

## enviroments

```
nodejs --version
v12.22.9
```

## grpc.build

### Setup

- gRPCライブラリがビルドされていること
- Pathを追加する

```
export GRPC_INSTALL_PATH=$HOME/.grpc-lib && \
export PATH="$GRPC_INSTALL_PATH/bin:$PATH" $$ \
export OPENCV_INSTALL_PATH=$HOME/.opencv-lib && \
export PATH="$OPENCV_INSTALL_PATH/bin:$PATH"
```

- Nodejs をインストールする

```
sudo apt update
sudo apt install nodejs
sudo apt install npm
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
## Start Nodejs client app

```
pushd client && \
npm install && \
node ./node greeter_client.js
```

## reference

- [Node / Quick start](https://grpc.io/docs/languages/node/quickstart/)
- [【初心者向け】NPMとpackage.jsonを概念的に理解する](https://qiita.com/righteous/items/e5448cb2e7e11ab7d477)
- [セマンティック バージョニング](https://semver.org/lang/ja/)
- [How To Install Node.js on Ubuntu 22.04](https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-ubuntu-22-04)
- [cv::Mat Class Reference](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)
- [cv::Matの基本処理](http://opencv.jp/cookbook/opencv_mat.html)
- [How to convert opencv mat into string c++](https://stackoverflow.com/questions/61263971/how-to-convert-opencv-mat-into-string-c)