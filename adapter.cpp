class round_hole
{
public:
    round_hole(int radius) : radius_(radius) {}

private:
    int radius_;
};

class round_peg
{
public:
    round_peg(int radius) : radius_(radius) {}
    virtual ~round_peg() {}

private:
    int radius_;
};

class square_peg
{
public:
    square_peg(int width) : width_(width) {}

private:
    int width_;
};

class square_peg_adapater
    : public round_peg
{
public:

};