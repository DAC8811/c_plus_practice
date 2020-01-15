#include <iostream>
#include  <vector>
#include <map>

using namespace std;
class matrix
{
    public:
        matrix(int r = 1,int c = 1,int input = 0);
        matrix(int r = 1,int c = 1,vector<int> input = {0});
        ~matrix() {}
        vector<int> size(void);
        void display(void);
        int & get(int r,int c);

    private:
        int row;
        int column;
        vector<int> data;
};