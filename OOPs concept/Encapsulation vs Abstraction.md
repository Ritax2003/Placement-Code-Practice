# Encapsulation vs. Abstraction in OOP

## 1. **Definition**

| Aspect               | **Encapsulation**                                                                                                  | **Abstraction**                                                                                           |
|----------------------|---------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
| **Concept**          | Encapsulation is the concept of bundling the data (variables) and methods (functions) that operate on the data into a single unit (class). | Abstraction is the concept of hiding the complex implementation details and showing only the necessary features of an object. |
| **Goal**             | Protect the data from unauthorized access and modification by restricting direct access to class members.         | Simplify complex systems by exposing only the essential features and hiding the unnecessary details.       |

## 2. **Key Characteristics**

| **Encapsulation**                                                                                          | **Abstraction**                                                                                               |
|-------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|
| **Data Hiding**: It hides the internal state of the object from the outside world.                           | **Focus on Essential Features**: Only the relevant and essential features are exposed, while others are hidden. |
| **Access Modifiers**: Encapsulation uses access modifiers like `private`, `public`, `protected` to restrict access. | **Interfaces/Abstract Classes**: Abstraction typically uses abstract classes or interfaces to define abstract methods.  |
| **Implementation**: Data and methods are encapsulated into a single unit (class or object).                  | **Implementation Hiding**: Hides the implementation details of a function or class from the user.             |

## 3. **Purpose**

| **Encapsulation**                                           | **Abstraction**                                           |
|-------------------------------------------------------------|-----------------------------------------------------------|
| To protect and control access to an object's data.         | To reduce complexity by hiding unnecessary details.       |
| To provide controlled access to the data through methods (getter/setter). | To expose only relevant functionality to the user.         |

## 4. **Real-World Example**

| **Encapsulation**                                   | **Abstraction**                                     |
|-----------------------------------------------------|-----------------------------------------------------|
| A **bank account**: The internal balance of a bank account is hidden (encapsulated) and can only be modified via methods such as `deposit()` or `withdraw()`. | A **remote control**: The user interacts with the remote control to perform operations like volume control or changing channels without needing to understand the internal workings of the television. |

## 5. **Visibility**

| **Encapsulation**                         | **Abstraction**                                           |
|-------------------------------------------|-----------------------------------------------------------|
| Focuses on how the data is stored and accessed. | Focuses on what operations can be done without revealing how they are performed. |
| The internal state is hidden, but the external interface is provided to access or modify it. | Hides the implementation details, leaving only the relevant features visible. |



