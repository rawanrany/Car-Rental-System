# Car Rental System
> A console-based car rental management system built in C++ as a first-year university project.

Overview

A fully functional command-line application that simulates a real-world car rental service. Users can register, log in, browse available cars, rent them, and cancel reservations. all backed by persistent file storage so data survives between sessions.

Features

  | Feature |                                    | Description |
|  Sign Up / Login            | Secure registration with 14-digit National ID validation |
|  Search Cars                | Search by brand, model, or color with partial matching |
|  Rent a Car                 | Select and rent any available car |
|  Cancel Reservation         | Release a previously rented car |
|  Payment                    | Supports Cash and Visa card payment flows |
|  Add / Update / Remove Cars | Full car inventory management |
|  List & Check Cars          | View all cars or check a specific car's availability |
|  Persistent Storage         | Data saved to and loaded from `.txt` files between sessions |


Tech Stack

- **Language:** C++
- **Concepts used:** Structs, arrays, functions, file I/O (`fstream`), input validation



Project Structure

```
CarRentalSystem/
│
├── main.cpp          # All source code
├── CARS.txt          # Auto-generated: persisted car data
└── CUSTOMERS.txt     # Auto-generated: persisted customer data
```
### Prerequisites
- A C++ compiler 

## Sample Interaction

```
==== Car Rental System ====
1.  Sign Up
2.  Login
3.  Search Car
...
Choice: 1

Enter your National ID (14 digits only): 12345678901234
Enter your name: Rawan
Enter your mobile: 01012345678
Enter your address: Cairo, Egypt
Enter your job title: Student
Account created successfully!
```

---

## Team

Built collaboratively as a university group project:

| Name | Contribution |
|---|---|
| Yousef Bebars | Structs design, payment system, rent & cancel reservation |
| Yousef Fouad  | File handling (save/load), search car, main function |
| Rawan         | Input validation, sign up flow |
| Haneen        | Login system |
| Ahmad         | Add car functionality |
| Amira         | Update & remove car |
| Amany         | Show, list & check car |


##  What I Learned

- Designing and using **structs** to model real-world entities
- Managing data with **arrays** and index-based operations
- **Input validation** and defensive programming in C++
- Collaborating on a shared codebase as a team


##  Future Improvements

- [ ] Add rental duration and pricing calculation
- [ ] Implement proper authentication (password hashing)
- [ ] Migrate from flat files to a proper database
- [ ] Build a GUI with Qt or a web front-end
- [ ] Add admin vs. customer role separation


*First-year CS project — [Ain Shams University], 2026*
