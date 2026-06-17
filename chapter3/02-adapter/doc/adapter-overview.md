# Adapter UML Files

Use these PlantUML files for `chapter3/02-adapter`:

- [adapter-class-diagram.puml](adapter-class-diagram.puml)
- [adapter-sequence-diagram.puml](adapter-sequence-diagram.puml)

What each file shows:

- `adapter-class-diagram.puml`: the target interface, client classes, factory, adapters, and vendor proxies
- `adapter-sequence-diagram.puml`: how `main`, `GasDisplay`, and `GasMixer` request `iO2Sensor` objects from the factory and call through adapters into the vendor-specific sensor APIs
