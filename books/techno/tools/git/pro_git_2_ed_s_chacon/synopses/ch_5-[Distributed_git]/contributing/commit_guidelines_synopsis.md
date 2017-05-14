Commit guidelines
=================

Base material
-------------

- do not submit any whitespace errors:
  to identify possible whitespace errors (trail spaces) in your
  sources files before staging your files
  ```   
  $ git diff --check --color  
  ```
- make each commit in a logically separate changeset;
- Make correct messages:
  your messages should start with a single line
  that's no more about 50 characters and that describes 
  the changeset concisely, followed by a blank line, followed
  by a more detailed explanation.
  (in the body of the messages you can include your motivation
   for the change and constrast its implementation 
   with previous behaviour).
  (use the imperative present tense
   instead of "I added test for" use "Add tests for").
