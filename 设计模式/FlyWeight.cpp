#include <iostream>
#include <vector>

enum class Color
{
    black,
    white
};

class PiecePos
{
public:
    int x;
    int y;
};

/* 抽象棋子类 */
class Piece
{
public:
    virtual void draw() = 0;
protected:
    Color c;
};

class BlackPiece : public Piece
{
public:
    void draw()
    {
        std::cout << "黑棋" << std::endl;
    }
};

class WhitePiece : public Piece
{
public:
    void draw()
    {
        std::cout << "白棋" << std::endl;
    }
};

class PieceBoard
{
public:
    PieceBoard(const std::string& white, const std::string& black)
    {
        this->blackName = black;
        this->whiteName = white;
        this->black = nullptr;
        this->white = nullptr;
    }

    void SetPiece(Color c, int x, int y)
    {
        if (c==Color::white)
        {
            if (this->white == nullptr)
            {
                this->white = new WhitePiece;
            }
            std::cout << whiteName << "在(" << x << "," << y <<")下了一颗";
            this->white->draw();
            whitevec.push_back({x,y});
        }
        else
        {
            if (this->black == nullptr)
            {
                this->black = new BlackPiece;
            }
            std::cout << blackName << "在(" << x << "," << y <<")下了一颗";
            this->black->draw();
            blackvec.push_back({x,y});
        }
    }
private:
    Piece *black;
    Piece *white;
    std::vector<PiecePos> blackvec;
    std::vector<PiecePos> whitevec;
    std::string whiteName;
    std::string blackName;
};

int main()
{
    PieceBoard board("A","B");
    board.SetPiece(Color::white,0,0);
    board.SetPiece(Color::black,1,0);
    return 0;
}