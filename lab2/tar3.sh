echo "the name is $1"
wc $1 -m			#number of chars in file
grep printf $1 -c
gcc $1				#compile
./a.out				#run
