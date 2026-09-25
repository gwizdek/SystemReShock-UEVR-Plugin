# Architecture Standards

> These rules apply to ALL code in the project, regardless of technology stack.

**Rules:**
- Presentation layer is thin: parse input, delegate to service, return response
- Services contain ALL business logic and throw domain errors
- Services never import framework-specific request/response types
- Only the data layer talks to the database directly
- Cross-domain orchestration uses facade services that delegate without containing logic

## Domain Isolation

Each domain owns its own vertical slice of files. The exact files depend on the stack, but the principle is universal:

- A domain service NEVER imports another domain's data queries directly
- Cross-domain communication goes through the other domain's service interface
- Shared types live in a dedicated types/interfaces location
- Each domain's validation schemas are co-located with the domain

## Cross-Domain Name Resolution

When a domain needs to display data owned by another domain (e.g., a Report rendering a Project's client name), go through that domain's **service interface** — never inject another domain's repository directly. If resolution spans 3+ entity types, prefer a strategy pattern (a list of resolver beans) over a switch. This keeps domains decoupled and makes new types addable without modifying existing code.

## Shared Domain Interfaces

Interfaces implemented by entities across multiple domains live in `com.budget.common.model` — the top-level shared model package, not inside any single domain. This avoids circular imports and satisfies layer rules (the Domain layer cannot depend on Security/Service layers).

## SOLID Principles

### Single Responsibility (SRP)
- One service per domain. One handler per domain.
- A function does ONE thing. If you need "and" to describe it, split it.
- A file should have one reason to change.

### Open/Closed (OCP)
- Extend behavior through composition, not modification of existing code
- Use strategy patterns (function maps, config objects) over growing switch statements
- New features should add files, not modify core logic

### Liskov Substitution (LSP)
- Any abstraction's consumers should work with any implementation
- Implementations must not throw unexpected errors or violate interface contracts

### Interface Segregation (ISP)
- Don't force consumers to depend on methods they don't use
- Prefer small, focused interfaces over large catch-all ones
- Split large service files when they exceed ~300 lines

### Dependency Inversion (DIP)
- Services depend on abstractions, not concrete implementations
- Infrastructure (database, email, queues) is injected or imported via a shared lib layer
- Test doubles replace infrastructure, not business logic

## Composition Over Inheritance

- No class hierarchies deeper than 1 level
- Prefer function composition and higher-order functions
- Utility functions over base classes
- In React: hooks and composition, never class components
- In Java: favor composition and interfaces over abstract class hierarchies
- In Python: mixins sparingly, prefer standalone functions

## Method Size Limits

Methods and functions MUST be short, focused, and readable. Long methods are the root cause of most complexity, testability, and readability problems.

**Rules:**
- No method or function body may exceed **30 lines** of logic (excluding blank lines and single-line annotations/decorators)
- If a method exceeds 20 lines, look for extract-method opportunities
- Each method does ONE thing — if you need "and" to describe it, extract a helper
- Prefer early returns to reduce nesting depth (max 3 levels of indentation)
- Long parameter lists (4+) indicate the method is doing too much — introduce a parameter object or split
- Callbacks and lambdas count: an inline lambda longer than 5 lines must be extracted to a named method

**Enforcement:**
- `/review` must flag any method over 30 lines as a BLOCKER
- `/implement` must proactively break logic into small, named methods as it builds
- During code generation, if a method starts exceeding 20 lines, stop and refactor before continuing

**How to split:**
1. **Extract method** — pull a logical block into its own method with a descriptive name
2. **Guard clauses** — move preconditions to the top with early returns
3. **Strategy pattern** — replace multi-branch conditionals with a function map or strategy
4. **Pipeline/chain** — break sequential transforms into composable steps
5. **Delegation** — if a method orchestrates multiple concerns, each concern is its own method

## Anti-Patterns to Avoid

- **God objects**: No file over 500 lines. Split by responsibility.
- **Circular dependencies**: Domain A must not import Domain B if B already imports A. Introduce a facade.
- **Anemic domain model**: Services must contain logic, not just pass-through to the data layer.
- **Shotgun surgery**: If changing one behavior requires touching 5+ files across domains, the boundaries are wrong.
- **Feature envy**: If a service mostly accesses another domain's data, the logic belongs in that other domain.
- **Leaky abstractions**: Don't expose ORM entities or framework types through service interfaces.
