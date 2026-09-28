---
name: brainstorm
description: "Generate standalone HTML comparing 2-4 architectural or technical approaches for a decision. Opens in browser for visual side-by-side comparison before committing to an approach."
disable-model-invocation: true
argument-hint: <question-or-dilemma> [--directions=2-4]
allowed-tools: Read, Grep, Glob, Write, Edit, Bash, AskUserQuestion
---

# Technical Brainstorm

Generate a self-contained HTML file comparing multiple technical approaches for visual side-by-side comparison. Opens in the browser so the user can evaluate trade-offs before committing to an implementation direction.

## When to use

- Before implementation when 2+ viable approaches exist with roughly equal trade-offs
- Architecture decisions: data model design, API patterns, service decomposition
- Technology choices: library selection, caching strategy, state management
- **Not needed for:** clear-winner decisions, cosmetic choices, naming conventions

## Inputs

Parse `$ARGUMENTS` for:
- Decision question or context (required)
- `--directions=N` (default: 3, range: 2-4)

## Phase 1: Gather Context

1. Understand the decision scope from the user's question
2. Read relevant source code — existing patterns, architecture, dependencies
3. Read specs if relevant (`documentation/specs/<domain>/`)
4. Read architecture rules (`.claude/rules/architecture.md`)
5. Identify hard constraints that narrow the solution space

### Phase 1 output: Decision frame

```
Decision: <one-line question>
Constraints: <hard limits from codebase/rules>
Dimensions: <what varies between approaches — e.g., complexity, performance, coupling>
```

## Phase 2: Design the Approaches

Generate N approaches (default 3). Each must be a **structurally different** solution, not a minor variation.

**Each approach includes:**
- **Name** — short label (e.g., "Event-Driven Decoupling")
- **One-line summary** — the core idea
- **How it works** — 3-5 bullet points covering implementation
- **Architecture sketch** — ASCII diagram of components/data flow (max 15 lines)
- **Files affected** — what changes in the codebase (new / modified)
- **Pros** — 2-4 concrete benefits
- **Cons** — 2-4 concrete drawbacks
- **Complexity** — estimated effort (Low / Medium / High) and risk level
- **Best when** — the scenario where this approach clearly wins

**Differentiation rules:**
- Approaches must differ in at least one structural dimension (coupling, data flow, abstraction level, technology choice)
- No filler approaches — every option must be something you'd genuinely recommend in the right context
- Include trade-off dimensions that help the user decide: maintainability vs. performance, simplicity vs. extensibility, speed-to-ship vs. future flexibility

## Phase 3: Generate HTML

Produce a single self-contained HTML file (≤ 600 lines).

### HTML structure

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Brainstorm — <Decision></title>
  <style>/* all CSS inline */</style>
</head>
<body>
  <header><!-- decision title + constraints --></header>
  <nav><!-- tab buttons for each approach + Compare All toggle --></nav>
  <!-- one <section> per approach -->
  <footer><!-- comparison table (visible in Compare All mode) --></footer>
  <script>/* tab switching + comparison toggle */</script>
</body>
</html>
```

**CSS requirements:**
- System font stack: `"DM Sans", sans-serif`
- All styling inline in `<style>` — no external dependencies
- Color coding per approach — distinct but muted palette
- Responsive: readable at 1200px+
- Dark header (`#2B1E3D`) with decision title for visual anchoring

**Header:**
- Decision question as `<h1>`
- Constraints listed below (the non-negotiables)
- Date generated

**Navigation bar (sticky below header):**
- One button per approach with short label and colored accent
- Active approach highlighted
- "Compare All" toggle button on the right

**Each approach panel contains:**
1. **Approach name** as `<h2>` with colored left border
2. **One-line summary** in italics
3. **How it works** — numbered implementation steps
4. **Architecture diagram** — `<pre>` block with ASCII art, monospace font, subtle background
5. **Files affected** — grouped by new / modified
6. **Pros** and **Cons** — side by side in two columns, checkmark/cross prefix
7. **Complexity badge** — Low (green) / Medium (amber) / High (red)
8. **Best when** — highlighted callout box with light background

**Comparison footer (visible in "Compare All" mode):**
- Table with approaches as columns, dimensions as rows
- Dimensions: complexity, coupling, performance, extensibility, testing ease, migration effort
- Each cell: brief rating with color indicator (green/amber/red)

**Tab switching JavaScript:**
```javascript
function show(n) {
  document.querySelectorAll('.approach').forEach(d => d.classList.remove('active'));
  document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
  document.getElementById('a' + n).classList.add('active');
  document.querySelectorAll('.nav-btn')[n - 1].classList.add('active');
  document.getElementById('compare').classList.remove('active');
}
function toggleCompare() {
  const cmp = document.getElementById('compare');
  const isActive = cmp.classList.toggle('active');
  document.querySelectorAll('.approach').forEach(d =>
    isActive ? d.classList.add('active') : d.classList.remove('active')
  );
  if (isActive) {
    document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
  }
}
```

## Phase 4: Write Output & Present

**When called from pipeline (plan phase):** write to `$WS/brainstorm/`
**When called standalone:** write to `documentation/tmp/brainstorm/<slug>/`

Files:
- `brainstorm.html` — the visual comparison
- `brainstorm-summary.md` — text summary for pipeline handoff:

```markdown
# Brainstorm: <decision question>

## Decision
<what needs to be decided and why>

## Constraints
<hard limits identified in Phase 1>

## Approaches

| # | Name | Complexity | Key Trade-off |
|---|------|-----------|---------------|
| A1 | <name> | Low/Med/High | <main trade-off> |
| A2 | <name> | Low/Med/High | <main trade-off> |
| A3 | <name> | Low/Med/High | <main trade-off> |

## Selected: A<N> — <name>
<rationale for selection>
```

Open the HTML in browser:
```
open <path-to-html-file>
```

Ask which approach the user prefers. Record the selection in `brainstorm-summary.md`.

If called from pipeline: the selected approach feeds back into `plan.md` — the plan adopts it for all downstream phases.
