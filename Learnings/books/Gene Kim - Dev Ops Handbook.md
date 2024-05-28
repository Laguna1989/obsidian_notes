---
tags:
  - book
created: 2022-08-01
---
# Ultralearning Preface

see [[Ultralearning]]



<table>
  <tr>
   <td>What Topic and scope?
   </td>
   <td>DevOps book club
   </td>
  </tr>
  <tr>
   <td>Primary Resources?
   </td>
   <td>
<ul>

<li><a href="https://www.amazon.de/Devops-Handbook-World-class-Reliability-Organizations/dp/1950508404">DevOps Handbook on Amazon</a>

<li>Book club at work
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>What is the Benchmark?
   </td>
   <td>
<ul>

<li>Learn and understand about DevOps
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>Direct Practice Activities?
   </td>
   <td>
<ul>

<li>Read

<li>Prepare questions

<li>Discuss

<li>Participate in sessions
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>Backup Materials and Drill exercises?
   </td>
   <td>
<ul>

<li><a href="https://www.youtube.com/watch?v=LdOe18KhtT4&ab_channel=O%27Reilly">10+ Deploys a Day</a>

<li><a href="https://blog.huima.net/2021/02/08/BookclubDevopsHandbook/">bookclub blog post (1st edition)</a>

<li><a href="https://red-green-refactor.com/series/devops-handbook/">Bookclub blog posts (one for each chapter)</a>
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>Planned Time Schedule
   </td>
   <td>
<ul>

<li>2h preparation time + advertising

<li>~1h reading/week for 13 weeks

<li>~30min/week prepare questions for 9 weeks

<li>~30min/week meta sources

<li>participate in 1h session every week
</li>
</ul>
   </td>
  </tr>
</table>


# book club schedule


<table>
  <tr>
   <td><strong>week</strong>
   </td>
   <td><strong>date</strong>
   </td>
   <td><strong>pages</strong>
   </td>
   <td><strong>count</strong>
   </td>
   <td><strong>topic</strong>
   </td>
  </tr>
  <tr>
   <td>1
   </td>
   <td>19.9.
   </td>
   <td>….
   </td>
   <td>23
   </td>
   <td>Introduction
   </td>
  </tr>
  <tr>
   <td>2  
   </td>
   <td>26.9
   </td>
   <td>3 - 32
   </td>
   <td>29
   </td>
   <td>Pt1: The Three Ways 1/2
   </td>
  </tr>
  <tr>
   <td>3
   </td>
   <td>3.10.
   </td>
   <td>33 - 60
   </td>
   <td>27
   </td>
   <td>Pt1: The Three Ways 2/2
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>10.10
   </td>
   <td>61 - 96
   </td>
   <td>35
   </td>
   <td>Pt2: Where to Start 1/2
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>17.10
   </td>
   <td>97 - 132
   </td>
   <td>35
   </td>
   <td>Pt2: Where to Start 2/2
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>24.10
   </td>
   <td>Break
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>31.10
   </td>
   <td>133 - 176
   </td>
   <td>43
   </td>
   <td>Pt3: The First Way: Technical Practices of Flow 1/2
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>7.11.
   </td>
   <td>177 - 222
   </td>
   <td>45
   </td>
   <td>Pt3: The First Way: Technical Practices of Flow 2/2
   </td>
  </tr>
  <tr>
   <td>9
   </td>
   <td>14.11.
   </td>
   <td>223 - 258
   </td>
   <td>35
   </td>
   <td>Pt4: The Second Way: Technical Practices of Feedback 1/2
   </td>
  </tr>
  <tr>
   <td>10
   </td>
   <td>21.11
   </td>
   <td>259 - 302
   </td>
   <td>43
   </td>
   <td>Pt4: The Second Way: Technical Practices of Feedback 2/2
   </td>
  </tr>
  <tr>
   <td>11
   </td>
   <td>28.11
   </td>
   <td>Break
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>12
   </td>
   <td>5.12.
   </td>
   <td>303 - 350
   </td>
   <td>46
   </td>
   <td>Pt5: Third Way: Technical Practices of Continual Learning
   </td>
  </tr>
  <tr>
   <td>13
   </td>
   <td>12.12.
   </td>
   <td>351-395
   </td>
   <td>43
   </td>
   <td>Pt6: Technological Practices of Integrating
   </td>
  </tr>
