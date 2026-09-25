---
name: discover
description: "Cross-domain discovery. Two modes: crosscut (scan all domains for a shared pattern) and feature (scan for cross-domain impact of a new feature). Produces discovery.md listing affected domains, files, specs, and recommended approach."
disable-model-invocation: true
argument-hint: <change-or-feature-description>
allowed-tools: Read, Grep, Glob, Bash, Agent, Write, Edit, AskUserQuestion, TodoWrite
---

# Cross-Domain Discovery

Scan the codebase to identify domains affected by a change. Two modes:

- **Crosscut mode**: find every domain where a pattern occurs (e.g., RBAC on archive buttons)
- **Feature mode**: given a feature in a primary domain, find secondary domains that need updates

## Mode Detection

| Signal | Mode |
|--------|------|
| `audit.md` exists in workspace (feature pipeline ran audit first) | **Feature mode** |
| No `audit.md`, change targets a pattern across domains | **Crosscut mode** |
| Pipeline preamble says "crosscut" | **Crosscut mode** |
| Pipeline preamble says "feature" | **Feature mode** |

## Inputs

- `$ARGUMENTS` — description of the change or feature
- `requirement.md` if it exists (from pipeline) — authoritative source
- `audit.md` if it exists (from feature pipeline) — primary domain context

---

## Crosscut Mode

Scan the entire codebase for a pattern. All domains are scanned equally.

### Step 1: Understand the Change

1. Read `requirement.md` if it exists — extract the precise scope
2. Parse the change description to identify:
   - **Target functionality**: what feature/behavior is being changed
   - **Change type**: add, modify, remove, or fix
   - **Search terms**: keywords, method names, component names, API paths to grep for
3. Build a search plan: list 3-5 grep patterns that would find this functionality across domains

### Step 2: Map All Domains

1. **Backend domains**: Glob for controller/route files — each parent package/directory is a domain
2. **Frontend domains**: Glob for `frontend/src/pages/*/` or equivalent — each directory is a domain
3. **Existing specs**: Glob for `documentation/specs/*/README.md` — known specified domains
4. Build a domain inventory: name, backend path, frontend path, spec path (if exists)

### Step 3: Scan for Affected Functionality

For each search term from Step 1, scan across ALL domains:

1. **Backend grep**: search backend source for the term — group hits by domain package
2. **Frontend grep**: search frontend source for the term — group hits by page/component domain
3. **Spec grep**: search `documentation/specs/` for the term — find which specs already cover this
4. Record every hit: file path, line number, 3 lines of context

Filter: a domain is "affected" if it has at least one hit for the target functionality.

### Step 4: Deep-Dive Each Affected Domain

For each affected domain (max 3 files read per domain to stay focused):

**4a. Understand current implementation**
- Read the most relevant file (the one with the strongest hit)
- Identify: what does the code do now? What's the current behavior?
- Note: controller, service, entity, frontend component involved

**4b. Check existing spec coverage**
- If spec exists: read README.md and grep UC files for the functionality
- Note which UCs already cover it and their AC IDs
- If no spec: note "no spec — implementation only"

**4c. Identify the gap**
- Compare current behavior against the requirement
- What's missing? What's wrong? What needs to change?

### Step 5: Identify Shared Patterns

Look across all affected domains for:

- **Common code pattern**: is the same logic copy-pasted?
- **Shared abstractions already in use**: base class, utility, shared component, helper
- **Inconsistencies**: do different domains handle it differently? Which is correct?
- **Shared fix opportunity**: can one change fix all domains at once?

### Step 6: Write Crosscut Discovery Report

Write `discovery.md` to the pipeline workspace.

```markdown
# Discovery: <change-name>

## Change Summary
<1-2 sentences: what needs to change and why>

## Search Strategy
| Search Term | Pattern | Hits |
|-------------|---------|------|
| <term> | <grep pattern> | <N files across M domains> |

## Affected Domains

### <Domain 1> — `<spec-path-if-exists>`
- **Backend**: `<file1>:L<line>`, `<file2>:L<line>`
- **Frontend**: `<file1>:L<line>`
- **Existing spec**: <path> — <UC-ID covers this> / "no spec"
- **Current behavior**: <what it does now>
- **Gap**: <what needs to change>

### <Domain 2> — `<spec-path-if-exists>`
...

## Unaffected Domains
<domains scanned but not affected — confirms scope completeness>

## Shared Pattern
<common implementation pattern across domains>

## Recommended Approach
- **Strategy**: <per-domain fix / shared utility / shared component / mixed>
- **Estimated scope**: <N domains, ~M files to change>
- **Risk areas**: <any domain that's more complex or different from the pattern>
```

