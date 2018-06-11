# Welcome to ECE 264 (Advanced C Programming) 
**Summer 2018**

This git repository will be used to distribute the programming exercises and assignments for the summer offering of ECE 264.
It is highly recommended that you set this up as soon as possible. As students you will have only read access to this repository. New homeworks will be released weekly.

# Getting started with ECE 264 Homeworks
This course will use Linux machines **ONLY. No Windows, no macOS.**  The primary reason for this is the compiler differences across the platforms. What works on one platform may not work in exactly the same manner on another platform. All the homeworks are graded on a Linux machine. 

Step 1
---------------------------------------------
Setup Linux or obtain access to a Linux machine. 
This can be done in the following ways
* You can go to EE 206 and EE 207 and use the machines there. **(Recommended)**
* You can use Purdue ThinLinc https://ecegrid.ecn.purdue.edu/main/ **(Recommended)**
* You can use the desktop client for ThinLinc https://www.cendio.com/thinlinc/download **(Recommended)**
	* Use career account to login
	* For Server use: ecegrid.ecn.purdue.edu
* You can install Linux on your personal computer and make it dual boot (i.e. boot to either Linux or Windows). 
* You can also install Linux inside Windows by using Virtural Box. 
* If you are in an ITaP lab (running Windows), select "Start" and search "Secure". Click "SecureCRT" and connect to ecegrid.ecn.purdue.edu. 
* If you have a Linux (or Mac) computer, you can remotely connect to these machines using secure shell (SSH) on a terminal.  Use "ssh -Y youraccount@ecegrid.ecn.purdue.edu"; The flag -Y allows new windows (such as emacs or ddd) to return to your local machine.  You can add an ssh key so that you do not have to type password every time.

Step 2
---------------------------------------------
Installing git

Once a linux machine is setup make sure to install git on the machine. 
If you are using the Purdue's Thinlinc server's or the EE206/207 Labs this will already be installed and you can skip Step 2 and go to Step 3.

Step 3
---------------------------------------------
Getting Homework 1

For homework 1 you will clone the repository.

* Identify a folder where you want to the homework problems to reside.
* Navigate to the folder
* Open the terminal in the corresponding folder
* Type the following command in the terminal

`git clone https://github.com/ECE264AdvancedCProgramming/2018SummerProblems.git`

Step 4:
---------------------------------------------
To get Homework 2 and later homeworks/assignments.
* Navigate to the folder where you cloned homework 1
* Open the terminal in the corresponding folder
* You can type the following command to get newer homeworks when they are released.

`git pull`

**All homework submissions are on Blackboard only.**

**Congratulations! You are now setup for ECE 264 homeworks.** 