</table>


**average**: 31 pages/week; median: 29 pages/week

**Meetings**: Fr früher Nachmittag


# Book Content

## Introduction

### Excerpt

* DevOps Myths
    * Only for Start-ups
    * Replaces agile
    * Incompatible with ITIL or itsm
    * Incompatible with infosec
    * Eliminates Ops or means noops
    * Means Just Infrastructure as Code
    * Only for Open Source Software
* DevOps Shows the best way forward
* Problem: Deployments are not normal, take weeks or months and are performed only few times a year
* The core conflicting goals:
    * Respond to rapid changes (Dev)
    * Provide a stable, reliable and secure service (Ops)
* Downward spiral in three acts:
    * Act 1:
        * One of the core problems are complex, badly documented applications and infrastructure that are extremely fragile
        * This leads to technical debts and daily workarounds (which requires enormous cognitive load)
    * Act 2:
        * Someone has to compensate for a broken promise (e.g. product management promising a bigger feature for the last missed one)
        * This leads to more cutting corners and even more added technical debt
    * Act 3: 
        * Work gets more coupled, everything gets more complicated (because of workarounds)
        * Feedback becomes slower
* Every company is a software company
* The Human cost: feeling powerless, burnout, high retention …
* Devops 
    * Improves operational performance
    * Achieve the goals of all technical roles (security, safety, development, qa, …)
    * Improve the human condition
    * Everyone will work during normal working hours during the week
    * Create fast feedback loops thanks to fast automated tests in production like environments
    * Problems are immediately fixed when they are found
    * Everyone feels productive
    * (dark launch techniques &lt;- lookup!) enabling features via easy switches?
    * Releases are controlled, predictable, reversible and low stress
    * Every fix creates organizational learning
    * Everyone is constantly learning, the scientific method is used and nothing is taken for granted
    * Instead of a culture of fear, we have a culture of high trust, collaborative, blame free culture with a lot of psychological safety
    * Everyone builds automated tests and uses peer reviews or even pair programming
    * Internal technology conferences teach new skills to everyone
    * Conduct planned fault injection (fuzz testing) into our system
    * Work matters and is meaningful
### Discussion & Questions

* What are your experiences for this book and for the book club?
* What of the DevOps myths mentioned have you heard or even experienced?
* What of the problems and challenges described on pages xxix ff. Have you encountered any of them yourself? How did you handle them?
* How many deploys a day are performed by your current team? How many developers does your team have? Now place your team in the Plot on Page xl. What Graph do you see your current team on?
* Now the same question for your complete project/product.
* Do you agree that the conflict between IT operations and Development is the root cause for the mentioned issues?


### Text for the Book club

Hi everyone, great to have you! Welcome to the first week of the book club. Let’s read the book together. Please feel free to discuss any topic related to the book in this chapter. Of course it is highly appreciated to share your insights here. The live session meeting for this week will be posted shortly. 

This week we are going to read the Introduction chapter. It starts out with some Devops Myths and describes the problem that DevOps is solving. Furthermore a first overview of DevOps is given.

As discussion starters I would like to propose the following questions

* What are your experiences for this book and for the book club?
* What of the DevOps myths mentioned have you heard or even experienced?
* What of the problems and challenges described on pages xxix ff. Have you encountered any of them yourself? How did you handle them?
* How many deploys a day are performed by your current team? How many developers does your team have? Now place your team in the Plot on Page xl. What Graph do you see your current team on?
* Now the same question for your complete project/product.
* Do you agree that the conflict between IT operations and Development is the root cause for the mentioned issues? Do you see other or additional reasons for those issues?


## Chapter 1: The Three Ways
### Excerpt