---

## Feature Mode

Given a primary domain and feature, scan for secondary domains that need updates.

### Step F1: Understand the Feature Scope

1. Read `requirement.md` — what feature is being added
2. Read `audit.md` — primary domain's current architecture: entities, APIs, components
3. Identify the primary domain's **boundary elements** — things other domains might reference:
   - Entity names and their IDs
   - API endpoints other domains might call
   - Shared DTOs or response types
   - Frontend components or hooks used outside the domain
   - i18n key namespaces

### Step F2: Build Impact Search Terms

From the requirement and audit, extract:
- **New/changed entity fields** that might appear in other domains' views or filters
- **New/changed API endpoints** that other domains consume
- **Changed behavior** that other domains depend on (e.g., status values, validation rules)
- **UI elements** used across domains (shared components, cross-domain navigation)

Build 3-5 grep patterns targeting cross-domain references to the primary domain.

### Step F3: Scan Other Domains

For each search term, scan domains OTHER than the primary:

1. **Backend grep**: search for imports/references to primary domain's entities, services, or DTOs
2. **Frontend grep**: search for references to primary domain's components, hooks, or API calls
3. **Spec grep**: search other domain specs for references to the primary domain

Filter: a secondary domain is "affected" if it references primary domain elements that the feature changes.

### Step F4: Assess Impact per Secondary Domain

For each hit (max 2 files read per secondary domain):
- **Impact type**: data model reference, API consumer, UI display, shared component, navigation link
- **Severity**: must-change (would break without update) vs should-change (improvement, consistency)
- **Required changes**: brief description of what needs updating

### Step F5: Write Feature Discovery Report

Write `discovery.md` to the pipeline workspace.

```markdown
# Discovery: <feature-name>

## Feature Summary
<what's being added to which primary domain>

## Primary Domain: <domain>
- **Spec path**: `documentation/specs/<domain>/`
- **Key entities affected**: <from audit + requirement>
- **Key APIs affected**: <from audit + requirement>

## Secondary Domains

### <Domain 2> — `documentation/specs/<domain2>/`
- **Impact type**: <data model reference / API consumer / UI display / shared component>
- **Affected files**: `<file>:L<line>`
- **Required changes**: <brief description>
- **Severity**: must-change / should-change
- **Existing spec**: <path> — <UC-ID to update>

### <Domain 3> — ...

## No Secondary Impact
<if no secondary domains affected, state: "No cross-domain impact detected. Feature is contained within the primary domain.">

## Recommended Approach
- **Primary domain**: full spec + implementation
- **Secondary domains**: delta updates to existing specs + targeted implementation changes
```

---

## Size Constraints

| File | Target | Hard Cap |
|------|--------|----------|
| `discovery.md` | 150 | 200 |

If more than 6 affected domains, use a summary table instead of per-domain sections.

## Pipeline Handoff

### Inputs (when called by pipeline)
- Change or feature description from pipeline arguments
- `requirement.md` if saved by pipeline
- `audit.md` if audit phase ran (triggers feature mode)

### Outputs
Write `discovery.md` to the pipeline workspace:

**Crosscut mode:**
- `## Affected Domains` — per-domain: files, specs, current behavior, gap
- `## Shared Pattern` — common implementation across domains
- `## Recommended Approach` — strategy for the change

**Feature mode:**
- `## Primary Domain` — the domain being extended
- `## Secondary Domains` — cross-domain impact with severity
- `## Recommended Approach` — primary full + secondary delta

## Next Step

- **Crosscut**: plan phase reads this in delta mode.
- **Feature**: plan phase reads this in hybrid mode — full plan for primary domain + delta for secondary domains. If no secondary domains found, plan proceeds in standard mode.
