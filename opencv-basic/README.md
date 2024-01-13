# opencv-basic

## opencv.build

### Setup

```
export OPENCV_INSTALL_DIR=$HOME/.opencv-lib && \
mkdir -p $OPENCV_INSTALL_DIR && \
export PATH="$OPENCV_INSTALL_DIR/bin:$PATH"
```

### Download the opencv source code

```
mkdir -p library && \
pushd library && \
wget https://github.com/opencv/opencv/archive/4.8.1.zip -O opencv-4.8.1.zip && \
unzip opencv-4.8.1.zip && \
ln -s opencv-4.8.1 opencv
```


### Build and install opencv

```
mkdir -p opencv/build
cd opencv/build
cmake -D CMAKE_INSTALL_PREFIX=$OPENCV_INSTALL_DIR \
  -D BUILD_DOCS=OFF \
  -D BUILD_EXAMPLES=OFF \
  -D BUILD_TESTS=OFF \
  -D BUILD_PERF_TESTS=OFF \
  -D BUILD_opencv_calib3d=OFF \
  -D BUILD_opencv_dnn=OFF \
  -D BUILD_opencv_features2d=OFF \
  -D BUILD_opencv_flann=OFF \
  -D BUILD_opencv_gapi=OFF \
  -D BUILD_opencv_highgui=OFF \
  -D BUILD_opencv_ml=OFF \
  -D BUILD_opencv_photo=OFF \
  -D BUILD_opencv_video=OFF \
  -D BUILD_opencv_videoio=OFF \
  ../ && \
make -j 4 && \
make install && \
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
