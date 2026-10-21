# Simple Contact Book (C)

A small command-line contact manager written in C. Contacts (name and phone
number) are stored in a plain text file, one contact per line, so they
persist between runs.

## Features

- Add a contact (name + phone number)
- View all saved contacts
- Search for a contact by exact name
- Persistent storage in `contacts.txt` (created automatically when you add
  your first contact)

## Build

Requires a C compiler (developed with gcc):

```
gcc -std=c11 -Wall -Wextra main.c contact.c -o contact_book
```

## Run

```
./contact_book
```

Then use the on-screen menu:

```
1. Add Contact
2. View all Contacts
3. Search Contact by Name
4. Exit
```

## Sample output (trimmed from an actual run)

```
--- Contact List ---
Name: Test Person, Phone: 5551234567

Contact found: Test Person - 5551234567
```

## Project structure

```
main.c       Menu and program entry point
contact.c    Add, view, and search logic
contact.h    Contact struct and function declarations
contacts.txt Contact data (name,phone per line) — ships with the sample
             contacts from the original repo; replace with your own
```

## Notes

- This project was extracted from a C projects collection repo; the source
  code is unchanged (see CHANGES.md).
- Search matches the full name exactly (case-sensitive).
