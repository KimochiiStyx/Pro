#README
#Written by Sun Haoyuan
#This project is written for Linux OS
#https://github.com/KimochiiStyx/Pro
------------------------------------------------
Title of the project: Acoustic Sensor using RPi3
------------------------------------------------

1. Configuration Instructions

This section contains 2 parts: hardware configurations and software configuration.

	1.1 Hardware configuration
	
	This project is built on a Raspberry pi3, with a USB sound card and a microphone.
	Ethernet connection is recommeded. If an older version of Raspberry Pi is used,
	certain change might be necessary.
	
	1.2 Software configuration:
	
			The USB sound card has to be set as default audio device.
			To do so, you need to modify two files with following contents:
	
		1)you have to set USB sound card as default audio device.
	
		2)you need to downgrade the alsa-utils from 1.0.28 to 1.0.25.
	
			a) Use “lsusb” command to check if your USB sound card is mounted
			b) Use "sudo nano /etc/asound.conf" command and put the following content:
	
				pcm.!default {
				  type plug
				  slave {
				    pcm "hw:1,0"	
				  }
				}
				ctl.!default {
				    type hw
				    card 1
				}
	
			c) Go to your home directory. Use “nano .asoundrc” command and put the same content to the file.
			d) Run “alsamixer” you should be able to see that USB sound card is the default audio device

2. Installation Instructions
	a) Open Terminal Windows on Linux
	b) Change your terminal to UTF-8
	c) Type "make" to compile and link all the source code

3. Operation Instructions
	a) After the installation, simply execute "./wave.a" in the project folder.
	b) View in DEBUG mode, where you can see the file WAV header: go to "wave.h" and add line "#define DEBUG".
	c) View in COMM  mode, where your program will send the record information to the server: go to "comm.h" and add line "#define COMM".
	d) Stop the program: 'Ctrl + C'.

4. List of project files
The project contains following files:
--README.md :  this file
--makefile  :  the makefile of this project
--wave.c    :  the module containing functions about wave processing
--wave.h    :  the header of wave.c
--screen.c  :  the module contaububg functions about screen manipulation
--screen.h  :  the header of screen.c
--comm.c    :  the communication module using libcurl
--comm.h    :  the header file of comm.c
--main.c    :  contains main() function
--sound.php :  the server page to receive data

5. Contact Information
	Name: Sun Haoyuan
	Phone: 046 5494 022
	Email: 598053856@qq.com

6. If you have any problem with this program you can contact me, if not, you are very awesome!!! 
