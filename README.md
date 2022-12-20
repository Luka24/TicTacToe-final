# Ultimate-Tic-Tac-Toe
## Programming language: C++(Qt)

The ultimate tic tac toe game is one of my projects that I started in college and built on at home. Here is a link to the game instructions: https://en.wikipedia.org/wiki/Ultimate_tic-tac-toe.

At the begining you can choose whether you want to play against the computer or your opponent. The computer automatically chooses a move that is legal.

![image](https://user-images.githubusercontent.com/92547922/208774265-50b7d50f-4e9d-4f9a-9dd0-4b9d90941e88.png)

Class **IgralnoPolje** is designed as usual tic-tac-toe game.

![image](https://user-images.githubusercontent.com/92547922/208772675-abcef8ce-4bd4-47f5-883b-2d608656b7c8.png)

Class **VelikoIgralnoPolje** is seald class. On the whole game board we can look as a game of classical tic-tac-toe on nine boards. The class contains an array type IgralnoPolje that has size 3x3. It also contains information about the player on the move and the square in which the player must play the next move (that square is colored green).
![image](https://user-images.githubusercontent.com/92547922/208772838-d566d9e3-ff7b-445a-a6dc-7cb9a1690326.png)

In class **MainWindow** there are methods poteza and spremeniBarvoOzadjaKvadrata. In method poteza, the move is performed. The details of the method are written in the comments next to the code.
The spremeniBarvoOzadjaKvadrata method causes the game board backgrounds to be colored. Green are the squares into which the next move is legal. Blue and red are the fields in which one of the players won. The fields in which there is a tie are yellow.
![image](https://user-images.githubusercontent.com/92547922/208775402-6eeef259-578e-40c6-bb89-5212c2d7ac5c.png)

At the end of the game, the program detects victory and congratulates the winner. I wish you a nice game!

P. S. Don't get angry if the computer beats you 😊.

![image](https://user-images.githubusercontent.com/92547922/208777328-2b0d941b-347e-4ad6-b052-69fec52ba1df.png)