* DevOps is the result of many managerial, cultural, architectural and technological changes and practices “convergence of dev and ops”
* Apply the most trusted principles from the manufacturing business to the it value stream (lean, toyota production stream, theory of constraints, learning organizations, safety culture
* Lean (1980 Toyota -> 1997 application to other industries)
    * Lead time is the best indicator of quality, customer satisfaction and employee happiness
    * Embracing scientific thinking, flow and pull, quality at the source and respecting every individual
    * Manufacturing value Stream "the sequence of activities an Organization Undertakes in Order to Deliver on a customer requests"
    * Smooth and even flow of Work, small batch Sites, reducing Work in Progress, preventing rework, optimizing Systems towards global Goals
    * Input: formulation of Business Objective, concept or Idea
    * Output: value created by Services running in production 
* Lead Times

> [!example]+ A Technology Value stream with a deployment lead time of three months
>  
![[devops_handbook_value_stream_complex.png]]


> [!example]+ A Technology Value stream with a deployment lead time of 25 minutes
> ![[devops_handbook_value_stream_simple.png]]



* Agile Manifesto (2001)
    * [10+ Deploys a Day](https://www.youtube.com/watch?v=LdOe18KhtT4&ab_channel=O%27Reilly) great video
* Agile Infrastructure and Velocity movement
* Continuous Delivery movement
* Toyota Kata
    * Daily practice of improvement work

The three ways

![[devops_handbook_the_three_ways.png]]

* The First way
    * Speeding Up left to right flow
    * CI, Test, Integration, deployment processes, limiting wip, enabling Change
* The Second way
    * Enables fast and constant flow of Feedback from right to left
    * Amplify Feedback
* The third way
    * Create a high Trust culture, that Supports the scientific approach

The First way: the principles of flow



* Fast and smooth flow of Work from Dev to ops
* Make Work visible, reduce batch Sites, build quality in and prevent defects
* Make Work visible
    * In technology, Work is invisible
    * Make Work visible by Kanban/Scrum Boards
    * Work is "done" when the code runs successfully in production
* Limit Work in Progress
    * In technology, Work is highly dynamic with spontaneous requests pouring in from different communication Channels -> Team API from Team Topologie
    * Interrupting Tech workers is easy because the consequences are invisible
    * Multitasking is terrible
    * -> Limit Queue Sites for each column of the Kanban Board.
    * "Stop starting, start finishing"
* Reduce Batch Sites
    * Big batch Sizes means High Level of Work in Progress an high variability in flow that cascades -> Long lead Times and Low wuality
    * AIM for a batch Size of 1 (1x1 flow)
* Reduce number of handoffs
    * Automate Tasks
    * Build platforms and reorganize Teams so they can self-Service build/Service/deployment
* Continually identify and elevate constraints
    * Optimize at the bottleneck, Not before or after
* Eliminates hardships and waste in the value stream
    * Partially done work
    * Extra provesses
    * Extra Features
    * Task switching
    * Waiting
    * Motion
    * Defects
    * Nonstandard or Manual Work
    * Heroics

The Second Way: the principles of Feedback



* Feedback and Feedforward loops
* Working safely within compicated Systems
    * One single person cannot see or understand the complete system
    * High degree of interconnected and coupled components
    * Sometimes even Non-deterministic
    * Stativ Checklists and best practices are often insufficient
    * We can only make a complicated system safer, But never completely Safe
        * Problems in Design and operations are revealed
        * Problems are swarmed and solved, creating new knowledge
        * News local knowledge ist exploited globally
        * Leaders grow Others Leaders
* See Problems as they occur
    * Constantly Test Design and operating assumptions
    * Feedback loops are critical for learning
* Swarm and solve Problems
    * Problems are solved immediately
    * A Task taking top Long is also considered a Problem
        * This stops the Problem from progressing downstreams
        * IT prevents new Work from being queued(which will have the Same or new errors)
    * Swarming is plan do check act
* Move quality closer to the source
    * Adding checks and processes lengthens cycle time and introduces more failures
    * Automate as much of documentation and quality checking
    * Provide feedback in minutes, not months
* Enable optimizing for downstream work centers

The third way: Continual Learning



* Constant creation of individual knowledge turns into shared team and organizational knowledge 
* Normally suggestions for improvements meet a brick wall of indifference
* Aim create a high trust culture
* Scientific approach to process improvement and product development
* A culture of learning also makes the workplace fun, inspiring and rewarding
* Reserve time for learning
* Constantly introduce stress to the system to force continual improvement
* Enabling organizational learning and a safety culture
    * Strictly avoid “name, blame and shame” followed by pouring more processes on top
    * Bureaucracy vs careful organizations
    * Three types of organizations
        * Pathological: information is hoarded, often altered. Failure is almost always hidden
        * Bureaucratic: ruled by processes, silo thinking. Failure is either punished or dealt with mercily
        * Generative: Actively seeking and sharing information. Responsibilities are shared throughout the value stream
    * A generative organization creates a safe culture of work


| Pathological Org                    | Bureaucratic Org                               | Generative Org                     |
| ----------------------------------- | ---------------------------------------------- | ---------------------------------- |
| Information is hidden               | Information may be ignored                     | Information is actively sought     |
| Messengers are shot                 | Messengers are tolerated                       | Messengers are trained             |
| Responsibilities are shirked        | Responsibilities are compartmented             | Responsibilities are shared        |
| Briding between teams is disallowed | Bridging between teams allowed but discouraged | Bridging between teams is rewarded |
| Failure is covered up               | Organization is just and merciful              | Failures causes injury             |
| New ideas are crushed               | New ideas create problems                      | New ideas are welcomed             |

* Institutionalize the improvement of daily work
    * Often teams do not have the authority or capabilities to improve daily work
    * -> They continue to suffer and their suffering grows over time
    * “Even more important than daily work is improvement of daily work”
    * This leads to problems being fixed when consequences are smaller
* Transform local discoveries into global improvements
    * New learnings must be available to the complete organization
* Inject Resilience patterns into daily work
    * Antifragility: Introduce stress to push the system to the limits, creating knowledge how to improve or where a bottleneck is
    * Do fuzz testing and randomly shut down services in production to check for failures
* 


### Discussions & Questions


### Text for the book club week2

Hello everyone, besides the live discussion today about the introduction, let’s start the second week of the book club. This week is about the first part of the “three ways” (pages 3 - 32).

Some discussion starters



* Let’s talk about the continuous deployment and dark launch methods (see e.g. [10+ Deploys a Day](https://www.youtube.com/watch?v=LdOe18KhtT4&ab_channel=O%27Reilly)). Those surely work great for online services. How would you translate something like that to e.g. an automotive middleware solution (which has to provide long time support of old versions and is run only when used by customers in their cars)? More specifically: how to convince customers to take in additional features that they do not see? How would that work in a safety context when the code needs to be “golden” and you need to justify every line of code and have a manual inspection for every branch of code?
* I know that we measure flow metrics and lead time. Do we also measure %CA (percent complete and accurate)?
* P 21 states “Work is done when it Runs successfully in production, delivering value to the customer.” How does this align with us having only 3-4 Major releases a year? And how does the “in production” part work out, because it might take years until our software really shows up in the cars on the street.
* As “User Account Creation” is mentioned in this chapter: How Long does it take until a new employee can start to write his/her first line of code in your team?


### Text for the book club week3

Hello everyone! This week we are going to read about the second part of the “three ways” (pages 33 - 60)

Some things I would like to discuss with you:



* The chapter speaks often about Feedback and Feedforward loops. Can you list some Feedback and Feedforward loops from your Daily Work?
* I see quite some Feedback loops for us, But have a hard time finding Feedforward loops.
* What is your fastest Feedback Loop? How Long does it take and how should you make it even faster? What is your slowest Feedback Loop?
* Do you practice Swarmingin in your Team or Product?
* In the example on page 41 a counterintuitive learning is mentioned: Pulling the andon chord and disrupting the team helped, although there was a disruption and a break of flow. However the team flow seems to increase. How do you explain this?
* Do you have both the internal and external customer in mind in your daily work?
* In which of the three types of organizations (page 48) do you see us?
* I find it interesting that I have a very different understanding of learning than the book. While the book promotes team and corporation learning from incidents, I see learning more as academic learning of things that might not necessarily be related to daily work, but still help in the broader picture, e.g. to become a better developer.
* The overview of the three three ways offer a great number of topics to discuss and think about. However, I am still missing quite some of them. Focus on inter- and intra team collaboration. Technical Excellence (this is a big one, on all levels). Improving communication. Getting rid of cumbersome processes. Empowerment of developers to actually take the decisions instead of having a disconnected “Process” team. Getting the right people hired. knowledge building and knowledge transfer. Meaningful leadership. And many others. What do you think about the selection of topics in this book?


## Chapter 2: Where to start


### Excerpt



* Focus on:
    * Identifying Value streams to start the transformation
    * Understanding the work in those value streams
    * Designing the organization according to conways law
    * Enabling outcomes
    * Protecting and enabling the team

Selecting The value stream to start with



* The value stream dictates the difficulty of the transformation and the involved parties
* Pick carefully, because if you are in trouble you do not get many shots
* Focus on early wins to convince others
* Integrate testing into their daily work
* Stop throwing bodies at the problem and improve the way we work
* Brownfield: Already existing project, possibly high level of technical debt, already in production
* Greenfield Project: Start from scratch
* System of Records (HR, ERP, “do it right”) and Systems of engagement (customer facing, “do it fast”). Both can be combined with DevOps. By making downstream projects safer and faster to change, the upstream projects (and often the complete organization) benefit as well.

Start with the most sympathetic and innovative group



* Find Teams that already believe in devops and work with them
* Avoid the big bang “Starting all at once”
* This resembles the “Our Iceberg is melting” plan.
* Demonstrate early wins 
* Use change agents
* Steps:
    * Find innovators and early adopters
    * Build critical mass and silent majority
    * Identify the holdouts
* “Culture eats strategy for breakfast”

Understand the work in the value stream



* Improvements can start with incremental work
* Often it is not the tools, but the processes that make things slow
* No single person knows everything, so you need to bring everyone together
* Create a Value stream map
* Focus on: 
    * Places where work must wait for weeks or months
    * Places where significant rework is generated
* Aim for one goal (reduced lead time, %CA, …) and set a concrete goal for 3 or 12 months.
* Create a dedicated Transformation team
    * They work outside of the daily business work context
    * The team is hold accountable for a measurable system wide result
        * Members are dedicated to that team instead of 80%/20% splitting
        * Select generalist team members
        * Team members who have long standing and respectful relationship with key aeras
        * Create separate physical and virtual spaces for the team
* Agree on a shared goal with a fixed timeline
    * Reduce budget spent on unplanned work by 50%
    * Teams need to decide on a regular cadence to work on that goal
* Keep improvement Horizons short
* Reserve 20% for unplanned work and Technical Debt
* Increase the visibility of work
* Use Tools to reinforce desired behavior

Conways Law



* Optimize for Speed instead of for money
* Hire EShaped employees
* Fund Products and services instead of Projects
* Design Team boundaries with Conway’s law in mind.
* Create loosely coupled architectures
* Keep Team sizes small

How to get great outcomes by integrating ops into dev



* All the platforms and services should be automated and available on demand without requiring anyone to open or work on a ticket.
* Use the best tools and services available. This means that internal services need to compete with commercial services and.
* Embed ops engineers into service/product teams
    * This also helps with training
* Integrate ops into dev rituals
    * Standup and retrospectives
* Ops tasks should be on the same kanban board


### Discussions & Questions


### Text for the book club week4



* Do you consider yourself in a greenfield or brownfield project/product?
* What are systems of records and systems of engagement that you regularly use? Or do you see devops already applied?
* There have been multiple value stream analyses at EB. Did you take a look at the Value Stream maps and did you agree with the findings?
* What is not clear to me: The actual work is being performed by the teams. How will they interact with the transformation team that is not doing the actual work? I see a big risk of the Transformation team becoming an ivory tower team.
* On the tools reinforcing desired behavior: What tools are you using in your daily work and do they reinforce desired behavior (e.g. easy refactoring)? Do you have a shared prioritized backlog for your product or is it split up for different teams?


### Text for the book club week5



* In which Type of organizational Archetype(funktional, Matrix, Market)  do you See us?
* Do you see yourself as I, T or E shaped?
* Which parts from the Conways Law do you recognize from Team Topologies? Which differ?
* How big is your team compared to the two-pizza-rule?
* Regarding automated and available-on-demand Services and platforms: How well do you follow this? E.g. when onboarding new team members (access rights?), when changing your build environment or when performing a release.
* What do you think about our approach of “only using approved tools and services” compared to the suggestion from the book that each team picks the best platform and service for the job?


## Chapter 3: The first way: Technical practices of flow


### Excerpt

Create the foundations of your deployment pipeline



* We must use production-like environments in every part of the value chain
* No manual work to get those production-like environments

Enable on demand creation of dev, test and production environments



* Ways of providing an environment
    * Copying a virtualized environment
    * Building an automated environment from scratch
    * Using Infrastructure as code
    * Using automated OS configuration tools
    * Assembling an environment from a set of virtual images
    * Spinning up an environment in the cloud
* Create a single repository of truth
    * All application code and dependencies 
    * All scripts (e.g. for database schemas, …)
    * Environment creation tools
    * Test code
    * Everything for deployment
    * Use hashes to ensure you have the right files
* Make Infrastructure easier to rebuild than to repair
    * Create immutable infrastructure
    * Extend the DoD to run the software in production like environments
    * Same tools for monitoring and escalation are used, giving confidence in the processes
* Continuously build, test and integrate code and environments
    * Increase the frequency of integration, testing and environments from periodic to continuous 
    * Keep code in a always-shippable state
    * Catch errors early. 
    * Unit tests should complete within max 10minutes
    * Use TDD or Acceptance TDD (ATDD)
    * Automate as many manual tests as possible
    * Integrate Performance testing (long running memory consumption, or performance, empty database entries, …)
    * Integrate non-functional requirements into automated tests
* Create a virtual andon cord
    * Treat as Priority 0 show stoppers and work on the immediately
    * If an acceptance test fails, have people on call who deal with this immediately
* Use Trunk based development, Continuous Integration and Continuous Delivery
* Automate and enable low-risk releases
* Decouple Deployment and Releases
* Architect for low risk releases

### Text for the book club week6

*  How would dev and production environments look like when the software is a middleware library, when customers run it on many different systems?
* What about the time it takes for the tools that create/run an environment to spin up? How long would you accept to wait (one time or regularly)?
* Do you have some sort of CI Pipeline? Is your code in an “always shippable” state?
* What is your branching strategy? Do you work on “master” or “trunk” or do you have feature branches? How long do those branches live on average?
* How do you support older versions? How easy is it for you to get the code running from last week? Last year? 4 years ago? I could imagine that the CI requirements are quite different depending on whether you need to do long time support of older releases.
* What is covered by your tests? How do you take care of manual tests, performance tests and non functional requirements in your current project?
* Do you have an “andon cord” equivalent? How do you deal with build breaks or red nighty/master branch verifications?
* What is the frequency of your deployments? What is the average lifetime of your branches? Do you practice Trunk-Based-Development?

### Text for the book club week7

* What is your deployment process? How automated is it?
* Who in your setup can deploy code to production? 
* How often do you perform releases? When doing a release, do you use any special release strategy such as the green/blue deployment pattern?

## Chapter 4: Second Way technical practices of feedback

### Excerpt

* Log production, Dev and Business metrics
* Create application logging telemetry that helps production
* Telemetry can help in problem solving and swarming
* Production metrics creation should be a part of daily work
* Create self-service access to all telemetry (easy access)
* Find and Fill any Telemetry gaps
* Analyze Telemetry to better anticipate problems and achieve goals

### Discussions & Questions

* How to Log metrics if you do not own the systems your software is running on? For us there can be e.g. diagnostics, but feedback for that is normally slow, e.g. only on the next car service.
* One thing I find strongly puzzling in the quote "we enable engineers to track what they want to track, at the drop of a hat, without requiring time sucking configuration changes or complicated processes". Why don't we Just make it easy for developers to do what they are here for: developing software?
* I do not understand Figure 14.1. what exactly is “MTTR”?
* Which of the metrics listed on page 239 (or equivalent counterparts) do you see fit for your product/project?
* 