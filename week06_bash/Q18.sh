#!/bin/bash

SHCNT=$(find . -maxdepth 1 -name "*.sh" | wc -l)
echo "현재 디렉토리의 .sh 파일 개수: $SHCNT"
