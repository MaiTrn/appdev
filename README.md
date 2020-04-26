# appdev project 2020

# This project is for I-IT-1N students to understand what procedure and 
# what tools are needed in an application development.

General Description of the Application

	This application will display the wave for a 5 second sound file (.wav) and display 
	all the necessary information above the wave. Peaks with value larger than 60 dB will 
	be displayed in red color.

	Always indent for paragraphs.

Table of Contents
1. Configuration instructions
2. Installation instructions
3. Operating instructions.
4. File manifest
5. Copyright and licensing information


1. Configuration instructions
	To run this program you need to have putty. 

2. Installation instructions
	Follow these steps: 
		Step 1: open your command prompt window.
		Step 2: move to your desired folder (cd <folder path>)
		Step 3: run this command: git clone https://github.com/MaiTrn/appdev

3. Operating instruction
	Follow these steps:
		Step 1: move to the program folder (cd appdev)
		Step 2: use command make to compile the program
		Step 3: download a 5-second sound file (.wav) and rename it to "test.wav"
		Step 4: run the program using ./sound
	If you wish to delete the program, run make clean

4. File manifest
	In this section you need to offer a list of files included in this application.
	In our case, so far, the list may look like this:
		README.md:		this file.

		display.c:		contains screen manipulation functions.

		display.h:		contains display function declarations and related constants.

		comm.c:			contains the functions for the client-server communication.

		comm.h:			contains communication function declarations and the URL.

		testscreen.c:	contains main function to test the display functions
						and the client-server communication function.

		makefile:		contains the commands to manipulate the C files (make/delete).

		testcurl.c:		contains main function to test the client-server communication.

		sound.c:		handles all the sound manipulation (reading and displaying .wav 
						file header and data).

		sound.h:		contains the struct definition and functions declarations for sound.

		main.c:			main function to put other functions to usage, in this case we 
						open a .wav file and pass it in the sound functions.

		sound.php:		take the sound file information and display it in a php log file.
						to open the log file, copy this address and run it on your 
						internet browser: http://www.cc.puv.fi/~e1900308/php/sound.log

5. Copyright and licensing information
	This application follows FPLv2 license.
