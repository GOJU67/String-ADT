# Custom String Class Project

Welcome to the Custom String Class Project! This repository features a comprehensive implementation of a `String` class built using Object-Oriented Programming (OOP) principles in C++. The project’s goal is to create a robust and flexible string manipulation library, providing users with a wide array of functionalities for managing and working with strings efficiently.

## Features

- **Object-Oriented Design**: Built with OOP principles to encapsulate string operations, ensuring modularity and code reusability within a dedicated class.
- **Custom Implementation**: A unique approach to string handling that offers optimized performance and specialized functionalities beyond standard string libraries.
- **Rich Functionality**: Includes a variety of methods for string manipulation, such as insertion, deletion, trimming, conversion, and comparison, with further extensions planned.
- **Extensibility**: The class is designed to be easily extendable, allowing developers to add new features and functionalities over time to enhance its capabilities.

## Class Attributes

- **`char* data`**: A pointer that stores the character array (the actual string content). The class manages memory dynamically for this array to accommodate variable string lengths.
- **`int size`**: An integer representing the size of the allocated memory for the string.

## Private Utility Methods

These are helper functions to keep low-level operations encapsulated within the class:
- **`isValidIndex(const int index) const`**: Checks if a given index is within the valid bounds of the string, preventing out-of-bounds access.
- **`mySwap(char* a, char* b)`**: Swaps two characters, used in operations like reversing the string.
- Additional helper methods for operations such as:
  - Calculating the length of numbers and strings.
  - Managing memory allocation and copying strings.

## Public Methods

### A. Constructors
- **Default Constructor** (`String()`): Initializes an empty string.
- **Overloaded Constructors**: Supports various input types like integers, characters, and C-strings.
- **Copy Constructor**: Creates a deep copy of another string object.
- **Move Constructor**: Transfers ownership of the string from another object efficiently.
- **Variadic Constructor**: Supports flexible initialization with variable arguments.

### B. Destructor
- **`~String()`**: Cleans up dynamically allocated memory when the object is destroyed.

### C. Basic Operations
- **`void input()`**: Accepts user input for the string.
- **`bool isEmpty() const`**: Checks if the string is empty.
- **`int getLength() const`**: Returns the length of the string.
- **`int getSize() const`**: Returns the allocated memory size.
- **`void display() const`**: Displays the string content.

### D. Access and Modification
- Methods for accessing, inserting, and removing characters, as well as trimming spaces and modifying string cases.

### E. String Manipulation
- Supports concatenation, swapping, and resizing operations.

### F. Conversion Methods
- Convert the string to numeric types such as integers and floating-point values.

### G. Comparison and Overloaded Operators
- Provides relational and logical operators, as well as assignment and bracket operators for intuitive string management.

## Contributing

We welcome contributions from the open-source community to enhance the Custom String Class. Whether you're a seasoned developer or a newcomer to the world of programming, your insights and contributions are valuable to us.

## Feedback and Support

If you have any questions, suggestions, or feedback regarding the project, feel free to reach out. We are committed to fostering a collaborative and inclusive environment for all contributors and users.
