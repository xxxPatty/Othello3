//
//  main.cpp
//  Othello3
//
//  Created by 林湘羚 on 2021/6/9.
//

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>    // std::max
using namespace std;

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


class minimaxSearchWithAlphaBetaPlayer{
public:
    string gameboard;
    int playerColor;
    
    string action(){
        if(!passTurn(gameboard, playerColor)){
            int index=minimaxSearchWithAlphaBeta(gameboard, playerColor, 10, playerColor, -INT_MAX, INT_MAX).second;
            string action="";
            action=action+char(index/6+'A')+char(index%6+'a');
            return action;
        }else{
            return "pass";
        }
    }
    pair<int, int> minimaxSearchWithAlphaBeta(string gameboard, int playerColor, int depth, int myTurn, int a, int b){
        int i, temp2=-2, index=-1;
        if(depth==0 || gameOver(gameboard)){
            return pair<int, int> (heuristicScore(gameboard, playerColor), index);
        }
        if(playerColor==myTurn){    //MAX_Player
            for(i=0;i<36;i++){
                string temp="";
                temp=temp+char(i/6+'A')+char(i%6+'a');
                if(gameboard[i]=='+' && isValidMove(gameboard, playerColor, temp)) {
                    string new_board="";
                    new_board=gameboard;
                    flipPieces(&new_board, gameboard, playerColor, temp);
                    if((temp2=(minimaxSearchWithAlphaBeta(new_board, playerColor == 1 ? 2 : 1, depth-1, myTurn, a, b).first))>a) {
                        a=temp2;
                        index=i;
                    }
                    if(b<=a) break;
                }
            }
            if(i==36){  //pass
                if((temp2=(minimaxSearchWithAlphaBeta(gameboard, playerColor == 1 ? 2 : 1, depth-1, myTurn, a, b).first))>a) {
                    a=temp2;    //?
                }
            }
            return pair<int, int>(a, index);
        }else{      //MIN_Player
            for(i=0;i<36;i++){
                string temp="";
                temp=temp+char(i/6+'A')+char(i%6+'a');
                if(gameboard[i]=='+' && isValidMove(gameboard, playerColor, temp)) {
                    string new_board="";
                    new_board=gameboard;
                    flipPieces(&new_board, gameboard, playerColor, temp);
                    if((temp2=minimaxSearchWithAlphaBeta(new_board, playerColor == 1 ? 2 : 1, depth-1, myTurn, a, b).first)<b) {
                        b=temp2;    //?
                    }
                    if(b<=a) break;
                }
            }
            if(i==36){  //pass
                if((temp2=(minimaxSearchWithAlphaBeta(gameboard, playerColor == 1 ? 2 : 1, depth-1, myTurn, a, b).first))<b) {
                    b=temp2;
                    index=i;
                }
            }
            return pair<int, int>(b, index);
        }
    }
};
class MCTSPlayer2{
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
            int wins = 0;
            int visits = 0;
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
                unexamined.erase(next(unexamined.begin(), index), next(unexamined.begin(), index+1));
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



void MCTSvsMinmax(){
    string gameboard, action;
    
    MCTSPlayer2 player2;
    minimaxSearchWithAlphaBetaPlayer player1;
    player2.playerColor=2;
    player1.playerColor=1;
    gameboard="++++++++++++++OX++++XO++++++++++++++";   //intial gameboard
    player2.gameboard=gameboard;
    player1.gameboard=gameboard;
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
                string action2=player2.action();
                cout<<"player2 action: "<<action2<<endl;
                string new_board2=gameboard;
                flipPieces(&new_board2, gameboard, 2, action2);
                gameboard=new_board2;
                player2.gameboard=gameboard;
                player1.gameboard=gameboard;
            }else{
                cout<<"player2 pass"<<endl;
            }
        }else{
            cout<<"Wait for player1."<<endl;
            //player1
            string action1=player1.action();
            cout<<"player1 action: "<<action1<<endl;
            string new_board=gameboard;
            flipPieces(&new_board, gameboard, 1, action1);
            gameboard=new_board;
            player2.gameboard=gameboard;
            player1.gameboard=gameboard;
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
                string action2=player2.action();
                cout<<"player2 action: "<<action2<<endl;
                string new_board2=gameboard;
                flipPieces(&new_board2, gameboard, 2, action2);
                gameboard=new_board2;
                player2.gameboard=gameboard;
                player1.gameboard=gameboard;
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
void MCTSvsHuman(){
    string gameboard, action;
    
    MCTSPlayer2 player2;
    player2.playerColor=2;
    gameboard="++++++++++++++OX++++XO++++++++++++++";   //intial gameboard
    player2.gameboard=gameboard;
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
                string action2=player2.action();
                cout<<"player2 action: "<<action2<<endl;
                string new_board2=gameboard;
                flipPieces(&new_board2, gameboard, 2, action2);
                gameboard=new_board2;
                player2.gameboard=gameboard;
            }else{
                cout<<"player2 pass"<<endl;
            }
        }else{
            cout<<"Wait for player1."<<endl;
            cout<<"Input your action: ";
            //player1
            string action1;
            cin>>action1;
            while(!isValidMove(gameboard, 1, action1)){
                cout<<"Not valid move, input action again: ";
                cin>>action1;
            }
            string new_board=gameboard;
            flipPieces(&new_board, gameboard, 1, action1);
            gameboard=new_board;
            player2.gameboard=gameboard;
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
                string action2=player2.action();
                cout<<"player2 action: "<<action2<<endl;
                string new_board2=gameboard;
                flipPieces(&new_board2, gameboard, 2, action2);
                gameboard=new_board2;
                player2.gameboard=gameboard;
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
int main(int argc, const char * argv[]) {
    srand (time(NULL));
    
//    MCTSvsHuman();
    MCTSvsMinmax();
    return 0;
}
