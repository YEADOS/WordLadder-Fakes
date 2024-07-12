Word Ladder With Fakes!

Word Ladder is a word game where you are given two words and must transform one into the other by changing one letter at a time, such that each change results in a valid word.  For example if we want to change "four" into "five" we can do so in six steps via: four-tour-torr-tore-tire-fire-five (torr is a unit of pressure).  Given two words, we want to find the minimum number of moves it takes to change one into another, or determine that it is not possible to do so.  

The list of valid four letter words are provided in 4words.txt file 

The main function of the program is a function that finds the shortest path between two four-letter words, where adjacent words differ in one letter, with the additional novelty that we are allowed a budget of fake words, words that are not on the list of valid words.

Let's look at an example: If we want to find the shortest way to change four to five, where we can only change one letter at a time and each word must be on the valid word list, it takes us 6 moves: four-tour-torr-tore-tire-fire-five.  Every word here is on the word list.
