1. Passing a normal variable

If you pass a variable like int a = 5; into a function without pointers, the function only gets a copy. Changes inside the function won’t affect the original variable outside.

Example:

```
void modify(int x) {
    x = 10;
}
int main() {
    int a = 5;
    modify(a);
    cout << a << endl; // still 5, because only a copy was changed
}
```

2. Passing a pointer (\*)

If you want the function to change the original variable’s value, you pass a pointer to it.

```
void modify(int* p) {
    *p = 10; //  DEREFERENCE operator (getting the value)
}

int main() {
    int a = 5;
    modify(&a); // give the address of a
    cout << a << endl; // now it's 10
}
```

Here:

p is a pointer to a.

\*p means “go to that address and change the value”.
Result: the value of a is updated.

3. Passing a pointer to a pointer (\*\*)

Now imagine you don’t just want to change the value at an address, but you want to change the pointer itself (where it points).
That’s when you pass a pointer to a pointer.

Example:

```
void safe_free(int\** p) {
    free(*p); // free memory that *p points to
    *p = 0; // set the pointer to NULL (0), so it’s safe
}

int main() {
    int* p = (int*)malloc(sizeof(int));
    \*p = 42;
    safe_free(&p); // pass address of p
    cout << p << endl; // prints 0 (NULL) -> p is changed itself
}
```

Here:

p is a pointer to memory.

&p is a pointer to that pointer.

Inside safe_free, \*p refers to the original pointer in main.

Setting \*p = 0 makes p in main become NULL.

Result: the pointer itself was changed.

In conclusion:
Use \* (single pointer) when you want to CHANGE the value stored in a variable. (Second example)
Use \*\* (double pointer) when you want to change the pointer itself (e.g., make it point somewhere else, or set it to NULL after freeing). (Third example)
