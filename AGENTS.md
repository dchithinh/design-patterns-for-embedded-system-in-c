# AGENTS.md

This repository contains chapter-based C examples from *Design Patterns for Embedded Systems in C*, plus supporting notes and UML documentation.

## Scope

These instructions apply to the whole repository.

## Documentation Rules

- Use relative paths in repository documentation.
- Do not use absolute filesystem paths such as `/home/thinhdo/learn/design-patterns-for-embedded-system-in-c/...`.
- Prefer links like `chapter3/02-adapter/doc/adapter-class-diagram.puml` or `./chapter3/02-adapter/doc/adapter-class-diagram.puml`.
- Keep documentation portable so it still works if the repository is moved to another machine or directory.

## UML and Notes

- Prefer small, preview-friendly PlantUML files.
- Do not mix different UML diagram families in one PlantUML file unless the syntax explicitly supports it.
- When documenting a pattern, separate the “pattern view” from the “current code view” if the implementation is not a perfect match for the textbook pattern.
- UML relationship notation should follow standard UML semantics first, especially in learning-oriented diagrams.
- Do not use PlantUML-specific arrow tricks if they make the relationship look non-standard or misleading from a UML perspective.
- Prefer textbook-style relationships such as `*--`, `o--`, `-->`, `..>`, `--|>`, and `..|>` unless there is a strong reason not to.
- When PlantUML lines overlap, prefer layout hints before changing the model itself.
- Useful PlantUML layout tools:
- `left to right direction` or `top to bottom direction`
- `skinparam linetype polyline`
- directional arrows like `-left->`, `-right->`, `-up->`, `-down->`
- `together { ... }` to keep related elements close
- hidden links like `A -[hidden]-> B` to influence placement without adding visible relationships
- Avoid mixing composition/aggregation markers with directional arrowheads just to force layout when a plain UML relationship is clearer.

## Code Style

- Preserve the chapter/example structure unless a change is intentionally improving the pattern implementation.
- Prefer small, local changes over broad refactors unless the user asks for a pattern cleanup.
- When modeling object-oriented ideas in C, be explicit about whether a relationship reflects implementation detail or design intent.

## Verification

- When changing code, compile the affected chapter when practical.
- When changing PlantUML docs, keep names and relationships aligned with the current code or clearly label them as conceptual.
