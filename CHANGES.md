# Changes made during standalone extraction (October 2026)

Extracted from the `c-projects-portfolio` collection repo. Only the project's
real source files and its sample `contacts.txt` were carried over — Visual
Studio files (`.sln`, `.vcxproj`, Debug folders, `.ilk`, `.obj.enc`) were
left behind.

**No code changes were needed.** The original code compiles cleanly with
`gcc -std=c11 -Wall -Wextra` (zero errors, zero warnings), and a scripted
test run verified all flows: add a contact, view all contacts, search with a
matching name (found), search with a non-matching name (correctly reports
not found), and exit.

One accuracy note: the original repo's readme claimed contacts include an
email field. The code stores only name and phone number, so this standalone
README describes only what the code actually does.
