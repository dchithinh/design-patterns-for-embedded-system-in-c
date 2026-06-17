# Chapter 3 Hardware Patterns Memorize Note

This note is for fast review of the hardware-related patterns in Chapter 3.

Use it to remember:

- what the pattern is
- why we use it
- main advantages
- main tradeoff
- what to memorize for exams, interviews, or reading code

## 1. What You Should Memorize First

For every pattern, try to memorize these 5 things:

1. `Intent`
2. `Problem it solves`
3. `Main structure / roles`
4. `Advantages`
5. `Cost / tradeoff`

If you can remember only one sentence per pattern, remember the `intent`.

## 2. Quick Pattern Map

| Pattern | Very short memory sentence |
|---|---|
| Hardware Proxy | Wrap hardware access in a software object |
| Hardware Adapter | Convert one hardware API into the API the app wants |
| Mediator / Intermediary | Put one coordinator in the middle of many interacting devices |
| Observer | Notify interested clients when sensor data changes |
| Debouncing | Filter noisy or bouncing hardware input |
| Interrupt | React quickly when hardware signals an urgent event |
| Polling | Check hardware regularly for new state or data |

## 3. Hardware Proxy Pattern

### What

Encapsulate direct hardware access inside a dedicated software object.

### Why

Application code should not be full of raw register access, bit twiddling, and hardware-specific details.

### Main idea

- client talks to proxy
- proxy talks to hardware
- proxy hides low-level details

### Advantages

- isolates hardware-specific code
- improves readability
- makes code easier to test or replace
- reduces hardware details leaking into business logic

### Tradeoff

- adds another layer
- may add a little code overhead

### What to memorize

- `Intent`: hide raw hardware behind a class/struct
- `Use when`: direct hardware access is messy or repeated
- `Key benefit`: separation of concerns
- `Key risk`: too-thin proxy may not give much value

### Memory phrase

`Proxy = safe software face for ugly hardware details`

## 4. Hardware Adapter Pattern

### What

Convert a hardware/vendor API into the interface your application expects.

### Why

Different hardware devices may provide different function names, units, or APIs, but the application wants one stable interface.

### Main idea

- client depends on target interface
- adapter implements that interface
- adapter translates to vendor-specific API

### Advantages

- lets old and new hardware fit the same application code
- reduces client coupling to vendor-specific APIs
- makes hardware replacement easier

### Tradeoff

- adds translation code
- can hide conversion mistakes if not documented clearly

### What to memorize

- `Intent`: convert one interface into another
- `Use when`: provided hardware API does not match required app API
- `Key benefit`: portability and replaceability
- `Key risk`: client may still become coupled to concrete adapters if pattern is used badly

### Memory phrase

`Adapter = translator between the app and a mismatched hardware API`

## 5. Mediator / Intermediary Pattern

### What

Use one central object to coordinate communication among several devices/components.

### Why

Without it, each part may talk directly to many other parts, creating tangled dependencies.

### Main idea

- client talks to mediator/intermediary
- mediator coordinates all device actions
- devices do not need to manage the whole collaboration themselves

### Advantages

- reduces many-to-many coupling
- centralizes coordination logic
- makes complex workflows easier to understand

### Tradeoff

- mediator can become too large or too smart
- may become a “god object” if overused

### What to memorize

- `Intent`: centralize interaction logic
- `Use when`: many components must cooperate in a structured sequence
- `Key benefit`: less coupling between colleague objects
- `Key risk`: mediator becomes bloated

### Memory phrase

`Mediator = traffic controller for cooperating devices`

## 6. Observer Pattern

### What

One subject notifies many interested observers when data changes or when an event occurs.

### Why

Sensor data often needs to go to many clients like displays, analyzers, alarms, or loggers.

### Main idea

- subject keeps subscriber list
- observers subscribe/unsubscribe
- subject notifies all observers

### Advantages

- supports dynamic add/remove of clients
- one producer can feed many consumers
- good for data distribution

### Tradeoff

- update flow can become harder to trace
- many subscribers can affect timing/performance

### What to memorize

- `Intent`: publish updates to interested clients
- `Use when`: one source feeds many clients
- `Key benefit`: scalable event/data distribution
- `Key risk`: hidden coupling through callbacks

### Memory phrase

`Observer = one source, many listeners`

## 7. Debouncing Pattern

### What

Filter unstable hardware input so the system reacts only to a real, stable signal.

### Why

Mechanical switches and some signals bounce, creating many false transitions.

### Main idea

- input changes
- wait/check stability
- accept only stable value

### Advantages

- prevents false triggers
- improves reliability of input handling
- protects logic from noisy transitions

