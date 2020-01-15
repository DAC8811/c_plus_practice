#include "include/matrix.h"

int main(void)
{
    matrix m1(3,3,0);
    vector <int> data = {1,2,3,4,5,6,7,8,9};
    matrix m2(3,3,data);
    cout << "m1:" << endl;
    m1.display();
    cout << "m2:" << endl;
    m2.display();
    m1.get(1,1) ;
    cout << "m1 changed:" << endl;
    m1.display();
    return 0;
}