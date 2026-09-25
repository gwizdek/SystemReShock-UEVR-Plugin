# Documentation Rules

Two rules. Both apply to every documentation file.

> **1. Write in plain English.** Use simple, common words and short sentences.
> Readers are not all native English speakers.
>
> **2. Describe the current state.** Documentation describes the app and its
> source code as they are now. It is not a changelog, and it is not a record of
> what a previous version of the document claimed. If a statement is no longer
> true, delete it — don't just add a note next to it.

Applies to everything under `documentation/`, every `README.md`, the spec
folders, `CLAUDE.md`, and the files in `.claude/` itself.

## Write in plain English

The people who read these files work in English but do not all speak it as a
first language. Rare words, idioms, and long clauses make a document slower to
read and easier to misread — and a spec that is misread is worse than one that
is missing, because the reader acts on it.

Prefer the common word. Keep sentences short — one idea each. Split a sentence
that needs two commas to hold itself together.

The test is simple: **is there a more common word that means the same thing?**
If yes, use it. Write "where it came from" rather than "provenance", "no longer
applies" rather than "moot", "use" rather than "leverage".

**This is not a rule against precise technical words.** Names from the code and
the domain stay exactly as they are — `hasClientAccess`, `entity_type`,
`cursor`, `CHECK constraint`, `migration`. A reader who does not know those
words needs to learn them; that is what the document is for. It is the prose
*around* them that must be plain.

Two habits that help more than word choice:

- **Say the thing, then explain it.** Put the conclusion in the first sentence
  of the paragraph, not the last.
- **Avoid metaphors.** "The trail goes cold", "paying down the coupling", "this
  bites you later" all translate badly. Say what actually happens.

## Why the current-state rule exists

Git already stores history, perfectly, forever. A doc that also carries it pays
twice: once in the reading, and once when the retraction itself goes stale and
someone has to work out whether the correction or the thing it corrected is the
current truth.

The failure mode is specific and recurring — a doc gets fixed, and the fix is
written as a *narrative about the fix* rather than as the corrected fact:

```markdown
<!-- NO — the reader learns what a file they never read used to say -->
> **This section previously stated two things that were never true.** It claimed
> `team_role` was written for `team_roles` mutations — it never was. And it
> claimed `change_log` has no CHECK constraint — it has had one since V1.

<!-- YES — the reader learns what is true -->
**`team_roles` rows themselves are not audited.** `TeamRoleService.update()`
calls no `recordChange`, so role renames and deactivations leave no trail.
```

Both are the same correction. Only the second is useful to someone reading the
file for the first time — which is everyone, eventually.

## What to delete outright

- "Previously…", "used to…", "was renamed from…", "no longer says…"
- Retraction narratives — the correct fact, stated plainly, *is* the correction
- Status ledgers for work that finished (`✅ Done` rows whose subject is gone)
- Descriptions of deleted domains, tables, endpoints, or packages stated in the
  present tense

## What the current-state rule does not mean

- **Dead code still in the tree is the one real exception.** Where source code
  survives the feature it belonged to, the doc **must** say where it came from.
  Otherwise the next reader cannot tell dead code from odd-looking code that
  still does a job. Knowing where it came from is the only way to tell them
  apart, and it is what makes the cleanup possible.

  ```markdown
  <!-- Correct: the history IS the removal instruction -->
  Those migrations also drop-and-recreate a Postgres enum named
  `"ChangeEntityType"`. It is leftover — no column uses it; it survives from
  the legacy Node backend, where it *was* the column type. Nothing exercises
  it. Removing it is a fair change to propose.
  ```

  All three conditions must hold: the code, column, or config **is still
  there**; the reader cannot safely judge it without knowing where it came
  from; and there is a way out — an issue, a checkbox, a named follow-up.
  When the code goes, the paragraph goes with it, in the same commit.
- **A past bug cited as the reason a guard exists is current-state.** "The
  dropdown once offered `role_name` and returned an empty feed" is what stops
  someone deleting the regression test that pins it. Keep it, next to the thing
  it justifies.
- **Migration files are append-only history by design.** Don't rewrite a `V*.sql`
  comment to match today; migrations record what happened at their point in time.
- **A doc whose subject *is* a past decision** — a PRD, an ADR, a completed
  paydown plan — may stay historical, but must say so in its first lines, and
  must not be cited elsewhere as a description of current behaviour. If it lists
  work items, mark the ones that no longer apply, so they don't read as open.
- **Changelog sections are fine where they are labelled as such.** A spec's
  `## Changelog` is the one right place for "this used to say X" — keep it
  there and out of the prose.

## How to apply these rules

1. **When you correct a doc, write the corrected fact — not the correction.**
   Ask: does a first-time reader need this sentence? If it only makes sense to
   someone who read the previous version, cut it.
2. **When you delete code, grep the docs for it in the same change.** A deleted
   package named in the present tense in `CLAUDE.md` or a `.claude/rules/` file
   is worse than no documentation — those load automatically and actively
   misdirect.
3. **When you find leftover code, document it once, next to that code, with a
   way out.** Not in three places, and not without an issue link.
4. **Read your paragraph back and cut every word that is not needed.** If a
   sentence needs two commas to hold together, split it in two.
5. **`/review` and `/sync-docs` flag present-tense claims about deleted code as
   BLOCKERs.** They flag rare words with a common alternative, and text that
   only explains what a doc used to say, as WARNINGs.
