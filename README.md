# Piscine Starfleet: Technical Interview Bootcamp
This two-week bootcamp teaches the fundementals of computational thinking and prepares participant for a functional role at an organisation.<br><br>In essence, the content covered is equivalent to two years of Computer Science modules at any major university. 

## Topics
Over the course of 8 days of assignments, the following topics were covered:
- Big O Notation
- Searching Algorithms
- Sorting Algorithms
- Bit Manipulation
- Recursive Algorithms
- Data structures (Arrays, Linked Lists, Binary Trees, Graphs)

## Notes
For reference, time complexity usually refers to the amount of time a program (i.e. a set of functions) take to run. This is computed based on how data structures, like arrays, are traversed and modified. For example:
```
A program counts the number of characters in a string and returns the count. (e.g. "hello world" => 11)
This is done by running through each character and incrementing a counter.

function countCharacters(char *str)
{
  int count;
  
  count = 0;
  while (*str)
  {
    count++;
    str++;
  }
  return (count);
}
```
The runtime grows **linearly** with the number of characters, thus we say that the time complexity is O(n).

In comparison:
```
A program checks, for each character, if the character was repeated in the string and substitutes the
character with 1 or 0. (e.g. hello world => "00111001010")

function checkRepeats(char *str)
{
  int i;
  int j;
  
  i = 0;
  while (str[i])
  {
    j = 0;
    while (str[j])
    {
      if (j != i && str[j] == str[i])
      { 
        str[i] = '1';
        break ;
       }
    }
    if (str[i] != '1')
      str[i] = '0';
    i++;
  }
}
```
In this case, we traverse the entire array for **each** character. Therefore, the runtime will be the length of the the array multipled by the length of the array, thus we say the time complexity is O(n<sup>2</sup>).
## Score
`90/100`
