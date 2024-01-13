cmake_minimum_required(VERSION 3.8)

project(opencv-basic)

set(SOURCE_FILE main.cpp)

# OpenCVがインストールされたディレクトリのbinにPATHが通っていること
# OpenCVConfig.cmakeファイルを探索する
# ビルドでエラーが発生する場合上記ファイルを直接指定しても良い
# -D OpenCV_DIR=<PATH>
find_package(OpenCV REQUIRED)

# Includeファイルのディレクトリを設定する
# OpenCV_INCLUDE_DIRSはOpenCVConfig.cmakeファイルに定義されている
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

# 実行形式のファイルを作成する
add_executable(opencv-basic
    ${SOURCE_FILE}
)

# Libraryファイルを設定する
# OpenCV_LIBRARIESはOpenCVConfig.cmakeファイルに定義されている
target_link_libraries(opencv-basic
    ${OpenCV_LIBRARIES}
)