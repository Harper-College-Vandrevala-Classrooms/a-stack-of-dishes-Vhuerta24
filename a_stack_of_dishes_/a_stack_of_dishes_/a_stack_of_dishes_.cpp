#include <iostream>
#include <string>
#include <array>

using namespace std;

// Provided Dish class from lab
class Dish {
private:
    string description;

public:
    
    Dish(string description) : description(description) {}

   
    Dish() : description("") {}


    string get_description() const {
        return this->description;
    }
};

// Stack class
template <size_t MAX_SIZE>
class DishStack {
private:
    array<Dish, MAX_SIZE> stack; // Array to store Dish objects
    int top;                     // Index of the top element

public:
    // Constructor
    DishStack() : top(-1) {}

    // Push method to add a Dish object to the stack
    void push(const Dish& dish) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full. Cannot add more dishes." << endl;
        }
        else {
            stack[++top] = dish;
            cout << "Dish added: " << dish.get_description() << endl;
        }
    }

    // Pop method to remove and return the top Dish object from the stack
    Dish pop() {
        if (top < 0) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return Dish(); // Return a default Dish if the stack is empty
        }
        else {
            return stack[top--];
        }
    }

    // Peek method to view the top Dish object without removing it
    Dish peek() const {
        if (top < 0) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return Dish(); // Return a default Dish if the stack is empty
        }
        else {
            return stack[top];
        }
    }

    // Size method to return the current number of elements in the stack
    int size() const {
        return top + 1;
    }
};

// Driver program to test DishStack
int main() {
    // Create a stack with a maximum size of 5
    DishStack<5> stack;

    // Create Dish objects
    Dish one_dish("A dish with one fish pattern on it");
    Dish two_dish("A dish with two fish patterns on it");
    Dish red_dish("A dish with a red fish pattern on it");
    Dish blue_dish("A dish with a blue fish pattern on it");

    // Testing the size when stack is empty
    int stack_size = stack.size();
    cout << "Stack size: " << stack_size << endl;

    // Pushing the dishes onto the stack
    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // Testing the size after pushes
    int size_after_pushes = stack.size();
    cout << "Stack size after pushes: " << size_after_pushes << endl;

    // Peek at the top dish
    Dish peeked_dish = stack.peek();
    cout << "Peeked dish: " << peeked_dish.get_description() << endl;

    // Pop dishes from the stack
    Dish popped_dish = stack.pop();
    cout << "Popped dish: " << popped_dish.get_description() << endl;

    Dish another_popped_dish = stack.pop();
    cout << "Another popped dish: " << another_popped_dish.get_description() << endl;

    // Test final size
    int final_size = stack.size();
    cout << "Final stack size: " << final_size << endl;

    return 0;
}
