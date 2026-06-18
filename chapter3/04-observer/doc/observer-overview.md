# Observer UML Files

Use these PlantUML files for `chapter3/04-observer`:

- [observer-class-diagram.puml](observer-class-diagram.puml)
- [observer-sequence-diagram.puml](observer-sequence-diagram.puml)

What each file shows:

- `observer-class-diagram.puml`: the subject (`GasSensor`), payload (`GasData`), notification handle, callback role, and implemented observer (`DisplayClient`)
- `observer-sequence-diagram.puml`: the intended flow of subscription, new gas data arrival, notification, and observer update

Notes:

- `GasMixerClient` and `SatetyMonitorClient` files are currently empty in this chapter, so they are not included as concrete observers in the diagrams.
- The current code has rough edges, so the diagrams model the intended observer structure while staying aligned with the implemented class names.
