---
name: audit
description: Retroactively audit existing code. Reverse-engineers specs from code, identifies test gaps, checks architecture compliance against rules. Auto-detects stack. Use when onboarding existing code.
disable-model-invocation: true
argument-hint: [domain-name|all]
allowed-tools: Read, Grep, Glob, Bash, Agent, Write, Edit, AskUserQuestion, TodoWrite
---

# Retroactive Compliance Audit

Audit existing code backwards through the SDLC: code → spec → tests → architecture.

## Inputs

- `$ARGUMENTS` — domain name or `all`
- If no arguments, scan for domains and ask

## Phase 1: Discovery — Trust-but-Verify

Start from existing documentation, validate against code. Only fall back to
full code scan when docs are missing or stale.

### Step 1a: Check for existing docs

1. Detect stack via `shared-references/stack-detection.md`
2. Look for `documentation/specs/<domain>/architecture.md`, `README.md`,
   and any `UC-*.md` files
3. Read `.claude/rules/` files relevant to the detected stack
4. Check `documentation/audits/<domain>-audit-*.md` for the most recent
   dated audit report — note previously identified gaps

### Step 1b: If docs exist → adopt and spot-check

1. Read `architecture.md` and `README.md` — build initial mental model
   (entities, endpoints, layers, patterns, relationships)
2. **Spot-check** key implementation files to verify the model:
   - Entity / model files — do fields and relationships match architecture.md?
   - Service layer — do business rules match the UC descriptions?
   - Controller / routes — do endpoints match the API surface in architecture.md?
4. **If model matches** (≤ minor drift): adopt the documented model and focus
   audit effort on **gaps, drift, and new code** not covered by existing docs.
   Skip Phase 2 (Reverse-Engineer) and go to Phase 2b (Drift Report).
5. **If model doesn't match** (missing entities, wrong relationships,
   undocumented endpoints): fall through to Step 1c.

### Step 1c: If docs missing or stale → full code scan

1. Find all files belonging to the domain (using stack profile layer mapping)
2. Build inventory: handlers, services, models, schemas, tests
3. Read all implementation files — proceed to Phase 2 (Reverse-Engineer)

## Phase 2: Reverse-Engineer Spec (only when docs missing or stale)

Read all implementation files and extract what the system does.

Create `documentation/specs/<domain>/<feature>/`:
- **README.md** — goal, concepts, UC index, security, scope
- **architecture.md** — data model, endpoints, components, decisions (write at domain level: `documentation/specs/<domain>/architecture.md`)
- **UC-N-\<name\>.md** — ACs from actual code behavior (mark `[IMPLEMENTED]`)
- **implementation.md** — files table, test coverage, "reverse-engineered" note (written to pipeline workspace)

## Phase 2b: Drift Report (when docs exist but have minor drift)

Compare adopted model against spot-check findings. Produce a drift report
listing:
- New code not covered by existing specs (new endpoints, fields, behaviors)
- Spec claims that no longer match code (renamed fields, removed endpoints)
- Architecture.md sections that need updating

Do NOT overwrite existing specs — append drift findings to the audit output.

## Phase 3: Test Coverage Analysis

Map every AC to existing tests:
```
| AC | Description | Unit | Integration | Component | Status |
```

Prioritize gaps: CRITICAL (security logic untested) → HIGH (core business) → MEDIUM → LOW

## Phase 4: Architecture Compliance

Read all `.claude/rules/` files applicable to the stack. Check:
- Structural: required files exist, thin handlers, logic in services
- Security: auth on endpoints, validation on mutations, no secrets
- API: standard envelopes, pagination, correct status codes
- Data: UUIDs, timestamps, soft deletes, indexes

## Phase 5: Generate Report

Save to `documentation/audits/<domain>-audit-YYYY-MM-DD.md`:

```markdown
# Compliance Audit: {Domain}
## Summary
| Metric | Value |
| Overall Compliance | N% |
| Spec Status | Generated / Exists / Drift |
| Test Coverage | N% |
| Architecture Score | N/N |
| Critical Issues | N |
```

## Special: `all` Mode

List all domains → run Phase 1 for each → summary matrix → deep-dive worst domain first → ask to continue.

## Size Constraints

Claude Code best practice: **target 200 lines per file**. Read `shared-references/documentation-size-limits.md` for full policy.

| File | Target | Hard Cap | If Exceeding |
|------|--------|----------|-------------|
| Audit report | 200 | 300 | Split: `*-audit-summary.md` (metrics + critical) + `*-audit-detail.md` (findings) |
| `architecture.md` (reverse-engineered) | 200 | 300 | Split: `architecture.md` + `api-contracts.md` |
| `UC-N-*.md` | 100 | 150 | Split use case into sub-use-cases |

When reverse-engineering specs, use summary tables for data models — not full ORM entity definitions.

## Pipeline Handoff

### Inputs (when called by pipeline)
- Domain name or `all` from pipeline arguments

### Outputs
Write `audit.md` to the pipeline workspace (`documentation/tmp/pipeline/<slug>/`):
- `## Domain Summary` — what the domain does, key entities
- `## Existing Architecture` — layers present, patterns used, stack
- `## Data Model` — entities with fields, relationships, constraints
- `## API Surface` — endpoints with methods, auth, validation status
- `## Patterns & Conventions` — coding patterns observed (naming, error handling, etc.)
- `## Dependencies` — cross-domain imports, external packages
- `## Gaps & Risks` — missing tests, security issues, architectural violations

This file is inter-phase communication only — durable architecture lives in `documentation/specs/<domain>/architecture.md`. Do NOT write `audit.md` into the spec folder.

Also writes full audit report to `documentation/audits/<domain>-audit-YYYY-MM-DD.md` (durable historical record).

## Next Step

Audit complete. Run `/implement` to fix issues, `/test-plan` to fill coverage gaps, or `/pipeline audit <domain>` for the full audit → review flow.
