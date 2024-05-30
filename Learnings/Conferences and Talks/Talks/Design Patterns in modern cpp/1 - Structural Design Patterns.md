---
tags:
  - design-patterns
---
# Adapter

- First structural design pattern
- Getting the interface you want by the interface you are given
- Same as e.g. with power adapters
- We can not support every possible interface
- “A construct which adapts an existing interface X to the required interface Y”

> [!example]+ MFC technology with `CAboutDilg`
> Interface: `DrawPoints`
> ![Enter image alt description](Images/uX0_Image_1.png)
> - `DrawPoints`, but we have lines
> - Define geometric objects
> ![Enter image alt description](Images/uBK_Image_2.png)
> - Vector object is made out of lines
> - ![Enter image alt description](Images/2fD_Image_3.png)
> - `Rectangle`s are basically `VectorObject`s
> - ![Enter image alt description](Images/1d9_Image_4.png)
> - => We need a conversion from `VectorObject`s to `Point`s,
> - This is where the Adapter comes in
> - ![Enter image alt description](Images/XKl_Image_5.png)
> - ![Enter image alt description](Images/sB0_Image_6.png)
> - Concrete implementation is not that important
> - ![Enter image alt description](Images/5Rt_Image_7.png)
>

> [!warning] Problem
> No caching. Can be added with the adapter easily

- Let’s build a caching adapter
![Enter image alt description](Images/TlR_Image_8.png)

- If no cache found, recalculate and add to static cache

> [!warning] General Problem
> The adapter often spawns temporary objects and if this is a problem.
>
> => Caching is a massive improvement

> [!summary]
> - Implementing an Adapter is easy
> 	- Determine the API you have and the API you need and then create a component which has a reference to the origin and provides access to the destination.
> - Be careful about caching and other optimizations to avoid spawning too much data and cleaning up correctly

# Bridge

> [!quote] Connecting Classes together, avoiding cartesian product complexity explosion

> [!example] Bad design
>  ![Enter image alt description](Images/bbT_Image_9.png)

> [!example] Good design
> ![Enter image alt description](Images/aOj_Image_10.png)

> [!note] Aggregation over inheritance
> A bridge is a pattern that decouples an interface from an implementation

## Pimpl

- Manifestation of the bridge design pattern, hiding the implementation details
- The implementation details are deferred
> [!example] Person and PersonImpl classes
> ![Enter image alt description](Images/2uk_Image_11.png)

- Does not need to be an inner class, important is the forward declaration of the impl class
- `Person` does not need any Details of what `PersonImpl` does
- Benefits:
	- No need to give away inner details of a class (that would normally be in the header files)
	- Improves compilation speed
	- Ensures Binary compatibility

## Shrink-Wrapped Pimpl

- Library-fied version of pimpl
![[Images/y0w_Image_12.png]]

- Horrible looking template is the forwarding constructor
- Also add `operator*` and `operator->`

## Bridge Design Pattern

> [!example] Rendering different kinds of shapes
>  ![Enter image alt description](Images/nmp_Image_13.png)
 Now we have different types of renderers
   ![Enter image alt description](Images/qAo_Image_14.png)
> > [!note] 👆 Cout in wrong order
>
>
> Let’s introduce a `Shape` class that acts as a bridge
> ![Enter image alt description](Images/YMP_Image_15.png)
> ![Enter image alt description](Images/cFw_Image_16.png)
> Non Intrusive design by Igelberger seems more powerful (but also way more complex)

> [!summary]
> - Decouple abstraction from implementation
> - A stronger form encapsulation

# Composite

- Allowing us to handle aggregate objects and individual components in the same way.
- Objects work through inheritance and composition
- Composition lets us make compound objects
> [!example]
> - Math expression built from simple applications
> - Shape or grouping of shapes
- Composite allows to use both single and composite objects uniformly
- `Foo` and `Collection<Foo>` have common APIs

## Shapes and Groups of Shapes

![Enter image alt description](Images/pNe_Image_17.png)

- Now let’s add a `Group`
![Enter image alt description](Images/All_Image_18.png)

- `Group`s can be added to other `Group`s
![Enter image alt description](Images/s5n_Image_19.png)

- Here the common behavior is enforced by the interface.

