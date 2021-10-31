#include <vector>
#include <windows.h>
#include <conio.h>
using std::vector;

class Coord {
  public:
    Coord(int x, int y): x(x), y(y) {};
    int getX();
    int getY();
    void setX(int);
    void setY(int);
  private:
    int x;
    int y;
};

class Block {
  public:
    void doSth();
    bool isWall();
    void print();
    bool isDie();
  private:
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    void moveLeft();
    void moveRight();
    void moveDown();
    void toDown();
    bool isToLeft();
    bool isToRight();
    bool isDown();

  protected:
    vector<Coord> shape;
};

class ShapeT: public Block {
  public:
    ShapeT();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class ShapeL: public Block {
  public:
    ShapeL();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class ShapeSquare: public Block {
  public:
    ShapeSquare();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class ShapeLZ: public Block {
  public:
    ShapeLZ();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class ShapeRZ: public Block {
  public:
    ShapeRZ();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class ShapeLL: public Block {
  public:
    ShapeLL();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class ShapeRL : public Block {
  public:
    ShapeRL();
  private:
    void turnLeft() override;
    void turnRight() override;
};

class Game {
  public:
    Game();
    void menu();
    void create();
    void deleteLine();
    int getDifficult();  
    void setDifficult();
    void printWall();
    void print();
  private:
    vector<vector<bool> > wall;
    vector<Coord> map;
    int difficult;
};

int Coord::getX() {
    return x;
}

int Coord::getY() {
    return y;
}

void Coord::setX(int x) {
    this->x += x;
}

void Coord::setY(int y) {
    this->y += y;
}

void Block::doSth() {
    char c = getch();
    switch (c) {
        case 80:
            moveDown();
            break;
        case 75:
            moveLeft();
            break;
        case 77:
            moveRight();
            break;
        case 'z':
            turnLeft();
            break;
        case 'c':
            turnRight();
            break;
        case 'x':
            toDown();
            break;
        default:
            break;
    }
}

void Block::toDown() {

}

bool Block::isWall() {

}

void Block::print() {

}

bool Block::isDie() {

}

void Block::moveLeft() {
    if (!isToLeft()) {
        for (auto &r: shape) {
            r.setX(r.getX() - 1);
        }
    }
}

void Block::moveRight() {
    if (!isToLeft()) {
        for (auto &r: shape) {
          r.setX(r.getX() + 1);
        }
    }
}

void Block::moveDown() {
    if (!isDown()) {
        for (auto &r: shape) {
            r.setY(r.getY() + 1);
        }
    }

}

bool Block::isToLeft() {
    for (auto &r : shape) {
        int temp = r.getX();
        if (temp == 0)
            return true;
    }
    return false;
}

bool Block::isToRight() {
    for (auto &r: shape) {
        int temp = r.getX();
        if (temp == 10)
            return true;
    }
    return false;
}

bool Block::isDown() {

}

Game::Game(): wall(20, vector<bool>(10, false)){
    
}
