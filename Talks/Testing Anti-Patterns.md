---
tags:
  - Talk
  - testing
  - tdd
created: 2021-10-14
---
# References

> [!tip]- When [[TDD]] goes wrong
> <iframe width="560" height="315" src="https://www.youtube.com/embed/UWtEVKVPBQ0?si=3ElPQDuXJhzp8is6" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
- First international [[TDD]] Conference, videos available [http://tddconf.com/](http://tddconf.com/)
- yegor bugayenko test patterns and anit patterns
- Martin Fowler: Eradication non-determinism in Tests

# Anti Patterns

- Big Setup
    - Example: Nuxt js
    - Requires excessive setup just to start testing
    - Big amount of dependencies for tests
- The liar
    - Appear to test things but actually does not test it.
    - E.g. always passing
    - missing assertions completely
    - misleading test description
- The Giant
    - Testing e.g. a God Object
    - Having multiple assertions in one test
- The Slow Poke
    - runs incredibly slow
    - can perhaps be avoided by mocks
    - always favor fast tests