## ML Example

- Neuron struct
- Neurons have connections for other Neurons (in and out)
- Every Neuron has a unique ID
![Enter image alt description](Images/HB7_Image_20.png)

- Neuron also has a stream output operator
![Enter image alt description](Images/smL_Image_21.png)

- This does not yet allow to connect multiple neurons
- Let’s add `NeuronLayers`
> [!warning] Bad style
> Do not inherit from vector

![Enter image alt description](Images/uFB_Image_22.png)

- Problem: We want to connect
	- All neurons from a layer to a single neuron
	- Single neuron to layer
	- Layer to layer
	- Neuron to neuron (all done)

- => State space explosion for connections
- Let’s introduce a new interface using CRTP `SomeNeurons`
- This will be used in Neuron and NeuronLayer
- CRTP is used to deduct which type we have
![Enter image alt description](Images/8db_Image_23.png)

- 👆 This is the single function that connects all Neurons together
- Ranged based for loop will need to be implemented by adding begin and end functions
- For single neuron (arrrg!)
![Enter image alt description](Images/W4l_Image_24.png)

## Intersection of Composite and Proxy

- Example of creature in computer game with certain statistics
	- Str, int, agi , …
	- This requires some getters and setters
	- Some aggregate statistics might be required (max, average, sum …)
	- This approach does not scale for multiple properties
- Having separate fields does not bring any benefit
- Let’s use something called “array backed properties”
![Enter image alt description](Images/xsC_Image_25.png)

- Same for setter. Calculating aggregate statistics becomes very simple
![Enter image alt description](Images/k1m_Image_26.png)

> [!summary]
> - Objects can use other objects either by composition or inheritance
> - Sometimes they need similar behaviours
> - The Composite design pattern lets us treat scalar and composite objects similarly
> - C++ supports “duck typing” when using begin() and end() objects and ranged based for loops

# Decorator

- Allows to augment an object with additional functionality
- No need to rewrite existing code
- Keeping existing functionality
- In C++ there are two options:
	- Aggregate decorated object
	- Inherit from the decorated object
- “Facilitates the addition of behavior to individual objects”

## Dynamic Decorator

- Base class `Shape` and implementation `Circle`
![Enter image alt description](Images/sZO_Image_27.png)

- We can also add `Square`s
![Enter image alt description](Images/KEH_Image_28.png)

- Now we want to have color. Bad idea: Add two more classes “colorsquare” and “colorcircle”
- Instead: Use Decorator
![Enter image alt description](Images/ubw_Image_29.png)

- Dynamic because we use inheritance
- Let’s add TransparentShape
![Enter image alt description](Images/xPt_Image_30.png)

- -> both colored and transparent
> [!warning] Downside
Once you decorate a type, you are restricted to the interface

## Static Decorator

- Use some c++ tricks to bake information about decorator into the type
	- Mixin Inheritance ([[CRTP]])
	- Perfect Forwarding
- [[CRTP]] allows to call members of the base class

![Enter image alt description](Images/ymt_Image_31.png)

- Use concepts to check that decorator is used in the correct underlying types
- Let’s use constructor forwarding with argument packs to use constructors of the base class

![Enter image alt description](Images/vF3_Image_32.png)

- We hope that the baseclass has a matching constructor that works with the passed arguments
![Enter image alt description](Images/5t7_Image_33.png)

- We still need to write functions manually of course
- Applying decorator on a decorator:
![Enter image alt description](Images/9w7_Image_34.png)

- Through inheritance, `bis` is a `Square`, a `ColoredShape2` and a `TransparentShape2`.
- Members can be modified easily, even if they are not part of the interface

## Functional Decorator

- For now we were decorating a class
- Now let’s make a functional decorator to decorate functions

![Enter image alt description](Images/9E2_Image_35.png)

- Instead of storing `std::function`, we can use a Template (which has some challenges)
- Template argument of class can not be inferred
![Enter image alt description](Images/ahZ_Image_36.png)

- We can create a helper function that avoids the error by explicitly providing the template argument
![Enter image alt description](Images/Vc7_Image_37.png)

- Currently no arguments and no return value. Now it gets interesting
![Enter image alt description](Images/yga_Image_38.png)

