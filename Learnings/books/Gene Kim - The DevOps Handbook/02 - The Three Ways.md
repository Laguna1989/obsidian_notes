---
tags:
  - book-chapter
  - devops
---
# Excerpt

- DevOps is the result of many managerial, cultural, architectural and technological changes and practices “convergence of dev and ops”
- Apply the most trusted principles from the manufacturing business to the it value stream (lean, toyota production stream, theory of constraints, learning organizations, safety culture
- Lean (1980 Toyota -> 1997 application to other industries)
    - Lead time is the best indicator of quality, customer satisfaction and employee happiness
    - Embracing scientific thinking, flow and pull, quality at the source and respecting every individual
    - Manufacturing value Stream "the sequence of activities an Organization Undertakes in Order to Deliver on a customer requests"
    - Smooth and even flow of Work, small batch Sites, reducing Work in Progress, preventing rework, optimizing Systems towards global Goals
    - Input: formulation of Business Objective, concept or Idea
    - Output: value created by Services running in production
- Lead Times

 [!example]+ A Technology Value stream with a deployment lead time of three months

![](IMG-2024-06-16-071600329.png)
 a deployment lead time of 25 minutes

 ![](IMG-2024-06-16-071559853.png)
 A deployment lead time of multiple months

- (<https://www.youtube.com/watch?v=LdOe18KhtT4&ab_channel=O%27Reilly>) great video
ity movement
- Continuous Delivery movement
- Toyota Kata
    - Daily practice of improvement work

## The Three Ways

![[IMG-2024-06-16-071600444.png]]

- The First way
    - Speeding Up left to right flow
    - CI, Test, Integration, deployment processes, limiting wip, enabling Change
- The Second way
    - Enables fast and constant flow of Feedback from right to left
    - Amplify Feedback
- The third way
    - Create a high Trust culture, that Supports the scientific approach

The First way: the principles of flow

- Fast and smooth flow of Work from Dev to ops
- Make Work visible, reduce batch Sites, build quality in and prevent defects
- Make Work visible
    - In technology, Work is invisible
    - Make Work visible by Kanban/Scrum Boards
    - Work is "done" when the code runs successfully in production
- Limit Work in Progress
    - In technology, Work is highly dynamic with spontaneous requests pouring in from different communication Channels -> Team API from Team Topologie
    - Interrupting Tech workers is easy because the consequences are invisible
    - Multitasking is terrible
    - -> Limit Queue Sites for each column of the Kanban Board.
    - "Stop starting, start finishing"
- Reduce Batch Sites
    - Big batch Sizes means High Level of Work in Progress an high variability in flow that cascades -> Long lead Times and Low wuality
    - AIM for a batch Size of 1 (1x1 flow)
- Reduce number of handoffs
    - Automate Tasks
    - Build platforms and reorganize Teams so they can self-Service build/Service/deployment
- Continually identify and elevate constraints
    - Optimize at the bottleneck, Not before or after
- Eliminates hardships and waste in the value stream
    - Partially done work
    - Extra provesses
    - Extra Features
    - Task switching
    - Waiting
    - Motion
    - Defects
    - Nonstandard or Manual Work
    - Heroics

The Second Way: the principles of Feedback

- Feedback and Feedforward loops
- Working safely within compicated Systems
    - One single person cannot see or understand the complete system
    - High degree of interconnected and coupled components
    - Sometimes even Non-deterministic
    - Stativ Checklists and best practices are often insufficient
    - We can only make a complicated system safer, But never completely Safe
        - Problems in Design and operations are revealed
        - Problems are swarmed and solved, creating new knowledge
        - News local knowledge is exploited globally
        - Leaders grow Others Leaders
- See Problems as they occur
    - Constantly Test Design and operating assumptions
    - Feedback loops are critical for learning
- Swarm and solve Problems
    - Problems are solved immediately
    - A Task taking top Long is also considered a Problem
        - This stops the Problem from progressing downstreams
        - IT prevents new Work from being queued(which will have the Same or new errors)
    - Swarming is plan do check act
- Move quality closer to the source
    - Adding checks and processes lengthens cycle time and introduces more failures
    - Automate as much of documentation and quality checking
    - Provide feedback in minutes, not months
- Enable optimizing for downstream work centers

The third way: Continual Learning

- Constant creation of individual knowledge turns into shared team and organizational knowledge
- Normally suggestions for improvements meet a brick wall of indifference
- Aim create a high trust culture
- Scientific approach to process improvement and product development
- A culture of learning also makes the workplace fun, inspiring and rewarding
- Reserve time for learning
- Constantly introduce stress to the system to force continual improvement
- Enabling organizational learning and a safety culture
    - Strictly avoid “name, blame and shame” followed by pouring more processes on top
    - Bureaucracy vs careful organizations
    - Three types of organizations
        - Pathological: information is hoarded, often altered. Failure is almost always hidden
        - Bureaucratic: ruled by processes, silo thinking. Failure is either punished or dealt with mercily
        - Generative: Actively seeking and sharing information. Responsibilities are shared throughout the value stream
    - A generative organization creates a safe culture of work

| Pathological Org                    | Bureaucratic Org                               | Generative Org                     |
| ----------------------------------- | ---------------------------------------------- | ---------------------------------- |
| Information is hidden               | Information may be ignored                     | Information is actively sought     |
| Messengers are shot                 | Messengers are tolerated                       | Messengers are trained             |
| Responsibilities are shirked        | Responsibilities are compartmented             | Responsibilities are shared        |
| Briding between teams is disallowed | Bridging between teams allowed but discouraged | Bridging between teams is rewarded |
| Failure is covered up               | Organization is just and merciful              | Failures causes injury             |
| New ideas are crushed               | New ideas create problems                      | New ideas are welcomed             |

- Institutionalize the improvement of daily work
    - Often teams do not have the authority or capabilities to improve daily work
    - -> They continue to suffer and their suffering grows over time
    - “Even more important than daily work is improvement of daily work”
    - This leads to problems being fixed when consequences are smaller
- Transform local discoveries into global improvements
    - New learnings must be available to the complete organization
- Inject Resilience patterns into daily work
    - Antifragility: Introduce stress to push the system to the limits, creating knowledge how to improve or where a bottleneck is
    - Do fuzz testing and randomly shut down services in production to check for failures

# Discussions & Questions

# Text for the Book Club Week2

Hello everyone, besides the live discussion today about the introduction, let’s start the second week of the book club. This week is about the first part of the “three ways” (pages 3 - 32).

Some discussion starters

- Let’s talk about the continuous deployment and dark launch methods (see e.g. [10+ Deploys a Day](https://www.youtube.com/watch?v=LdOe18KhtT4&ab_channel=O%27Reilly)). Those surely work great for online services. How would you translate something like that to e.g. an automotive middleware solution (which has to provide long time support of old versions and is run only when used by customers in their cars)? More specifically: how to convince customers to take in additional features that they do not see? How would that work in a safety context when the code needs to be “golden” and you need to justify every line of code and have a manual inspection for every branch of code?
- I know that we measure flow metrics and lead time. Do we also measure %CA (percent complete and accurate)?
- P 21 states “Work is done when it Runs successfully in production, delivering value to the customer.” How does this align with us having only 3-4 Major releases a year? And how does the “in production” part work out, because it might take years until our software really shows up in the cars on the street.
- As “User Account Creation” is mentioned in this chapter: How Long does it take until a new employee can start to write his/her first line of code in your team?

# Text for the Book Club Week3

Hello everyone! This week we are going to read about the second part of the “three ways” (pages 33 - 60)

Some things I would like to discuss with you:

- The chapter speaks often about Feedback and Feedforward loops. Can you list some Feedback and Feedforward loops from your Daily Work?
- I see quite some Feedback loops for us, But have a hard time finding Feedforward loops.
- What is your fastest Feedback Loop? How Long does it take and how should you make it even faster? What is your slowest Feedback Loop?
- Do you practice Swarmingin in your Team or Product?
- In the example on page 41 a counterintuitive learning is mentioned: Pulling the andon chord and disrupting the team helped, although there was a disruption and a break of flow. However the team flow seems to increase. How do you explain this?
- Do you have both the internal and external customer in mind in your daily work?
- In which of the three types of organizations (page 48) do you see us?
- I find it interesting that I have a very different understanding of learning than the book. While the book promotes team and corporation learning from incidents, I see learning more as academic learning of things that might not necessarily be related to daily work, but still help in the broader picture, e.g. to become a better developer.
- The overview of the three three ways offer a great number of topics to discuss and think about. However, I am still missing quite some of them. Focus on inter- and intra team collaboration. Technical Excellence (this is a big one, on all levels). Improving communication. Getting rid of cumbersome processes. Empowerment of developers to actually take the decisions instead of having a disconnected “Process” team. Getting the right people hired. knowledge building and knowledge transfer. Meaningful leadership. And many others. What do you think about the selection of topics in this book?
