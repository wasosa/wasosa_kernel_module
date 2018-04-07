NAME = wasosa_kernel_module

obj-m += $(NAME).o

build: clean
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	@rm -f *~

$(NAME).ko: build

check: $(NAME).ko
	sudo rmmod $(NAME).ko || true
	sudo dmesg -C
	sudo insmod $(NAME).ko
	sudo rmmod $(NAME).ko
	sudo dmesg
