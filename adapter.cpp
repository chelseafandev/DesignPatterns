#include <iostream>
#include <cmath>

class round_peg
{
public:
    round_peg(double radius) : radius_(radius) {}
    virtual ~round_peg() {}

    double get_radius()
    {
        return radius_;
    }

private:
    double radius_;
};

class round_hole
{
public:
    round_hole(double radius) : radius_(radius) {}

    double get_radius()
    {
        return radius_;
    }

    bool fits(round_peg peg)
    {
        return get_radius() >= peg.get_radius();
    }

private:
    double radius_;
};

class square_peg
{
public:
    square_peg(double width) : width_(width) {}

    double get_width()
    {
        return width_;
    }

private:
    double width_;
};

// round hole에 squre peg이 fit한지를 확인하기 위해서는 square peg을 round peg처럼 사용할 수 있도록 해주는 adpater가 필요함
class square_peg_adapater
    : public round_peg
{
public:
    square_peg_adapater(square_peg peg) : peg_(peg), round_peg(peg.get_width()) {}

    double get_radius()
    {
        return (std::sqrt(std::pow((peg_.get_width() / 2), 2) * 2));
    }

private:
    square_peg peg_;
};

int main()
{
    round_hole rh(5);
    round_peg rp(5);
    std::cout << std::boolalpha << rh.fits(rp) << std::endl;

    square_peg sp_5(5);
    square_peg sp_10(10);
    // rh.fits(sp_5); // error! incompatible type

    square_peg_adapater spa_5(sp_5);
    std::cout << "spa_5 radius: " << spa_5.get_radius() << std::endl;
    square_peg_adapater spa_10(sp_10);
    std::cout << "spa_5 radius: " << spa_10.get_radius() << std::endl;
    std::cout << std::boolalpha << rh.fits(spa_5) << std::endl;
    std::cout << std::boolalpha << rh.fits(spa_10) << std::endl;

    return 0;
}
