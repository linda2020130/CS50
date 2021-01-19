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

CS50 teaches students how to **think algorithmically** and **solve problems efficiently**. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, and software engineering. Languages include C, Python, and SQL plus students’ choice of: HTML, CSS, and JavaScript (for web development); Java or Swift (for mobile app development); or Lua (for game development). Problem sets inspired by the arts, humanities, social sciences, and sciences.
<br>

<h2 id="week1">Week 1 C</h2>

[🐳](/Week%201%20C)
1. [Using the Linux command line](/Week%201%20C/CommandLine.md): Common Linux CLI commands including `ls`, `cd`, `mkdir`, `cp`, `rm`, `mv` and how to compile the C languages source code into machine code.
2. **Problem Set 1**: 
    * [Hello](/Week%201%20C/hello.c): Return `hello, XXX` after user inputs the name.
    * [Mario](/Week%201%20C/mario.c): Return the **pyramids** using hashes (`#`) for bricks after user inputs how tall the pyramids should be. 
      <details><summary>Details:</summary>
      <p>If the user doesn’t input a positive integer between 1 and 8, inclusive, the program should re-prompt the user until they cooperate.</p>
      </details>
      <details><summary>Illustration:</summary>
      
      ```
      $ ./mario
      Height: -1
      Height: 0
      Height: 42
      Height: 50
      Height: 4
         #  #
        ##  ##
       ###  ###
      ####  ####
      ```
      </details>
    * [Cash](/Week%201%20C/cash.c): Return the **minimum number of coins** that the user's input (how much change he/she owned) can be made.
      <details><summary>Details:</summary>
   
      1. The only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
      2. Only allow user to input float number(use `get_float`). The program should re-prompt the users until they cooperate.
      3. Round your cents to the nearest penny, as with round, which is declared in `math.h`.
      4. Beware the inherent imprecision of floating-point values. Convert the user’s inputted dollars to cents (i.e., from a `float` to an `int`) to avoid tiny errors that might otherwise add up!
      </details>
      <details><summary>Illustration:</summary>
      
      ```
      $ ./cash
      Change owed: -0.41
      Change owed: foo
      Change owed: 0.41
      4
      ```
      </details>
    * [Credit](/Week%201%20C/credit.c): Return `VISA`, `AMEX`, `MASTERCARD`, or `INVALID` after user inputs a credit card number.
      <details><summary>Details:</summary>
   
      1. The program should re-prompt the users until they input entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card). 
      2. According to *Luhn’s algorithm*, you can determine if a credit card number is (syntactically) valid.
      3. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4.
        
      </details>
      <details><summary>Illustration:</summary>
      
      ```
      $ ./credit
      Number: 4003-6000-0000-0014
      Number: foo
      Number: 4003600000000014
      VISA
      $ ./credit
      Number: 6176292929
      INVALID
      ```
      </details>

<h2 id="week2">Week 2 Arrays</h2>

[🐳](/Week%202%20Arrays)
1. [Arrays](/Week%202%20Arrays/Arrays.md): Important features of arrays and the way to declare an array in C. *Call by value vs. call by reference* are also covered.
2. [Variable Scope](/Week%202%20Arrays/VariableScope.md): Definitions and examples of *local variables* and *global variables*.
3. **Problem Set 2**:
   * [Readability](/Week%202%20Arrays/readability.c): Return the approximate grade level after user input some text.
      <details><summary>Details:</summary>
   
      1. Use the *Coleman-Liau index* (`index = 0.0588 * L - 0.296 * S - 15.8`) to compute the grade reading level. Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
      2. Prompt the user for a `string` of text using `get_string`.
      3. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
      4. If the resulting index number is 16 or higher, your program should output `Grade 16+`. If the index number is less than 1, your program should output `Before Grade 1`.
        
      </details>
      <details><summary>Illustration:</summary>
   
      ```
      $ ./readability
      Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
      Grade 5
      $ ./readability
      Text: A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.
      Grade 16+
      ```
      </details>
   * [Caesar](/Week%202%20Arrays/caesar.c): Return encrypted messages using *Caesar's cipher*.
      <details><summary>Details:</summary>
   
      1. Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by k positions. 
      2. Accept a single command-line argument, a non-negative integer k. Return `Usage: ./caesar key` if not receive exactly one command-line argument from user.
      3. Work for all non-negative integral values of k less than 2^31 - 26.
      4. Output `plaintext:` and then prompt the user for a string of plaintext (using `get_string`).
      5. Output `ciphertext:` followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions.
      6. Non-alphabetical characters should be outputted unchanged and case must be preserved.

      </details>
      <details><summary>Illustration:</summary>
   
      ```
      $ ./caesar 1
      plaintext:  HELLO
      ciphertext: IFMMP
      $ ./caesar HELLO
      Usage: ./caesar key
      ```
      </details>
   * [Substitution](/Week%202%20Arrays/substitution.c): Return a substitution cipher.
      <details><summary>Details:</summary>
   
      1. Encrypt a message by replacing every letter with another letter using a 26-character mapping key.
      2. Accept a single command-line argument, a 26-character mapping key. Return `Usage: ./substitution key` if not receive exactly one command-line argument from user. Return `Key must contain 26 characters.` if not receive exactly 26 characters.
      3. Output `plaintext:` and then prompt the user for a string of plaintext (using `get_string`).
      4. Output `ciphertext:` followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext.
      5. Non-alphabetical characters should be outputted unchanged and case must be preserved.
        
      </details>
      <details><summary>Illustration:</summary>
   
      ```
      $ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
      plaintext:  hello, world
      cyphertext: jrssb, ybwsp
      $ ./substitution
      Usage: ./substitution key
      $ ./substitution ABC
      Key must contain 26 characters.
      ```
      </details>

