//
//  main.cpp
//  Othello
//
//  Created by 林湘羚 on 2021/5/28.
//

#include <iostream>
#include <utility>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

//function
int countFlipPieces(string gameboard, int playerColor, string grid, int direction){
    // 0上 1右上 2右 3右下 4下 5左下 6左 7左上 direction方向
    int row= grid[0]- 'A', col= grid[1]- 'a';
    char opponent, player;
    if(playerColor== 1){
        opponent= 'O';
        player= 'X';
    }
    else{
        opponent= 'X';
        player= 'O';
    }
    
    int index= row* 6+ col;
    int Xstep= 0, Ystep= 0, counttt= 0;
    
    if(direction== 0){ // 上
        Xstep= -1;
        Ystep= 0;
    }
    else if(direction== 1){ // 右上
        Xstep= -1;
        Ystep= 1;
    }
    else if(direction== 2){ // 右
        Xstep= 0;
        Ystep= 1;
    }
    else if(direction== 3){ // 右下
        Xstep= 1;
        Ystep= 1;
    }
    else if(direction== 4){ // 下
        Xstep= 1;
        Ystep= 0;
    }
    else if(direction== 5){ // 左下
        Xstep= 1;
        Ystep= -1;
    }
    else if(direction== 6){ // 左
        Xstep= 0;
        Ystep= -1;
    }
    else if(direction== 7){ // 左上
        Xstep= -1;
        Ystep= -1;
    }
    
    row+= Xstep; col+= Ystep;
    index= row* 6+ col;
    
    while(row>= 0&& row< 6&& col>= 0&& col< 6){
        if(gameboard[index]== player) return counttt;
        else if(gameboard[index]== opponent) counttt++;
        else return 0;
        row+= Xstep; col+= Ystep;
        index= row* 6+ col;
    }
    return 0;
}
void flipPieces(string* new_board, string org_board, int playerColor, string grid) {
    int i, j, row, col, count, tempRow, tempCol;
    row = grid[0] - 'A';
    col = grid[1] - 'a';
    if(playerColor==1){
        (*new_board)[row*6+col]='X';
    }else if(playerColor==2){
        (*new_board)[row*6+col]='O';
    }
    for(i=0;i<8;i++){
        if((count = countFlipPieces(org_board, playerColor, grid, i)) > 0){
            tempRow=row;
            tempCol=col;
            if(i==0){   //上
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(--tempRow)*6+tempCol]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(--tempRow)*6+tempCol]='O';
                    }
                }
            }else if(i==1){ //右上
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(--tempRow)*6+(++tempCol)]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(--tempRow)*6+(++tempCol)]='O';
                    }
                }
            }else if(i==2){ //右
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(tempRow)*6+(++tempCol)]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(tempRow)*6+(++tempCol)]='O';
                    }
                }
            }else if(i==3){ //右下
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(++tempRow)*6+(++tempCol)]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(++tempRow)*6+(++tempCol)]='O';
                    }
                }
                
            }else if(i==4){ //下
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(++tempRow)*6+tempCol]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(++tempRow)*6+tempCol]='O';
                    }
                }
            }else if(i==5){ //左下
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(++tempRow)*6+(--tempCol)]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(++tempRow)*6+(--tempCol)]='O';
                    }
                }
            }else if(i==6){ //左
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(tempRow)*6+(--tempCol)]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(tempRow)*6+(--tempCol)]='O';
                    }
                }
                
            }else if(i==7){ //左上
                if(playerColor==1){
                    for(j=0;j<count;j++){
                        (*new_board)[(--tempRow)*6+(--tempCol)]='X';
                    }
                }else if(playerColor==2){
                    for(j=0;j<count;j++){
                        (*new_board)[(--tempRow)*6+(--tempCol)]='O';
                    }
                }
            }
        }
    }
}
int countColorPieces(string gameboard, int playerColor){
    int i, count=0;
    
    if(playerColor==1){
        for(i=0;i<36;i++){
            if(gameboard[i]=='X') count++;
        }
    }else if(playerColor==2){
        for(i=0;i<36;i++){
            if(gameboard[i]=='O') count++;
        }
    }
    return count;
}
bool isValidMove(string gameboard, int playerColor, string grid){
    for(int i=0;i<8;i++){
        if(countFlipPieces(gameboard, playerColor, grid, i)>0) return true;
    }
    return false;
}
bool passTurn(string gameboard, int playerColor){
    for(int i=0;i<36;i++){
        if(gameboard[i]=='+'){
            string temp="";
            temp=temp+char(i/6+'A')+char(i%6+'a');
            if(isValidMove(gameboard, playerColor, temp)) {
                return false;
            }
        }
    }
    return true;
}
bool gameOver(string gameboard){
    return passTurn(gameboard, 1) && passTurn(gameboard, 2);
}
int heuristicScore(string gameboard, int playerColor){
    return countColorPieces(gameboard, playerColor) - countColorPieces(gameboard, playerColor==1 ? 2 : 1);
}
void getDirection_xue(int direction, int* x, int* y) {
    switch(direction) {
        case 1: // 右上 up-right
            *x = -1, *y = 1;
            break;
        case 2: // 右 right
            *x = 0, *y = 1;
            break;
        case 3: // 右下 down-right
            *x = 1, *y = 1;
            break;
        case 4: // 下 down
            *x = 1, *y = 0;
            break;
        case 5: // 左下 down-left
            *x = 1, *y = -1;
            break;
        case 6: // 左 left
            *x = 0, *y = -1;
            break;
        case 7: // 左上 up-left
            *x = -1, *y = -1;
            break;
        default:    // 上 up
            *x = -1, *y = 0;
            break;
    }
}
int countFlipPieces_xue(string gameboard, int playerColor, int grid, int direction) {
    int i, j, x, y, count = 0;
    string color;
    
    if (playerColor == 1)   color = "OX";   // color[1] - enemy
    else                    color = "XO";   // color[2] - self
    
    getDirection_xue(direction, &x, &y);
    for (i = (grid / 6) + x, j = (grid % 6) + y; i >= 0 && i < 6 && j >= 0 && j < 6; i += x, j+= y) {
        if (gameboard[(i * 6) + j] == color[0])         count++;
        else if (gameboard[(i * 6) + j] == color[1])    break;
        else {
            count = 0;
            break;
        }
    }
    
    // 不在棋盤的範圍內 (到邊邊外了)
    if (!(i >= 0 && i < 6 && j >= 0 && j < 6))    count = 0;
    
    return count;
}
string flipPieces_xue(string gameboard, int playerColor, int grid) {
    int direction, i, j, x, y, flipNum;
    char color;
    string newGameboard = gameboard;
    
    if (playerColor == 1)   color = 'X';
    else                    color = 'O';
    
    newGameboard[grid] = color;
    for (direction = 0; direction < 8; direction++) {
        flipNum = countFlipPieces_xue(gameboard, playerColor, grid, direction);
        if (flipNum > 0) {
            getDirection_xue(direction, &x, &y);
            for (i = (grid / 6) + x, j = (grid % 6) + y; flipNum > 0; i += x, j+= y, flipNum--) {
                newGameboard[(i * 6) + j] = color;
            }
        }
    }
    return newGameboard;
}
bool isValidMove_xue(string gameboard, int playerColor, int grid) {
    for (int direction = 0; direction < 8; direction++) {
        if (countFlipPieces_xue(gameboard, playerColor, grid, direction) > 0)
            return true;
    }
    return false;
}

