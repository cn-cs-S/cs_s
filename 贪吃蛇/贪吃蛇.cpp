#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;

//学会了控制台操作的我感觉天下无敌
void gotoxy(int x, int y) { 
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
    
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(hout, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(hout, &CursorInfo);//设置控制台光标状态
}

//蛇用链表定义
class Node {
public:
    int x;
    int y;
    Node* next;
};

class Snake {
private:
    Node* Head; 
    Node* EndPre;  //倒数第二个结点和最后一个界定存起来
    Node* End;     //用来计算添加到蛇尾的方向
    int length;
    char head;     //符号
    char body;
    char direction;//蛇头的方向, 未按键时维持原方向移动
public:
    Snake (char head, char body) : head(head), body(body), length(1) {
        direction = 'd';    //默认方向向右
        Head = new Node;
        Head->next = nullptr;
        Head->x = 20;
        Head->y = 20;
        End = Head;
        EndPre = Head;
    }
    Snake() = default;
    int getLength();        //用来计算分数
    void move();            //移动, 调用以下两个方法
    void getMove();
    void notGetMove();
    void add();             //添加, 调用以下两个方法
    void addOnly();
    void addMore();
    void print();           //打印蛇
    bool eat(int x, int y); //是否吃到食物
    bool die();             //是否死亡
};

int Snake::getLength() {
    return length;
}

void Snake::notGetMove() {
    if (direction == 'a')
        Head->x--;
    if (direction == 'd')
        Head->x++;
    if (direction == 'w')
        Head->y--;
    if (direction == 's')
        Head->y++;
}

void Snake::getMove() {
    char c = getch();
    if (c >= 'A' && c <= 'Z')
        c -= 32;
    if (c == 'a' && direction != 'd')
        Head->x--;
    else if (c == 'd' && direction != 'a')
        Head->x++;
    else if (c == 'w' && direction != 's')
        Head->y--;
    else if (c == 's' && direction != 'w')
        Head->y++;
    else {
        notGetMove();
        return ;
    }
    direction = c;
}

void Snake::move() {
    gotoxy(End->x, End->y); //用来消除最后一个尾巴
    putchar(' ');
    Node* h = Head->next;
    int xPre = Head->x;
    int yPre = Head->y;
    if (kbhit())
        getMove();
    else
        notGetMove();
    
    while (h) {
        int xNext = h->x;
        int yNext = h->y;
        h->x = xPre;
        h->y = yPre;
        xPre = xNext;
        yPre = yNext;
        h = h->next;    //血的教训
    }
}

void Snake::print() {
    gotoxy(Head->x, Head->y);
    putchar(head);
    Node* t = Head->next;
    while (t) {
        gotoxy(t->x, t->y);
        putchar(body);
        t = t->next;
    }
    gotoxy(Head->x, Head->y);
}

void Snake::addOnly() {
    //如果只有一个结点 方向就很好判断
    Node* temp = new Node;
    temp->next = Head->next;
    Head->next = temp;
    if (direction == 'a') {
        temp->x = Head->x + 1;
        temp->y = Head->y;
    }
    if (direction == 'd') {
        temp->x = Head->x - 1;
        temp->y = Head->y;
    }
    if (direction == 'w') {
        temp->x = Head->y + 1;
        temp->y = Head->y;
    }
    if (direction == 's') {
        temp->x = Head->y - 1;
        temp->y = Head->y;
    }
    End = temp;
}

void Snake::addMore() {
    //如果有多个结点就需要计算
    Node* temp = new Node;
    temp->next = End->next;
    End->next = temp;
    if (EndPre->x == End->x) {
        temp->x = End->x;
        if (EndPre->y > End->y)
            temp->y = End->y - 1;
        else
            temp->y = End->y + 1;
    }
    else {
        temp->y = End->y;
        if (EndPre->x > End->x)
            temp->x = End->x - 1;
        else
            temp->x = End->x + 1;
    }
    EndPre = End;
    End = temp;
}

void Snake::add() {
    if (length == 1)
        addOnly();
    else
        addMore();
    ++length;
}

bool Snake::eat(int x, int y) {
    if (Head->x == x && Head->y == y)
        return true;
    return false;
}

bool Snake::die() {
    if (Head->x < 1 || Head->x > 51 || Head->y < 1 || Head->y > 25)
        return true;
    return false;
}

class Food {
private:
    int x;
    int y;
    char food;  //符号
public:
    Food(char food) : food(food){}
    Food() = default;
    void creat();               //生成食物
    bool reCreat(int x, int y); //判断食物生成是否与蛇重合 (未实现)
    int getX();
    int getY();
};

void Food::creat() {
    srand(time(nullptr) << x);
    x = rand() % 50 + 2;
    y = rand() % 24 + 2;
    gotoxy(x, y);
    putchar(food);
}

int Food::getX() {
    return x;
}

int Food::getY() {
    return y;
}

class Game {
private:
    int difficulty; //难度, 默认1
public:
    Game() : difficulty(1){};
    int getDifficulty();    
    void setDifficulty(int); 
    void menu();
    void map();
    void game();
    void begin();
    void end();
};

int Game::getDifficulty() {
    return difficulty;
}

void Game::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
}

void Game::menu() {
    system("cls");      //清空终端
    system("color 13"); //终端背景颜色

    gotoxy(21, 13);
    cout << "1. 开始游戏";
    gotoxy(21, 14);
    cout << "2. 设置难度";

}

void Game::map() { 
    for (int i = 0; i <= 52; ++i) {
        gotoxy(0, i / 2);
        puts("█");
        gotoxy(52, i / 2);
        puts("█");
        gotoxy(i, 0);
        puts("█");
        gotoxy(i, 26);
        puts("█");
    }
}

void Game::game() {
    while (1) {
        menu();
        char c = getch();
        system("cls");
        if (c == '1') {
            map();
            begin();
        }
        else if (c == '2') {
            system("cls");
            gotoxy(21, 13);
            cout << "输入你理想的难度 1~9" << endl;
            char difficulty;
            difficulty = getch() - '0';
            setDifficulty(difficulty);
            continue;
        }
        else
            continue;
        end();
    }
}

void Game::begin() {
    Snake snake('*', '*');
    Food food('+');
    while (1) {
        food.creat();
        int x = food.getX();
        int y = food.getY();
        bool stata = false;     //判断是否死亡跳出两重循环
        while (1) {
            snake.move();
            stata = snake.die();
            if (stata)
                break;
            if (snake.eat(x, y))
                break;
            snake.print();
            Sleep(1000 - 100 * difficulty);
        }
        if (stata) {
            end();
            break;
        }
        snake.add();
        snake.print();
    }
}

void Game::end() {
    system("cls");
    cout << "you died !" << endl;
    //cout << "your score : " << snake.getLength() << endl;
    cout << "输入任意按键返回主菜单" << endl;
    getch();
}

int main() { //简洁的main函数
    Game game;
    game.game();
    return 0;
}