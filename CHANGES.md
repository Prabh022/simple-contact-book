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

## Update — October 22, 2026

**Feature: delete a contact by name.** The menu had add, view, and search
but no way to remove a contact. Added `deleteContact()` to `contact.c`
(menu option 4; Exit moved to 5): it copies every line except the match
into a temporary file, then replaces `contacts.txt` with it; when the
name is absent it reports "No Contact Found!", removes the temp file,
and leaves the data file untouched. Verified with a scripted run on
seeded data (Alice / Bob / Carol): deleting Bob left Alice and Carol
intact and in order, deleting a nonexistent name changed nothing, and
no temp file was left behind. Builds clean with
`gcc -std=c11 -Wall -Wextra`.
