#Zhihao Jin - CS250
#!/bin/bash

#This is the line to test if the command argument is non-negative or omitted.
if [ $1 -gt "0" ] && [ $1 ];then
    echo ""
else
    echo "Please make sure the command line argument greater than 0."
    exit -1
fi

#Enter the name of the program.
echo "Enter name of executable to build:"
read CHECK

#Try to clean the files before make them. 
make clean

make $CHECK
#This will check if the file exists.
if [ $? -eq "0" ];then
    echo ""
else
    echo "No such a file in this directory!"
    exit -1
fi

#Delcare a variable to store the failure times.
FAILURE=`expr 0`

#The for loop will iterate as the command argument entered
for INDEX in `seq 1 $1`; do
    echo "Running test $INDEX..."
    echo ""
    echo "Enter test input file name for test $INDEX"
    #Input the input file name and test if it exist.
    read INPUTFILE
    test -f $INPUTFILE
    if [ $? -eq "0" ];then
	echo ""
    else
	echo "No such a file in this directory."
	exit -1
    fi

    #Enter the amount that user wants to shift character.
    echo "Please enter the command line argument for test $INDEX."
    read SHIFTAMOUNT
    if [ $SHIFTAMOUNT -ge "0" ] && [ $SHIFTAMOUNT ];then
	echo ""
    else
	echo "The command line argument should be existed and non-negative."
	exit -1
    fi
    
    #Enter the name of output file, which is used to compare with input.
    echo "Enter name of file that contains correct output for test 1:"
    read OUTPUTFILE
    test -f $OUTPUTFILE
    #Test if the output exist.
    if [ $? -eq "0" ];then
	echo ""
    else
	echo "No such file in this directory."
	exit -1
    fi
    
    #Run the program and input the content and output the resuts into a
    #temporary file.
    ./rotate $SHIFTAMOUNT < $INPUTFILE > results.txt

    #Test the output file if it exist, and compare with the temporary file
    diff $OUTPUTFILE results.txt
    if [ $? -eq "0" ];then
	echo "test $INDEX succeed"
	echo ""
    else
	FAILURE=`expr $FAILURE + 1`
	echo "test $INDEX failed"
	echo ""
    fi
    rm results.txt
done

#Std output results.
if [ $FAILURE -ne "0" ];then
    echo "The $CHECK didn't pass those tests!"
else
    echo "The $CHECK passed all tests!!!!"
fi



