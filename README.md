# URI CSC212 Final Project: Sorting Algorithms
By Claudia Deverdits, Jessica Tingley, Samuel Calise

# Summary
This repository holds the source code for our final project, the implementation of insertion sort, quick sort, merge sort, and parallel insertion sort. 

# Compilation Instructions
The source code is written in C++ and can be compiled in an IDE using the “g++” compiler. You will need the following files:

* main.cpp
* merge_sort.cpp
* merge_sort.h
* quick_sort.cpp
* quick_sort.h
* insertion_sort.cpp
* insertion_sort.h
* parallel_insertion_sort.cpp
* parallel_insertion_sort.h

Once these files are in the same folder, you can access the folder using cd folder_name. You can use the following line in the terminal to compile the program:

```
g++ main.cpp merge_sort.cpp insertion_sort.cpp quick_sort.cpp -o prog
```

# Runtime Instructions
To run the code, enter the following line into your terminal after compiling: 

```
./prog
```

# Our Graphical User Interface
Our graphical user interface (GUI) can be accessed in the "DSA" folder on our repository's main branch. We used Qt, a software development framework for creating graphical user interfaces, with C++ as our implementation language to showcase our group's sorting algorithm implementation. We created separate windows for Quick Sort, Insertion Sort, and Merge Sort, displaying the sorted values in randomly populated arrays of sizes four to six. The code implementation in each window allows for the visualization of the sorting process and displays the expected numerical ascending array. Additionally, each visualization window can view the C++ algorithms implemented, and a link can be copied and pasted into a web browser to access the source code on our GitHub page. If you want to see our GUI, below are steps to download the application onto your computer. (Registering a free account is required to use the application)


Installation Process
1. Go to qt.io and click "Download. Try." in the upper right corner of the site page
2. Scroll down until the you see "Download Qt for open source use"
3. Click "Go open source"
4. Scroll down and click the green button "Download the Qt Online Installer"
5. Scroll down on the page and click "> Download"
6. Then in the bottom right of the browser screen click on the downloaded file
7. When the QT Setup window appears, click next on the bottom right corner of the window
8. An account is required to use Qt, enter your information in the "Sign-up" portion of the window and check "I accept the service terms." When done, click "Next" on the bottom right corner of the window
9. After entering your information, go to the entered email address and verfiy the account (While filling out your information, make sure to check "I am an individual person not using QT for any company")
10. Once completing Step 9, click "Next"
11. Click "I have read and read obligations of using Open Source Qt" and "I am an individual person not using Qt for any company"
12. Click "Next"
13. Click "Disable sending pseudonymous usage statistics in Qt Creator"
14. In the Installation Folder window, click browse, and select your "Desktop" to be the location
15. Click "Next"
16. Click the proper component for your computer's operating system, then click "Next"
17. Click "I have read and agree to the terms contained in the license agreements." Then, click "next"
18. Click "Next" (Again)
19. At the bottom right corner of the window click "Install"
20. When the install is completed, click "Finish" at the bottom right corner of the window.

File Management Process
1. Create a new Folder on your Desktop called, "DSA"
2. Download files and copy the files into the created folder on your Desktop (Only .cpp, .h, .ui)
3. Open Qt Creator, and click "Open Project"
4. Through your computer's file explorer, Go to Desktop, DSA, then click on the Project File called "DSA.pro"

(If there is an error, revisit steps 2-4)
5. The window will then build the project
6. After the build process is finished click the green play bottom on the left corner of the screen, then the window will appear and you are able to enteract and see our visualizations of the sorting algorithms
