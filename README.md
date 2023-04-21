# URI CSC212 Final Project: Sorting Algorithms
Group members: Claudia Deverdits, Jessica Tingley, Samuel Calise

# Summary
This repository holds the source code for our final project, the implementation of insertion sort, quick sort, merge sort, and parallel insertion sort. We have also provided source files to benchmark runtimes, with instructions included in the “Compilation Instructions” section. Our benchmarking tests each algorithm with arrays that are sorted, reverse sorted, partially sorted, and random, recording their runtimes so you can see the differences between each algorithm.

# Algorithms

### Insertion Sort
Insertion Sort is a sorting algorithm that works by sorting one element at a time. While iterating over an input array, for each element, it finds the correct position to insert it into. This algorithm starts with the first element considered to be sorted and compares the second element with the first, inserting it either before or after, depending on if it is smaller or larger. This process is repeated for the next elements all the way until all elements have been considered. With a time complexity of O(n^2) in the worst-case scenario, this algorithm is suitable for small or partially sorted arrays but can be inefficient for larger unsorted arrays.

### Merge Sort
Merge Sort is another sorting algorithm that makes use of the divide-and-conquer strategy. This algorithm divides the array into 2 halves recursively until each has a size of 1; each partition is then merged, being sorted in the process. The merging process works by comparing the first elements of 2 sorted sub-arrays and choosing the smaller element to be added to the merged array, with this continuing until all elements have been merged. Merge sort has a time complexity of O(n log n) making it a good choice for large sets of data. Another great feature of merge sort is its ability for stable sorting to preserve the order of elements of the same value.

### Quick Sort
Quick Sort is a sorting algorithm that uses a divide-and-conquer technique to sort an array. A “pivot” element is selected and the array is partitioned into 2 sub-arrays, with elements less than the pivot going in one sub-array and elements greater than the pivot going in the other array. This process repeats recursively on each sub-array until the whole array is considered sorted. Quick sort has a time complexity of O(n log n) in average case and O(n^2) in the worst case. Even with this worst case time complexity, the average case tends to perform better than other sorting algorithms, making it a popular choice.

### Parallel Insertion Sort
Parallel Insertion Sort is a variation on the insertion sort algorithm that uses parallel processing to sort an array. The input array is divided into smaller array which are then sorted independently by separate threads running in parallel. These sorted sub-arrays are then merged together for the final array. This algorithm has a time complexity of O(n^2/p + n log p) where n is the number of elements and p is the number of processors used, making it useful for sorting large datasets.

# Inputs
In order to run our program, you must enter a command line argument for the number of elements you want to fill the arrays up with. Please read the “Runtime Instructions” for more information on this.

# Outputs
After running the program, runtimes of each algorithm sorting various arrays will be outputted. An example of what to expect would look like the below image:

<img src = "" />

# Compilation Instructions
The source code is written in C++ and can be compiled in an IDE using the “g++” compiler. To run this program with our graphical user interface, continue to the section labeled "Our Graphical User Interface" for instructions on how to install the required software. 

To run this program and benchmark all algorithms, you will need the following files:

* benchmark.cpp
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
g++ benchmark.cpp merge_sort.cpp insertion_sort.cpp parallel_insertion_sort.cpp quick_sort.cpp -o prog
```

# Runtime Instructions
To run the code, enter the following line into your terminal after compiling, where \<num_elements> is replaced by an integer signifying how many elements you would like to populate the arrays with. 

```
./prog <num_elements>
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
* If there is a linker error, revisit steps 2-4
5. The window will then build the project
6. After the build process is finished click the green play bottom on the left corner of the screen, then the window will appear and you are able to enteract and see our visualizations of the sorting algorithms
