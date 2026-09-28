# Git Workflow Rules

> These rules apply to all commits, branches, and PRs.

## Branch Naming

```
<type>/<short-description>
```

Types: `feature/`, `fix/`, `refactor/`, `chore/`, `hotfix/`

Examples: `feature/user-notifications`, `fix/login-race-condition`, `refactor/auth-service`

## Commit Messages

Use conventional commits format:

```
<type>(<scope>): <description>

<optional body explaining WHY>
```

Commits carry no co-author or tool attribution line. The configured git user is the sole author.

**Types:** `feat`, `fix`, `refactor`, `test`, `chore`, `docs`, `ci`, `perf`

**Rules:**
- Subject line under 72 characters
- Imperative mood: "add", not "added" or "adds"
- Body explains WHY, not WHAT (the diff shows what)
- Reference AC numbers if applicable

## Commit Hygiene

- Each commit should be independently revertible without breaking the system
- Never use `git add -A` or `git add .` — stage specific files
- Never force-push to shared branches
- Never use `--no-verify` to skip hooks
- Database migrations are always a separate commit

## Pull Requests

- Keep PRs focused: one feature or fix per PR
- PR title follows commit convention: `feat(domain): description`
- Description includes: summary, test plan, link to spec if applicable
- Request review before merging
- Squash-merge for clean history, or merge commits for complex features
