#!/bin/sh

mkdir -p bin
cd bin
cmake -D foo:BOOL=on -D "bar:STRING=this contains spaces" -D hideMe=mysteryValue -D helpers:FILEPATH=subdir/helpers.txt -D helpDir:PATH=/opt/helpThings -G "Unix Makefiles" ../src

