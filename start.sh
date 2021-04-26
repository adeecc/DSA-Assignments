#!/usr/bin/bash

mkdir $1 && cd $1

for i in {a..j}
do
    touch $i.cpp
done