int num_validMove(string gameboard, int playerColor){
    // 整個棋盤中有幾個位置是可以走的
    int counttt= 0;
    for(int i= 0; i< 6; i++){
        for(int j= 0; j< 6; j++){
            char xChar= ('A'+ i), yChar= ('a'+ j);
            string grid= "";
            grid+= xChar; grid+= yChar;
            if(isValidMove(gameboard, playerColor, grid))
                counttt++;
        }
    }
    return counttt;
}
int goodHeuristic(string gameboard, int playerColor){
    int opppnentColor;
    char myChar;
    char oppChar;
    if(playerColor== 1){
        opppnentColor= 2;
        myChar= 'O';
        oppChar= 'X';
    }else{
        opppnentColor= 1;
        myChar= 'X';
        oppChar= 'O';
    }
    
    int my_tiles = 0, opp_tiles = 0, my_front_tiles = 0, opp_front_tiles = 0;
    double pieceDiff= 0, corner= 0, closeCorner= 0, mobility= 0, frontier= 0, diskWeight= 0;
    
    int weight[6][6]= { {18, -3, 10, 10, -3, 18},
        {-3, -7, 0, 0, -7, -3},
        {10, 0, 1, 1, 0, 10},
        {10, 0, 1, 1, 0, 10},
        {-3, -7, 0, 0, -7, -3},
        {18, -3, 10, 10, -3, 18} };
    int x_d[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int y_d[] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    // Piece difference, frontier disks and disk squares
    for(int i= 0; i< 6; i++){
        for(int j= 0; j< 6; j++){
            if(gameboard[i*6+ j]== myChar){
                diskWeight+= weight[i][j];
                my_tiles++;
            }else if(gameboard[i*6+ j]== oppChar){
                diskWeight-= weight[i][j];
                opp_tiles++;
            }
            if(gameboard[i*6+ j]== '+'){
                for(int k= 0; k< 8; k++){ // 8個方向
                    int x= i+ x_d[k];
                    int y= j+ y_d[k];
                    if(x>= 0&& x < 6&& y>= 0&& y< 6&& gameboard[x*6+ y]== '+'){
                        if(gameboard[i*6+ j]== myChar)
                            my_front_tiles++;
                        else opp_front_tiles++;
                        break;
                    }
                }
            }
        }
    }
    
    // std::cout<< endl<< "my_tile: "<< my_tiles<< endl;
    // std::cout<< "opp_tile: "<< opp_tiles<< endl;
    // std::cout<< "my_front_tile: "<< my_front_tiles<< endl;
    // std::cout<< "opp_front_tile: "<< opp_front_tiles<< endl;
    
    if(my_tiles> opp_tiles)
        pieceDiff= (float)(100.0* my_tiles)/(float)(my_tiles+ opp_tiles);
    else if(my_tiles< opp_tiles)
        pieceDiff= -(float)(100.0* opp_tiles)/(float)(my_tiles+ opp_tiles);
    else pieceDiff= 0;
    
    if(my_front_tiles> opp_front_tiles)
        frontier= -(float)(100.0* my_front_tiles)/(float)(my_front_tiles+ opp_front_tiles);
    else if(my_front_tiles < opp_front_tiles)
        frontier= (float)(100.0* opp_front_tiles)/(float)(my_front_tiles+ opp_front_tiles);
    else frontier= 0;
    
    // Corner occupancy
    my_tiles= 0;
    opp_tiles= 0;
    if(gameboard[0]== myChar) my_tiles++; // 左上
    else if(gameboard[0]== oppChar) opp_tiles++;
    if(gameboard[5]== myChar) my_tiles++; // 右上
    else if(gameboard[5]== oppChar) opp_tiles++;
    if(gameboard[30]== myChar) my_tiles++; // 左下
    else if(gameboard[30]== oppChar) opp_tiles++;
    if(gameboard[35]== myChar) my_tiles++; // 右下
    else if(gameboard[35]== oppChar) opp_tiles++;
    corner= 25.0* (float)(my_tiles- opp_tiles);
    
    // Corner closeness
    my_tiles= 0;
    opp_tiles= 0;
    if(gameboard[0]== '+'){
        if(gameboard[1]== myChar) my_tiles++;
        else if(gameboard[1]== oppChar) opp_tiles++;
        if(gameboard[6]== myChar) my_tiles++;
        else if(gameboard[6]== oppChar) opp_tiles++;
        if(gameboard[7]== myChar) my_tiles++;
        else if(gameboard[7]== oppChar) opp_tiles++;
    }
    if(gameboard[5]== '+'){
        if(gameboard[4]== myChar) my_tiles++;
        else if(gameboard[4]== oppChar) opp_tiles++;
        if(gameboard[11]== myChar) my_tiles++;
        else if(gameboard[11]== oppChar) opp_tiles++;
        if(gameboard[10]== myChar) my_tiles++;
        else if(gameboard[10]== oppChar) opp_tiles++;
    }
    if(gameboard[30]== '+'){
        if(gameboard[24]== myChar) my_tiles++;
        else if(gameboard[24]== oppChar) opp_tiles++;
        if(gameboard[31]== myChar) my_tiles++;
        else if(gameboard[31]== oppChar) opp_tiles++;
        if(gameboard[25]== myChar) my_tiles++;
        else if(gameboard[25]== oppChar) opp_tiles++;
    }
    if(gameboard[35]== '+'){
        if(gameboard[34]== myChar) my_tiles++;
        else if(gameboard[34]== oppChar) opp_tiles++;
        if(gameboard[29]== myChar) my_tiles++;
        else if(gameboard[29]== oppChar) opp_tiles++;
        if(gameboard[28]== myChar) my_tiles++;
        else if(gameboard[28]== oppChar) opp_tiles++;
    }
    closeCorner= -12.5* (float)(my_tiles- opp_tiles);
    
    // Mobility
    my_tiles= num_validMove(gameboard, playerColor);
    opp_tiles= num_validMove(gameboard, opppnentColor);
    if(my_tiles> opp_tiles)
        mobility= (float)(100.0* my_tiles)/(float)(my_tiles+ opp_tiles);
    else if(my_tiles < opp_tiles)
        mobility= -(float)(100.0* opp_tiles)/(float)(my_tiles+ opp_tiles);
    else mobility= 0;
    
    // final weighted score
    double score= (10.0* pieceDiff)
    + (801.724* corner)+ (382.026* closeCorner)
    + (78.922* mobility)
    // + (74.0* frontier)
    + (10.0* diskWeight);
    
    // cout<< endl<< "pieceDiff: "<< pieceDiff<< endl;
    // cout<< "corner: "<< corner<< endl;
    // cout<< "closeCorner: "<< closeCorner<< endl;
    // cout<< "mobility: "<< mobility<< endl;
    // cout<< "frontier: "<< frontier<< endl;
    // cout<< "diskWeight: "<< diskWeight<< endl;
    // cout<< "h Score: "<< score<< endl;
    return (int)score;
}
int heuristicScore(string gameboard, int playerColor, int heuristicChoose){
    // 可換其他種設計方法
    if(heuristicChoose== 0){
        int opppnentColor= 2? (playerColor== 1): 1;
        return countColorPieces(gameboard, playerColor)- countColorPieces(gameboard, opppnentColor);
    }else if(heuristicChoose== 1){
        return goodHeuristic(gameboard, playerColor);
    }
    cout<< "Choose Error"<< endl;
    return -1;
}

string flipPieces(string gameboard, int playerColor, string grid){
    // return 新狀態
    string newboard= gameboard;
    char opponent, player;
    if(playerColor== 1) player= 'X';
    else player= 'O';
    
    if(isValidMove(gameboard, playerColor, grid)){
        int row= grid[0]- 'A', col= grid[1]- 'a';
        int index= row* 6+ col;
        int step= 0;
        
        for(int d= 0; d< 8; d++){
            int counttt= countFlipPieces(newboard, playerColor, grid, d);
            if(d== 0) step= -6;
            else if(d== 1) step= -6+1;
            else if(d== 2) step= 1;
            else if(d== 3) step= 6+1;
            else if(d== 4) step= 6;
            else if(d== 5) step= 6-1;
            else if(d== 6) step= -1;
            else if(d== 7) step= -6-1;
            for(int i= 1; i<= counttt; i++){
                newboard[index+ step* i]= player;
            }
        }
        newboard[index]= player;
    }
    return newboard;
}

//player class
class MCTSPlayer{
public:
    string gameboard;
    int playerColor;
    
    string action(){
        OthelloBoard board = OthelloBoard();
        board.board = gameboard;
        board.activePlayer = playerColor;
        if(!board.isPass()){
            Uct uct = Uct();
            uct.board = board;
            return uct.getActionInfo();
        }else{
            return "pass";
        }
    }
    class OthelloBoard {
    public:
        string board;
        int activePlayer;
        vector<string> getActions(){
            vector<string> temp;
            for(int i=0;i<36;i++){
                if(board[i]=='+'){
                    string grid="";
                    grid=grid+char(i/6+'A')+char(i%6+'a');
                    if(isValidMove(board, activePlayer, grid)){
                        temp.push_back(grid);
                    }
                }
            }
            return temp;
        }
        void doAction(string action){
            string new_board = board;
            flipPieces(&new_board, board, activePlayer, action);
            board = new_board;
            activePlayer = activePlayer == 1 ? 2 : 1;
        }
        int getResult(){    //win->1, lose->0, tie->0.5
            return (heuristicScore(board, activePlayer) > 0) ? 1 : (heuristicScore(board, activePlayer) == 0) ? 0.5 : 0;
        }
        bool isPass(){
            return passTurn(board, activePlayer);
        }
        bool over(){
            return gameOver(board);
        }
        void pass(){
            activePlayer = activePlayer == 1 ? 2 : 1;
        }
        int emptyPeices(){
            return countEmptyPieces(board);
        }
    private:
        bool isValidMove(string gameboard, int playerColor, string grid){
            for(int i=0;i<8;i++){
                if(countFlipPieces(gameboard, playerColor, grid, i)>0) return true;
            }
            return false;
        }
        int countFlipPieces(string gameboard, int playerColor, string grid, int direction){
            int i, j, row, col, count=0;
            bool legal=false;
            row = grid[0] - 'A';
            col = grid[1] - 'a';
            if(direction==0){   //上
                if(row-1>0){
                    if(playerColor==1){
                        if(gameboard[(row-1)*6+col]=='O'){
                            for(i=row-1;i>=0;i--){
                                if(gameboard[i*6+col]=='O'){
                                    count++;
                                }else if(gameboard[i*6+col]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[(row-1)*6+col]=='X'){
                            for(i=row-1;i>=0;i--){
                                if(gameboard[i*6+col]=='X'){
                                    count++;
                                }else if(gameboard[i*6+col]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(direction==1){ //右上
                if(row-1>0 && col+1<5){
                    if(playerColor==1){
                        if(gameboard[(row-1)*6+(col+1)]=='O'){
                            for(i=row-1, j=col+1; (i>=0) && (j<6); i--, j++){
                                if(gameboard[i*6+j]=='O'){
                                    count++;
                                }else if(gameboard[i*6+j]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[(row-1)*6+(col+1)]=='X'){
                            for(i=row-1, j=col+1; (i>=0) && (j<6); i--, j++){
                                if(gameboard[i*6+j]=='X'){
                                    count++;
                                }else if(gameboard[i*6+j]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(direction==2){ //右
                if(col+1<5){
                    if(playerColor==1){
                        if(gameboard[row*6+(col+1)]=='O'){
                            for(j=col+1;j<6;j++){
                                if(gameboard[row*6+j]=='O'){
                                    count++;
                                }else if(gameboard[row*6+j]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[row*6+(col+1)]=='X'){
                            for(j=col+1;j<6;j++){
                                if(gameboard[row*6+j]=='X'){
                                    count++;
                                }else if(gameboard[row*6+j]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(direction==3){ //右下
                if(row+1<5 && col+1<5){
                    if(playerColor==1){
                        if(gameboard[(row+1)*6+(col+1)]=='O'){
                            for(i=row+1, j=col+1; (i<6) && (j<6); i++, j++){
                                if(gameboard[i*6+j]=='O'){
                                    count++;
                                }else if(gameboard[i*6+j]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[(row+1)*6+(col+1)]=='X'){
                            for(i=row+1, j=col+1; (i<6) && (j<6); i++, j++){
                                if(gameboard[i*6+j]=='X'){
                                    count++;
                                }else if(gameboard[i*6+j]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(direction==4){ //下
                if(row+1<5){
                    if(playerColor==1){
                        if(gameboard[(row+1)*6+col]=='O'){
                            for(i=row+1;i<6;i++){
                                if(gameboard[i*6+col]=='O'){
                                    count++;
                                }else if(gameboard[i*6+col]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[(row+1)*6+col]=='X'){
                            for(i=row+1;i<6;i++){
                                if(gameboard[i*6+col]=='X'){
                                    count++;
                                }else if(gameboard[i*6+col]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
                
            }else if(direction==5){ //左下
                if(row+1<5 && col-1>0){
                    if(playerColor==1){
                        if(gameboard[(row+1)*6+(col-1)]=='O'){
                            for(i=row+1, j=col-1; (i<6) && (j>=0); i++, j--){
                                if(gameboard[i*6+j]=='O'){
                                    count++;
                                }else if(gameboard[i*6+j]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[(row+1)*6+(col-1)]=='X'){
                            for(i=row+1, j=col-1; (i<6) && (j>=0); i++, j--){
                                if(gameboard[i*6+j]=='X'){
                                    count++;
                                }else if(gameboard[i*6+j]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(direction==6){ //左
                if(col-1>0){
                    if(playerColor==1){
                        if(gameboard[row*6+(col-1)]=='O'){
                            for(j=col-1;j>=0;j--){
                                if(gameboard[row*6+j]=='O'){
                                    count++;
                                }else if(gameboard[row*6+j]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[row*6+(col-1)]=='X'){
                            for(j=col-1;j>=0;j--){
                                if(gameboard[row*6+j]=='X'){
                                    count++;
                                }else if(gameboard[row*6+j]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }else if(direction==7){ //左上
                if(row-1>0 && col-1>0){
                    if(playerColor==1){
                        if(gameboard[(row-1)*6+(col-1)]=='O'){
                            for(i=row-1, j=col-1; (i>=0) && (j>=0); i--, j--){
                                if(gameboard[i*6+j]=='O'){
                                    count++;
                                }else if(gameboard[i*6+j]=='X'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }else if(playerColor==2){
                        if(gameboard[(row-1)*6+(col-1)]=='X'){
                            for(i=row-1, j=col-1; (i>=0) && (j>=0); i--, j--){
                                if(gameboard[i*6+j]=='X'){
                                    count++;
                                }else if(gameboard[i*6+j]=='O'){
                                    legal=true;
                                    break;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return legal ? count : 0;
        }
        void flipPieces(string* new_board, string org_board, int playerColor, string grid) {
            int i, j, row, col, count, tempRow, tempCol;
            row = grid[0] - 'A';
            col = grid[1] - 'a';
            if(playerColor==1){
                (*new_board)[row*6+col]='X';
            }else if(playerColor==2){
                (*new_board)[row*6+col]='O';
            }
            for(i=0;i<8;i++){
                if((count = countFlipPieces(org_board, playerColor, grid, i)) > 0){
                    tempRow=row;
                    tempCol=col;
                    if(i==0){   //上
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(--tempRow)*6+tempCol]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(--tempRow)*6+tempCol]='O';
                            }
                        }
                    }else if(i==1){ //右上
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(--tempRow)*6+(++tempCol)]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(--tempRow)*6+(++tempCol)]='O';
                            }
                        }
                    }else if(i==2){ //右
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(tempRow)*6+(++tempCol)]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(tempRow)*6+(++tempCol)]='O';
                            }
                        }
                    }else if(i==3){ //右下
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(++tempRow)*6+(++tempCol)]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(++tempRow)*6+(++tempCol)]='O';
                            }
                        }
                        
                    }else if(i==4){ //下
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(++tempRow)*6+tempCol]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(++tempRow)*6+tempCol]='O';
                            }
                        }
                    }else if(i==5){ //左下
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(++tempRow)*6+(--tempCol)]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(++tempRow)*6+(--tempCol)]='O';
                            }
                        }
                    }else if(i==6){ //左
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(tempRow)*6+(--tempCol)]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(tempRow)*6+(--tempCol)]='O';
                            }
                        }
                        
                    }else if(i==7){ //左上
                        if(playerColor==1){
                            for(j=0;j<count;j++){
                                (*new_board)[(--tempRow)*6+(--tempCol)]='X';
                            }
                        }else if(playerColor==2){
                            for(j=0;j<count;j++){
                                (*new_board)[(--tempRow)*6+(--tempCol)]='O';
                            }
                        }
                    }
                }
            }
        }
        int countColorPieces(string gameboard, int playerColor){
            int i, count=0;
            
            if(playerColor==1){
                for(i=0;i<36;i++){
                    if(gameboard[i]=='X') count++;
                }
            }else if(playerColor==2){
                for(i=0;i<36;i++){
                    if(gameboard[i]=='O') count++;
                }
            }
            return count;
        }
        int countEmptyPieces(string gameboard){
            int i, count=0;
            for(i=0;i<36;i++){
                if(gameboard[i]=='+') count++;
            }
            return count;
        }
        int heuristicScore(string gameboard, int playerColor){
            return countColorPieces(gameboard, playerColor) - countColorPieces(gameboard, playerColor==1 ? 2 : 1);
        }
        bool passTurn(string gameboard, int playerColor){
            for(int i=0;i<36;i++){
                if(gameboard[i]=='+'){
                    string temp="";
                    temp=temp+char(i/6+'A')+char(i%6+'a');
                    if(isValidMove(gameboard, playerColor, temp)) {
                        return false;
                    }
                }
            }
            return true;
        }
        bool gameOver(string gameboard){
            return passTurn(gameboard, 1) && passTurn(gameboard, 2);
        }
    };
    class Uct {
    public:
        OthelloBoard board;
        
        string getActionInfo(){
            UctNode* root = new UctNode();
            root->init(NULL, board, "");
            int sim_no = 10000;
            for(int i=0;i<sim_no;i++){
                UctNode* node = new UctNode();
                node = root;
                int nodeVisited = 0;
                OthelloBoard variantBoard = OthelloBoard();
                variantBoard = board;
                //Selection
                while(node->unexamined.size() == 0 && node->children.size() > 0){
                    node = node->selectChild();
                    variantBoard.doAction(node->action);
                }
                //Expansion
                if(node->unexamined.size() > 0){
                    int r = rand() % node->unexamined.size();
                    variantBoard.doAction(node->unexamined[r]);
                    node = node->addChild(variantBoard, r);
                }
                //Simulation
                vector<string> actions = variantBoard.getActions();
                while(!variantBoard.over()){
                    if(actions.size() > 0){
                        variantBoard.doAction(actions[rand() % actions.size()]);
                        ++nodeVisited;
                        actions = variantBoard.getActions();
                    }else{
                        variantBoard.pass();
                        actions = variantBoard.getActions();
                    }
                }
                //Backpropagation
                int result = variantBoard.getResult();
                while(node){
                    node->update(result);
                    node = node->parentNode;
                }
            }
            return root->mostVisitedChild()->action;
        }
        class UctNode {
        public:
            string action;
            UctNode* parentNode;
            vector<UctNode*> children;
            int wins;
            int visits;
            vector<string> unexamined;
            
            int activePlayer;
            void init(UctNode* ParentNode, OthelloBoard board, string Action){
                action=Action;
                parentNode=ParentNode;
                unexamined=board.getActions();
                activePlayer=board.activePlayer;
            }
            
            UctNode* addChild(OthelloBoard board, int index){
                UctNode* node = new UctNode();
                node->init(this, board, unexamined[index]);
                unexamined.erase(unexamined.begin()+index, unexamined.begin()+index+1);
                children.push_back(node);
                return node;
            }
            UctNode* selectChild(){     //UCT
                UctNode* selected = NULL;
                double bestValue = -INT_MAX;
                for(int i=0;i<children.size();i++){
                    UctNode* child = children[i];
                    double uctValue = child->wins / child->visits + sqrt(2 * log(visits) / child->visits);
                    if(uctValue > bestValue){
                        bestValue = uctValue;
                        selected = child;
                    }
                }
                return selected;
            }
            void update(int result){
                ++visits;
                wins += result;
            }
            UctNode* mostVisitedChild(){
                UctNode* mostVisited = children[0];
                for(int i=0;i<children.size();i++){
                    if(children[i]->visits > mostVisited->visits){
                        mostVisited = children[i];
                    }
                }
                return mostVisited;
            }
        };
    };
};  
class PVSearch{
public:
    string gameboard;
    int playerColor;
    
    string action(){
        int row, col, depth = 11;
        string action;
        if(passTurn(gameboard, playerColor)){  // pass or full served
            return "pass";
        }
        else {
            int b = pvSearch(gameboard, playerColor, -99999, 99999, depth).second;
            row = b / 6;
            col = b % 6;
            action = char(row+'A');
            action.append(1, char(col+'a'));
            return action;
        }
    }
    
    pair<int, int> pvSearch(string gameboard, int player, int alpha, int beta, int depth){ // player: you
        int j = 0, best = -99999, row, col, count = 0, val, bestDir;
        string g;
        bool bSearchPv = true;
        if(depth == 0){ // me
            return make_pair(countColorPieces(gameboard, (player==1?'X':'O')) - countColorPieces(gameboard, (player==1?'O':'X')), -1);  // heuristicScore: me - you
        }
        else{
            while(j != gameboard.length()){
                if(gameboard[j] == '+' && (isValidMove_xue(gameboard, player, j) == true) && depth != 0){
                    
                    g = gameboard;
                    //cout << "gameboard: " << gameboard << endl;
                    g = flipPieces_xue(g, player, j); // flip
                    if(bSearchPv){
                        val = -pvSearch(g, player==1?2:1, -beta, -alpha, depth-1).first;
                    }
                    else{
                        val = -pvSearch(g, player==1?2:1, -alpha-1, -alpha, depth-1).first;
                        if(val > alpha)  val = -pvSearch(g, player==1?2:1, -beta, -alpha, depth-1).first; // re-search
                    }
                    //cout << depth << " " << val << endl;
                    if(val >= beta) return make_pair(beta, j);
                    if(val > alpha){
                        alpha = val;
                        bestDir = j;
                        bSearchPv = false;
                    }
                    //cout << j << endl;
                    //cout << g << endl;
                    count++;
                    
                }
                j++;
            }
            //cout << "depth: " << depth << ", best: " << best << endl;
            if(count == 0){ // if no move change to you
                return make_pair(-pvSearch(gameboard, player==1?2:1, -99999, 99999, depth-1).first, -1);
            }
            else return make_pair(alpha, bestDir);
        }
        return make_pair(-1, -1);
    }
};
class AlphaBetaPruningPlayer {
public:
    string gameboard;
    int playerColor;
    
    string action(){
        if(!passTurn(gameboard, playerColor)) {
            int index = AlphaBetaPruning(gameboard, playerColor, 10, INT_MIN, INT_MAX, true).second;
            string action = "";
            action = action + char(index/6 + 'A') + char(index%6 + 'a');
            return action;
        } else {
            return "pass";
        }
    }
    
    pair<int, int> AlphaBetaPruning(string gameboard, int playerColor, int depth, int alpha, int beta, bool isMaximizingPlayer) {
        // 前面是 heuristicScore , 後面是 grid
        int opponentColor, grid;
        pair<int, int> tempValue, bestValue;
        
        if (playerColor == 1)   opponentColor = 2;
        else                    opponentColor = 1;
        
        if (depth == 0 || gameOver(gameboard)) {
            return make_pair(heuristicScore(gameboard, playerColor), -1);
        }
        
        if (isMaximizingPlayer) {   // max
            bestValue.first = -10000, bestValue.second = -1;
            for (int grid = 0; grid < gameboard.length(); grid++) {
                if (gameboard[grid] == '+' && isValidMove_xue(gameboard, playerColor, grid)) {
                    string newGameboard = flipPieces_xue(gameboard, playerColor, grid);
                    tempValue = AlphaBetaPruning(newGameboard, opponentColor, depth - 1, alpha, beta, false);
                    tempValue.second = grid;
                    
                    if (tempValue.first > bestValue.first)
                        bestValue = tempValue;
                    
                    if (bestValue.first > alpha)
                        alpha = bestValue.first;
                    
                    if (alpha >= beta)
                        break;
                }
            }
        } else {    // min
            bestValue.first = 10000, bestValue.second = -1;
            for (int grid = 0; grid < gameboard.length(); grid++) {
                if (gameboard[grid] == '+' && isValidMove_xue(gameboard, playerColor, grid)) {
                    string newGameboard = flipPieces_xue(gameboard, playerColor, grid);
                    tempValue = AlphaBetaPruning(newGameboard, opponentColor, depth - 1, alpha, beta, true);
                    tempValue.second = grid;
                    
                    if (tempValue.first < bestValue.first)
                        bestValue = tempValue;
                    
                    if (bestValue.first < beta)
                        beta = bestValue.first;
                    
                    if (alpha >= beta)
                        break;
                }
            }
        }
        return bestValue;
    }
};  //BestPlayer
class MinimaxPlayer{
public:
    int playerTile;
    int heuristic; // 0= origin, 1= good, 2= best
    
    MinimaxPlayer(int playerColor, int heuristicChoose){
        playerTile= playerColor;
        heuristic= heuristicChoose;
    }
    string action(string gameboard){
        if(passTurn(gameboard, playerTile)){
            // cout<< (playerTile== 1? "(X)黑":"(O)白")<< "子沒有位置可以下了"<< endl;
            return "pass";
        }else{
            pair<string, int>bestNode;
            // gameboard, playerColor, depth, alpha, beta, heuristic
            bestNode= minimaxSearch(gameboard, playerTile, 4, -99999, 99999, heuristic);
            // cout<< "選擇 \""<< bestNode.first<< "\""<< endl;
            return bestNode.first;
        }
    }
    pair<string, int> minimaxSearch(string gameboard, int playerColor, int depth, int alpha, int beta, int heuristic){
    // return <最佳位置, 最大/小值> ex.<"Ae",-5>
    if(depth== 0 || gameOver(gameboard))
        return pair<string, int>("", heuristicScore(gameboard, playerColor, heuristic));
    
    map<string, int> hScore;
    map<string, int>::iterator iter;
    int opppnentColor;
    if(playerColor== 1) opppnentColor= 2;
    else opppnentColor= 1;
    
    for(int x= 0; x< 6; x++){
        for(int y= 0; y< 6; y++){
            if(gameboard[x*6+ y]== '+'){
                char xChar= ('A'+ x), yChar= ('a'+ y);
                string grid= "";
                grid+= xChar; grid+= yChar;
                if(isValidMove(gameboard, playerColor, grid)){
                    string filped= flipPieces(gameboard, playerColor, grid);
                    hScore[grid]= heuristicScore(filped, playerColor, heuristic);
                }
            }
        }
    }
    
    for(iter= hScore.begin(); iter!= hScore.end(); iter++){
        string filped= flipPieces(gameboard, playerColor, iter->first);
        iter->second= (minimaxSearch(filped, opppnentColor, depth-1, alpha, beta, heuristic)).second;
    }
    
    string maxGrid= "", mingrid= "";
    int max= -9999999, min= 9999999;
    
    if(depth% 2== 0){ // max node
        for(iter= hScore.begin(); iter!= hScore.end(); iter++){
            if(iter->second> max){
                max= iter->second;
                maxGrid= iter->first;
            }
            if(max> alpha) alpha= max;
            if(beta<= alpha) break;
        }
        pair<string, int>maxNode(maxGrid, max);
        return maxNode;
    }
    else{ // min node
        for(iter= hScore.begin(); iter!= hScore.end(); iter++){
            if(iter->second< min){
                min= iter->second;
                mingrid= iter->first;
            }
            if(min< beta) beta= min;
            if(beta<= alpha) break;
        }
        pair<string, int>minNode(mingrid, min);
        return minNode;
    }
}
};
class RandomPlayer{
public:
    int playerTile;
    
    RandomPlayer(int playerColor){
        playerTile= playerColor;
    }
    string action(string gameboard){
        if(passTurn(gameboard, playerTile)){
            cout<< (playerTile== 1? "(X)黑":"(O)白")<< "子沒有位置可以下了"<< endl;
            return "pass";
        }else{
            vector<string> validPos;
            for(int x= 0; x< 6; x++){
                for(int y= 0; y< 6; y++){
                    if(gameboard[x*6+ y]== '+'){
                        char xChar= ('A'+ x), yChar= ('a'+ y);
                        string grid= "";
                        grid+= xChar; grid+= yChar;
                        if(isValidMove(gameboard, playerTile, grid)){
                            validPos.push_back(grid);
                        }
                    }
                }
            }
            int num= validPos.size();
            int randnum= rand()% num;
            string grid= validPos[randnum];
            // cout<< "選擇 \""<< grid<< "\""<< endl;
            return grid;
        }
    }
};

//test function
void AIvsAI(){
    string gameboard, action;
    
    RandomPlayer player1=RandomPlayer(1);
    MinimaxPlayer player2=MinimaxPlayer(2, 1);
    //player2.playerColor=2;
    //player1.playerColor=1;
    gameboard="++++++++++++++OX++++XO++++++++++++++";   //intial gameboard
    //player2.gameboard=gameboard;
    //player1.gameboard=gameboard;
    while(!gameOver(gameboard)){
        cout<<"player2 result: "<<endl;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                cout<<gameboard[i*6+j]<<"  ";
            }
            cout<<endl;
        }
        if(passTurn(gameboard, 1)){
            cout<<"player1 pass"<<endl;
            cout<<"Wait for player2."<<endl;
            //player2
            if(!passTurn(gameboard, 2)){
                string action2=player2.action(gameboard);
                cout<<"player2 action: "<<action2<<endl;
                string new_board2=gameboard;
                flipPieces(&new_board2, gameboard, 2, action2);
                gameboard=new_board2;
                //player2.gameboard=gameboard;
                //player1.gameboard=gameboard;
            }else{
                cout<<"player2 pass"<<endl;
            }
        }else{
            cout<<"Wait for player1."<<endl;
            //player1
            string action1=player1.action(gameboard);
            cout<<"player1 action: "<<action1<<endl;
            string new_board=gameboard;
            flipPieces(&new_board, gameboard, 1, action1);
            gameboard=new_board;
            //player2.gameboard=gameboard;
            //player1.gameboard=gameboard;
            cout<<"player1 result: "<<endl;
            for(int i=0;i<6;i++){
                for(int j=0;j<6;j++){
                    cout<<gameboard[i*6+j]<<"  ";
                }
                cout<<endl;
            }
            cout<<"Wait for player2."<<endl;
            //player2
            if(!passTurn(gameboard, 2)){
                string action2=player2.action(gameboard);
                cout<<"player2 action: "<<action2<<endl;
                string new_board2=gameboard;
                flipPieces(&new_board2, gameboard, 2, action2);
                gameboard=new_board2;
                //player2.gameboard=gameboard;
                //player1.gameboard=gameboard;
            }else{
                cout<<"player2 pass"<<endl;
            }
        }
    }
    cout<<endl<<"game end"<<endl;
    cout<<"final: "<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<gameboard[i*6+j]<<"  ";
        }
        cout<<endl;
    }
    int scores=heuristicScore(gameboard, 1);
    cout<<"player1 scores: "<<scores<<endl;
    int scores2=heuristicScore(gameboard, 2);
    cout<<"player2 scores: "<<scores2<<endl;
    if(scores==0){
        cout<<"tie"<<endl;
    }else if(scores>0){
        cout<<"player1 win"<<endl;
    }else{
        cout<<"player2 win"<<endl;
    }
}

void printGameboard(string gameboard){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<gameboard[i*6+j]<<"  ";
        }
        cout<<endl;
    }
}
void AIAction(AlphaBetaPruningPlayer &AIplayer, string &gameboard, int AITurn){
    if(passTurn(gameboard, AITurn)){
        cout<<"AlphaBetaPruningPlayer pass"<<endl;
    }else{
        cout<<"Wait for AlphaBetaPruningPlayer."<<endl;
        string action2=AIplayer.action();
        cout<<"AlphaBetaPruningPlayer action: "<<action2<<endl;
        string new_board2=gameboard;
        flipPieces(&new_board2, gameboard, AITurn, action2);
        gameboard=new_board2;
        AIplayer.gameboard=gameboard;
        cout<<"AlphaBetaPruningPlayer result:"<<endl;
        printGameboard(gameboard);
    }
}
void humanAction(string &gameboard, AlphaBetaPruningPlayer &AIplayer, int humanTurn){
    if(passTurn(gameboard, humanTurn)){
        cout<<"HumanPlayer pass"<<endl;
    }else{
        cout<<"Wait for HumanPlayer."<<endl;
        cout<<"Enter action (ex:Ae):";
        string action1;
        cin>>action1;
        while(!isValidMove(gameboard, humanTurn, action1)){
            cout<<"Not valid move, input action again: ";
            cin>>action1;
        }
        string new_board=gameboard;
        flipPieces(&new_board, gameboard, humanTurn, action1);
        gameboard=new_board;
        AIplayer.gameboard=gameboard;
        cout<<"HumanPlayer result:"<<endl;
        printGameboard(gameboard);
    }
}
void AIvsHuman(){
    string gameboard, action;
    int AIOrder=0;
    AlphaBetaPruningPlayer AIPlayer;
    gameboard="++++++++++++++OX++++XO++++++++++++++";   //intial gameboard
    AIPlayer.gameboard=gameboard;
    
    cout<<"AI order (1 or 2):";
    cin>>AIOrder;
    while(AIOrder!=1&&AIOrder!=2){
        cout<<"Enter 1 or 2:";
        cin>>AIOrder;
    }
    
    cout<<"start"<<endl;
    if(AIOrder==1){
        AIPlayer.playerColor=1;
        cout<<"initial gameboard:"<<endl;
        printGameboard(gameboard);
        while(!gameOver(gameboard)){
            AIAction(AIPlayer, gameboard, 1);
            humanAction(gameboard, AIPlayer, 2);
        }
    }else{
        AIPlayer.playerColor=2;
        cout<<"initial gameboard:"<<endl;
        printGameboard(gameboard);
        while(!gameOver(gameboard)){
            humanAction(gameboard, AIPlayer, 1);
            AIAction(AIPlayer, gameboard, 2);
        }
    }
    
    cout<<endl<<"game end"<<endl;
    cout<<"final: "<<endl;
    printGameboard(gameboard);

    int humanScores=heuristicScore(gameboard, AIOrder==1?2:1);
    cout<<"HumanPlayer scores: "<<humanScores<<endl;
    int AIscores=heuristicScore(gameboard, AIOrder);
    cout<<"AIPlayer scores: "<<AIscores<<endl;
    if(humanScores==0){
        cout<<"tie"<<endl;
    }else if(humanScores>0){
        cout<<"HumanPlayer win"<<endl;
    }else{
        cout<<"AIPlayer win"<<endl;
    }
}


int main(int argc, const char * argv[]) {
    srand (time(NULL));
    
    AIvsHuman();
//    AIvsAI();
    return 0;
}
