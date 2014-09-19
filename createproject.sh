#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
    echo "Usage:  createproject.sh PROJECTDIR"
    exit 1
fi
PROJECTDIR=$1
mkdir -p "$PROJECTDIR"
git archive master | tar -x -C "$PROJECTDIR"
rm "$PROJECTDIR/createproject.sh"
