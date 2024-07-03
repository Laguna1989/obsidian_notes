---
tags:
  - Talk
  - google-tech-talk
created: 2024-05-30
links: "[[Talks MOC]]"
---

<iframe width="560" height="315" src="https://www.youtube.com/embed/4F72VULWFvc?si=1cDoil_gtLOpVnoS" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Premise

- History:
	- when moving from basic languages to procedural languages, `goto` statements could be removed - nobody missed them
- The idea is: if you go from prodedural languages to #object-oriented languages, you can get rid of most `if`s

> [!info] Premise
> Most `if`statements can be replaced by polymorphism

# Why Would We want to Do That?

- Functions without ifs are easier to read
- Functions without ifs are easier to test
	- There is only one path through the function
- Polymorphic systems are easier to maintain

# How to Get Rid of `if`?

Use polymorphism when
- an object should behave differently based on its state
- you have to check the same condition in multiple places (e.g. flags)

> [!warning] Where **NOT** to get rid of `if`
>  When comparing primitive types via comparison operators

> [!info] Never return `null`
> But use a `NullObject` instead

> [!info] Don't return error codes
> Throw an exception or use `Result` types

> [!danger] Avoid massive inheritance hierarchies

# State Based Behaviour

- Different behavior based on a specific Field
- Move each leg of conditional to an overriding method in a subclass.
- Make the original method `abstract`
> [!hint] See also
> [[Martin Fowler - Refactoring]]

## Example 1: Bird Speed

```ts
double getSpeed() {
	switch (_type) {
		case EUROPEAN:
			return getBaseSpeed();
		case AFRICAN:
			return getBaseSpeed() - getLoadFactor();
		case NORWEGIAN_BLUE:
			return (_isNailed) ? 0 : getBaseSpeed(_voltage);
	}
	throw new RuntimeException("Unsupported type");
}
```

Isn't there already a type subsystem available?

> [!check] Suggestion
> ![[IMG-2024-07-03-173748421.png|500|center]]

## Example 2: Math Equations

> [!info] Model this!
> 1 + 2 * 3

- Represent this as a tree
- Perform an `evaluate()` method or `toString()` operation
- Let's take a look at `evaluate()`

Most people come up with this solution

```ts
class Node {
	char operator;
	double value;
	Node left;
	Node right;

	double evaluate(){
		case '#': return value;
		case '+': retrn left.evaluate() + right.evaluate();
		case '*': return left.evaluate() * right.evaluate();
		case ...: // more operators
	}
}
```

> [!note] Note
> The `toString()`method would mimic that behavoir

The example from above would be represented as this
![[IMG-2024-07-03-173748727.png|500|center]]

> [!danger] Problem
> Every `Node` has leaf nodes, potentially `null` (e.g. `#`)

> [!danger] Problem
> Every `Node` has a value (e.g. `+` or `*` `Node`s, which don't use them)

### Analyzing Attributes

There are two groups of `Node`s.

> [!info] You need the `value` **XOR** you need the (`left`and `right` Nodes)

![[IMG-2024-07-03-173749434.png|500|center]]

### Better Solution

![[IMG-2024-07-03-173749564.png|500|center]]

In Code:

```ts
abstract class Node {
	abstract double evaluate();
}

class ValueNode extends Node {
	double value;
	double evaluate() {
		return value;
	}
}
```

> [!hint] Notice the simplicity of `ValueNode`
> No if statements

#### Basic `OperationNode`

```ts
class OperationNode extends Node {
	char operator;
	Node left;
	Node right;
	double evaluate() {
		case '+': retrn left.evaluate() + right.evaluate();
		case '*': return left.evaluate() * right.evaluate();
		case ...: // more operators
	}
}
```

![[IMG-2024-07-03-173749623.png|500|center]]

The behavior still changes based on a field.

> [!danger] Problem
> This violates the [[Open Close Principle]] as every new operation needs to modify the existing `OperationNode::evaluate()`method

#### Improved `OperationNode`

Let's furhter analyze attributes
![[IMG-2024-07-03-173749749.png|500|center]]

![[IMG-2024-07-03-173749818.png|500|center]]

```ts
class abstract OpNode extends Node {
	Node left;
	Node right;
	abstract double evaluate();
}

class AdditionNode extends OpNode {
	double evaluate() {
		return left.evaluate() + right.evaluate();
	}
}

class MultiplicationNode extends OpNode {
	double evaluate() {
		return left.evaluate() * right.evaluate();
	}
}
```

> [!hint] No `null`checks needed anymore

> [!hint] Perfectly follows the [[Open Close Principle]] and [[Single Responsibility Principle]]

![[IMG-2024-07-03-173749889.png|500|center]]

### Summary

> [!summary] Example 2 Summary
> A polymorphic solution is often better because
> - New behavior can be added without having the original sourcecode
> - Each operation/concern is separated in a separate field which makes it easy to understand

## Summary

> [!summary] State Based Behavior Summary
> Prefer polymorphism over conditionals
> - `switch` almost always measn you should use polymorphism
> - `if` is more subtle. Sometimes an `if` is just an `if`

# Repeated Condition

> [!quote] Same condition all over the code base

> [!example] Example: This isn't so bad...?
>
> ```ts
> class Update{
> 	execute() {
> 		if(FLAG_il8n_ENABLED) {
> 			// Do A
> 		} else {
> 			// Do B
> 		}
> 	}
> 	render() {
> 		if(FLAG_il8n_ENABLED) {
> 			// Render A
> 		} else {
> 			// Render B
> 		}
> 	}
> 	// what if more functions are there?
> }
> ```

> [!danger] Problem: How to test this?
> Are the if statements combinatorial or mutually exclusive?

Straightfowrard approach

```ts
abstract class Update {
// ...
}

class I18NUpdate extends Update {
	execute() {
		// Do A
	}
	render() {
		// Render A
	}
}
```

> [!check] Testing is so much easier
> - Subclasses can be tested individually
> - Subclasses can not interfere with each other

> [!info] Where Did the `if` Statements Go?
> - vtables
> - As a user you don't care which object you are working with

# Two Piles of Code

- Pile of Objects
	- Business logic
	- Where the actual work is done
- Pile of Construction (Ideally via [[Dependency Injection]])
	- Factories
	- Builders
	- `Provider<T>`

> [!summary] Benefits
> Common code is in one location
>
> Testing independently is easy
>
> Looking at a subclass makes it clear what the differences are

> [!hint] When to use polymorphism
> - Behavior changes based on state
> - Parallel conditionals in multiple places in the code

> [!warning] Be pragmatic
> You will still need some conditionals
