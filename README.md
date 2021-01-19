# CS50
Notes and problem sets for Harvard CS50.<br>
Online course website: [CS50](https://cs50.harvard.edu/x/2020/)(2020 version)
<br><br>

## Table of Contents
* [Introduction](#intro)
* [Week 1 C](#week1)
* [Week 2 Arrays](#week2)
* [Week 3 Algorithms](#week3)
* [Week 4 Memory](#week4)
* [Week 5 Data Structures](#week5)
* [Week 6 Python 🐍](#week6)
* [Week 7 SQL](#week7)
* [Week 8 Information](#week8)

<h2 id="intro">Introduction</h2>

CS50 teaches students how to **think algorithmically** and **solve problems efficiently**. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, and software engineering. Languages include C, Python, and SQL plus students’ choice of: HTML, CSS, and JavaScript (for web development); Java or Swift (for mobile app development); or Lua (for game development). Problem sets inspired by the arts, humanities, social sciences, and sciences. <br>

<h2 id="week1">Week 1 C</h2>

[🐳](/Week%201%20C)
1. [Using the Linux command line](/Week%201%20C/CommandLine.md): Common Linux CLI commands including `ls`, `cd`, `mkdir`, `cp`, `rm`, `mv` and how to compile the C languages source code into machine code.
2. **Problem Set 1** : 
    * [Hello](/Week%201%20C/hello.c): 
      * **Output**: Return `hello, XXX` after user inputs the name.
      * **Constraints**: None.
    * [Mario](/Week%201%20C/mario.c): 
      * **Output**: Return the **pyramids** using hashes (`#`) for bricks after user inputs how tall the pyramids should be. 
      * <details><summary>Constraints:</summary>
         <p>If the user doesn’t input a positive integer between 1 and 8, inclusive, the program should re-prompt the user until they cooperate.</p>
         </details>
      * **Illustration**:<br>![mario](/Pictures/mario.PNG)
    * [Cash](/Week%201%20C/cash.c):
      * **Output**: Return the **minimum number of coins** that the user's input (how much change he/she owned) can be made.
      * <details><summary>Constraints:</summary>
   
        1. The only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
        2. Only allow user to input float number(use `get_float`). The program should re-prompt the users until they cooperate.
        3. Round your cents to the nearest penny, as with round, which is declared in `math.h`.
        4. Beware the inherent imprecision of floating-point values. Convert the user’s inputted dollars to cents (i.e., from a `float` to an `int`) to avoid tiny errors that might otherwise add up!
        </details>
        
      * **Illustration**:<br>![cash](/Pictures/cash.PNG)
    * [Credit](/Week%201%20C/credit.c):
      * **Output**: Return `VISA`, `AMEX`, `MASTERCARD`, or `INVALID` after user inputs a credit card number.
      * <details><summary>Constraints:</summary>
   
        1. The program should re-prompt the users until they input entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card). 
        2. According to *Luhn’s algorithm*, you can determine if a credit card number is (syntactically) valid.
        3. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4.
        
        </details>
      * **Illustration**:<br>![credit](/Pictures/credit.PNG)
<br>

<h2 id="week2">Week 2 Arrays</h2>

[🐳](/Week%202%20Arrays)
<br>

<h2 id="week3">Week 3 Algorithms</h2>

[🐳](/Week%203%20Algorithms)
<br>

<h2 id="week4">Week 4 Memory</h2>

[🐳](/Week%204%20Memory)
<br>

<h2 id="week5">Week 5 Data Structures</h2>

[🐳](/Week%205%20Data%20Structures)
<br>

<h2 id="week6">Week 6 Python</h2>

[🐍](/Week%206%20Python)
<br>

<h2 id="week7">Week 7 SQL</h2>

[🐍](/Week%207%20SQL)
<br>

<h2 id="week8">Week 8 Information</h2>

[🐍](/Week%208%20Information)
<br>
