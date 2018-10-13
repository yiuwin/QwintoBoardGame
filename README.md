# QwintoBoardGame
Players take turns rolling up to three dice but all players can record the points for all rolls. The player who rolls the dice can decide to roll one, two or three dice. The dice are colour-coded red, yellow and blue. The score sheet is organized in a sheared matrix with three rows and five overlapping columns. The rows are also colour-coded red, yellow and blue. The players can enter points only in a row if the dice of the corresponding colour was used but the score entered are the points from all dice rolled, e.g., if the yellow and blue dice was rolled, the points from the yellow and blue dice can be entered in the yellow or blue row. However, the numbers in each row must strictly increase and in each overlapping column, no number is allowed to repeat. If a player cannot score his or her own roll of the dice, it counts as a failed throw. Each failed throw will count as minus 5 points in the final score for the player. After four failed throws, the game ends. The game also ends if one player has filled two rows completely. The scoring is a mixture between the number of scores entered in each row plus a special bonus for a filled overlapping column. Completely filled rows are counted differently. Instead of counting the number of entries, the score of the right-most entry is counted.
The score sheet for this version needs 4 rows in our adaption: one row for each colour of dice: red, yellow and blue, as well as a fourth row for the failed throws. We need a maximum of twelve columns. The bonus fields are marked within % while invalid fields are marked XX. Notice that since the scores have a range form 1-18, we need a space of two characters.

An empty score sheet should look like this:
Player name:
------------------------------- Red | % % |XX| % % | | | |
---------------------------------- Yellow ||||||XX|%%|| ----------------------------------
Blue ||%%|XX||||%% -------------------------------
Failed throws:

At the end of a game, a score sheet may look like as below:
Player name: Jane Doe            Points: 28
              -------------------------------
Red           | 2% 3% 6|XX| 9%11%12|13|15|16|
           ----------------------------------
Yellow     | 1| 3| 4| 5|  |XX|12%13%  |  |
        ----------------------------------
Blue |1|3% %6|XX|7| | |10% % -------------------------------
Failed throws: 1 2 3

Jane Doe scored 28 points: The red row is complete and hence the right most score is used (16 points). The yellow row has 6 entries and the blue row has 5 entries. Two bonus columns are completed for an extra of 3 plus 13 points (the scores in the corresponding fields marked with %) and three failed throws are recorded at 3 times -5 = -15.
This game is an adaption of the game Qwinto by Bernhard Lach and Uwe Rapp which was published by Gigamic, Nürnberger-Spielkarten-Verlag and White Goblin Games. You can find an English review at https://www.boardgamegeek.com/boardgame/183006/qwinto.