#include<iostream>
using namespace std;

#define MAX 50

bool sequence_finder(char Matrix[MAX][MAX], char sequence[MAX], int nrow, 
                     int ncol, int seq_len, int len_matched, 
                     bool status[MAX][MAX], int x, int y)
{
                     
    if(len_matched == seq_len)
        return (true);
    
    if(seq_len > nrow*ncol)
        return (false);
    
    if(status[x][y])
        return (false);
        
    if(Matrix[x][y] != sequence[len_matched] && len_matched == 0)
        {
            if(x < nrow-1) return(sequence_finder(Matrix, sequence, nrow,
                                  ncol, seq_len, len_matched, status, x+1, y));
            else if(y < ncol-1) return(sequence_finder(Matrix, sequence, nrow,
                                  ncol, seq_len, len_matched, status, 0, y+1));
            else return(false);
        }
    
    else if(Matrix[x][y] == sequence[len_matched])
        {
            bool res;
            status[x][y] = true;
            
            res = (x > 0 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x-1, y) : false) ||
                  (res = y > 0 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x, y-1) : false) ||
                  (res = x < nrow-1 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x+1, y) : false) ||
                  (res = y < ncol-1 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x, y+1) : false) ||
                  (res = x > 0 && y > 0 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x-1, y-1) : false) ||
                  (res = x < nrow-1 && y < ncol-1 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x+1, y+1) : false) ||
                  (res = x > 0 && y < ncol-1 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x-1, y+1) : false) ||
                  (res = x < nrow-1 && y > 0 ? sequence_finder(Matrix, sequence, nrow,
                   ncol, seq_len, len_matched+1, status, x+1, y-1) : false);
            
            status[x][y] = false;
            return res;
        }
    else return(false);

}        

bool sequence_finder_wrapper(char Matrix[MAX][MAX], char sequence[MAX], 
                             int nrow, int ncol, int seq_len)
{
    bool status[MAX][MAX] = {{false,},};
    int len_matched = 0;
    int x = 0, y = 0;
    
    //cout<<"bool = "<<status[3][5]<<endl;              
    return (sequence_finder(Matrix, sequence, nrow, ncol, 
                            seq_len, len_matched, status, x, y));
}
    
int main(int argc, char **argv)
{
    char Matrix[MAX][MAX] = {{'A', 'C', 'P', 'R', 'C'},
                             {'X', 'S', 'O', 'P', 'C'},
                             {'V', 'O', 'V', 'N', 'I'},
                             {'W', 'G', 'F', 'M', 'N'},
                             {'Q', 'T', 'O', 'I', 'T'}};
    char Sequence[MAX] = {'M', 'I', 'C', 'R', 'O', 'S', 'O', 'F', 'T'};
    
    //cout<<Matrix[0][0]<<Matrix[0][1]<<Matrix[1][0]<<Matrix[1][1]<<endl;

    cout<<sequence_finder_wrapper(Matrix, Sequence, 5, 5, 9)<<endl;
    
    cin.get();
    return (0);
}    
    
