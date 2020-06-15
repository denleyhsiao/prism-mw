#!/bin/bash

set -o errexit

CUR_PATH=`pwd`
WORK_PATH=$(cd $(dirname $0); pwd)
BUILD_PATH=$WORK_PATH/../build
mkdir -p $BUILD_PATH
cd $BUILD_PATH && cmake .. && make && ./test/prism-mw-test
cd $CUR_PATH
