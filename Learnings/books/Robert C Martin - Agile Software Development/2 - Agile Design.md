
## Code Smells



* Odors of Rotting Software:
    * Rigidity
    * Fragility
    * Immobility
    * Viscosity
    * Needless Complexity
    * Needless Repetition
    * Opacity
* Why does software rot?
    * requirements change in ways that the initial design did not anticipate.

[[Single Responsibility Principle]]
* Also known as cohesion
* A Class should have only one reason to Change
* A Responsibility is defined as a reason to Change
* Responsibility can be managed i.e. by 
    * Facade or Proxy pattern
    * Interface Segregation or by 
    * inheritance
* An Axis of Change is an Axis only If the Change actually occurs

Open Close Principle



* Open for Extension: behvior can be extended with new Code
* Closed for Modification: Extension dies not require modification of already existing Code or other, unrelated Code
*  
* Create abstractions that are fixed and Set represent an unbounded group of possible behaviours, e.g. by derived classes
* No model or abstraction is natural to all contexts. Anticipate the right Changes
* Initially write Code that anticipates no Changes. I.e. take the First bullet
    * Write tests First
    * Develop in short cycles
    * Develop Features before Infrastrukturen
    * Show Features to the customer
    * Develop Most important Features first
    * Release early and often
* Ocp means abstraction and polymorphism

Liskov Substitution Principle



* Subtypes must be substitutable for their base types
* Violation of LSP is often a latent violation of OCP
* Inheritance is about behavior, Not about is-A relationship
* E.g.:
    * Rectangle and Square (square is not a rectangle if the expectation is that you can change a and b independently)
    * Line and LineSegment (but they have common behavior, so they could share some functions and members in a common base class