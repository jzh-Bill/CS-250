#!/bin/bash
# GNU bash, version

for LETTER in a b c d; do
    for NUMBER in `seq 1 10`;do
	echo "$LETTER$NUMBER"
    done
done
