#include <iostream>
#include <time.h>
#include <conio.h>


using namespace std;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };



class pingo
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;

public:
	pingo(int posX, int posY)
	{
		//setting the position of the players
		originalX = posX;
		originalY = posY;
		x = posX; 
		y = posY;
		direction = STOP;

	}

	void Reset()
	{
		x = originalX;
		y = originalY;
		direction = STOP;

	}
	void changeDirection(eDir d)
	{
		direction = d;

	}
	//random direction for the ball to move
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX()
	{
		return x;
	}
	inline int getY()
	{
		return y;
	}
	inline int getDirection()
	{
		return direction;
	}

	void Move()
	{
		//move the ball in all directions
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
		case UPRIGHT:
			x++; y--;
		case DOWNRIGHT:
			x++; y++;
		default:
			break;
		}
	}
	//print the players
	friend ostream& operator<<(ostream& o, pingo c)
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}

};

class cPlayer
{
private:
	int x, y;
	int originalX, originalY;
public:
	cPlayer()
	{
		x = y = 0;

	}
	cPlayer(int posX, int posY) : cPlayer()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() 
	{
	x = originalX;
	y = originalY;
	}
	inline int getX()
	{
		return x;
	}
	inline int getY()
	{
		return y;
	}
	inline void moveUp()
	{
		y--;
	}
	inline void moveDown()
	{
		y++;
	}
	friend ostream& operator<<(ostream& o, cPlayer c)
	{
		//printing the paddles
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}

};

class cGameManager
{
private: //define the level
	int width, height; //of the level
	int score1, score2; //scores for each player
	char up1, down1, up2, down2; //movements for players, keys
	bool quit; //while loop ends when this is set
	pingo *ball;
	cPlayer *player1;
	cPlayer *player2;

public:
	cGameManager(int w, int h)
	{
		//set random, setting to null = 0
		srand(time(NULL));
		quit = false;
		up1 = 'w';
		up2 = 'i';
		down1 = 's'; 
		down2 = 'k';
		score1 = score2 = 0;
		width = w;
		height = h;
		ball = new pingo(w / 2, h / 2); //place the ball in the middle
		player1 = new cPlayer(1, h / 2 - 3); // placing paddles on either side
		player2 = new cPlayer(w - 2, h / 2 - 3); //placing paddle on side

	}

	~cGameManager()
	{
		delete ball, player1, player2;
	}
	void ScoreUp(cPlayer* player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();
		player1->Reset();
		player2->Reset();
		//resetting all their postions to default when the score of either player goes up by 1

	}
	void Draw()
	{
		system("cls"); //clear the screen
		for (int i = 0; i < width + 2; i++)
			cout << "\xDB";
		cout << endl;


		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player2x = player2->getX();
				int player1y = player1->getY();
				int player2y = player2->getY();

				if (j == 0)
					cout << "\xDB";

				if (ballx == j && bally == i)
					cout << "0"; //ball

				else if (player1x == j && player1y == i)
					cout << "\x7C"; //player1

				else if (player2x == j && player2y == i)
					cout << "\x7C"; //player2


				//print the 4 segments for the players 

				else if (player1x == j && player1y + 1  == i)
					cout << "\x7C"; //player1
				else if (player1x == j && player1y + 2 == i)
					cout << "\x7C"; //player1
				else if (player1x == j && player1y + 3 == i)
					cout << "\x7C"; //player1

				else if (player2x == j && player2y + 1 == i)
					cout << "\x7C"; //player1
				else if (player2x == j && player2y + 2 == i)
					cout << "\x7C"; //player1
				else if (player2x == j && player2y + 3 == i)
					cout << "\x7C"; //player1



				else
					cout << " ";

				if (j == width - 1)
					cout << "\xDB";

				//printing player 1 and 2
			}
			cout << endl;

		}
		for (int i = 0; i < width + 2; i++)
			cout << "\xDB";
		cout << endl;

		cout << "Score 1:" << score1 << endl << "Score 2:" << score2 << endl;
	}
	void Input()
	{
		ball->Move();

		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();

		if (_kbhit())
		{ //keypressed function, movement scripts
			char current = _getch();
			if (current == up1)
				if (player1y > 0)
					player1->moveUp();
			if (current == up2)
				if (player2y > 0)
					player2->moveUp();
			if (current == down1)
				if (player1y + 4 < height)
					player1->moveDown();
			if (current == down2)
				if (player2y + 4 < height)
					player2->moveDown();

			if (ball->getDirection() == STOP)
			{
				ball->randomDirection(); //if the ball is stopped, press any key to randomize the movement of the ball, this basically starts the game after a point is scored or in the beginning of the game
			}
			if (current == 'q')
			{
				quit = true;
			}
		}
	}
	void Logic()
	{
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();


		//left player
		for (int i = 0; i < 4; i++)
		{
			if (ballx == player1x + 1)
			{
				if (bally == player1y + i)
				{
					//make it randomize direction when the ball hits the player
					ball->changeDirection((eDir)((rand() % 3) + 4));
				}
			}
		}

		//right player
		for (int i = 0; i < 4; i++)
		{
			if (ballx == player2x - 1) 
			{
				if (bally == player2y + i)
				{
					//make it randomize direction when the ball hits the player
					ball->changeDirection((eDir)((rand() % 3) + 1)); // +1 because using the initialization at the beginning it goes from left (2) to down left (3)
				}
			}
		}
		//bottom wall
		if (bally == height - 1)
		{
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		}

		//topwall
		if (bally == 0)
		{
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		}

		//rightwall
		if (ballx == width - 1)
		{
			ScoreUp(player1);

		}

		//leftwall
		if (ballx == 0)
		{
			ScoreUp(player2);
		}
	}

	void Run()
	{
		while (!quit)
		{
			Draw();
			Input();
			Logic();
		}
	}

};

int main()
{
	cGameManager c(40, 20);
	c.Run();
	return 0;
}



