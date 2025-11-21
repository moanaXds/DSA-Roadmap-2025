# Word Frequency Counter - Hash Table Implementation

A C++ program that counts word frequencies in text files using a custom hash table with separate chaining for collision resolution.

## Features

- **Word Frequency Analysis**: Counts occurrences of each unique word in text files
- **Case Insensitive**: Treats uppercase and lowercase letters as the same
- **Punctuation Handling**: Automatically removes non-letter characters from words
- **Hash Table Storage**: Efficient storage and retrieval using hash tables
- **Interactive Menu**: User-friendly interface for operations

## How It Works

### Core Components

1. **Hash Table Class**: 
   - Implements separate chaining for collision resolution
   - Dynamic insertion and deletion of words
   - Efficient lookup using hash functions

2. **Word Processing**:
   - `cleanWord()`: Removes punctuation and converts to lowercase
   - `isLetter()`: Identifies valid alphabetical characters

3. **File Handling**:
   - Reads text files line by line
   - Processes words separated by spaces
   - Handles large text files efficiently

### Hash Function
The program uses a simple hash function that:
- Sums ASCII values of all characters in the word
- Uses modulo operation with table size for index calculation

## Usage

### Prerequisites
- C++ compiler (GCC, Clang, MSVC)
- Text file to analyze

### Menu Options

1. **Display All Words**: Shows all words with their frequency counts
2. **Delete a Word**: Remove a specific word from the frequency table
3. **Exit**: Close the program

**Program Output**:
```
Something like this:

NULL
NULL
Word : hello        |         No Of Times : 2
Word : world        |         No Of Times : 2
Word : this         |         No Of Times : 1
Word : is           |         No Of Times : 1
Word : a            |         No Of Times : 1
Word : test         |         No Of Times : 1
Word : again        |         No Of Times : 1
```

## Code Structure

```
HashTable/
├── Node Class
│   ├── string word
│   ├── int count
│   └── Node* next
│
├── HashTable Class
│   ├── hashFunction()
│   ├── insertWord()
│   ├── deleteWord()
│   ├── displayWords()
│   └── insertFromFile()
│
└── Utility Functions
    ├── isLetter()
    └── cleanWord()
```

## Key Features

- **Efficient Storage**: Hash table provides O(1) average case insertion and lookup
- **Memory Management**: Proper cleanup of dynamically allocated nodes
- **Error Handling**: File opening validation and error messages
- **Flexible Table Size**: Configurable hash table size for different needs

## Customization

- **Table Size**: Modify the table size in `main()` for different load factors
- **Hash Function**: Replace the hash function for different distribution characteristics
- **Word Cleaning**: Adjust `cleanWord()` for different text processing requirements

## Limitations

- Simple hash function may cause collisions with certain word patterns
- Fixed table size (consider dynamic resizing for production use)
- Basic word splitting (space-delimited only)

## Ideal Use Cases

- Text analysis and frequency counting
- Educational purposes for learning hash tables
- Small to medium-sized document processing
- Word frequency visualization projects

This implementation demonstrates fundamental data structure concepts while providing practical text analysis capabilities.
