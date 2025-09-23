Basic Calculator (C++)

This is a simple command-line calculator written in C++ that supports comman arithmetic operations, exponentiation, square root and history keeping of the calculator.

✨ Features
- Operations
  - '+' Addition
  - '-' Subtraction
  - '*' Multiplication
  - '/' Division
  - '^' Exponentiation
  - '?' Square Root
 
- Commands 
  - 'exit' -> To quit the program
  - 'history' -> To display all the previous calculations from the current session
  - 'clear' -> To clear all previously stored history

- Error Handling
  - Invalid Numbers
  - Invalid Operations
  - Division by Zero
  - Square Root of a negative number

- History Management
  - The calculator can remember up to 100 past results
  - Oldest entries are dropped automatically if the limit is exceeded


How to Build & Run:

  Requires: 
    - C++17 or newer to run 
    - g++ / clang++ (Linux/Mac) or MSVC (Windows)

  Build:
    Step 1. Open the terminal from project root
    <img width="1328" height="902" alt="image" src="https://github.com/user-attachments/assets/96c389b6-e5c6-4ca6-9459-a5dc58270d98" />
    Step 2. In the terminal enter/copy & paste the following below for you to compile
    
    g++ -std=c++17 -Iinclude src/*.cpp -o calculator

  Run:
    Step 3. To run the program, enter/copy & paste the following below in the same terminal

    ./calculator
    
  It should look like this
  <img width="1114" height="627" alt="image" src="https://github.com/user-attachments/assets/30f02db6-d1f9-4565-8c39-f61b846f3bbf" />

Now to showcase what it can do...

After typing finish the first number, enter and type in the operation, if the operation is not a square root, you may type in another number. The final line will show the user the full expression of the arithmetic 

Basic Arithmetic
<img width="1114" height="630" alt="image" src="https://github.com/user-attachments/assets/cece3c25-6034-404b-9ade-56c333c3f91a" />

Square root and Exponentiation
<img width="1118" height="629" alt="image" src="https://github.com/user-attachments/assets/1d58ee91-73cd-4b80-970a-21c9d0136c46" />

History

To see the history of the calculator, please type in "history" when prompt for entering the first number of the second number(If you do it for the second number it will void the previous attempt at arithmetic expression)
<img width="1111" height="628" alt="image" src="https://github.com/user-attachments/assets/ab680d9c-2f6d-4c00-b0dc-b42e4ad5bc28" />

You can also clear the calulator's history by typing in "clear" and to show that it works I have attempted to get the history of the calulator itself, and it shows that no history is being recorded.
<img width="1115" height="628" alt="image" src="https://github.com/user-attachments/assets/65cdad70-4621-4939-8dd2-5d9523d9f73f" />

Error Handling
<img width="1114" height="630" alt="image" src="https://github.com/user-attachments/assets/18c6b73c-166d-4ad9-a1a3-c9bfe8e1a9e6" />


