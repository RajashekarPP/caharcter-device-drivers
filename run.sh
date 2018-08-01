#!/bin/bash
#File Name : run
#Author       : Raja Shekar 

#user compilation in sequence

	read -p "do u want to compile the myapp.c :[y/n] :" choice
	if [ $choice == 'y' ]; then
		make clean
			if (make)then
			echo "compilation sucessful"
			fi
		ls -ll	
	fi	
	read -p "Do u want to insert the node :[y/n] :" choice
	if [ $choice == 'y' ]; then
		sudo insmod ./modules/MyCharDev.ko
		echo -e "Modelu has been inserted\n"
		lsmod | grep MyCharDev
		dmesg tail -10
		read 
		cat /proc/devices
		echo "please enter major number"
		read major
		echo "sudo mknod ./MyCharDev c major minor"
		sudo mknod ./MyCharDev c $major 0
		sudo chmod 666 MyCharDev
		ls -l MyCharDev
	fi	
	read -p "Do u want to run the application :[y/n]" choice
	if [ $choice == 'y' ]; then
		gcc myapp.c
		echo "a.out file created"
		./a.out
		read
		dmesg tail -n 10
	fi
	sudo rmmod MyCharDev
	dmesg
	unlink MyCharDev
echo "running script is completed"
