## Python

### Lists

* **not** fixed in size. 
* They can grow or shrink as needed, and you can always tack extra elements onto your array and splice things in and out easily.

#### To declare a list

```
nums = []
nums = [1, 2, 3, 4]
nums = [x for x in range(10)]
nums = list()
```

#### To tack on to an existing list

```
nums = [1, 2, 3, 4]

# Add element 5 to the last of nums
nums.append(5)   # put 5 tp the last
nums.insert(4, 5)   # put 5 to position 4
nums[len(nums):] = [5]   # replace list of 5 to position 4 to last
```

<br />

### Tuples

* **ordered**, **immutable** sets of data.
* They are great for associating collections of data, sort of like a struct in C, but where those values are unlikely to change.

#### A list of tuples
```
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1809),
    ("James Madison", 1809)
]

# This list is iterable
for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))
```

<br />

### Dictionaries

* Python also has built in support for **dictionaries**, allowing you to specify list indices with words or phases (keys), instead of integers, which you were restricted to in C.
* But this creates a somewhat new problem... how do we iterate through a dictionary? We don't have indexes ranging from [0, n-1] anymore.

#### Examples
```
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}

# Transform the dictionary to a list
# Print values only
for pie, price in pizzas.items():
    print(price)    # not guaranteed the same order as in the dictionary

# Print both keyss and values
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
    print("A whole " + pie + " pizza costs $" + str(price))
```

<br />

### Functions

* Like variables, we don't need to specify the return type of the function, not the data types of any parameters.
* All functions are introduced with the `def` keyword
  * Also, no need for main; the interpreter reads from top to bottom!
  * If you wish to define main nonetheless (and you might want to!), you must at the very end of your code have:
```
if __name__ == "__main__":
    main()
```

<br />

### Objects

* Python is an **object-oriented** programming language.
* An object is sort of analogous to a C structure.
  * C structures contain a number of fields, which we might also call **properties**.
  * But the properties themselves can not ever stand on their own.
* Objects have properties but also **methods**, or functions that are inherent to the object, and mean nothing outside of it. You define the methods inside the object also.
  * Thus, properties and methods don't ever stand on their own.
* You define a type of object using the ` class` keyword in Python.
* Classes require an initialization function, also more-generally known as a **constructor**, which sets the starting values of the properties of the object.
* In defining each method of an object, `self` should be its first parameter, which stipulates on what object the method is called.

#### Example
```
class Student():

    def __init__(self, name, id):
        self.name = name
        self.id = id
        
    def changeID(self, id):
        self.id = id
        
    def print(self):
        print("{} - {}".format(self.name, self.id))
        
jane = Student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()
```

<br />

### Style

* Tabs and indentation actually matter in this language, and things will not work the way you intend for them to if you disregard styling!

<br />

### Run file

* To run your Python program through the Python interpreter at the command-line, simply type ` python <file>`
* Your program will run through the interpreter, which will execute everything inside of the file, top to bottom.

