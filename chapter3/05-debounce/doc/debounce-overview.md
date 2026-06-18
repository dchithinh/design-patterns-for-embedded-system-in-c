# Debounce UML Files

Use these PlantUML files for `chapter3/05-debounce`:

- [debounce-class-diagram.puml](debounce-class-diagram.puml)
- [debounce-sequence-diagram.puml](debounce-sequence-diagram.puml)

What each file shows:

- `debounce-class-diagram.puml`: the debouncer (`ButtonDriver`), input device (`Button`), delay source (`Timer`), and controlled output (`MicrowaveEmitter`)
- `debounce-sequence-diagram.puml`: the debounce flow of wait, re-check, validate the state change, and then toggle output only for a valid release event
