#ifndef ECOMMERCECORE_COMMAND_H
#define ECOMMERCECORE_COMMAND_H


/**
 * The Command class is an abstract base class that defines a common interface
 * for all concrete command classes within the application. Commands encapsulate
 * a specific action and its parameters, allowing for flexible and decoupled
 * execution. This pattern is particularly useful in implementing operations
 * such as menu actions, where each action can be encapsulated in a command object,
 * enabling dynamic invocation and enhancing the scalability and maintainability
 * of the code.
 *
 * Usage:
 * To create a new command, define a subclass that implements the execute() method,
 * providing the specific implementation for the action that the command represents.
 * The Command class itself cannot be instantiated directly due to its abstract nature.
 *
 * Example:
 * class MyCommand : public Command {
 * public:
 *     void execute() override {
 *         // Implement the action here
 *     }
 * };
 *
 * Key Methods:
 * - execute(): A pure virtual function that must be implemented by derived classes.
 *   This method contains the code that will be executed when the command is invoked.
 *
 * Destructor:
 * - The virtual destructor ensures that derived class destructors are called
 *   correctly, allowing for proper cleanup of resources when a Command object
 *   is deleted through a pointer to Command.
 */
class Command {
public:
    virtual void execute() = 0;
    ~Command() = default;
};


#endif //ECOMMERCECORE_COMMAND_H
