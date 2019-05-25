# CG Generic List Object Oriented


This project was made for fun and is trying to bring some kind of object oriented generic list concept in C. Definitely still a beta stuff and is likely to stay in this state. But feel free to try it.

## Features
The list offered by this library is similar in the concept to a double chained list. For this reason it contains the following features when considering the list itself :
  - Add to head
  - Add to tail
  - Get head
  - Get tail


When you are considering a particular node of the list, like in a double chained list you have the following features:

- Get data stored at the given node
- Go to the previous node
- Go to the next node

But this lib is also offering new features:
- Get an element at a specific index. 
- Insert an element at a specific index.
- Remove the specified element from the list
- Remove an element at a specific index
- Set the value of an element at a specific index
- Apply a function to all the elements of the list

And all of this is done in a way similar to what you would have in an Object Oriented language.

### Installation

As no binaries are given, you need to compile the project yourself if you want to use it as a lib.
This is simplified thanks to the CMakeLists.
For those who don't know how to use CMake, I'm sorry but I'm not going to explain how to use it.
However, you can also add the header file and the source file to your project (listeChainee.h and listeChainee.c) that's all you need.

### Getting started

Now let's move on and let's learn how to use the list.

First you will need to create a ListeChainee variable:
```c
ListeChainee myList;
```

Then, let's initialize this variable by passing the address of it to the initialize function:
```c
initializeList(&myList);
```


Now you have access to all the features of the list. For the example I'm using an int pointer. But as the list is generic, you can use whatever you want, even your own custom type. But be careful, just like in other languages, a list is supposed to contain only **one** type of data:
```c
int *test = calloc(1, sizeof(int));
*test = 25;

myList.addToTail(&myList, test);
test = calloc(1, sizeof(int));
test = 32;
myList.addToHead(&myList, test);
```
Be aware that as you're manipulating data as generic, you will need to cast them back to their type. 
Let's keep the previous code in mind and imagine we want to print all the values to the console:
```c
void printIntValues(void *values[], int size) {
    printf("Printing values as integers.\n");
    
    for (int i = 0; i < size; i++) {
        printf("Value n%d: %d\n", i + 1, *(int *) values[i]);
    }
    
    printf("\n");
}
...
int main(){
    myList.getAll(&myList, printIntValues);
}
```
That's all for now.