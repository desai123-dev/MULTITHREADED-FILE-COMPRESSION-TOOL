# MULTITHREADED-FILE-COMPRESSION-TOOL


*COMPANY* :CODETECH IT SOLUTIONS

*NAME* :ANIKET DESAI

*INTERN ID* :CT08DL616

*DOMAIN*:C++PROGRAMMING

*DURATION*:8WEEK

*MENTOR*:NEELA SANTOSH KUMAR



Project Title: MULTITHREADED-FILE-COMPRESSION-TOOL
Internship Program: CODTECH – Task 2

Project Description:
This project, titled "Multithreaded File Compression Tool", was developed as part of Task-2 of the CODTECH Internship Program. The primary goal of this task is to build an efficient file compression application in C++ that leverages multithreading to enhance performance. Multithreading allows parallel execution of code, making it a powerful technique to improve the speed and efficiency of file operations—especially on large datasets.

The application uses a simple but effective compression technique called Run-Length Encoding (RLE). RLE works by replacing sequences of repeated characters with a single character followed by the number of repetitions. For example, a string like "AAABBB" would be compressed to "A3B3". This method is particularly effective for files with lots of repeated or redundant data.

The key enhancement in this project is the use of C++ multithreading (std::thread) to divide the file content into multiple segments and compress them in parallel. This approach significantly reduces the time taken for compression, especially when dealing with large text files. The use of mutexes ensures thread safety while accessing shared resources such as the final compressed string.

Technical Implementation:
Language Used: C++
Compression Algorithm: Run-Length Encoding (RLE)
Multithreading: Implemented using std::thread from the C++ Standard Library
Thread Synchronization: Achieved using std::mutex to safely update shared data
File Handling: Implemented using standard file streams (ifstream, ofstream)
Performance Measurement: Time taken for compression is calculated using <chrono>
The program begins by reading the input file into memory. The content is then split into equal parts based on the number of threads (default is four). Each part is processed in a separate thread, where the RLE algorithm is applied. Once all threads finish execution, the compressed outputs are combined into a single result and written to an output file.

To ensure a complete demonstration, the tool also creates a sample input file if none exists, compresses it, and displays the compressed output along with the execution time in milliseconds.

Conclusion:
The Multithreaded File Compression Tool successfully meets the objectives outlined in CODTECH Internship Task-2. It provides a working example of how multithreading can be used to optimize the performance of file processing operations in C++. This project not only demonstrates technical proficiency in C++ but also highlights the importance of writing efficient, scalable, and well-organized code. It lays a solid foundation for more advanced compression utilities and multithreaded applications in the future.
