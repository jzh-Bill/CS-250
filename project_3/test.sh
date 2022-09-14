#!/bin/bash

./rotate 10 < input1.txt > results.txt

diff results.txt output1.txt
echo "$?"
rm results.txt
