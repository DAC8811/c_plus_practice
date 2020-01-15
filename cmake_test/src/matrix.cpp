#include  "../include/matrix.h"


        matrix::matrix(int r ,int c ,int input )
        {
            row = r;
            column = c;
            for(int i=0;i<r*c;i++)
                data.push_back(input);
        }
        matrix::matrix(int r ,int c ,vector<int> input )
        {
            row = r;
            column = c;
            data = input;   
            while(data.size()<r*c)
                data.push_back(0);
        }
        vector<int> matrix::size(void)
        {
            vector<int> result = {row,column};
        }
        void matrix::display(void)
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                    cout << data[i*column+j] <<' ';
                cout << endl;
            }
        }
        int & matrix::get(int r,int c)
        {
            return data[r*column+c];
        }

