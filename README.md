# README #

This project is a character device driver created for the Howard University Operating Systems Course. The course is taught by Dr. Gedare Bloom.


Our solution for the device driver is to create a mailbox object that can read or write from either side. It receives data from user input. The driver is able to account for multiple instances of the object. I/O is resolved using mutex locks to prevent an instance of the mailbox from
having access to the read/write buffers while another is currently using it. 

Challenges: 

The first challenge was understanding what the best choice was between spinlocks and mutex for handling I/O. After some research, we decided to go with mutex because it was the option that would most likely give us the shortest wait time as possible. 

The second challenge was thinking about how to design a device driver and what structures and functions would be needed to accomplish the task. 

### How do I get set up? ###
Set Up: 

Download the repository. You must be running linux kernel version 3.16.0 for this to work. 
Open up a terminal window and change the directory to the downloaded folder. From there you can run make on the mailbox file. 
To add the device driver:

make
sudo insmod mailbox.ko
sudo dmsg - this shows the output of adding the module and if it was successful or not. 
gcc test.c
sudo ./a.out 

Removing the module:

sudo rmmod mailbox.ko
sudo dmsg - shows output of removing the module

### Resources ###
http://derekmolloy.ie/writing- a-linux-kernel-module-part-2- a-character-device/ -char device driver

https://www.kernel.org/doc/ htmldocs/kernel-api/kfifo.html - kfifio

http://tuxthink.blogspot.com/ 2011/04/wait-queues.html - wait queue

https://stuff.mit.edu/afs/ sipb/contrib/linux/samples/ kfifo/record-example.c