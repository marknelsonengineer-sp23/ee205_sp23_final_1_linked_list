
<img src=".doxygen/images/logo_Final.png" style="width:250px; float: right; margin: 0px 10px 10px 10px;" alt="Final Exam"/>

The project's home page is hosted by GitHub at:  https://github.com/marknelsonengineer-sp23/sre_lab4_memscan

The source code is documented at:  https://www2.hawaii.edu/~marknels/sre/memscan  (hosted by The University of Hawaiʻi at Mānoa)

Linked List
===========

Remove the `n`-th node _from the end_ of a linked list and return the node that 
was removed.

For example, given: `Ali->Bea->Cal->Dan->Edo->nullptr` and `n=2`.  After 
removing the second node from the end, the linked list becomes 
`Ali->Bea->Cal->Edo->nullptr` and you return `Dan->nullptr`.

#### Special Cases
  - If the list is empty, do nothing and return `nullptr`.
  - If `n` is <= 0, do nothing and return `nullptr`.
  - If `n` is greater than the size of the list, remove the **first node** from
    the list.
  - `main()` doesn't really do anything, but it's there if you want to use it.

#### Rubric
  - The only place you can write code is in `List.cpp`, specifically, 
    `doSomethingInteresting()`.  You can add your own methods, but you can not 
    modify any existing code.
  - The program is functional and passes all of my tests.
  - The program must compile without any warnings (-5% for the first warning.
    -2% for up to 10 additional warnings).
  - Don't worry about clang-tidy problems reported by CLion.
  - I'll deduct up to 10% for variable names that are not descriptive -- write
    your code to tell your story.  `i`, `j` and `k` for iterators are acceptable.
