obj-m = k_thread.o

all:
	make -C/lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C/lib/modules/$(shell uname -r)/build/ M=$(pwd) clean