- The decorator now needs to be more complicated. We will need to use variadic templates.
- Also we need to allow for partial specialization by providing a generic template (line 45)
![Enter image alt description](Images/1yS_Image_39.png)

- We will need another helper function. We take a function pointer and create an std::function from it.
![Enter image alt description](Images/vOI_Image_40.png)
![Enter image alt description](Images/AHU_Image_41.png)

> [!summary]
> - A dynamic decorator keeps the reference to the decorated object(s)
> - A static decorator uses mixin inheritance
> 	- `ColoredShape<Square>`
> - Both approaches allow limitless composition
> 	- `TransparentShape<ColoredShape<Circle>>`

# Facade

> [!quote] Expose several components through a single interface

> [!quote] Provides a simple, easy to understand interface over a large, complicated code base

> [!example]
> - House is a system which needs to balance complexity and presentation/usability
> - The end user is not exposed to the internal details

> [!example] Without facace
> ![Enter image alt description](Images/bAT_Image_43.png)

> [!example] With a facade
> ![Enter image alt description](Images/Cwx_Image_44.png)

- Wrap a complicated API into a single method
- Optionally allow users to use the more complicated API behind the facade

# Flyweight

- Concerned with Space optimization, avoid redundancy when storing data
- E.g. MMORPG user name storage. Many names are very common, so let’s not waste space on storing all of them individually
	- Store a list of names, use indices or pointers to the names
- E.g. ranges/stringview
- A space optimization technique which lets us use less memory by storing externally the data associated with similar objects and reference to it, when needed
- Let’s stick with the mmorpg example

![Enter image alt description](Images/U1n_Image_45.png)

- How to create users and get names?

![Enter image alt description](Images/Son_Image_46.png)

- Boost offers a convenient library for flyweights
![Enter image alt description](Images/xzu_Image_47.png)

- Flyweight can also be used for text formatting
- Formatted text is initialized by plain text. Some part of the plain text should be capitalized.
- Naive approach: Store an array of bools as long as the text and check the array while printing
![Enter image alt description](Images/8Nv_Image_48.png)

- Actually we do not need to store a bool array for each class. Using a range is sufficient

- Create a nested class TextRange, which stores begin and end

![Enter image alt description](Images/Mqs_Image_49.png)

> [!summary]
>  - Store common data externally
> 	 - e.g. static map
>  - Define the idea of `ranges`on homogeneous collections
> 	 - store data related to those ranges

# Proxy

> [!quote] Interface for accessing a particular resource
>

- The interface looks like the interface of the object you want to access
- Same interface but entirely different internal behavior
- A class that functions as an interface to a particular resource which may be remote, expensive to construct or may require logging or any other added functionality
- Best Example: Smart Pointers.
	- Same functionality as with a raw pointer, but with some extensions available and very different underlying behavior.

## Property Proxy

- In C# there are properties, which is a member with a getter and setter
- Take care of assignment and access and add special behavior
![Enter image alt description](Images/acV_Image_51.png)

## Virtual Proxy

- Example:
	- Image interface with single interface function draw() = 0
	- Bitmap is an Image
![Enter image alt description](Images/euW_Image_52.png)

- Drawback: We do not actually need to load the bitmap unless someone wants to draw it
- We can build a virtual Proxy (LazyBitmap) which follows the interface of the bitmap, but it is actually a lazy proxy which only loads the bitmap when draw is called

- In draw we check if the bitmap has been loaded and then actually load it once.
![Enter image alt description](Images/Bmb_Image_53.png)

## Communication Proxy

- We start with a “Pingable” Interface with single function `ping (std::string const& message) = 0`
- Then we have a Struct Ping, which inherits from Ping.
- A Function `tryit(Pingable& pp)`, which calls ping
- Lets create a RemotePong class that uses the same interface (ping) but connects to a REST service.
![Enter image alt description](Images/qwW_Image_54.png)

- In main we only need to replace `Pong` with `RemotePong`
![Enter image alt description](Images/CcF_Image_55.png)

## Proxy Vs Decorator

- They are really similar
- Proxy provides an identical interface, decorated provides an enhanced interface
- Decorator typically aggregates, Proxy can be a brand new object, not related to the original implementation at all
