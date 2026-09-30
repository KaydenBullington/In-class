<div align="right"><strong>Kayden Bullington</strong></div>

# W05 HW

**CS 2143 · Object-Oriented Programming — Inheritance**

1. **Q1 — Fill in the blanks**
   - (1) base · derived
   - (2) is
   - (3) inherits / derives

2. **Q2** — Circle all four: `make`, `model`, `topSpeed`, and `describe()`. All of them become part of every `Car` object through inheritance, regardless of access level. Access level only controls who can reach them, not whether they exist.

3. **Q3 — Access control table**

   | Specifier   | Same Class | Derived Class | Outside (`main()`) |
   |-------------|:----------:|:-------------:|:------------------:|
   | `private`   | Y | N | N |
   | `protected` | Y | Y | N |
   | `public`    | Y | Y | Y |

   Line X does **not** compile. `make` has no access label in `Vehicle`, so it defaults to `private`, and private members are never visible to a derived class. One-word fix: change `make` to `protected`.

4. **Q4** — Prints `A B C`. Construction always runs base-first down the chain. Destructors run in the opposite order: `~C ~B ~A`.

5. **Q5 — Motorcycle constructor**

   ```cpp
   Motorcycle::Motorcycle(string mk, string mo, int spd, bool sidecar)
       : Vehicle(mk, mo, spd), hasSidecar(sidecar) {}
   ```

6. **Q6** — `v.describe();` prints `"A vehicle."` and `c.describe();` prints `"A car."`. To call the base version from inside the override: `Vehicle::describe();`

7. **Q7 — Overloaded, overridden, or neither?**
   - (1) `Car(string)` / `Car(string,int)` — **OVERLOADED** (same name, different parameter lists, same class)
   - (2) `Vehicle::describe()` / `Car::describe()` — **OVERRIDDEN** (identical signature, redefined in the derived class)
   - (3) `Vehicle::describe()` / `Car::honk()` — **NEITHER** (different names, unrelated functions)
   - (4) `operator+(Fraction)` / `operator+(int)` — **OVERLOADED**

8. **Q8 — Motorcycle class**

   ```cpp
   class Motorcycle : public Vehicle {
       bool hasSidecar;
   public:
       Motorcycle(string mk, string mo, int spd, bool sidecar)
           : Vehicle(mk, mo, spd), hasSidecar(sidecar) {}

       void describe() {
           Vehicle::describe();
           cout << (hasSidecar ? "Has a sidecar.\n" : "No sidecar.\n");
       }
   };
   ```

9. **Find the Error — Case A** — `class Car : Vehicle` with no keyword defaults to **private** inheritance, which turns every inherited public member of `Vehicle` (including `describe()`) into a private member of `Car`. Line X (`c.describe();` in `main()`) does **not** compile. Fix: `class Car : public Vehicle`.

10. **Find the Error — Case B** — Does **not** compile. `Car(int doors)` never chains to a `Vehicle` constructor, so the compiler tries to call `Vehicle()` implicitly, but `Vehicle` only has `Vehicle(string mk)` and no default constructor. Fix:

    ```cpp
    Car(string mk, int doors) : Vehicle(mk), numDoors(doors) {}
    ```

11. **Find the Error — Case C** — Does **not** compile. `protected` only widens access for derived classes, not outside code. `main()` isn't a member of `Vehicle` or a derived class, so `v.make` is just as unreachable as if it were `private`.

12. **A Peek Ahead: Polymorphism** — No graded response. Marking `Vehicle::describe()` as `virtual` would make `v->describe();` print `"A car."` instead of `"A vehicle."`.
