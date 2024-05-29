---
tags:
  - book
created: 2021-01-01
links: "[[Book reviews]]"
---
# Chapter 1 - The Age of Software

- No sector is safe from digital disruption. The Higher the sector, the Higher the disruption
    - 1 Resource Extraction
    - 2 Processing and Manufacturing
    - 3 Services
    - 4 Knowledge Work
- Types of Disruption
    - Infrastructure Model (how do customers Access a product or offering?)
    - Operating Model (Change relationship of customers with Business, e.g. Mobile Phone Apps)
    - Business Model (e.g. Cut a manual step how customers get goods)
- Technical Innovation theories
    - Kondratiev cycles (50yesrs)
    - Creative Destruction
    - Others
    - Disagreement in cause and duration
- Age of Software
    - Installation Period(Venture Capital flows in, new technological systems, disruption, Start-ups)
    - Deployment Period (companies master the means of production, new infrastructure, production becomes more efficient
![[project2product_installationToDeployment.png]]
    - Unknown how Long turning Point will last
    - Different ages
![[project2product_different_ages.png]]

- Epiphany leadup
    - Technology improvements are no longer the bottleneck
    - Disconnect between it and Business
    - Disconnect within it
- Epiphanies
    - Productivity decreases, waste increases als Software scales due to disconnects between Architecture and value Stream
    - Disconnected value streams are the bottleneck to Software production
    - Software value streams are no linear Manufacturing process, but complex collaborations

# Chapter 2 - From Project to Product

- Lesson 1 to avoid the pitfalls of local optimization, Focus on the end to end value stream
    - from ideation to delivery
- Lesson 2 If you manage a transformation on Cost alone, you will reduce productivity
- Lesson 3 engineering/IT and the Business must be connected.
- Projects vs products
![[project2product_management1.png]]
![[project2product_management2.png]]

# Chapter 3 - Introducing the Flow Framework

- The Flow Framework will:
    - See end to end flow of business value in real time
    - Instantly spot bottlenecks (allows to prioritize investments)
    - Test hypothesis based on real time data
    - Rearchitecturing the organization around optimal flow
- Focus on result oriented business metrics, e.g. revenue and cost. Avoid Proxy Metrics
- Lean thinking in five principles:
    - Precisely specify value by specific product
    - Identify the value stream for each product
    - Make value flow without interruption
    - Let the customer pull value from the producer
    - Pursue perfection
- What is a value stream?
    - The end to end set of activities performed to deliver value to the customer via a product or service
    - Value stream segments are important, but not the focus here (end2end)
- Software Flow : the activities involved in creating business value in a software value stream
- Pulling value from software: new features or bug fixes. risk mitigation, technical debt reduction
- Flow Item: a unit of business value pulled by a stakeholder through a product’s value stream
- The Four Flow Items:

![[project2product_theFourFlowItems.png]]
# Chapter 4 - Flow Metrics

![[Pasted image 20240529231353.png]]

> [!hint] Flow distribution
> - The proportion of each flow Item in a value Stream, adjusted depending on the needs of that Stream to maximize Business.
> - Flow distribution is unique to each Product.
> - Teams know best which flow distribution is needed.
> - Flow distribution can be tailored to current Situation, e.g. trade features-debt

> [!hint] Flow Velocity
> - Number of flow items finished during one time Interval
> - Time Interval: e.g. one release, one month, a quarter.

> [!hint] Flow time
> - Duration from when Item being accepted for Work in the value Stream (Ticket creation for  schedule Feature for Release) until Item completion
> - Four states: new, waiting, active, done
> - Click runs Always, including Off hours and weekends.
> ![[project2product_FlowTime.png]]
> 

> [!hint] Flow Load
> - The Number of flow items being actively worked on in a value Stream, showing the Work in progress

> [!hint] Flow Efficiency
> - Time actively worked on Item Dividend by flow time of Item
> - 20-40% are very good.

# Chapter 5 - Connecting to Business Results

- Business results: Value, Cost, Quality, Happiness
![[project2prodct_businessresults.png]]

> [!hint] Value
> - E.g. Overall or monthly revenue, monthly active Users,
> - Do Not Mix value streams, e.g. from Product bundles


> [!hint] Cost
> - Cost of owning the value Stream.
> - Do not include marketing and Sales
> - Shared resources (e.g. a Designer) should be exceptions, Not the Norm.


> [!hint] Quality
> - Use customers visible quality metrics
> 

>[!hint] Happiness
>- The health of the value Stream
>- Value Stream dashboards



# Chapter 7 - The Ground Truth of Enterprise Tool Networks

- Value stream networks: concepts, layers and indices for measuring
- Tech giants have invested heavily in value stream networks, giving them a customized advantage.

# Chapter 8 - Specialized Tools and the Value Stream

- Tools cause disconnections, because developers need to switch context
- Scale production -> specialize workers
- Scale business -> specialize in tools (e.g. one issue tracker vs individual issue trackers for customers, internal development and business aspects)
- Two types of complexities
    - Fundamental complexity: can not be optimized out
    - Accidental complexity: e.g. through acquisitions. does not increase flow
- Twitter/netflix have a very streamlined & simple user interface and thus not much complexity there.

# Chapter 9 - Value Stream Management

- Software is fundamentally different (network) to the goods from the age of mass production (linear production line)
- Start at tools network, goto artifact network and end at value stream network
- How to search for bottlenecks in software production?
- How to work around a bottleneck: reroute the work instead of doing a production stop
- Linear and network does not only apply to production, but also to bottlenecks.
- Differences between network and linear
    - Variability: design of sofware is open ended, while manufacturing has a fixed set ot options (e.g. colors of a car)
    - Repeatability: manufacturing is about maximizing the throughput of the same item, software is about maximizing the iterations and feedback loops
    - Design frequency: manufacturing designs up front, software redesigns constantly
    - Creativity: manufacturing wants to reproduce, while software wants to create
- Connecting the tool network
    - Connectivity index: number of tools that have been connects to those which have been.
- connecting tools network to the integration model
    - The integration model defines the cross tool work items that flow through value streams
    - It is a layer of abstraction for the artifacts of the tool model and provides mapping
    - The integration model enables easy reporting of flow metrics across any number of tools
    - The integration model enables modularity by abstracting details
- Traceability index:
    - Should be 100%
    - The measure of artifact connection breadth and depth relative to artifact type
- Aligning the value stream network with the Product Model
    - Value stream network is the topmost layer, while the lower layers provide infrastructure and traceability
    - Product model provides a mapping between existing artifact containment and the product oriented value stream
    - Alignment index: the ratio of artifact containers connected to a product value stream relative to all artifact containers
- Making Value Streams visible
- Time thieves:
    - Too much work in progress
    - Unknown Dependencies
        - Three dependencies: architecture, expertise and activity
    - Unplanned work
    - Conflicting Priorities
    - Neglected Work
