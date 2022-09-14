#!/bin/bash
S1=0
test $S1 == "0" && test $S1 -eq "0"
echo $?
