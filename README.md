This is a project undertaken at the university as part of the object-oriented programming course. The project, written in C++, involved creating a program capable of solving mathematical calculations with parentheses, such as:
-34*[3^(3-1)] or 12.3*(4-(5^(3-7))) or {2*{3+6+[2^(4*(5-7+(5)))]}}--8.5+(6^(3/1))
Certainly, we had to handle this without using pre-made functions from libraries like math.h.

The program I developed accomplishes this task, calculating inputted expressions from both the console and a txt file. It can display either the direct result or, as an added option, the entire step-by-step solution. Each step of solving a parenthesis is displayed on a separate line.

Several classes were created and utilized for this purpose. I am particularly proud of implementing the capability to handle calculations with nested parentheses, even though it was not explicitly required for the project. This was done through the implementation of a recursive function in Equation.h, specifically in line 375, the method 'CalculateParentheses,' and, of course, the subsequent 'Calculate' method, which manages the order of operations.

I could provide a more detailed explanation of how the program was conceived and operates, but I want to avoid making this text overly lengthy.
