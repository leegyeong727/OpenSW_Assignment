#!/bin/bash

file_wordcnt() {
    count=$(wc -w < "$1")
    echo "$1 파일의 단어는 ${count}개 입니다."
    return 0
}

file_wordcnt file1.txt
file_wordcnt file2.txt
file_wordcnt file3.txt
file_wordcnt sample.txt

