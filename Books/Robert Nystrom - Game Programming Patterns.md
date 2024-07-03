---
tags:
  - book
  - gamedev
  - design-patterns
created: 2021-11-17
links: "[[Books]]"
---
# How To?

- Reading (everyone on their own)
- Hardcover is nice, but there is a free [online version](https://gameprogrammingpatterns.com/)
- Discuss the latest chapter (together)
- Code (together)
    - Testproject
    - Jamtemplate
- Take notes here

# Introduction

- Three speeds to balance:
    - immediate development speed,
    - long term development speed and
    - speed of your game at runtime

# Design Patterns Revisited

## [[Command]]

- Objectified Function call
- E.g. for input actions
- Objects can be parameterized either via method argument or construction
- Undo/Redo

## [[Flyweight]]

- Object/Class that does not contain all of its heavy data
- Reference to some common data shared between the objects
- E.g. Sprite and Texture
- Tilemap with sprites being stored only once and then re-drawn at different positions.
- Purely about efficiency
- Already pretty well represented in the JamTemplate

## [[Observer]]

- Abstract communication channel
- No need to know about details
- mysterious action over distance
- Jamtemplate: E.g. for HUD

## [[Prototype]]

- Create new instances of objects by cloning old instances
- Downsides:
    - Is it the responsibility of an object to clone itself? Would a factory/repository be a better solution?
    - deep copy semantics will take some thought
    - Do you need multiple spawners?
    - Does a spawner even need a state or would a free function suffice?
- Details:
    - Don’t like the naming in fig 5.1. better would be spawner_ghost, spawner_sorcerer, …
    - In C++ base classes should have deleted copy operations anyway, so clone() is the only viable option
- Self: looking at the parent for the appropriate method sounds like c++ name lookup for functions (search in increasing parent scope)
- json example:
    - I don’t like the mapping of data to behavior (e.g. spells, shortrange/longrange attacks)
    - inheritance comparison: prototype behaves as a class and not an interface, which will make it harder to maintain.
    - It is nice to write it in `json` format, but I expect quite some pain when doing the object creation in game based on the data. Latest when it comes to using the modeled functionality
- Not mentioned alternative: “ObjectRepository”

## [[Singleton]]

- Chapter is mainly about how not to use a singleton
- Singleton: Have only one instance and make it available globally
- Alternative: Class with static members: This exactly what `GameProperties` does.
    - Problem: Initialization order
- Unmentioned Drawback: Worst testing ever
- Solution: [[Dependency Injection]]. Yes, it requires some thought, but it works out great in the JamTemplate.

## [[State]]

- Allow an object to alter its behavior on internal state changes
- State Machines
    - Example in the Jam Template: State Manager
    - Example in the Book: Animations/Character Actions
- Implementations:
    - Static states (only limited applicability - e.g. when multiple instances of the class are available)
    - Instantiated States (widely applicable)
    - Can have enter and exit actions
- State machines can be concurrent (movement/equipment of a hero)
- State machines can be hierarchical

# Sequencing Patterns

## Double Buffer

- Have a second buffer and flip it
- Most engines take care of that for you
- Also needed for: When the algorithm modifying an object is reading from the object (e.g. in game of life)

## Game Loop

- The most important basic building block for any game
- How to perform individual steps
- Multiple options:
    - run as fast as possible - game is bound to processor speed, which will cause all sort of weird effects
    - variable timestep - might cause issues with physics or networking
    - fixed timesteps - update in fixed steps, render in between

## Update

- The second most important building block for any game
- Do not do update everything in the main game loop, but every object can update itself
- Allows for decoupling of Objects and Events

# Behavioral Patterns

## Byte Code

- Have some precompiled scripting language for your game
- Give behavior the flexibility of data by encoding it as instructions for a virtual machine
- Carefully decide if you actually need this
- Alternatives:
    - Lua. bindings for c++ are pretty good. e.g. [selene](https://github.com/jeremyong/Selene) or [luaaa](https://github.com/gengyong/luaaa)
    - Console with `ActionCommands`

## Subclass Sandbox

- Pattern:
    - Base class provides an abstract sandbox method and one or multiple provided operations for derived classes to be used.
    - Derived classes do not depend directly on any of the games systems, but only on the base class
    - Reduce behavioral overlap between derived classes
    - provided operations can either be
        - functions like playSound() or spawnParticles()
        - getters for interfaces (getGame()) <- Hint: Only hand out interfaces to avoid a brittle base class
    - How does the base class get the needed features
        - Constructor injection - Bad because every class will have to provide all needed systems
        - Property Injection (whyever it is called init) - Good, but can easily be used wrongly
        - Static state - AAAARG
        - Service Locator - AAAARG!!!
        - Not mentioned: Collection object that is passed in on construction - Mix of constructor and property injection, can be automated so that the user does not see it - See JamTemplate GameObject
- Application:
    - GameObject with
        - getGame() <- provided operation via Facade Pattern
        - create(), update(), draw() <- sandbox methods

## Type Object

- Avoid big inheritance hierarchies by adding a data subclass
- Defining behavior will be very hard with this pattern
    - -> [[Strategy]] or [[State]] pattern can help out
- Construction options
    - Monster(Breed const&) or
    - monster = breed.newMonster
- Data can be shared through inheritance if desired
    - Might make it more complicated (where is the data actually coming from?)

# Decoupling Patterns

## Component

- Might be interesting to look at: [https://github.com/skypjack/entt](https://github.com/skypjack/entt)
- Separate concerns within one entity
- Tested it on Alakajam14 Player and it works great
- Individual data and functionality is moved to components
- Common functionality stays in base class
- E.g. Player
    - Input Component
    - Graphics Component
    - Sound Component
- In the best case, the components can be made reusable between different entities (not the case for alakajam)

## Event Queue

> [!hint] See also [[Mediator#Event Broker|Event Broker]]

- Temporal decoupling
- Did not work out that great in Funky Trip

## Service Locator

- Rather an antipattern than a pattern
- Basically a singleton with extra steps
- Provide a global point of access to a service without coupling users to the concrete class that implements it.
- In fact, it hides the dependency and adds another one on top
- Testing in isolation becomes more problematic
- Better solution:
    - Pass in dependency via [[Constructor Injection]] or [[Property Injection]]

# Optimization Patterns

## Data Locality

## Dirty Flag

## Object Pool

## Spatial Partition