<h2 id="week3">Week 3 Algorithms</h2>

[🐳](/Week%203%20Algorithms)
1. [Algorithms](/Week%203%20Algorithms/Algorithms.md): Includes `Linear Search`, `Binary Search`, `Bubble Sort`, `Selection Sort`, `Insertion Sort`, and `Merge Sort`.
2. [Recursion](/Week%203%20Algorithms/Recursion.md): Definition and examples of recursion.
3. **Problem Set 3**: 
    * [Plurality](/Week%203%20Algorithms/plurality.c): Run a plurity election. Every voter gets one vote, and the candidate with the most votes wins.
      <details><summary>Details:</summary>
      
      1. The maximum number of candidates an election can have is 9.
      2. Sets a global variable `candidate_count` representing the number of candidates in the election, copies command-line arguments into the array `candidates`, and asks the user to type in the number of voters.
      3. Every voter type in a vote, calling the `vote` function on each candidate voted for.
      4. `main` makes a call to the `print_winner` function to print out the winner (or winners) of the election.
      5. `vote` takes a single argument, a `string` called `name`, representing the name of the candidate who was voted for. Indicate an invalid ballot if not match any name.
      6. May assume that no two candidates will have the same name.
      </details>
      <details><summary>Illustration:</summary>
      
      ```
      $ ./plurality Alice Bob
      Number of voters: 3
      Vote: Alice
      Vote: Charlie
      Invalid vote.
      Vote: Alice
      Alice
      $ ./plurality Alice Bob Charlie
      Number of voters: 5
      Vote: Alice
      Vote: Charlie
      Vote: Bob
      Vote: Bob
      Vote: Alice
      Alice
      Bob
      ```
      </details>
    * [Runoff](/Week%203%20Algorithms/runoff.c): Run a runoff election, a ranked-choice voting system. Voters can rank the candidates in order of preference. 
      <details><summary>Details:</summary>
   
      1. If no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference. Once a candidate has a majority, that candidate is declared the winner.
      2. All candidates who are tied for last place will be eliminated. Declare the election a tie if every remaining candidate has the exact same number of votes.
      3. Assume that all voters will rank all of the candidates in their preferred order.
      4. An election with any number of candidate (up to the MAX of 9).
      5. Invalid votes for candidates who are not on the ballot.
      6. Voting for a candidate by name and may assume that no two candidates will have the same name.
      </details>
      <details><summary>Illustration:</summary>
      
      ```
      ./runoff Alice Bob Charlie
      Number of voters: 5
      Rank 1: Alice
      Rank 2: Bob
      Rank 3: Charlie

      Rank 1: Alice
      Rank 2: Charlie
      Rank 3: Bob

      Rank 1: Bob
      Rank 2: Charlie
      Rank 3: Alice

      Rank 1: Bob
      Rank 2: Alice
      Rank 3: Charlie

      Rank 1: Charlie
      Rank 2: Alice
      Rank 3: Bob

      Alice
      ```
      </details>
    * [Tideman](/Week%203%20Algorithms/tideman.c): Run a Tideman election, a ranked-choice voting system. Voters can rank the candidates in order of preference.
      <details><summary>Details:</summary>
      
      1. The Tideman method works by constructing a “graph” of candidates, where an arrow (i.e. edge) from candidate A to candidate B indicates that candidate A wins against candidate B in a head-to-head matchup. The winner of the election should be the “source” of the graph
      2. The Tideman algorithm specifies that matchup edges should be “locked in” to the graph one at a time, based on the “strength” of the victory (the more people who prefer a candidate over their opponent, the stronger the victory). So long as the edge can be locked into the graph without creating a cycle, the edge is added; otherwise, the edge is ignored.
      3. An election with any number of candidate (up to the MAX of 9)
      4. Invalid votes for candidates who are not on the ballot.
      5. Voting for a candidate by name and may assume that no two candidates will have the same name.
      </details>
      <details><summary>Illustration:</summary>
      
      ```
      ./tideman Alice Bob Charlie
      Number of voters: 5
      Rank 1: Alice
      Rank 2: Charlie
      Rank 3: Bob

      Rank 1: Alice
      Rank 2: Charlie
      Rank 3: Bob

      Rank 1: Bob
      Rank 2: Charlie
      Rank 3: Alice

      Rank 1: Bob
      Rank 2: Charlie
      Rank 3: Alice

      Rank 1: Charlie
      Rank 2: Alice
      Rank 3: Bob

      Charlie
      ```
      </details>

<h2 id="week4">Week 4 Memory</h2>

[🐳](/Week%204%20Memory)
1. [Pointers](/Week%204%20Memory/Pointers.md): Definition and examples of pointers including how to create one and how to use the dereference operator(`*`). Memory and size of each data type are also covered.
2. [Dynamic Memory Allocation](/Week%204%20Memory/Dynamic_Memory_Allocation.md): Basic introduction of dynamically-allocated memory including concepts of `heap` and `stack`, and how to use `malloc()` and `free()`.
3. [File Pointers](/Week%204%20Memory/File_Pointers.md): Definitions and examples of most common file I/O functions including `fopen()`, `fclose()`, `fgetc()`, `fputc()`, `fread()`, and `fwrite()`.
4. **Problem Set 4**:
   * [](): Return
      <details><summary>Details:</summary>

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
