# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

According to Merriam-Webster's Medical Dictionary, pneumonoultramicroscopicsilicovolcanoconiosis is a pneumoconiosis caused by inhalation of very fine silicate or quartz dust.


## According to its man page, what does `getrusage` do?

returns resource usage measures for RUSAGE_SELF, RUSAGE_CHILDREN, and/or RUSAGE_THREAD

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

We don't want to evaluate on the entire struct but rather on the value of struct members, so we need to pass by reference for this reason.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Within 'main', the for loop will iterate through every character in the file until end of file is reached. The incrementor is
implemented by getting the next character until the file is at an end.
We'll keep track of the length of each (potential) word with the index variable.
Each character is checked in the if/else if/else if/else conditional. If it is alphabetical or an apostrophe, we add the character
to the new or existing word. Within this if block, if the potential word is longer than 45 characters, we keep iterating through the
file ("consume remainder of alphabetical string") in a bodyless while loop and then reset the index to 0. If the potential word
contains any numbers, which we detect with isdigit(c), we want to ignore the character array and not consider it to be neither a
word nor misspelled, so again we just consume the rest of the characters in the alphanumeric string, and again reset the potential
word length to zero. If we've gotten to this point, and the potential word contains at least one character but the character we're
reading is not alphanumeric or an apostrophe (space, punctuation), then we must have found a whole word.
We add a null character to terminate the word, increment the word counter, and only now do we check the word's spelling, keeping
track of the resource usage information before and afterward, then calculating the time duration. Finally, we print the word if it
is misspelled and increment its counter if needed, then reset the index to get ready for the next word.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

If we used fscanf, one reason we may have a problem would be if a string longer than the LENGTH limit is encountered.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Using const char *word and const char *dictionary prevents the pointers from writing to the pointed data.
