---
name: commit-plan
description: Plan and execute granular, revertible commits for current changes. Groups by layer and dependency order, adapts to the detected stack. Use after /review passes.
disable-model-invocation: true
allowed-tools: Read, Write, Edit, Bash, Grep, Glob, AskUserQuestion, TodoWrite
---

# Granular Commit Planner

Plan and execute atomic, revertible commits. Each commit leaves the codebase valid.

## Process

### Step 0: Verify .gitignore

1. Read `shared-references/gitignore-patterns.md` for required patterns
2. Read `shared-references/stack-detection.md` — detect active stack(s)
3. Read `.gitignore` from project root (or note if missing)
4. Compare against required patterns for the detected stack
5. If patterns are missing: add them and include `.gitignore` in the first commit
6. If `.gitignore` doesn't exist: create it with "Always" + detected stack patterns

### Step 1: Analyze Changes

```bash
git status
git diff --stat
git diff --cached --stat
git log --oneline -10
```

List all changed files, grouped by domain and layer.

### Step 2: Group into Atomic Commits

Priority order:
1. **Database migrations** — always separate (schema + migration files)
2. **Seed data** — separate from migrations
3. **Backend domain** — service + tests, then API layer (controller/routes/schema)
4. **Frontend feature** — components + pages + hooks
5. **Tests** — with implementation or separate if large
6. **Config / docs** — last

### Step 3: Order for Safe Rollback

Each commit must leave the system in a working state:
```
1. DB migration (schema exists before code references it)
2. Backend service (logic exists before routes expose it)
3. Backend routes (API available before frontend calls it)
4. Frontend (UI calls working API)
5. Tests (verify everything)
6. Config/docs (non-functional)
```

### Step 4: Draft Commit Messages

```
<type>(<scope>): <description>

<WHY body — not WHAT>

Co-Authored-By: Claude <model> <noreply@anthropic.com>
```

Types: `feat`, `fix`, `refactor`, `test`, `chore`, `docs`, `ci`, `perf`
- Subject under 72 chars, imperative mood
- Reference ACs if applicable

### Step 5: Present Plan

Show the full commit plan with files per commit. Ask for approval.

### Step 6: Execute

For each commit:
1. `git add <specific files>` — never `git add .`
2. Create commit with planned message
3. Verify with `git log --oneline -1`

### Step 7: Summary

```bash
git log --oneline -N
```
Report: "Created N commits. Each independently revertible."

## Pipeline Handoff

### Inputs (when called by pipeline)
- Code changes (git diff)
- `review.md` if review phase ran — check verdict is PASS
- `smoke.md` if smoke phase ran — check verdict is PASS

### Outputs
- Git commits (the primary artifact)
- Returns: commit count, commit hashes, summary

## Next Step

Commits created. Run `/golive` before deploying to production.
