NAME=doc

all: build 

build: 
./generator > e.in
./e < e.in > e.out
./conf < e.out > conf.out
diff e.in conf.out