### Tradeoff

- adds delay before input is accepted
- needs timing logic

### What to memorize

- `Intent`: reject unstable/noisy transitions
- `Use when`: buttons, switches, noisy digital input
- `Key benefit`: reliability
- `Key risk`: delay/latency

### Memory phrase

`Debounce = do not trust the first noisy edge`

## 8. Interrupt Pattern

### What

Let hardware immediately signal software when urgent service is needed.

### Why

Some events are too urgent or too wasteful to handle by polling.

### Main idea

- hardware event occurs
- interrupt fires
- interrupt handler runs quickly

### Advantages

- fast response
- efficient for urgent or infrequent events
- avoids constant polling

### Tradeoff

- concurrency complexity
- race conditions
- must keep handler short and safe

### What to memorize

- `Intent`: handle urgent hardware events quickly
- `Use when`: low-latency reaction matters
- `Key benefit`: responsiveness
- `Key risk`: concurrency bugs and complexity

### Memory phrase

`Interrupt = hardware says “handle me now”`

## 9. Polling Pattern

### What

Software periodically checks a device for status or data.

### Why

Sometimes hardware does not provide interrupts, or regular scheduled checking is simpler and good enough.

### Main idea

- loop/timer runs
- software asks device for new state
- process result if available

### Advantages

- simple control flow
- predictable scheduling
- easy to reason about in many embedded systems

### Tradeoff

- can waste CPU
- slower response than interrupts if poll period is long
- too-fast polling wastes resources

### What to memorize

- `Intent`: periodically check for new device state
- `Use when`: simple periodic sampling is enough
- `Key benefit`: simplicity and predictability
- `Key risk`: latency or wasted cycles

### Memory phrase

`Polling = keep asking the device if anything changed`

## 10. Best “Why This Pattern?” Summary

This is the shortest useful comparison:

| Pattern | Why use it? |
|---|---|
| Hardware Proxy | hide ugly low-level hardware details |
| Hardware Adapter | make mismatched hardware fit your API |
| Mediator | reduce tangled device-to-device communication |
| Observer | distribute one source of data to many clients |
| Debouncing | reject noisy or unstable input |
| Interrupt | react fast to urgent hardware events |
| Polling | use simple periodic checking |

## 11. What Else You Should Memorize

Beyond `what` and `why`, these are worth memorizing:

### A. Trigger question

For each pattern, ask:

- `What pain in the code makes me choose this pattern?`

Examples:

- too much register logic -> `Hardware Proxy`
- vendor API mismatch -> `Hardware Adapter`
- too many objects calling each other -> `Mediator`
- one sensor, many consumers -> `Observer`
- noisy button input -> `Debouncing`
- urgent asynchronous event -> `Interrupt`
- periodic status checking -> `Polling`

### B. Pattern roles

Try to remember the important roles:

- Proxy: client, proxy, hardware
- Adapter: client, target interface, adapter, adaptee
- Mediator: client, mediator, colleague devices
- Observer: subject, observer, notification link/callback
- Interrupt: interrupt source, vector/handler, application logic
- Polling: poller, device, client/processor

### C. Main tradeoff

Patterns are not free.

Always ask:

- what complexity does this pattern add?

That helps you choose patterns, not just memorize names.

## 12. Good Exam / Interview Answers

If someone asks “What should I say about a pattern?”, a strong short answer is:

### Hardware Proxy

`It encapsulates direct hardware access so the rest of the software does not depend on raw registers and bit manipulation.`

### Hardware Adapter

`It converts a vendor-specific hardware API into the interface the application expects.`

### Mediator

`It centralizes coordination among multiple components so they do not all depend on each other directly.`

### Observer

`It lets one data source notify many interested clients dynamically.`

### Debouncing

`It filters unstable input transitions so the system responds only to a real stable signal.`

### Interrupt

`It provides fast reaction to urgent hardware events using an interrupt handler.`

### Polling

`It periodically checks the device state when simple scheduled sampling is acceptable.`

## 13. Best Study Order

If you want to memorize them efficiently:

1. Hardware Proxy
2. Hardware Adapter
3. Mediator
4. Observer
5. Debouncing
6. Interrupt
7. Polling

Why this order:

- first learn structure-hiding patterns
- then communication patterns
- then hardware event/input patterns

## 14. Final Minimal Memory Set

If you only memorize one line each:

- `Hardware Proxy`: wrap hardware access
- `Hardware Adapter`: translate hardware API
- `Mediator`: central coordinator
- `Observer`: one source, many listeners
- `Debouncing`: filter noisy input
- `Interrupt`: urgent event handling
- `Polling`: periodic checking
