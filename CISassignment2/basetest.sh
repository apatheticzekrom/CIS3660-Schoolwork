#!/bin/bash
case $1 in
pa02.c)
	rm a.out
	gcc pa02.c 
	EXE="./a.out"
	;;
pa02.cpp)
	rm a.out
	g++ pa02.cpp
	EXE="./a.out"
	;;
pa02.java)
	rm pa02.class
	javac pa02.java
	EXE="java pa02"
	;;
*)
    echo "Invalid source file name"
    echo "->  should be pa02.c, pa02.cpp, or pa02.java"
	exit 1
esac


for i in $(ls i?.txt); do
   echo Processing: $i
   eval $EXE $i 8   # comment this line out by placing a # in front of eval...
   eval $EXE $i 16  # comment this line out by placing a # in front of eval...
   eval $EXE $i 32  # comment this line out by placing a # in front of eval...
done
