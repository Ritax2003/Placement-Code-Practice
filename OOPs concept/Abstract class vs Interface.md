# Abstract Class vs Interface in OOP

## 1. **Definition**

| Aspect                 | **Abstract Class**                                                                                           | **Interface**                                                                                               |
|------------------------|---------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
| **Concept**            | An abstract class is a class that cannot be instantiated on its own and may contain both abstract and non-abstract methods. | An interface is a reference type, similar to a class, that can contain only abstract methods (before Java 8) and constants. |
| **Purpose**            | Used when you want to define a common base class with some implementation shared among derived classes.           | Used to define a contract that classes can implement, specifying the methods that must be implemented.       |

## 2. **Key Characteristics**

| **Abstract Class**                                               | **Interface**                                                                                                 |
|------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Can contain both **abstract** (without implementation) and **non-abstract** methods (with implementation).        | Can contain only abstract methods (in Java 7 and earlier), but from Java 8 onwards, interfaces can have default and static methods with implementations. |
| Can have **instance variables** (fields), which may be **private**, **protected**, or **public**.                  | Can only have **public static final variables** (constants). They are implicitly public, static, and final.    |
| Supports **constructor** definition.                             | Does not support constructors.                                                                                 |
| An abstract class can extend only **one class** (single inheritance). | An interface can extend multiple interfaces (multiple inheritance).                                          |
| Can implement methods from **other abstract classes** and use them in derived classes.                             | Cannot provide method implementations (except for default methods starting from Java 8).                       |

## 3. **When to Use**

| **Abstract Class**                                                   | **Interface**                                                   |
|----------------------------------------------------------------------|-----------------------------------------------------------------|
| Use an abstract class when you want to define a common base class with some shared implementation, and you expect derived classes to have a common behavior with optional extensions. | Use an interface when you want to specify a contract that classes must adhere to, regardless of their class hierarchy. |
| When you need to provide some **default behavior** but allow subclasses to override it.                         | When you want to define common operations that can be implemented by classes from different inheritance hierarchies. |

## 4. **Real-World Example**

| **Abstract Class**                                               | **Interface**                                                   |
|------------------------------------------------------------------|-----------------------------------------------------------------|
| **Shape**: An abstract class representing geometric shapes with a default method for calculating area, but each shape can define its own specific method for drawing. | **Drawable**: An interface that defines a contract for classes that can be drawn, such as `Circle` and `Square`, but does not define how to draw them. |

