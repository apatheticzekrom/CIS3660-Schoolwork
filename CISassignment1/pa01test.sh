#!/bin/bash
case $1 in
    pa01.c)
	rm a.out
	gcc pa01.c 
	if [ $? -ne 0 ]; then 
	    echo "Compile of pa01.c failed"
	    echo "Good bye!"
	    exit 1 
	fi
	EXE="./a.out"
	;;
    pa01.cpp)
	rm a.out
	g++ pa01.cpp
	if [ $? -ne 0 ]; then 
	    echo "Compile of pa01.cpp failed"
	    echo "Good bye!"
	    exit 1 
	fi
	EXE="./a.out"
	;;
    pa01.java)
	rm pa01.class
	javac pa01.java
	if [ $? -ne 0 ]; then 
	    echo "Compile of pa01.java failed"
	    echo "Good bye!"
	    exit 1 
	fi
	EXE="java pa01"
	;;
*)
    echo "Invalid source file name"
    echo "->  should be pa01.c, pa01.cpp, or pa01.java"
    exit 1
esac

echo "Compile of pa01 succeded."

echo "Case #1"
eval $EXE k1.txt p1.txt >stu1Output.txt
diff -w stu1Output.txt base1.txt
echo "Case #1 - complete"

echo "Case #2"
eval $EXE k2.txt p2.txt >stu2Output.txt
diff -w stu2Output.txt base2.txt
echo "Case #2 - complete"

echo "Case #3"
eval $EXE k3.txt p3.txt >stu3Output.txt
diff -w stu3Output.txt base3.txt
echo "Case #3 - complete"

echo "Case #4"
eval $EXE k4.txt p4.txt >stu4Output.txt
diff -w stu4Output.txt base4.txt
echo "Case #4 - complete"
